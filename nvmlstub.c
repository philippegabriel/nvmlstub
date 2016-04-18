#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <syslog.h>
#include "nvml.h"
//void log(char *msg){
//FILE *fp;
//time_t now;
//struct tm *tm;
//now = time(0);
//tm = localtime (&now);
//fp = fopen ("/tmp/nvmlstub.log","a");
//fprintf(fp,"%02d:%02d-%s\n",tm->tm_min,tm->tm_sec,msg);
//fclose(fp);
//}

int delay(){
int i;
sigset_t blockSet,prevMask;
//sigemptyset(&blockSet);
//sigaddset(&blockSet,SIGINT); //block SIGTERM
sigfillset(&blockSet); //block all signals
if(sigprocmask(SIG_BLOCK,&blockSet,&prevMask)==-1){
	exit(-1);}
for(i=0;i<1000000000;i++){
        int k=rand();
        }
if(sigprocmask(SIG_SETMASK,&prevMask,0)){
	exit(-1);}
syslog(LOG_DEBUG,"return");
return 0;
}

const DECLDIR char* nvmlErrorString(nvmlReturn_t result);
nvmlReturn_t DECLDIR nvmlInit_v2(void){
syslog(LOG_DEBUG,"nvmlErrorString");
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlInit(void){
syslog(LOG_DEBUG,"nvmlInit");
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlShutdown(void){
syslog(LOG_DEBUG,"nvmlShutdown");
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetCount(unsigned int *deviceCount){
*deviceCount=1;
syslog(LOG_DEBUG,"nvmlDeviceGetCount");
//delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleByIndex(unsigned int index, nvmlDevice_t *device){
/*ignore device param*/
syslog(LOG_DEBUG,"nvmlDeviceGetHandleByIndex");
//delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t *memory){
memory->total=10000;
memory->free=2000;
memory->used=8000;
syslog(LOG_DEBUG,"nvmlDeviceGetMemoryInfo");
//delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci){
strcpy(pci->busId,"1:1:1 mocknvml"); //!< The tuple domain:bus:device.function PCI identifier (&amp; NULL terminator)
pci->domain=1;             //!< The PCI domain on which the device's bus resides, 0 to 0xffff
pci->bus=1;                //!< The bus on which the device resides, 0 to 0xff
pci->device=0xbe;             //!< The device's id on the bus, 0 to 31
pci->pciDeviceId=0x0ff210de;        //!< The combined 16-bit device id and 16-bit vendor id
// Added in NVML 2.285 API
pci->pciSubSystemId=0x01;     //!< The 32-bit Sub System Device ID
// NVIDIA reserved for internal use only
pci->reserved0=0;
pci->reserved1=0;
pci->reserved2=0;
pci->reserved3=0;
syslog(LOG_DEBUG,"nvmlDeviceGetPciInfo");
//delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp){
*temp=60;
syslog(LOG_DEBUG,"nvmlDeviceGetTemperature");
delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int *power){
*power=200;
syslog(LOG_DEBUG,"nvmlDeviceGetPowerUsage");
delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t *utilization){
utilization->gpu=50;
utilization->memory=50;
syslog(LOG_DEBUG,"nvmlDeviceGetUtilizationRates");
delay();
return NVML_SUCCESS;
}
nvmlReturn_t DECLDIR nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode){
syslog(LOG_DEBUG,"nvmlDeviceSetPersistenceMode");
//delay();
return NVML_SUCCESS;
}
const DECLDIR char* nvmlErrorString(nvmlReturn_t result){
return "BaconOvercookedSystemError";
}
