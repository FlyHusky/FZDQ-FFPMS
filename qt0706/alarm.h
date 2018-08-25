#ifndef ALARM_H
#define ALARM_H

#include <QString>

class Alarm
{
public:
    Alarm();

    Alarm(unsigned char alarm_kind_t,  unsigned int fpm_id_t);

    unsigned char alarm_kind; //报警类型 1=电压1报警   2=电压2报警  3=报警3
    unsigned int  fpm_id; //发送故障的模块id
    QString fpm_name;   //模块名字
    QString date_str;   //日期
    QString time_str;   //时间
    QString value_str;  //相关数据。
    QString alarm_kind_str;// 报警类型的str类型。


};

#endif // ALARM_H
