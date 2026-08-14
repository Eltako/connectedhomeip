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

#include <app/util/cluster-setup.h>

namespace chip {
namespace app {
namespace Clusters {

#define CHIP_DEFINE_EMPTY_CLUSTER_SETUP(cluster)                                                                                   \
    bool cluster::setup()                                                                                                          \
    {                                                                                                                              \
        return true;                                                                                                               \
    }

CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Identify)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Groups)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OnOff)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(PulseWidthModulation)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Descriptor)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Binding)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(AccessControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Actions)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(BasicInformation)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OtaSoftwareUpdateRequestor)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(LocalizationConfiguration)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(TimeFormatLocalization)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(UnitLocalization)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(PowerSourceConfiguration)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(GeneralCommissioning)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(NetworkCommissioning)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(GeneralDiagnostics)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(SoftwareDiagnostics)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ThreadNetworkDiagnostics)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(WiFiNetworkDiagnostics)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(EthernetNetworkDiagnostics)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(TimeSynchronization)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(BridgedDeviceBasicInformation)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Switch)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(AdministratorCommissioning)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OperationalCredentials)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(GroupKeyManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(FixedLabel)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(UserLabel)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ProxyConfiguration)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ProxyDiscovery)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ProxyValid)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(BooleanState)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(IcdManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Timer)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OvenCavityOperationalState)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OvenMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ModeSelect)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(LaundryWasherMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RefrigeratorAndTemperatureControlledCabinetMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RvcRunMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RvcCleanMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(TemperatureControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RefrigeratorAlarm)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(DishwasherMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(AirQuality)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(SmokeCoAlarm)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(MicrowaveOvenMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(MicrowaveOvenControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OperationalState)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RvcOperationalState)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(HepaFilterMonitoring)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ActivatedCarbonFilterMonitoring)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ElectricalPowerMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(WaterHeaterManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(DemandResponseLoadControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(DeviceEnergyManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(EnergyEvse)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(EnergyPreference)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(PowerTopology)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(EnergyEvseMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(WaterHeaterMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(DeviceEnergyManagementMode)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ServiceArea)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(PumpConfigurationAndControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ThermostatUserInterfaceConfiguration)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(BallastConfiguration)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(IlluminanceMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(TemperatureMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(PressureMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(FlowMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RelativeHumidityMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(CarbonMonoxideConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(CarbonDioxideConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(NitrogenDioxideConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(OzoneConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Pm25ConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(FormaldehydeConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Pm1ConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Pm10ConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(TotalVolatileOrganicCompoundsConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(RadonConcentrationMeasurement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(WiFiNetworkManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ThreadBorderRouterManagement)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(ThreadNetworkDirectory)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(WebRTCTransportProvider)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(Chime)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(EcosystemInformation)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(CommissionerControl)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(UnitTesting)
CHIP_DEFINE_EMPTY_CLUSTER_SETUP(FaultInjection)

#undef CHIP_DEFINE_EMPTY_CLUSTER_SETUP

} // namespace Clusters
} // namespace app
} // namespace chip
