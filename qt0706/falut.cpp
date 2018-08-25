#include "falut.h"

Falut::Falut()
{


}

   Falut::Falut(unsigned char f_k,  unsigned int f_i)
{
        Falut::fault_kind=f_k; //故障类型 1=通讯故障  2=其它
        Falut::fpm_id=f_i; //发送故障的模块id
}
