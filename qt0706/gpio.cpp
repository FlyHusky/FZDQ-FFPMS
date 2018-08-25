#include "gpio.h"



int openGPIO3_4(char *cGpioName){
    int iFd;
    iFd = open(cGpioName, O_RDWR);
    return iFd;
}

int setHighLevel(int fd){
    int ret;
    ret=write(fd,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
    return ret;
}

int setLowLevel(int fd){
    int ret;
    ret=write(fd,GPIO_LOW_LEVEL,sizeof(GPIO_HIGH_LEVEL));
    return ret;
}
