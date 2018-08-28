#include "ffpm.h"

using namespace FFPM

FFPM::FFPM(){}

 //构造函数
 FFPM:: FFPM(int t_id,int t_addr, unsigned char t_kind, unsigned char t_net){
     int i;
   FFPM::id=t_id;
   FFPM::addr=t_addr;
   FFPM::kind=t_kind;
   FFPM::net=t_net;
   FFPM::comm_sta=0; //等待
   FFPM::self_sta=0; //无状态。1=故障状态（通讯故障）  2=报警状态
   FFPM::enable=true; //启用

   FFPM:: v1_alarm_pop=0; //电压1报警弹出  0=没有报警  1=将要弹出报警  2=已经弹出报警。
   FFPM:: v2_alarm_pop=0; //电压2报警弹出
   FFPM:: va_alarm_pop=0; //电压电流报警弹出
   FFPM::comm_fail_pop=0;
   FFPM::guoya=1; //过压判断使能。
  // FFPM::name_gbk="ce|d2";


   //FFPM::bj_pop='0'; //0=没有报警
   for (i=0;i<9;i++){
    cur_data[i]=999.9;
   }

  /*
   2018年8月25日23:19:28  注释掉此部分，超限值改为动态从数据库提取 超限值的和额定值的百分比。
   FFPM::bj_data[0]=180;   //电压为欠压欠值。 v1
   FFPM::bj_data[1]=250;   //电压为过压欠值。

   FFPM::bj_data[2]=180;   //电压为欠压欠值。 v2
   FFPM::bj_data[3]=250;   //电压为过压欠值。

   FFPM::bj_data[4]=180;   //电压为欠压欠值。va3
   FFPM::bj_data[5]=250;   //电压为过压欠值。
*/
    //将标准的超限比值赋给，qy_v
    qy_v1=STD_MIN_RATE_V;
    qy_v2=STD_MIN_RATE_V;
    qy_v3=STD_MIN_RATE_V;  //欠压比值

    gy_v1=STD_MAX_RATE_V;
    gy_v2=STD_MAX_RATE_V;
    gy_v3=STD_MAX_RATE_V; //过压比值

    a_rate = 1 ; //默认初始化互感器的电流变比为1，即在未知电流变比是，显示一次侧的电流。
    bj_data[0] = (qy_v1 / 100) * STD_V;
    bj_data[1] = (gy_v1 / 100) * STD_V; //过压值

    bj_data[2] = (qy_v2 / 100) * STD_V;
    bj_data[3] = (gy_v2 / 100) * STD_V; //过压值

    bj_data[4] = (qy_v3 / 100) * STD_V;
    bj_data[5] = (gy_v3 / 100) * STD_V; //过压值

    bj_data



 }


    //依据占比值，初始化报警值
   FFPM:: Bj_data_init(){
           

   }

    //数据库操作失败时，默认的报警值
    FFPM::Bj_data_init_default(){


    }

 //4位有效数转换浮点数
 QString FormatFloat(float f){
     //cur_data 以前是整数，现在改为浮点数，
     //电流显示原则 1.34A,10.45A,100.5,1000,10001

     QString rs="";
     if (f<100){
         rs=QString::number(f,'f',2);
     }else if (f<1000) {
         rs=QString::number(f,'f',1);
     }else{
         rs=QString::number(f,'f',0);
     }
      return rs;
 }












