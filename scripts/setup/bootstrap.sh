#
# Copyright (c) 2020 Project CHIP Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

_install_additional_pip_requirements() {
    _SETUP_PLATFORM=$1
    shift

    # figure out additional pip install items
    while [ $# -gt 0 ]; do
        case $1 in
            -p | --platform)
                _SETUP_PLATFORM=$2
                shift # argument
                shift # value
                ;;
            *)
                shift
                ;;
        esac
    done

    if [ -n "$_SETUP_PLATFORM" ]; then
        _OLD_IFS=$IFS
        IFS=","
        if [ -n "$ZSH_VERSION" ]; then
            setopt local_options shwordsplit
        fi

        for platform in ${_SETUP_PLATFORM}; do
            # Allow none as an alias of nothing extra installed (like -p none)
            if [ "$platform" != "none" ]; then
                echo "Installing pip requirements for $platform..."
                pip install -q \
                    -r "$_CHIP_ROOT/scripts/setup/requirements.$platform.txt" \
                    -c "$_CHIP_ROOT/scripts/setup/constraints.txt"
            fi
        done
        IFS=$_OLD_IFS
        unset _OLD_IFS
        unset _PLATFORMS
    fi

    unset _SETUP_PLATFORM
}

_bootstrap_or_activate() {
    if [ -n "$BASH" ]; then
        local _BOOTSTRAP_PATH="${BASH_SOURCE[0]}"
    else
        local _BOOTSTRAP_PATH="$1"
    fi

    local _BOOTSTRAP_NAME="${_BOOTSTRAP_PATH##*/}"
    local _BOOTSTRAP_DIR="${_BOOTSTRAP_PATH%/*}"
    # Strip off the 'scripts[/setup]' directory, leaving the root of the repo.
    _CHIP_ROOT="$(cd "${_BOOTSTRAP_DIR%/setup}/.." && pwd)"

    local _CONFIG_FILE="scripts/setup/environment.json"

    if [ -n "$PW_CONFIG_FILE" ]; then
        _CONFIG_FILE="$PW_CONFIG_FILE"
        unset PW_CONFIG_FILE
    fi

    if [ ! -f "$_CHIP_ROOT/third_party/pigweed/repo/pw_env_setup/util.sh" ]; then
        # Make sure our submodule remotes are correct for this revision.
        git submodule sync --recursive
        git submodule update --init
    elif [ "$_BOOTSTRAP_NAME" = "bootstrap.sh" ]; then
        # In this case, only update already checked out submodules.
        git submodule sync --recursive
        git submodule update
    fi

    PW_BRANDING_BANNER="$_CHIP_ROOT/scripts/setup/banner.txt"
    export PW_BRANDING_BANNER

    PW_PROJECT_ROOT="$_CHIP_ROOT"
    export PW_PROJECT_ROOT

    PW_ROOT="$_CHIP_ROOT/third_party/pigweed/repo"
    export PW_ROOT

    . "$_CHIP_ROOT/third_party/pigweed/repo/pw_env_setup/util.sh"

    _chip_bootstrap_banner() {
        if [ -z "$PW_ENVSETUP_QUIET" ] && [ -z "$PW_ENVSETUP_NO_BANNER" ]; then
            cat "$PW_BRANDING_BANNER"
            echo
        fi
    }

    local _PW_BANNER_FUNC="_chip_bootstrap_banner"

    # Force the Pigweed environment directory to be '.environment'
    if [ -z "$PW_ENVIRONMENT_ROOT" ]; then
        export PW_ENVIRONMENT_ROOT="$PW_PROJECT_ROOT/.environment"
    fi

    export _PW_ACTUAL_ENVIRONMENT_ROOT="$(pw_get_env_root)"
    local _SETUP_SH="$_PW_ACTUAL_ENVIRONMENT_ROOT/activate.sh"

    export PW_DOCTOR_SKIP_CIPD_CHECKS=1
    export PATH # https://bugs.chromium.org/p/pigweed/issues/detail?id=281

    local _PIGWEED_CIPD_JSON="$_CHIP_ROOT/third_party/pigweed/repo/pw_env_setup/py/pw_env_setup/cipd_setup/pigweed.json"
    mkdir -p "$_PW_ACTUAL_ENVIRONMENT_ROOT"
    local _GENERATED_PIGWEED_CIPD_JSON="$_PW_ACTUAL_ENVIRONMENT_ROOT/pigweed.json"
    scripts/setup/gen_pigweed_cipd_json.py -i $_PIGWEED_CIPD_JSON -o $_GENERATED_PIGWEED_CIPD_JSON

    if test -n "$GITHUB_ACTION"; then
        tee <<EOF >"${_PW_ACTUAL_ENVIRONMENT_ROOT}/pip.conf"
[global]
cache-dir = ${_PW_ACTUAL_ENVIRONMENT_ROOT}/pip-cache
EOF
        export PIP_CONFIG_FILE="$_PW_ACTUAL_ENVIRONMENT_ROOT/pip.conf"
    fi

    if [ "$_BOOTSTRAP_NAME" = "bootstrap.sh" ] ||
        [ ! -f "$_SETUP_SH" ] ||
        [ ! -s "$_SETUP_SH" ]; then
        pw_bootstrap --shell-file "$_SETUP_SH" \
            --install-dir "$_PW_ACTUAL_ENVIRONMENT_ROOT" \
            --config-file "$_CHIP_ROOT/$_CONFIG_FILE" \
            --virtualenv-gn-out-dir "$_PW_ACTUAL_ENVIRONMENT_ROOT/gn_out" \
            --additional-cipd-file "$_GENERATED_PIGWEED_CIPD_JSON"
        pw_finalize bootstrap "$_SETUP_SH"
        _ACTION_TAKEN="bootstrap"
    else
        pw_activate
        pw_finalize activate "$_SETUP_SH"
        _ACTION_TAKEN="activate"
    fi
}

# remember PW_ENVIRONMENT_ROOT so that things like another
# bootstrap or run_in_build_env.sh can be executed in a build env
_ORIGINAL_PW_ENVIRONMENT_ROOT="$PW_ENVIRONMENT_ROOT"

# pigweed does not seem to handle pwd involving symlinks very well.
original_pwd=$PWD
if hash realpath 2>/dev/null; then
    realpwd="$(realpath "$PWD")"
    if [ "$realpwd" != "$PWD" ]; then
        echo "Warning: $PWD contains symlinks, using $realpwd instead"
        cd "$realpwd"
    fi
fi

_bootstrap_or_activate "$0"

cd $original_pwd

if [ "$_ACTION_TAKEN" = "bootstrap" ]; then
    # By default, install all extra pip dependencies even if slow. -p/--platform
    # arguments may override this default.
    _install_additional_pip_requirements "all" "$@"
else
    _install_additional_pip_requirements "none" "$@"
fi

# Load bash completion helper if running bash
if [ -n "$BASH" ]; then
    . "$_CHIP_ROOT/scripts/helpers/bash-completion.sh"
fi

unset -f _bootstrap_or_activate
unset -f _install_additional_pip_requirements

pw_cleanup

unset _ACTION_TAKEN
unset _CHIP_ROOT
unset PW_CIPD_INSTALL_DIR
unset _PW_BANNER_FUNC
unset _PW_TEXT
unset PW_DOCTOR_SKIP_CIPD_CHECKS

unset -f _chip_bootstrap_banner

if [ -n "$_ORIGINAL_PW_ENVIRONMENT_ROOT" ]; then
    export PW_ENVIRONMENT_ROOT="$_ORIGINAL_PW_ENVIRONMENT_ROOT"
fi
