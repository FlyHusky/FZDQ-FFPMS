#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <limits.h>
#include <asm/ioctls.h>
//#include <time.h>
#include <string.h>


#define GPIO_HIGH_LEVEL "1"
#define GPIO_LOW_LEVEL "0"



//extern  int openSerial(char *cSerialName); //打开串口

  int openGPIO3_4(char *cGpioName);
  int setHighLevel(int *fd);
  int setLowLevel(int *fd);


#endif // GPIO_H
