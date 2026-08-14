/*
 *
 *    Copyright (c) 2026 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

namespace chip {
namespace app {
namespace Clusters {

/**
 * Set up process-lifetime storage used by a cluster.
 *
 * Applications must call the setup function for each enabled cluster before
 * initializing the CHIP stack. If a custom allocate-forever function is used,
 * install it before calling these functions. Calls are idempotent. A false
 * return value indicates that required storage could not be allocated.
 */
#define CHIP_DECLARE_CLUSTER_SETUP(cluster)                                                                                        \
    namespace cluster {                                                                                                            \
    bool setup();                                                                                                                  \
    }

CHIP_DECLARE_CLUSTER_SETUP(Identify)
CHIP_DECLARE_CLUSTER_SETUP(Groups)
CHIP_DECLARE_CLUSTER_SETUP(OnOff)
CHIP_DECLARE_CLUSTER_SETUP(LevelControl)
CHIP_DECLARE_CLUSTER_SETUP(PulseWidthModulation)
CHIP_DECLARE_CLUSTER_SETUP(Descriptor)
CHIP_DECLARE_CLUSTER_SETUP(Binding)
CHIP_DECLARE_CLUSTER_SETUP(AccessControl)
CHIP_DECLARE_CLUSTER_SETUP(Actions)
CHIP_DECLARE_CLUSTER_SETUP(BasicInformation)
CHIP_DECLARE_CLUSTER_SETUP(OtaSoftwareUpdateProvider)
CHIP_DECLARE_CLUSTER_SETUP(OtaSoftwareUpdateRequestor)
CHIP_DECLARE_CLUSTER_SETUP(LocalizationConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(TimeFormatLocalization)
CHIP_DECLARE_CLUSTER_SETUP(UnitLocalization)
CHIP_DECLARE_CLUSTER_SETUP(PowerSourceConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(PowerSource)
CHIP_DECLARE_CLUSTER_SETUP(GeneralCommissioning)
CHIP_DECLARE_CLUSTER_SETUP(NetworkCommissioning)
CHIP_DECLARE_CLUSTER_SETUP(DiagnosticLogs)
CHIP_DECLARE_CLUSTER_SETUP(GeneralDiagnostics)
CHIP_DECLARE_CLUSTER_SETUP(SoftwareDiagnostics)
CHIP_DECLARE_CLUSTER_SETUP(ThreadNetworkDiagnostics)
CHIP_DECLARE_CLUSTER_SETUP(WiFiNetworkDiagnostics)
CHIP_DECLARE_CLUSTER_SETUP(EthernetNetworkDiagnostics)
CHIP_DECLARE_CLUSTER_SETUP(TimeSynchronization)
CHIP_DECLARE_CLUSTER_SETUP(BridgedDeviceBasicInformation)
CHIP_DECLARE_CLUSTER_SETUP(Switch)
CHIP_DECLARE_CLUSTER_SETUP(AdministratorCommissioning)
CHIP_DECLARE_CLUSTER_SETUP(OperationalCredentials)
CHIP_DECLARE_CLUSTER_SETUP(GroupKeyManagement)
CHIP_DECLARE_CLUSTER_SETUP(FixedLabel)
CHIP_DECLARE_CLUSTER_SETUP(UserLabel)
CHIP_DECLARE_CLUSTER_SETUP(ProxyConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(ProxyDiscovery)
CHIP_DECLARE_CLUSTER_SETUP(ProxyValid)
CHIP_DECLARE_CLUSTER_SETUP(BooleanState)
CHIP_DECLARE_CLUSTER_SETUP(IcdManagement)
CHIP_DECLARE_CLUSTER_SETUP(Timer)
CHIP_DECLARE_CLUSTER_SETUP(OvenCavityOperationalState)
CHIP_DECLARE_CLUSTER_SETUP(OvenMode)
CHIP_DECLARE_CLUSTER_SETUP(LaundryDryerControls)
CHIP_DECLARE_CLUSTER_SETUP(ModeSelect)
CHIP_DECLARE_CLUSTER_SETUP(LaundryWasherMode)
CHIP_DECLARE_CLUSTER_SETUP(RefrigeratorAndTemperatureControlledCabinetMode)
CHIP_DECLARE_CLUSTER_SETUP(LaundryWasherControls)
CHIP_DECLARE_CLUSTER_SETUP(RvcRunMode)
CHIP_DECLARE_CLUSTER_SETUP(RvcCleanMode)
CHIP_DECLARE_CLUSTER_SETUP(TemperatureControl)
CHIP_DECLARE_CLUSTER_SETUP(RefrigeratorAlarm)
CHIP_DECLARE_CLUSTER_SETUP(DishwasherMode)
CHIP_DECLARE_CLUSTER_SETUP(AirQuality)
CHIP_DECLARE_CLUSTER_SETUP(SmokeCoAlarm)
CHIP_DECLARE_CLUSTER_SETUP(DishwasherAlarm)
CHIP_DECLARE_CLUSTER_SETUP(MicrowaveOvenMode)
CHIP_DECLARE_CLUSTER_SETUP(MicrowaveOvenControl)
CHIP_DECLARE_CLUSTER_SETUP(OperationalState)
CHIP_DECLARE_CLUSTER_SETUP(RvcOperationalState)
CHIP_DECLARE_CLUSTER_SETUP(ScenesManagement)
CHIP_DECLARE_CLUSTER_SETUP(HepaFilterMonitoring)
CHIP_DECLARE_CLUSTER_SETUP(ActivatedCarbonFilterMonitoring)
CHIP_DECLARE_CLUSTER_SETUP(BooleanStateConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(ValveConfigurationAndControl)
CHIP_DECLARE_CLUSTER_SETUP(ElectricalPowerMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(ElectricalEnergyMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(WaterHeaterManagement)
CHIP_DECLARE_CLUSTER_SETUP(DemandResponseLoadControl)
CHIP_DECLARE_CLUSTER_SETUP(Messages)
CHIP_DECLARE_CLUSTER_SETUP(DeviceEnergyManagement)
CHIP_DECLARE_CLUSTER_SETUP(EnergyEvse)
CHIP_DECLARE_CLUSTER_SETUP(EnergyPreference)
CHIP_DECLARE_CLUSTER_SETUP(PowerTopology)
CHIP_DECLARE_CLUSTER_SETUP(EnergyEvseMode)
CHIP_DECLARE_CLUSTER_SETUP(WaterHeaterMode)
CHIP_DECLARE_CLUSTER_SETUP(DeviceEnergyManagementMode)
CHIP_DECLARE_CLUSTER_SETUP(DoorLock)
CHIP_DECLARE_CLUSTER_SETUP(WindowCovering)
CHIP_DECLARE_CLUSTER_SETUP(ServiceArea)
CHIP_DECLARE_CLUSTER_SETUP(PumpConfigurationAndControl)
CHIP_DECLARE_CLUSTER_SETUP(Thermostat)
CHIP_DECLARE_CLUSTER_SETUP(FanControl)
CHIP_DECLARE_CLUSTER_SETUP(ThermostatUserInterfaceConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(ColorControl)
CHIP_DECLARE_CLUSTER_SETUP(BallastConfiguration)
CHIP_DECLARE_CLUSTER_SETUP(IlluminanceMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(TemperatureMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(PressureMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(FlowMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(RelativeHumidityMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(OccupancySensing)
CHIP_DECLARE_CLUSTER_SETUP(CarbonMonoxideConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(CarbonDioxideConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(NitrogenDioxideConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(OzoneConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(Pm25ConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(FormaldehydeConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(Pm1ConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(Pm10ConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(TotalVolatileOrganicCompoundsConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(RadonConcentrationMeasurement)
CHIP_DECLARE_CLUSTER_SETUP(WiFiNetworkManagement)
CHIP_DECLARE_CLUSTER_SETUP(ThreadBorderRouterManagement)
CHIP_DECLARE_CLUSTER_SETUP(ThreadNetworkDirectory)
CHIP_DECLARE_CLUSTER_SETUP(WakeOnLan)
CHIP_DECLARE_CLUSTER_SETUP(Channel)
CHIP_DECLARE_CLUSTER_SETUP(TargetNavigator)
CHIP_DECLARE_CLUSTER_SETUP(MediaPlayback)
CHIP_DECLARE_CLUSTER_SETUP(MediaInput)
CHIP_DECLARE_CLUSTER_SETUP(LowPower)
CHIP_DECLARE_CLUSTER_SETUP(KeypadInput)
CHIP_DECLARE_CLUSTER_SETUP(ContentLauncher)
CHIP_DECLARE_CLUSTER_SETUP(AudioOutput)
CHIP_DECLARE_CLUSTER_SETUP(ApplicationLauncher)
CHIP_DECLARE_CLUSTER_SETUP(ApplicationBasic)
CHIP_DECLARE_CLUSTER_SETUP(AccountLogin)
CHIP_DECLARE_CLUSTER_SETUP(ContentControl)
CHIP_DECLARE_CLUSTER_SETUP(ContentAppObserver)
CHIP_DECLARE_CLUSTER_SETUP(WebRTCTransportProvider)
CHIP_DECLARE_CLUSTER_SETUP(Chime)
CHIP_DECLARE_CLUSTER_SETUP(EcosystemInformation)
CHIP_DECLARE_CLUSTER_SETUP(CommissionerControl)
CHIP_DECLARE_CLUSTER_SETUP(UnitTesting)
CHIP_DECLARE_CLUSTER_SETUP(FaultInjection)
CHIP_DECLARE_CLUSTER_SETUP(SampleMei)

#undef CHIP_DECLARE_CLUSTER_SETUP

} // namespace Clusters
} // namespace app
} // namespace chip
