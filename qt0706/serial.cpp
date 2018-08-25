#include "serial.h"
/*********************************************************************************************************
** Function name:           openSerial
** Descriptions:            open serial port at raw mod
** input paramters:         iNum        serial port which can be value at: 1, 2, 3, 4
** output paramters:        NONE
** Return value:            file descriptor
** Create by:               zhuguojun
** Create Data:             2008-05-19
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
 int openSerial(char *cSerialName)
    {
        int iFd;

        struct termios opt;
         //设置串口非阻塞模式=O_NDELAY   相对于阻塞
        iFd = open(cSerialName, O_RDWR | O_NOCTTY | O_NDELAY);
        if(iFd < 0) {
            perror(cSerialName);
            return -1;
        }

        tcgetattr(iFd, &opt);

        //cfsetispeed(&opt, B57600);
        //cfsetospeed(&opt, B57600);

        // cfsetispeed(&opt, B115200);
        // cfsetospeed(&opt, B115200);

        cfsetispeed(&opt, B9600);
        cfsetospeed(&opt, B9600);

        // cfsetispeed(&opt, B19200);
         //cfsetospeed(&opt, B19200);

        /*
         * raw mode
         */
        opt.c_lflag   &=   ~(ECHO   |   ICANON   |   IEXTEN   |   ISIG);
        opt.c_iflag   &=   ~(BRKINT   |   ICRNL   |   INPCK   |   ISTRIP   |   IXON);
        opt.c_oflag   &=   ~(OPOST);
        opt.c_cflag   &=   ~(CSIZE   |   PARENB);
        opt.c_cflag   |=   CS8;

        /*
         * 'DATA_LEN' bytes can be read by serial
         */
        opt.c_cc[VMIN]   =   DATA_LEN;   //
        opt.c_cc[VTIME]  =   150;  //15秒后返回，如果没有接收到数据。

        if (tcsetattr(iFd,   TCSANOW,   &opt)<0) {
            return   -1;
        }


        return iFd;
    }


    /*********************************************************************************************************
        end file
    *********************************************************************************************************/

