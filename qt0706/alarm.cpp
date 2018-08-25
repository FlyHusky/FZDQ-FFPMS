#include "alarm.h"

Alarm::Alarm()
{
}

Alarm::Alarm(unsigned char alarm_kind_t,  unsigned int fpm_id_t){
     //alarm_kind=alarm_kind_t; //报警类型 1=通讯故障  2=其它
     fpm_id=fpm_id_t; //发送故障的模块id
}
