//定义FFPM 消防设备电源监控模块类。
#ifndef FFPM_H
#define FFPM_H
#include <QtGlobal>
#include <QString>
#define STD_A  5   //额定的电流
#define STD_V  230 //额定的电压
#define MAX_RATE_V 150 //最大超限值比  电压
#define MIN_RATE_V 50  //最小低限值比
#define STD_MAX_RATE_V 120 //标准超限值
#define STD_MIN_RATE_V  80  //标准低限值

#define MAX_RATE_A 200 //最大超限值比  电流
#define MIN_RATE_A 0  //最小低限值比
#define STD_MAX_RATE_A 120 //标准超限值
#define STD_MIN_RATE_A  0  //标准低限值



//4位有效数转换浮点数
QString FormatFloat(float f);

class FFPM
{
public:
    FFPM();

    FFPM(int t_id,int t_addr, unsigned char t_kind, unsigned char t_net);

    //依据占比值，初始化报警值
    Bj_data_init();

    //数据库操作失败时，默认的报警值
    Bj_data_init_default();

    unsigned int addr; //模块地址16位无符号整数
    unsigned int id;   //差不多和addr相同。

    QString name;        //箱号，名字
   // QString name_gbk;   //箱号的GBK编码。

    unsigned char kind; //kind 模块类型 1=M3-V2   2=M3-V2A  3=M3-V3  4=M3-VA  5=M2-V6  6=M2-V9
    unsigned char net; //归属之路，或在所在串口。  1=1-RS485   2=2-RS485   3=3-RS485  4=4-RS485

  //  int cur_data[9]; //遥测实时值。
    float cur_data[9];

    int bj_data[9];  //超限报警值

    //下面9个值都为额定的值的比
    //比如欠压比为78  ，时间欠压值=230*0.78    
    int  qy_v1;     //电压1的欠压比
    int  qy_v2 ;     //电压2的欠压
    int  qy_v3 ;     //电压3的低限
    int  gy_v1 ;   //电压1的过压
    int  gy_v2 ;   //电压2的过压
    int  gy_v3 ;   //电压3的高限
    int  qy_a; //电流低限
    int  gy_a; //电流高限比

    int a_rate; //电流变比 100：5 的互感器 ，变比=20

   unsigned char  guoya;      //过压判断启用>=1  不启用=0;
   unsigned char  qianya;     //欠压判断启用>=1   不启用=0;
   unsigned char guoliu;      //电流3的欠流启用>=1  不启用=0;
   unsigned char  qianliu;    //电流3的过流启用>=1   不启用=0;

    unsigned char comm_sta; //通讯状态 0=通讯 等待  1=通讯正常   2=通讯异常   3=通讯校验
    unsigned char comm_fail_ct;  //通讯失连统计。
    unsigned char comm_fail_pop; //通讯故障弹出状态0=没有故障  1=将要弹出  2=已经弹出

    unsigned char self_sta; //自生状态。
    bool enable; //启用或者隔离
    //bool guoya; //过压判断。
    //char bj_pop; //报警弹出标志。
    //后期，添加低限报警，超限报警，缺相报警，失压，无流，过流报警等。

    unsigned char v1_alarm_pop; //电压1报警弹出  0=没有报警  1=将要弹出报警  2=已经弹出报警。
    unsigned char v2_alarm_pop; //电压2报警弹出
    unsigned char va_alarm_pop; //电压电流报警弹出
};

#endif // FFPM_H


/*  sqlite3 中，数据库对ffpm的表定义及插入数据设计。

CREATE TABLE ffpm_info(id int primary key, addr int, net tinyint name nvarchar(30), kind tinyint, enable tinyint, guoya tinyint,qy_v1 int, qy_v2 int, qy_v3 int, gy_v1 int, gy_v2 int, gy_v3 int);

id int primary key,   //id 标号，主键，不可重复。。
addr int,             //地址
net tinyint，         //所在RS 485之路编号。  1= -4
name nvarchar(30),   //箱号
kind tinyint,        //模块类型 1=M3-V2   2=M3-V3   3=M3-V2A
enable tinyint,       //隔离，启用
guoya tinyint,      //过压判断启用
qianya tinyint,    //欠压判断启用
guoliu tinyint,   //电流3的欠流启用
qianliu tinyint, //电流3的过流启用

qy_v1 int,     //电压1的欠压值
qy_v2 int,     //电压2的欠压值
qy_va3 int,     //电压/电流3的低限值

gy_v1 int,    //电压1的过压值
gy_v2 int,    //电压2的过压值
gy_va3 int);   //电压/电流3的高限值

insert into ffpm_info values(1,1,1,'1ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(2,2,1,'群楼1层主配',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(3,3,1,'群楼2层主配',2,1,1,1,0,1,185,185,185,250,250,250);

insert into ffpm_info values(7,7,1,'7ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(6,6,1,'6ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(5,5,1,'5ALE',1,1,1,1,0,1,185,185,185,250,250,250);

insert into ffpm_info values(4,4,1,'4ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(8,8,1,'8ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(9,9,1,'9ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(10,10,1,'10ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(11,11,1,'11ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(12,12,1,'12ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(13,13,1,'13ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(14,14,1,'14ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(15,15,1,'15ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(16,16,1,'16ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(17,17,1,'17ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(18,18,1,'18ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(19,19,1,'19ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(20,20,1,'20ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(21,21,1,'21ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(22,22,1,'23ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(23,23,1,'23ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(24,24,1,'24ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(25,25,1,'25ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(26,26,1,'26ALE',1,1,1,1,0,1,185,185,185,250,250,250);
insert into ffpm_info values(27,27,1,'27ALE',1,1,1,1,0,1,185,185,185,250,250,250);

数据库基础信息表 sys_main_info
//系统名称
//系统节点数量
//探测器通讯口---暂时无用
//打印机通讯口---暂时无用
//是否为认证的---暂时无用
//3个密码。
//通讯失连次数---设置为0,系统将自动根据节点数量和报警30秒的时间，来算出此值。
//保留1---
//保留2
create table sys_main_info(
sys_name nvarchar(50),
sys_node_ct smallint unsigned not null,
sys_tcq_com tinyint unsigned,
sys_printer_com tinyint unsigned,
sys_renzheng tinyint unsigned,
sys_l1_pass char(6),
sys_l2_pass char(6),
sys_l3_pass char(6),
sys_comm_fail_ct  tinyint unsigned not null,
sys_b1 char(6),
sys_b2 char(6));
insert into sys_main_info values("FFPMS消防设备电源监控系统", 35,1,1,1,"885200","123456","123456",4,"123456","123456");


历史报警信息表
日期用text来保存
create table his_alarm(ffpm_id int,name nvarchar(30), alarm_kind text,alarm_date text,alarm_time text,alarm_value text);

*/



//将buf_rec 数组清零
// memset(buf_rec,0,sizeof(buf_rec));
//创建串口接收线程，创建成功后立刻开始运行。
//pthread_create(&tid,NULL,rec_data,NULL);

