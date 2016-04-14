#include <stdio.h>
#include "nvml.h"
int main (){
int ret,x;
ret=nvmlInit();
printf("Called %s return=%d\n","nvmlInit()",ret);
ret=nvmlShutdown();
printf("Called %s return=%d\n","nvmlShutdown()",ret);
ret=nvmlDeviceGetCount(&x);
printf("Called %s return=%d,%d\n","nvmlDeviceGetCount",ret,x);
nvmlMemory_t memory_info;
nvmlDevice_t device;
ret=nvmlDeviceGetHandleByIndex(0,&device);
printf("Called %s return=%d\n","nvmlDeviceGetHandleByIndex",ret);
ret=nvmlDeviceGetMemoryInfo(device,&memory_info);
printf("Called %s return=%d,%d,%d,%d\n","nvmlDeviceGetMemoryInfo",ret,memory_info.total,memory_info.used,memory_info.free);
nvmlPciInfo_t pci_info;
ret=nvmlDeviceGetPciInfo(device,&pci_info);
printf("Called %s return=%d,%s,%x\n","nvmlDeviceGetPciInfo",ret,pci_info.busId,pci_info.pciDeviceId);
unsigned int temp;
ret=nvmlDeviceGetTemperature(device,NVML_TEMPERATURE_GPU, &temp);
printf("Called %s return=%d,%d\n","nvmlDeviceGetTemperature",ret,temp);
unsigned int power;
ret=nvmlDeviceGetPowerUsage(device,&power);
printf("Called %s return=%d,%d\n","nvmlDeviceGetPowerUsage",ret,power);
nvmlUtilization_t utilization;
ret=nvmlDeviceGetUtilizationRates(device, &utilization);
printf("Called %s return=%d,%d,%d\n","nvmlDeviceGetUtilizationRates",ret,utilization.gpu,utilization.memory);
nvmlEnableState_t mode;
ret=nvmlDeviceSetPersistenceMode(device,mode);
printf("Called %s return=%d\n","nvmlDeviceSetPersistenceMode",ret);
nvmlReturn_t result;
printf("Called %s return=%s\n","nvmlErrorString",nvmlErrorString(result));
return 0;
}
