#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <dlfcn.h>
#include "nvml.h"
typedef struct nvmlInterface {
    void* handle;
    char* (*errorString)(nvmlReturn_t);
    nvmlReturn_t (*init)(void);
    nvmlReturn_t (*shutdown)(void);
    nvmlReturn_t (*deviceGetCount)(unsigned int*);
    nvmlReturn_t (*deviceGetHandleByIndex)(unsigned int, nvmlDevice_t*);
    nvmlReturn_t (*deviceGetMemoryInfo)(nvmlDevice_t, nvmlMemory_t*);
    nvmlReturn_t (*deviceGetPciInfo)(nvmlDevice_t, nvmlPciInfo_t*);
    nvmlReturn_t (*deviceGetTemperature)
        (nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int*);
    nvmlReturn_t (*deviceGetPowerUsage)(nvmlDevice_t, unsigned int*);
    nvmlReturn_t (*deviceGetUtilizationRates)(nvmlDevice_t, nvmlUtilization_t*);

    nvmlReturn_t (*deviceSetPersistenceMode)(nvmlDevice_t, nvmlEnableState_t);
} nvmlInterface;

int main (){
nvmlInterface *interface;
interface = malloc(sizeof(nvmlInterface));

// Open the library.
interface->handle = dlopen("libnvidia-ml.so.1", RTLD_LAZY);
if (!interface->handle) {
	errx(1,"%s\n","libnvidia-ml.so.1 not found");
}
printf("Loaded libnvidia-ml.so.1 OK\n");

// Load nvmlErrorString.
    interface->errorString = dlsym(interface->handle, "nvmlErrorString");
    if (!interface->errorString) {
	errx(1,"%s\n","Failed to load nvmlErrorString.");
    }
// Load nvmlInit.
    interface->init = dlsym(interface->handle, "nvmlInit");
    if (!interface->init) {
	errx(1,"%s\n","Failed to load nvmlInit");
    }
   // Load nvmlShutdown.
    interface->shutdown = dlsym(interface->handle, "nvmlShutdown");
    if (!interface->shutdown) {
	errx(1,"%s\n","Failed to load nvmlShutdown");
    }

    // Load nvmlDeviceGetCount.
    interface->deviceGetCount = dlsym(interface->handle, "nvmlDeviceGetCount");
    if (!interface->deviceGetCount) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetCount");
    }

    // Load nvmlDeviceGetHandleByIndex.
    interface->deviceGetHandleByIndex =
        dlsym(interface->handle, "nvmlDeviceGetHandleByIndex");
    if(!interface->deviceGetHandleByIndex) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetHandleByIndex");
    }

    // Load nvmlDeviceGetMemoryInfo.
    interface->deviceGetMemoryInfo =
        dlsym(interface->handle, "nvmlDeviceGetMemoryInfo");
    if(!interface->deviceGetMemoryInfo) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetMemoryInfo");
    }

    // Load nvmlDeviceGetPciInfo.
    interface->deviceGetPciInfo =
        dlsym(interface->handle, "nvmlDeviceGetPciInfo_v2");
    if(!interface->deviceGetPciInfo) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetPciInfo_v2");
    }

    // Load nvmlDeviceGetTemperature.
    interface->deviceGetTemperature =
        dlsym(interface->handle, "nvmlDeviceGetTemperature");
    if(!interface->deviceGetTemperature) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetTemperature");
    }

    // Load nvmlDeviceGetPowerUsage.
    interface->deviceGetPowerUsage =
        dlsym(interface->handle, "nvmlDeviceGetPowerUsage");
    if(!interface->deviceGetPowerUsage) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetPowerUsage");
    }

    // Load nvmlDeviceGetUtilizationRates.
    interface->deviceGetUtilizationRates =
        dlsym(interface->handle, "nvmlDeviceGetUtilizationRates");
    if(!interface->deviceGetUtilizationRates) {
	errx(1,"%s\n","Failed to load nvmlDeviceGetUtilizationRates");
    }

    // Load nvmlDeviceSetPersistenceMode.
    interface->deviceSetPersistenceMode =
        dlsym(interface->handle, "nvmlDeviceSetPersistenceMode");
    if(!interface->deviceSetPersistenceMode) {
	errx(1,"%s\n","Failed to load nvmlDeviceSetPersistenceMode");
    }

//Call the library
int ret,x;
ret=interface->init();
printf("Called %s return=%d\n","nvmlInit()",ret);
ret=interface->shutdown();
printf("Called %s return=%d\n","nvmlShutdown()",ret);
ret=interface->deviceGetCount(&x);
printf("Called %s return=%d,%d\n","nvmlDeviceGetCount",ret,x);
nvmlMemory_t memory_info;
nvmlDevice_t device;
ret=interface->deviceGetHandleByIndex(0,&device);
printf("Called %s return=%d\n","nvmlDeviceGetHandleByIndex",ret);
ret=interface->deviceGetMemoryInfo(device,&memory_info);
printf("Called %s return=%d,%llu,%llu,%llu\n","nvmlDeviceGetMemoryInfo",ret,memory_info.total,memory_info.used,memory_info.free);
nvmlPciInfo_t pci_info;
ret=interface->deviceGetPciInfo(device,&pci_info);
printf("Called %s return=%d,%s,%x\n","nvmlDeviceGetPciInfo",ret,pci_info.busId,pci_info.pciDeviceId);
unsigned int temp;
ret=interface->deviceGetTemperature(device,NVML_TEMPERATURE_GPU, &temp);
printf("Called %s return=%d,%d\n","nvmlDeviceGetTemperature",ret,temp);
unsigned int power;
ret=interface->deviceGetPowerUsage(device,&power);
printf("Called %s return=%d,%d\n","nvmlDeviceGetPowerUsage",ret,power);
nvmlUtilization_t utilization;
ret=interface->deviceGetUtilizationRates(device, &utilization);
printf("Called %s return=%d,%d,%d\n","nvmlDeviceGetUtilizationRates",ret,utilization.gpu,utilization.memory);
nvmlEnableState_t mode;
ret=interface->deviceSetPersistenceMode(device,mode);
printf("Called %s return=%d\n","nvmlDeviceSetPersistenceMode",ret);
nvmlReturn_t result;
printf("Called %s return=%s\n","nvmlErrorString",interface->errorString(result));
return 0;
}
