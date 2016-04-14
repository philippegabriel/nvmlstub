#include <string.h>
#include "nvml.h"
const DECLDIR char* nvmlErrorString(nvmlReturn_t result);
nvmlReturn_t DECLDIR nvmlInit(void){
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlShutdown(void){
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetCount(unsigned int *deviceCount){
*deviceCount=22;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleByIndex(unsigned int index, nvmlDevice_t *device){
/*ignore device param*/
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t *memory){
memory->total=10000;
memory->free=2000;
memory->used=8000;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci){
strcpy(pci->busId,"1:1:1 Test"); //!< The tuple domain:bus:device.function PCI identifier (&amp; NULL terminator)
pci->domain=1;             //!< The PCI domain on which the device's bus resides, 0 to 0xffff
pci->bus=1;                //!< The bus on which the device resides, 0 to 0xff
pci->device=0xbe;             //!< The device's id on the bus, 0 to 31
pci->pciDeviceId=0xbeef;        //!< The combined 16-bit device id and 16-bit vendor id
// Added in NVML 2.285 API
pci->pciSubSystemId=0xdead;     //!< The 32-bit Sub System Device ID
// NVIDIA reserved for internal use only
pci->reserved0=0;
pci->reserved1=0;
pci->reserved2=0;
pci->reserved3=0;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp){
*temp=60;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int *power){
*power=200;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t *utilization){
utilization->gpu=50;
utilization->memory=50;
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode){
return NVML_SUCCESS;
}
