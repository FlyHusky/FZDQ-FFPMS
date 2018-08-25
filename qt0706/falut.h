#ifndef FALUT_H
#define FALUT_H

#include <QString>

//故障对象类

class Falut
{
public:
    Falut();
    Falut(unsigned char f_k,  unsigned int f_i);

    unsigned char fault_kind; //故障类型 1=通讯故障  2=其它
    unsigned int  fpm_id; //发送故障的模块id
    QString fpm_name;   //模块名字
    QString date_str;   //日期
    QString time_str;   //时间

};

#endif // FALUT_H
