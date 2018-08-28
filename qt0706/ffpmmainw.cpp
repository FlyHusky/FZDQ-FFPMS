/*
  程序修改说明：
  时间：2017-11-02
  修改内容：为了调试485串口，修改了很多，
  1：修改serial.cpp 文件中 波特率为 19200
  2：修改了本文初始化函数中       Sys_Debug_State=true;   --191行
   注释掉了 270行
  3：改动了 Date_Time_Fresh()函数。 注意改回正常，并检查。
  4：修改了   Get_RS485_Input(int ffd) 函数。 注意改回正常，并检查。
----------------------------------------------------
程序修改时间：2018-5-28号
程序修改内容：修改上一页，下一页，手动翻页 按钮获取焦点时变黄色。
*/

#include "ffpmmainw.h"
#include "ui_ffpmmainw.h"
#include <QMessageBox>
#include <QtGui>
#include <QTimer>
#include <time.h>
#include <QTime>
#include <QString>
#include <QStandardItemModel>
#include<QProcess>


//----串口头文件-驱动文件--
#include "serial.h"  //加入串口 的 头文件

//---GPIO P3.4 头文件-----
#include "gpio.h"

#include "my_test.h"  //my_test 窗体
#include <pthread.h>
#include "form_baojin.h" //报警窗体。
#include "crc16.h"      //CRC校验
#include "QMessageBox"

#include "form_falut.h"
#include "falut.h"
#include "alarm.h"
#include "form_his_alarm.h"
#include "form_login.h"
#include "form_set_pra.h"
#include "form_rset.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>

#include <mybutton.h>
#include <form_selfcheck.h>


#include <vector>
using namespace std;

 //直接定义500个，电源模块对象。
//FFPM *Fpms=NULL;
FFPM *Fpms[500];

 bool First_data_send=true;      //标记第一次发送数据，给MCU。

 vector<Falut> vector_falut;
 vector<Alarm> vector_alarm;

qint16 Tatol_Alarm_Ct=0;   //消防电源模块报警总数
qint16 Tatol_Falut_Ct=0;   //消防电源模块故障总数目

 int Fpm_Total=25;  //消防电压模块总数量

quint8 Page_tatol=3;        //页面分页数量，my_test用。

QString Sys_name="FFPMS消防设备电源监控系统";    //系统默认名字。


qint16 time_ct;
qint8 time_ct_key;
qint16 tt;
qint16 ttt;


#define RS485_1_NAME "/dev/ttymxc2"
#define RS485_2_NAME "/dev/ttymxc1"
#define RS485_3_NAME "/dev/ttymxc7"
#define RS485_4_NAME "/dev/ttymxc5"
#define RS485_5_NAME "/dev/ttymxc3"
#define RS485_KEY_NAME "/dev/ttymxc4"


int RS485_1_fd=0;  //RS485通讯口1
int RS485_2_fd=0;  //RS485通讯口2
int RS485_3_fd=0;  //RS485通讯口3
int RS485_4_fd=0;  //RS485通讯口4
int RS485_5_fd=0;  //预留的RS485通讯模块接口
//int RS232_Printer=0; //RS232 打印机接口
int RS485_key_lamp=0; //按键和指示灯通讯口

qint16 wait_rec_ct=0;//标志等待接收数据。

quint8 Wait_rec_kind=1; //1=接收查询数据 2=接收命令回响


//通讯任务1=常规查询， 2=复位命令 ， 3=自检命令 ，  4=参数设置 ， 5.。。。。。
quint8 Send_work_kind=1;

//发送复位命令是ffpm的下标
qint16 Send_reset_id=0;

#define GPIO3_4_DEV_PATH "/sys/class/gpio/gpio68/value"
#define GPIO5_6_DEV_PATH "/sys/class/gpio/gpio134/value"


int fd_GPIO3_4;
int fd_GPIO5_6;

int fd_backlight;

quint16 Backlight_time;

QTimer *timer;
QTimer *timer_re;
QTimer *timer_ts;


My_Test *mt;
CRC16 *cc16;
Form_Baojin  *form_bj;
int nread;
char  buf_rec[20];
pthread_t tid;
int fpm_cur_id;
unsigned int Comm_Fail_Max=5;


//1秒定时，计数，用于刷新
quint8 Timer1s_Ct;


bool New_alarm_pop=false; //新的报警弹出。
bool New_fault_pop=false; //新的故障弹出。
unsigned char   Send_lamp=0;
unsigned char  Send_onoff=0;
unsigned char   Send_laba=0;
bool         Sys_mute=false;
bool    Sys_alarm_sta=false;
bool    Sys_fault_sta=false;

bool New_data_will_send=false;  //标记有新的，指示灯，喇叭数据 将要发向MCU

bool New_data_have_send=false;  //标记有新的，指示灯，喇叭数据，已经发向MCU\

//系统调试状态
bool Sys_Debug_State=false;
bool Sys_Debug_Stop_Main=false;

qint16 M_fid=1;

quint8 New_data_send_ct=0; //标记发送失败的次数。

//当前的Ui界面。
quint8 Cur_Ui_Page=1;
//需要验证后进入的界面。
quint8 Next_Ui_Page=0;


//导航栏按钮
QPushButton *But_SSXX;// Cur_Ui_Page=1
MyButton *But_DQBJ;// Cur_Ui_Page=2
MyButton *But_DQGZ;// Cur_Ui_Page=3
QPushButton *But_LSBJ;// Cur_Ui_Page=4
QPushButton *But_CSSZ;// Cur_Ui_Page=5
QPushButton *But_XTXX;// Cur_Ui_Page=6
QPushButton *But_SYBZ;// Cur_Ui_Page=7
QPushButton *But_XTZJ;  //系统自检
QPushButton *But_XTFW;  //系统复位
QPalette qp_hei;
QPalette qp_bai;

//子窗体定义
Form_Baojin    *form_bj1; //当前报警窗体
My_Test         *form_xx;  //实时信息窗体
Form_Falut      *form_gz; //当前故障窗体
form_his_alarm *form_his; //历史报警窗体
Form_Set_Pra    *form_cs; //参数设置界面
Form_SelfCheck  *form_zj; //自检窗体
Form_Login      *form_lg; //密码权限验证。
Form_Rset       *form_rs; //复位窗体

bool form_lg_show=false;

bool Sys_Zj=false; //系统自检标志。
bool Sys_All_Fpms_Zj=false;  //所有模块自检标志。

QSqlDatabase  qdb;

QString sys_l1_pass="63206455";  //权利最高，1级密码
QString sys_l2_pass="123456";  //第2,级密码
QString sys_l3_pass="123456";  //第3级密码。

const QString sys_super_pass="63206455";

BYTE rec_ar[40];
BYTE rec_ar1[30];

bool fasong=false;
bool set_low=false;

FFPMMainW::FFPMMainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FFPMMainW)
{

    printf("enter FFPMMainw init 215\n");

    this->setWindowState(Qt::WindowFullScreen);

    ui->setupUi(this);

   // Sys_Debug_State=true;

    //------------------连接到sqlite3数据库----------------------
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    //打开数据库，是否需要try catch 保护。
    qdb=QSqlDatabase::addDatabase("QSQLITE");
    qdb.setDatabaseName("/opt/ffpm.db");
    qdb.open();

     printf("Open QSqlDatabae have Done 231\n");

    //系统基础信息从数据库初始化
    if(Sys_Main_Info_Init()==false){
        //如果提取关键信息出错，则填充默认的信息。
        Sys_name=tr("FFPMS消防设备电源监控系统");
        Fpm_Total=20;
    }
     //fpms消防电压模块从数据库初始化
    if(Fpms_Init()==false){
       printf("FPMS Init from database erro load default datas  241\n");
        int isk=0;
              for(isk=0;isk<25;isk++){
                  FFPM fpm(isk+1,isk+1,1,1);
                  fpm.name=tr("ale");
                  *Fpms[isk]=fpm;
              }
    }else{
      printf("FPMS nodes init from databases have  Done 249\n");
    }



    //确定my_test窗体的分页数量。
    Page_tatol=Fpm_Total / 10;
    if(Fpm_Total % 10){
        Page_tatol++;
    }

    printf("ffmain 257 Page_tatol=%d Fpm_Total=%d \n",Page_tatol,Fpm_Total);
    //-----------------------界面初始化----------------------
    My_Ui_Init();
    printf("ffmain 260\n");
    form_xx->setAutoFillBackground(true);
    form_xx->show();

    printf("Ui init have Done 262\n");

    ui->textEdit->setEnabled(false);
    ui->textEdit_2->setEnabled(false);

    Timer1s_Ct=1;

    time_ct_key=0;

    cc16=new CRC16(); //crc16服务类的对象
    Timer1s_Ct=0;

    //------------------------系统通讯口，打开驱动，波特率全为9600-----------------------

    RS485_1_fd = openSerial(RS485_1_NAME);

    RS485_2_fd = openSerial(RS485_2_NAME);

    RS485_3_fd = openSerial(RS485_3_NAME);

    RS485_4_fd = openSerial(RS485_4_NAME);

    RS485_5_fd = openSerial(RS485_5_NAME);   //预留的RS485口，非隔离的5V 电源供电，建议接一拖四HUB使用。

    RS485_key_lamp = openSerial(RS485_KEY_NAME); //协MCU通讯口为A6B6,ttymxc2

    printf("Open 5 RS485 for ffpm have Done 286\n");



    fd_GPIO3_4=openGPIO3_4(GPIO3_4_DEV_PATH); //调用gpio.cpp 中的函数，打开p3.4
    fd_GPIO5_6=openGPIO3_4(GPIO5_6_DEV_PATH); //调用gpio.cpp 中的函数，打开p3.4

     write(fd_GPIO3_4,GPIO_LOW_LEVEL,sizeof(GPIO_LOW_LEVEL));
     write(fd_GPIO5_6,GPIO_LOW_LEVEL,sizeof(GPIO_LOW_LEVEL));

    //屏幕背光控制文件。。。亮度值1-7
    fd_backlight=open("/sys/class/backlight/backlight/brightness", O_RDWR);

    printf("Open GPIO-4-6 have Done 301\n");


    //定时器，定时50ms,在定时器内部，发送和接收 模块发过来的数据。。
     timer = new QTimer(this);  //系统关键定时器

     //串口发送数据口，估算发送时间，在此定时器内将485发送使能脚位拉低。
     //用于485芯片EN,RE脚由GPIO口控制时使用到的定时器
     timer_re =new QTimer(this);

     //系统串口调试时用到的定时器，接收串口数据
     timer_ts = new QTimer(this);

     connect(timer, SIGNAL(timeout()), this, SLOT(Date_Time_Fresh()));

     connect(timer_re, SIGNAL(timeout()), this, SLOT(Date_Time_Re()));

     connect(timer_ts, SIGNAL(timeout()), this, SLOT(Date_Time_Ts()));


   // connect(form_bj,SIGNAL(back_to_main_singal()),this,SLOT(Form_BJ_but1_clicked()));

     //权限验证窗体，在验证成功后，发送pass_is_ok信号，
     connect(form_lg,SIGNAL(Pass_Is_Ok()),this,SLOT(Show_Next_Page()));

     fpm_cur_id=0; //模块数组当期下标。 当前测试系统设置有50个模块，下标最大=49.

     Send_Chaxun_Order(Fpms[fpm_cur_id]->addr,Fpms[fpm_cur_id]->net);

     wait_rec_ct=1;//标志等待接收数据。
     Wait_rec_kind=1; //1=接收查询数据 2=接收命令回响

    timer->start(50);
    time_ct=0;
    tt=0;

   // But_SSXX_clicked();


    Back_light_on(); //上电点量屏幕背光。
}

void FFPMMainW::on_gao_clicked(){
          write(fd_GPIO5_6,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
}

void FFPMMainW::on_di_clicked(){
      write(fd_GPIO5_6,GPIO_LOW_LEVEL,sizeof(GPIO_LOW_LEVEL));
}

//屏幕背光控制
bool FFPMMainW::Set_Back_Light_Level(quint8 lev){

    int ret=0;

        if(fd_backlight<=0){
            return false;
        }

        if(lev==1){
           ret=write(fd_backlight,"1",sizeof("1"));
        }

        if(lev==2){
          ret= write(fd_backlight,"2",sizeof("2"));
        }

        if(lev==3){
           ret=write(fd_backlight,"3",sizeof("3"));
        }

        if(lev==4){
          ret=write(fd_backlight,"4",sizeof("4"));
        }

        if(lev==5){
          ret= write(fd_backlight,"5",sizeof("5"));
        }

        if(lev==6){
          ret= write(fd_backlight,"6",sizeof("6"));
        }

        if(lev==7){
           ret=write(fd_backlight,"7",sizeof("7"));
        }

        if(ret>0){
            return true;
        }else{
            return false;
        }
}

//背光控制中心。
//亮度7，亮屏幕时间10分钟。 然后20分钟，亮度逐渐降低，直到0.
//Backlight_time从1800开始自减。

void FFPMMainW::Back_light_control(){

    Backlight_time=Backlight_time-1;

    if(Backlight_time==1200){ //亮度7,降到亮度6.
        Set_Back_Light_Level(6);
        return;
    }

    if(Backlight_time==1000){ //亮度7,降到亮度5.
        Set_Back_Light_Level(5);
        return;
    }

    if(Backlight_time==800){ //亮度7,降到亮度4.
        Set_Back_Light_Level(4);
        return;
    }

    if(Backlight_time==600){ //亮度7,降到亮度3.
        Set_Back_Light_Level(3);
        return;
    }

    if(Backlight_time==400){ //亮度7,降到亮度2.
        Set_Back_Light_Level(2);
        return;
    }

    if(Backlight_time==200){ //亮度7,降到亮度1.
        Set_Back_Light_Level(1);
        return;
    }

    if(Backlight_time<=0){ //亮度7,降到亮度0.
        Backlight_time=0;
        Set_Back_Light_Level(0);
        return;
    }

}

//点亮屏幕背光
void FFPMMainW:: Back_light_on(){
    Backlight_time=1800;
    Set_Back_Light_Level(7);
}

FFPMMainW::~FFPMMainW()
{
    delete ui;
}
//我的界面UI 初始化
void FFPMMainW::My_Ui_Init()
{
     printf("ffmain 459\n");
     ui->centralWidget->hide();
     printf("ffmain 461\ns");

    //实时信息窗体
    form_xx=new My_Test(this);
    printf("ffmain 465\n");
    form_xx->setGeometry(0,0,800,410);
    form_xx->move(0,40);
    Cur_Ui_Page=1;
    form_xx->setAutoFillBackground(true);
    form_xx->show();
    printf("have Done 469");

    //当前报警窗体
    form_bj=new Form_Baojin(this)  ;
    form_bj->setGeometry(0,0,800,410);
    form_bj->move(0,40);
    form_bj->hide();

    //当前故障窗体
    form_gz=new Form_Falut(this);
    form_gz->setGeometry(0,0,800,410);
    form_gz->move(0,40);
    form_gz->hide();

    //历史报警窗体。
    form_his=new form_his_alarm(this);
    form_his->setGeometry(0,0,800,410);
    form_his->move(0,40);
    form_his->hide();
    printf("have Done 488");
    //历史报警窗体。
    form_cs=new Form_Set_Pra(this);
    form_cs->setGeometry(0,0,800,410);
    form_cs->move(0,40);
    form_cs->hide();


    //权限验证，登录窗体
    form_lg=new Form_Login();
    form_lg->hide();

    But_SSXX=new MyButton();
    But_SSXX->setText(tr(" 实时信息 "));
    But_SSXX->setGeometry(0,0,20,100);
    But_SSXX->move(0,0);
    But_SSXX->setFont(QFont("黑体",20,10,false));
    But_SSXX->setAutoDefault(true);
    But_SSXX->setFocusPolicy(Qt::StrongFocus);

    qp_hei=But_SSXX->palette();
    qp_hei.setColor(QPalette::Button,Qt::black);
    qp_hei.setColor(QPalette::ButtonText,Qt::white);
    But_SSXX->setPalette(qp_hei);

    qp_bai=But_SSXX->palette();
    qp_bai.setColor(QPalette::Button,Qt::white);
    qp_bai.setColor(QPalette::ButtonText,Qt::black);

    //But_SSXX->setEnabled(false);
    But_DQBJ=new MyButton();
    But_DQBJ->setText(tr(" 当前报警 "));
    But_DQBJ->move(10,0);
    But_DQBJ->setFont(QFont("黑体",20,10,false));
    But_DQBJ->setPalette(qp_bai);

    But_DQGZ=new MyButton();
    But_DQGZ->setText(tr(" 当前故障 "));
    But_DQGZ->move(200,0);
    But_DQGZ->setFont(QFont("黑体",20,10,false));
    But_DQGZ->setPalette(qp_bai);

    But_LSBJ=new MyButton();
    But_LSBJ->setText(tr(" 历史报警 "));
    But_LSBJ->move(200,0);
    But_LSBJ->setFont(QFont("黑体",20,10,false));
    But_LSBJ->setPalette(qp_bai);

    But_CSSZ=new MyButton();
    But_CSSZ->setText(tr(" 参数设置 "));
    But_CSSZ->move(200,0);
    But_CSSZ->setFont(QFont("黑体",20,10,false));
    But_CSSZ->setPalette(qp_bai);

    But_XTZJ=new MyButton();
    But_XTZJ->setText(tr(" 系统自检 "));
    But_XTZJ->move(200,0);
    But_XTZJ->setFont(QFont("黑体",20,10,false));
    But_XTZJ->setPalette(qp_bai);

    But_XTFW=new MyButton();
    But_XTFW->setText(tr(" 系统复位 "));
    But_XTFW->move(200,0);
    But_XTFW->setFont(QFont("黑体",20,10,false));
    But_XTFW->setPalette(qp_bai);

    But_XTXX=new MyButton();
    But_XTXX->setText(tr(" 系统信息 "));
    But_XTXX->move(200,0);
    But_XTXX->setFont(QFont("黑体",20,10,false));
    But_XTXX->setPalette(qp_bai);

    But_SYBZ=new MyButton();
    But_SYBZ->setText(tr(" 使用帮助 "));
    But_SYBZ->move(200,0);
    But_SYBZ->setFont(QFont("黑体",20,10,false));
    But_SYBZ->setPalette(qp_bai);

    ui->toolBar->addWidget(But_SSXX);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_DQBJ);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_DQGZ);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_LSBJ);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_CSSZ);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_XTZJ);
    ui->toolBar->addSeparator();

    ui->toolBar->addWidget(But_XTFW);
    ui->toolBar->addSeparator();

    connect(But_SSXX,SIGNAL(clicked()),this,SLOT(But_SSXX_clicked()));
    connect(But_DQBJ,SIGNAL(clicked()),this,SLOT(But_DQBJ_clicked()));
    connect(But_DQGZ,SIGNAL(clicked()),this,SLOT(But_DQGZ_clicked()));
    connect(But_LSBJ,SIGNAL(clicked()),this,SLOT(But_LSBJ_clicked()));
    connect(But_CSSZ,SIGNAL(clicked()),this,SLOT(But_CSSZ_clicked()));  
    connect(But_XTZJ,SIGNAL(clicked()),this,SLOT(But_XTZJ_clicked()));
    connect(But_XTFW,SIGNAL(clicked()),this,SLOT(But_XTFW_clicked()));

    connect(ui->gao,SIGNAL(clicked()),this,SLOT(on_gao_clicked()));
    connect(ui->di ,SIGNAL(clicked()),this,SLOT(on_di_clicked()));

    ui->gao->hide();
    ui->di->hide();
}

//在定时时间内串口将数据发送出去，然后关闭RS485的发送使能,进入接收使能。
void FFPMMainW:: Date_Time_Re()
{
      // write(fd_GPIO3_4,GPIO_LOW_LEVEL,sizeof(GPIO_LOW_LEVEL));
       write(fd_GPIO5_6,GPIO_LOW_LEVEL,sizeof(GPIO_LOW_LEVEL));

     // write(fd_GPIO3_4,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL)); //高电平接收
    //  write(fd_GPIO5_6,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL)); //2017-12-01 修改

        fasong=false;
        timer_re->stop();
        return;
}

//slot 槽，绑定到timer定时器溢出，每50ms后，将进入1次函数。
//每100ms,查询1个点。 第1个50ms开始时发送或前一个50ms结束时，发送查询通讯命令。
//在第2个50ms,结束时接收处理串口数据，然后在发送下一个查询命令。
//更新速率：1秒查询10个点。每分钟，查询600个点。
void FFPMMainW:: Date_Time_Fresh()
{
    QString s,s1;
    unsigned int comm_back_sta;


    //------------------------按键通讯-----------------------------
    time_ct_key=time_ct_key+1;
    //第1个50ms结束进入,发送查询和亮灯指令给MCU
   if(time_ct_key==1){
      Send_Key_Order(0,0); //暂时一直发0,不亮灯
   }
    //第300ms后进入,接收MCU 回响数据
    if (time_ct_key>=5){
        time_ct_key=0;

        bool rko=Rec_Key_Order();

        if( New_data_have_send){ //如果发送出去的是有效的指示灯命令。则要判断是否正确回响。
            if(rko){
                New_data_will_send=false;
                New_data_have_send=false;
            }else{  //如果mcu没有接受到，则一直发，或者将来，将输入压入缓冲区。
                New_data_send_ct=New_data_have_send=1;
                if(New_data_send_ct>=3){
                    New_data_send_ct=3;
                }
            }
        }
    }//-----------------------------------------------------------


    //如果主程序停止，那么就返回。。。
    if(Sys_Debug_Stop_Main==true){
        return;
    }

    time_ct++;
    wait_rec_ct++;

//----------------------消防电源模块通讯-----------------------
if (wait_rec_ct>=4){
     wait_rec_ct=0;
    if (Wait_rec_kind==1){
            //100ms时间到，接收并处理数据。
           comm_back_sta=Get_RS485_Input(fpm_cur_id);

           //通讯事物处理中心：1-通讯报警故障弹出
            Comm_Work_Center(comm_back_sta);

            //报警事物处理 ：1-电压电流越限报警弹出和恢复
             Alarm_Work_Center(comm_back_sta);

           // Fault_Work_Center(); //故障处理中心
            fpm_cur_id=fpm_cur_id+1;
           if (fpm_cur_id>=Fpm_Total){
               fpm_cur_id=0;
           }
        }

         if(Wait_rec_kind==2){  //接收复位回响
             Send_reset_id=Send_reset_id+1;
             if (Send_reset_id>=Fpm_Total){
               Send_work_kind=1;
             }
         }
    }

    if (wait_rec_ct==1){

        //先判断是否有其它的发送任务。
         if(Send_work_kind==1){
             //如果没有其它的发送任务，则执行常规查询。
             Send_Chaxun_Order(Fpms[fpm_cur_id]->addr,Fpms[fpm_cur_id]->net);
             Wait_rec_kind=1;
         }

         if(Send_work_kind==2){  //=2 表示有复位任务。
            Send_Reset_Order(Fpms[Send_reset_id]->addr,Fpms[Send_reset_id]->net);
            Wait_rec_kind=2;
         }

    }//-----------------------------------------------------------

    //-----------------------1秒时间显示刷新和总报警故障管理---------------------
    if (time_ct>=20 ) {
        time_ct=0;

        //--------------------左小角时间显示----------------------
        QTime qtime1=QTime::currentTime();
        QDate qdate1=QDate::currentDate();
        s=qdate1.toString("yyyy-MM-dd");
        s1=qtime1.toString("hh:mm:ss");
        s=s.append("  ");
        s=s.append(s1);
        ui->statusBar->showMessage(s);

        //--------------------屏幕背光控制-------------------
        //Backlight_time
        if(Backlight_time>0){
             Back_light_control();
        }

        //每秒中，刷新ffpm对象中的报警和故障。
        //检测是否有新的报警产生，如果产生，则发出声光提示，并同时记录条数。
        //检测是否有新的故障产生，如果有，则发粗声光，记录条数。
       //为提高程序效率，做出两全局的 报警 和 故障 更新标志。

        if(New_alarm_pop){  //新的报警， 报警指示灯亮，故障报警声音响。 arm会下发，灯和喇叭命令给mcu.
            New_alarm_pop=false;
            Back_light_on();
            Send_lamp=0x11; //监控报警。
            Send_onoff=0x01;
            New_data_will_send=true;  //标记有新的，指示灯，喇叭数据将发向MCU
            New_data_send_ct=0; //标记发送失败的次数。
            Tatol_Alarm_Ct = vector_alarm.size();
            //扬声器发生的真正表：
            //1：系统处于静音状态。
            //2：系统处于干净状态。
            //Sys_alarm_sta=true 表示系统有监控报警产生。
            //Sys_falut_sta=true 表示系统有故障报警产生。
            if(Sys_mute){
                Send_laba=0x13;  //报警喇叭响声=0x13
            }

            if((Sys_alarm_sta==false) && (Sys_fault_sta==false)){
                 Send_laba=0x13;  //故障喇叭响声=0x23
            }
            Sys_mute=false;
            Sys_alarm_sta=true;
            //1秒时间内，将有4次与mcu板通讯，将指令发出去。
            return ;
        }


        if(New_fault_pop){  //新的故障， 故障指示灯亮，故障报警声音响。 arm会下发，灯和喇叭命令给mcu.
            New_fault_pop=false;
            Back_light_on();
            Send_lamp=0x22; //故障灯。
            Send_onoff=0x01;
            New_data_will_send=true;  //标记有新的，指示灯，喇叭数据发向MCU
            New_data_send_ct=0; //标记发送失败的次数。
            Tatol_Falut_Ct= vector_falut.size();
            //如果是故障恢复，没有一个故障，则关闭故障指示灯，现在测试阶段，一旦故障灯亮起就不恢复，以测试系统的稳定性。
//            if(Tatol_Falut_Ct==0){
                  //  Send_onoff=0x00;
//            }

            //扬声器发生的真正表：
            //1：系统处于静音状态。Date_Time_Fresh
            //2：系统处于干净状态。
            //Sys_alarm_sta=true 表示系统有监控报警产生。
            //Sys_falut_sta=true 表示系统有故障报警产生。
            if(Sys_mute){
                Send_laba=0x23;  //故障喇叭响声=0x23
            }

            if((Sys_alarm_sta==false) && (Sys_fault_sta==false)){
                 Send_laba=0x23;  //故障喇叭响声=0x23
            }
            Sys_mute=false;
            Sys_fault_sta=true;
            //1秒时间内，将有4次与mcu板通讯，将指令发出去。
        }

    }//-----------------------------------------------------------
}

//函数名:Alarm_Work_Center
//函数功能：报警事物处理。在与接收到模块的回响数据好，判断模块当前的检测到电压，电流是否超限。
//传入参数：unsigned int com_back -->通信状态
//全局变量：Fpms[fpm_cur_id]
void FFPMMainW:: Alarm_Work_Center(unsigned int com_back){
   //因模块类型众多，现只处理3相的模块. m3-v2 m3-va m3-v2a
       if(com_back<5){  //通讯异常直接返回。
            return;
       }
       //把报警分成 3个部分,跟显示一样，如果其中一个值超限，则认定为整体报警，并标记。
       // 模块对象内，会产生3个报警状态.
       //  unsigned char v1_alarm_pop; //电压1报警弹出  0=没有报警  1=将要弹出报警  2=已经弹出报警。
       //  unsigned char v2_alarm_pop; //电压2报警弹出
       //  unsigned char va_alarm_pop; //电压电流报警弹出
       //模块kind :  1=M3-V2   2=M3-V2A  3=M3-V3  4=M3-VA  5=M2-V6  6=M2-V9
       // v1_alarm_pop 电压1报警弹出  0=没有报警  1=将要弹出报警  2=已经弹出报警。

        //第一部分电压超限检测
        Chao_Xian_M3V1();  //截至2018-8月，生产的模块，都至少有3个电压接入点。

        //第二部分电压超限检测
       if(Fpms[fpm_cur_id]->kind>=4 || Fpms[fpm_cur_id ]->kind==5 || Fpms[fpm_cur_id ]->kind==6 ){
           Chao_Xian_M3V2();    // bool Chao_Xian_2();
       }
       //第2部分电流超限检测
       if(Fpms[fpm_cur_id]->kind>=4 ){
          Chao_Xian_A2();
       }

       //第三部分电压超限检测
       if(Fpms[fpm_cur_id]->kind>=3 || Fpms[fpm_cur_id ]->kind==6 ){
           Chao_Xian_M3V3();
       }
       //第三部分电流超限检测
       if(Fpms[fpm_cur_id]->kind==2 ){
           Chao_Xian_A3();
       }
}

//函数名：Chao_Xian_M3V1
//函数功能：判断第1路3相交流电压是否超限，并存储报警时数据，
//流程概述：
//1：如果电压已经报警，则返回。
//2：判断电压1中3个电压欠压，过压.
//3：如果有（欠压，过压），那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_M3V1() {
     QString bj_str;
          //没有处于报警状态,才进入判是否报警
          if(Fpms[fpm_cur_id]->v1_alarm_pop!=0){
              return ;
          }
       
        if(Fpms[fpm_cur_id]->qianya){   //是否使能欠压报警
            if(Fpms[fpm_cur_id]->cur_data[0]<Fpms[fpm_cur_id]->v1_min){  //判断1:VA1是否欠压
              Fpms[fpm_cur_id]->v1_alarm_pop=1;
              bj_str=tr("电压1欠压");
            }else if(Fpms[fpm_cur_id]->cur_data[1]<Fpms[fpm_cur_id]->v1_min){
                Fpms[fpm_cur_id]->v1_alarm_pop=1;
                bj_str=tr("电压1欠压");
            }else if(Fpms[fpm_cur_id]->cur_data[2]<Fpms[fpm_cur_id]->v1_min){
                Fpms[fpm_cur_id]->v1_alarm_pop=1;
                bj_str=tr("电压1欠压");
            }
        }

        if(Fpms[fpm_cur_id]->guoya){    //是否使能过压报警
            if(Fpms[fpm_cur_id]->cur_data[0]>Fpms[fpm_cur_id]->v1_max){
                  Fpms[fpm_cur_id]->v1_alarm_pop=1;
                  bj_str=tr("电压1过压");
            }else if(Fpms[fpm_cur_id]->cur_data[1]>Fpms[fpm_cur_id]->v1_max){
                  Fpms[fpm_cur_id]->v1_alarm_pop=1;
                  bj_str=tr("电压1过压");
            }else if(Fpms[fpm_cur_id]->cur_data[2]>Fpms[fpm_cur_id]->v1_max){
                 Fpms[fpm_cur_id]->v1_alarm_pop=1;
                 bj_str=tr("电压1过压");
            }
        }

        if(Fpms[fpm_cur_id]->v1_alarm_pop==1){
           Alarm  al(1,fpm_cur_id);
           QString s,s1;
           QTime qtime1=QTime::currentTime();
           QDate qdate1=QDate::currentDate();
            s=qdate1.toString("yyyy-MM-dd");
            s1=qtime1.toString("hh:mm:ss");
            al.date_str=s;
            al.time_str=s1;
            al.fpm_name=Fpms[fpm_cur_id]->name;
            al.fpm_id=Fpms[fpm_cur_id]->id;
            al.alarm_kind=1;
            s1=QString::number(Fpms[fpm_cur_id]->cur_data[0]);
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[1]));
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[2]));
            al.value_str=s1;
            al.alarm_kind=1;
            al.alarm_kind_str=bj_str;
            vector_alarm.push_back(al);
            New_alarm_pop=true;
            Add_Alarm_Infos(&al);

            int gri;

           // if (Sys_Debug_State==true){
               // if(m_addr==1){
                    ui->textEdit_2->setText("");
                   QString str;
                   str="";
                    for(gri=0;gri<23;gri++){
                      str.append(QString::number(rec_ar[gri],16));
                    str.append(",");
                    }
                    if(ui->textEdit_2->textColor()==Qt::black){
                        ui->textEdit_2->setTextColor(Qt::red);
                    }else{
                     ui->textEdit_2->setTextColor(Qt::black);
                    }
                    ui->textEdit_2->append(str);
                //}
            //}

        }
    //}
}



//函数名：Chao_Xian_M3V2
//函数功能：判断第2路3相交流电压是否超限，并储存报警时数据
//流程概述：
//1：如果电压已经报警，则不判断。
//2：判断电压2中3个电压欠压，过压
//3：如果有（欠压，过压），那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_M3V2() {
    QString bj_str;
    //没有处于报警状态,才进入判是否报警
    //电压2中，三个电压值，只要只有有一个超限，则报警。
    if(Fpms[fpm_cur_id]->v2_alarm_pop!=0){
        return;
    }

    if(Fpms[fpm_cur_id]->qianya){   //电压欠压判断
       if(Fpms[fpm_cur_id]->cur_data[3]<Fpms[fpm_cur_id]->v2_min){
             Fpms[fpm_cur_id]->v2_alarm_pop=1;
              bj_str=tr("电压2欠压");
       }else if(Fpms[fpm_cur_id]->cur_data[4]<Fpms[fpm_cur_id]->v2_min){
             Fpms[fpm_cur_id]->v2_alarm_pop=1;
              bj_str=tr("电压2欠压");
       }else if(Fpms[fpm_cur_id]->cur_data[5]<Fpms[fpm_cur_id]->v2_min){
            Fpms[fpm_cur_id]->v2_alarm_pop=1;
             bj_str=tr("电压2欠压");
       } 
    }
       //如果启用过压判断，
    if(Fpms[fpm_cur_id]->guoya){
           if(Fpms[fpm_cur_id]->cur_data[3]>Fpms[fpm_cur_id]->v2_max]){
                 Fpms[fpm_cur_id]->v2_alarm_pop=1;
                  bj_str=tr("电压2过压");
           }else if(Fpms[fpm_cur_id]->cur_data[4]>Fpms[fpm_cur_id]->v2_max){
                 Fpms[fpm_cur_id]->v2_alarm_pop=1;
                  bj_str=tr("电压2过压");
           }else if(Fpms[fpm_cur_id]->cur_data[5]>Fpms[fpm_cur_id]->v2_max){
                Fpms[fpm_cur_id]->v2_alarm_pop=1;
                 bj_str=tr("电压2过压");
           }
    }

       if(Fpms[fpm_cur_id]->v2_alarm_pop==1){
          Alarm  al(2,fpm_cur_id);
          QString s,s1;
          QTime qtime1=QTime::currentTime();
          QDate qdate1=QDate::currentDate();
          s=qdate1.toString("yyyy-MM-dd");
          s1=qtime1.toString("hh:mm:ss");
          al.date_str=s;
          al.time_str=s1;
          al.fpm_name=Fpms[fpm_cur_id]->name;
          s1=QString::number(Fpms[fpm_cur_id]->cur_data[3]);
          s1.append("/");
          s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[4]));
          s1.append("/");
          s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[5]));
          al.value_str=s1;
          al.alarm_kind=1;
          al.fpm_id=Fpms[fpm_cur_id]->id;
          al.alarm_kind_str=bj_str;
          vector_alarm.push_back(al);
          Add_Alarm_Infos(&al);
       }
    //}
}


//函数名：Chao_Xian_M3VA
//函数功能：判断第3路3相电压是否超限
//流程概述：
//1：如果 已经报警，则不判断。
//2：判断电压2中3个电压欠压/过压
//3：如果有超限，那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_M3VA() {
       QString bj_str;

       if(Fpms[fpm_cur_id]->va_alarm_pop!=0){
           return;
       }

    //   Fpms[fpm_cur_id]->kind= 1=M3-V2  2=M3-V2A  3=M3-V3

       if(Fpms[fpm_cur_id]->kind==2){ //电流点

            //如果启用欠流
           if (Fpms[fpm_cur_id]->qianliu){
               if(Fpms[fpm_cur_id]->cur_data[6]<Fpms[fpm_cur_id]->bj_data[5]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                      bj_str=tr("电流3欠流");
               }
               if(Fpms[fpm_cur_id]->cur_data[7]<Fpms[fpm_cur_id]->bj_data[5]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                      bj_str=tr("电流3欠流");
               }
               if(Fpms[fpm_cur_id]->cur_data[8]<Fpms[fpm_cur_id]->bj_data[5]){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                     bj_str=tr("电流3欠流");
               }
           }

           //如果启用过流
           if(Fpms[fpm_cur_id]->guoliu){
               if(Fpms[fpm_cur_id]->cur_data[6]>Fpms[fpm_cur_id]->bj_data[6]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                      bj_str=tr("电流3过流");
               }
               if(Fpms[fpm_cur_id]->cur_data[7]>Fpms[fpm_cur_id]->bj_data[6]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                     bj_str=tr("电流3过流");
               }
               if(Fpms[fpm_cur_id]->cur_data[8]>Fpms[fpm_cur_id]->bj_data[6]){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流3过流");
               }
           }
       }

       if(Fpms[fpm_cur_id]->kind==3){ //电压点

           if(Fpms[fpm_cur_id]->cur_data[6]<Fpms[fpm_cur_id]->bj_data[5]){
                 Fpms[fpm_cur_id]->va_alarm_pop=1;
                  bj_str=tr("电压3欠压");
           }
           if(Fpms[fpm_cur_id]->cur_data[7]<Fpms[fpm_cur_id]->bj_data[5]){
                 Fpms[fpm_cur_id]->va_alarm_pop=1;
                  bj_str=tr("电压3欠压");
           }
           if(Fpms[fpm_cur_id]->cur_data[8]<Fpms[fpm_cur_id]->bj_data[5]){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                 bj_str=tr("电压3欠压");
           }
           //如果启用过压判断，  bj_data(1)过压值。
           if(Fpms[fpm_cur_id]->guoya){
               if(Fpms[fpm_cur_id]->cur_data[6]>Fpms[fpm_cur_id]->bj_data[6]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                      bj_str=tr("电压3过压");
               }
               if(Fpms[fpm_cur_id]->cur_data[7]>Fpms[fpm_cur_id]->bj_data[6]){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                     bj_str=tr("电压3过压");
               }
               if(Fpms[fpm_cur_id]->cur_data[8]>Fpms[fpm_cur_id]->bj_data[6]){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电压3过压");
               }
           }

       }

        if(Fpms[fpm_cur_id]->va_alarm_pop==1){
           Alarm  al(3,fpm_cur_id);
           QString s,s1;
           QTime qtime1=QTime::currentTime();
           QDate qdate1=QDate::currentDate();
            s=qdate1.toString("yyyy-MM-dd");
            s1=qtime1.toString("hh:mm:ss");
            al.date_str=s;
            al.time_str=s1;
            al.fpm_name=Fpms[fpm_cur_id]->name;

            s1=QString::number(Fpms[fpm_cur_id]->cur_data[6]);
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[7]));
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[8]));
            al.value_str=s1;

            al.alarm_kind=1;
            al.fpm_id=Fpms[fpm_cur_id]->id;
            al.alarm_kind_str=bj_str;
            vector_alarm.push_back(al);
            Add_Alarm_Infos(&al);
        }

    }





//函数名：Chao_Xian_M3V3
//函数功能：判断第3路电压是否超限
//流程概述：
//1：如果已经报警，则不判断。
//2：判断电压2中3个电压欠压/过压
//3：如果有超限，那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_M3V3() {
    QString bj_str;

       if(Fpms[fpm_cur_id]->va_alarm_pop!=0){  
           return;
       }

       if(Fpms[fpm_cur_id]->qianya){ // 欠压报警是否使能
           if(Fpms[fpm_cur_id]->cur_data[6]<Fpms[fpm_cur_id]->v3_min){
                 Fpms[fpm_cur_id]->va_alarm_pop=1;
                 bj_str=tr("电压3欠压");
           }else if(Fpms[fpm_cur_id]->cur_data[7]<Fpms[fpm_cur_id]->v3_min){
                 Fpms[fpm_cur_id]->va_alarm_pop=1;
                 bj_str=tr("电压3欠压");
           }else  if(Fpms[fpm_cur_id]->cur_data[8]<Fpms[fpm_cur_id]->v3_min){
                 Fpms[fpm_cur_id]->va_alarm_pop=1;
                 bj_str=tr("电压3欠压");
           }
       }
        
        if(Fpms[fpm_cur_id]->guoya){  //如果启用过压判断
            if(Fpms[fpm_cur_id]->cur_data[6]>Fpms[fpm_cur_id]->v3_max){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                      bj_str=tr("电压3过压");
            }else if(Fpms[fpm_cur_id]->cur_data[7]>Fpms[fpm_cur_id]->v3_max){
                     Fpms[fpm_cur_id]->va_alarm_pop=1;
                     bj_str=tr("电压3过压");
            }else if(Fpms[fpm_cur_id]->cur_data[8]>Fpms[fpm_cur_id]->v3_max){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电压3过压");
            }
        }

        if(Fpms[fpm_cur_id]->va_alarm_pop==1){
           Alarm  al(3,fpm_cur_id);
           QString s,s1;
           QTime qtime1=QTime::currentTime();
           QDate qdate1=QDate::currentDate();
            s=qdate1.toString("yyyy-MM-dd");
            s1=qtime1.toString("hh:mm:ss");
            al.date_str=s;
            al.time_str=s1;
            al.fpm_name=Fpms[fpm_cur_id]->name;
            s1=QString::number(Fpms[fpm_cur_id]->cur_data[6]);
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[7]));
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[8]));
            al.value_str=s1;
            al.alarm_kind=1;
            al.fpm_id=Fpms[fpm_cur_id]->id;
            al.alarm_kind_str=bj_str;
            vector_alarm.push_back(al);
            Add_Alarm_Infos(&al);
        }
}

//函数名：Chao_Xian_A2
//函数功能：判断第2路(为电流时) 3个电流是否超限，适用于M3VA(即一路3相电压，一路3相电流)  
//流程概述：
//1：如果 已经报警，则不判断。
//2：判断第2路3个电流是否超限。
//3：如果有超限，那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_A2() {
       QString bj_str;

       if(Fpms[fpm_cur_id]->va_alarm_pop!=0){
           return;
       }
            
        if (Fpms[fpm_cur_id]->qianliu){//如果启用欠流
            if(Fpms[fpm_cur_id]->cur_data[3]<Fpms[fpm_cur_id]->a1_min){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }else if(Fpms[fpm_cur_id]->cur_data[4]<Fpms[fpm_cur_id]->a1_min){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }else if(Fpms[fpm_cur_id]->cur_data[5]<Fpms[fpm_cur_id]->a1_min){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }
        }

        if(Fpms[fpm_cur_id]->guoliu){ //如果启用过流
            if(Fpms[fpm_cur_id]->cur_data[3]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }else if(Fpms[fpm_cur_id]->cur_data[4]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }else if(Fpms[fpm_cur_id]->cur_data[5]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }
        }
        
        if(Fpms[fpm_cur_id]->va_alarm_pop==1){
           Alarm  al(3,fpm_cur_id);
           QString s,s1;
           QTime qtime1=QTime::currentTime();
           QDate qdate1=QDate::currentDate();
            s=qdate1.toString("yyyy-MM-dd");
            s1=qtime1.toString("hh:mm:ss");
            al.date_str=s;
            al.time_str=s1;
            al.fpm_name=Fpms[fpm_cur_id]->name;

            s1=QString::number(Fpms[fpm_cur_id]->cur_data[6]);
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[7]));
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[8]));
            al.value_str=s1;

            al.alarm_kind=1;
            al.fpm_id=Fpms[fpm_cur_id]->id;
            al.alarm_kind_str=bj_str;
            vector_alarm.push_back(al);
            Add_Alarm_Infos(&al);
        }
}

//函数名：Chao_Xian_A3
//函数功能：判断第3路(为电流时) 3个电流是否超限，适用于M3VA(即一路3相电压，一路3相电流)  
//流程概述：
//1：如果 已经报警，则不判断。
//2：判断第2路3个电流是否超限。
//3：如果有超限，那么保存信息到数据库，在保存信息到vector_alarm（报警信息向量表）
void FFPMMainW::Chao_Xian_A2() {
       QString bj_str;

       if(Fpms[fpm_cur_id]->va_alarm_pop!=0){
           return;
       }
            
        if (Fpms[fpm_cur_id]->qianliu){//如果启用欠流
            if(Fpms[fpm_cur_id]->cur_data[3]<Fpms[fpm_cur_id]->a1_min){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }else if(Fpms[fpm_cur_id]->cur_data[4]<Fpms[fpm_cur_id]->a1_min){
                    Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }else if(Fpms[fpm_cur_id]->cur_data[5]<Fpms[fpm_cur_id]->a1_min){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                    bj_str=tr("电流欠流");
            }
        }

        if(Fpms[fpm_cur_id]->guoliu){ //如果启用过流
            if(Fpms[fpm_cur_id]->cur_data[3]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }else if(Fpms[fpm_cur_id]->cur_data[4]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }else if(Fpms[fpm_cur_id]->cur_data[5]>Fpms[fpm_cur_id]->a1_max){
                Fpms[fpm_cur_id]->va_alarm_pop=1;
                bj_str=tr("电流过流");
            }
        }
        
        if(Fpms[fpm_cur_id]->va_alarm_pop==1){
           Alarm  al(3,fpm_cur_id);
           QString s,s1;
           QTime qtime1=QTime::currentTime();
           QDate qdate1=QDate::currentDate();
            s=qdate1.toString("yyyy-MM-dd");
            s1=qtime1.toString("hh:mm:ss");
            al.date_str=s;
            al.time_str=s1;
            al.fpm_name=Fpms[fpm_cur_id]->name;

            s1=QString::number(Fpms[fpm_cur_id]->cur_data[6]);
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[7]));
            s1.append("/");
            s1.append(QString::number(Fpms[fpm_cur_id]->cur_data[8]));
            al.value_str=s1;

            al.alarm_kind=1;
            al.fpm_id=Fpms[fpm_cur_id]->id;
            al.alarm_kind_str=bj_str;
            vector_alarm.push_back(al);
            Add_Alarm_Infos(&al);
        }
}







//通讯事物处理-针对单个对象
//判断模块通讯正常，不正常，故障弹出，恢复等等。
void FFPMMainW::Comm_Work_Center(unsigned int com_back) {
         if(com_back>=5){
             //1：判断若先前的通讯状态=未连接，或已经弹出通讯故障，则此处要恢复。

            if(Fpms[fpm_cur_id]->comm_fail_pop>=1){
                //删除故障集合中的信息
                Remove_Vector_Falut(Fpms[fpm_cur_id]->id,1);
                Fpms[fpm_cur_id]->comm_fail_pop=0;
            }
             //2：重置通讯状态。
             Fpms[fpm_cur_id]->comm_fail_ct=0;
             Fpms[fpm_cur_id]->comm_sta=1; //1=通讯ok
         }else{

             if(Fpms[fpm_cur_id]->comm_sta==2){  //如果已经通信异常错误，则直接返回
                    return;
             }

              Fpms[fpm_cur_id]->comm_fail_ct= Fpms[fpm_cur_id]->comm_fail_ct+1;

              //弹出通讯故障报警,采用相等判断，因此只会进入一次。
              if( Fpms[fpm_cur_id]->comm_fail_ct>=Comm_Fail_Max){
                  // Fpms[fpm_cur_id]->comm_fail_ct=Comm_Fail_Max+1;
                   Fpms[fpm_cur_id]->comm_sta=2; //2=通讯异常
                    Fpms[fpm_cur_id]->comm_fail_pop=1; //即将弹出通讯故障。

                    Falut fa(1,fpm_cur_id);
                    QString s,s1;
                    QTime qtime1=QTime::currentTime();
                    QDate qdate1=QDate::currentDate();
                    s=qdate1.toString("yyyy-MM-dd");
                    s1=qtime1.toString("hh:mm:ss");
                    fa.fpm_id= Fpms[fpm_cur_id]->id;
                    fa.date_str=s;
                    fa.time_str=s1;
                    fa.fpm_name=Fpms[fpm_cur_id]->name;
                    fa.fault_kind=1; //通讯故障。
                    vector_falut.push_back(fa);
                    New_fault_pop=true;
              //}
//              if(Fpms[fpm_cur_id]->comm_fail_ct>Comm_Fail_Max){
//                   Fpms[fpm_cur_id]->comm_fail_ct=Comm_Fail_Max+1;
//              }
         }
         }}


//删除故障集合中，已经恢复的故障对象。
void FFPMMainW:: Remove_Vector_Falut(quint16 m_fpm_id, quint8 m_fault_kind){

     if(vector_falut.size()==0){
            return;
     }

    vector<Falut>::iterator fa;

   for(fa=vector_falut.begin();fa!=vector_falut.end();fa++){
       Falut fau=*(fa);
       if(fau.fpm_id==m_fpm_id && fau.fault_kind==m_fault_kind){
            vector_falut.erase(fa);
            break;
       }
   }
   if(New_data_will_send && (First_data_send==false) ){ //如果有新的指示灯发送出去。
    }
}

////键盘释放事件
//void FFPMMainW::keyReleaseEvent(QKeyEvent *){
//    QMessageBox msgBox;
//    msgBox.setText(tr("按键释放"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}



//void FFPMMainW::event(QEvent *event){

//}

//void FFPMMainW::keyReleaseEvent(QKeyEvent *){
//    QMessageBox msgBox;
//    msgBox.setText(tr("按键释放"));
//    msgBox.setGeometry(350,180,150,80printf);
//    msgBox.exec();
//}
//点击按钮后，打开串口2。


unsigned int  FFPMMainW :: RS485_Input_Test(){
     int len;
     int gri;
     quint8 tnet=1;

     memset(rec_ar,0,36);

     tnet= Fpms[M_fid-1]->net;


    // tnet=2;

     //根据pm_net的值，来将数据从对应的串口发出。
     if(tnet==1){
          len=read(RS485_1_fd,rec_ar,36);
     }else if(tnet==2){
          len=read(RS485_2_fd,rec_ar,36);
     }else if(tnet==3){
          len=read(RS485_3_fd,rec_ar,36);
     }else if(tnet==4){
         len=read(RS485_4_fd,rec_ar,36);
     }else{
          len=read(RS485_5_fd,rec_ar,36);
     }

    if (len<1){
        return 0;
    }

  // ui->textEdit_2->setText("");
   QString str;
   str="";
    for(gri=0;gri<len;gri++){
      str.append(QString::number(rec_ar[gri],16));
      str.append(",");
    }
    if(ui->textEdit_2->textColor()==Qt::black)
    {
        ui->textEdit_2->setTextColor(Qt::red);
    }else
    {
        ui->textEdit_2->setTextColor(Qt::black);
    }
        ui->textEdit_2->append(str);
}


//通讯调试寄存器
void FFPMMainW:: Date_Time_Ts()
{
    RS485_Input_Test();
}

//停止主程序通讯，直接关掉定时器。
//然后开启手动查询模式。
void FFPMMainW::on_pushButton_clicked()
{
    //   timer->stop();
       Sys_Debug_Stop_Main=true;
       timer_ts->start(1000);
       ui->pushButton_3->setEnabled(true);
       ui->pushButton->setEnabled(false);
       ui->pushButton_2->setEnabled(true);

//       QMessageBox msgBox;
//       msgBox.setText(tr("主程序通讯已停止,可以开始手动发送查询!!!"));
//       msgBox.setGeometry(350,180,150,80);
//       msgBox.exec();
         ui->label_4->setText(tr("主程序通讯已停止,可以开始手动发送查询!!!"));

         //But_SSXX_clicked();

 }

//开启主程序通讯,关闭手动查询模式
void FFPMMainW::on_pushButton_3_clicked()
{
    //timer->start(50);
    Sys_Debug_Stop_Main=false;
    timer_ts->stop();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);

//    QMessageBox msgBox;
//    msgBox.setText(tr("主程序通讯已开启!!!"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
   // ui->label_4->setText(tr("主程序通讯已开启,"));

     But_SSXX_clicked();

}

//清空接收区      */
void FFPMMainW::on_pushButton_4_clicked()
{
    ui->textEdit_2->setText("");
}

//关闭通讯调试模式
void FFPMMainW::on_p_but_open_clicked()
{
    Sys_Debug_Stop_Main=false;
    Sys_Debug_State=false;
    But_SSXX_clicked();
}

//手动发送查询1次
void FFPMMainW::on_pushButton_2_clicked()
{
     int i;
     quint8  tnet=1;

     BYTE send_ar[8];
     fasong=true;

     // write(fd_GPIO3_4,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
     write(fd_GPIO5_6,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));

    // timer->stop();

      i=1000;
      i=999;
      while(i--);
      send_ar[0]=M_fid;
      send_ar[1]=0x03;
      send_ar[2]=0x00;
      send_ar[3]=0x50;
      send_ar[4]=0x00;
      send_ar[5]=0x09;
      i= cc16->Get_CRC16(&send_ar[0],6);

      tnet= Fpms[M_fid-1]->net;

      //根据pm_net的值，来将数据从对应的串口发出。
    if(tnet==1){
          write(RS485_1_fd, &send_ar[0],8);
      }else if(tnet==2){
          write(RS485_2_fd, &send_ar[0],8);
      }else if(tnet==3){
          write(RS485_3_fd, &send_ar[0],8);
      }else if(tnet==4){
          write(RS485_4_fd, &send_ar[0],8);
      }else{
          write(RS485_5_fd, &send_ar[0],8);
      }


     // write(RS485_2_fd, &send_ar[0],8);

      timer_re->start(10);

      ui->textEdit->setText("");
      QString str;
      str="";
      for(i=0;i<8;i++){
        str.append(QString::number(send_ar[i],16));
        str.append(",");
      }
      if(ui->textEdit->textColor()==Qt::black){
          ui->textEdit->setTextColor(Qt::red);
      }else{
          ui->textEdit->setTextColor(Qt::black);
      }
          ui->textEdit->setText(str);
}

void  FFPMMainW :: Form_BJ_but1_clicked(){
//     ui->centralWidget->show();
//     ui->tableWidget->show();
//     form_bj->hide();
}

//消防电压模块-发送查询命令
void FFPMMainW ::  Send_Chaxun_Order(int pm_addr, unsigned char pm_net)
{
    int i;
    BYTE send_ar[8];
    write(fd_GPIO5_6,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
    send_ar[0]= pm_addr%0xFF;
    send_ar[1]=0x03;
    send_ar[2]=0x00;
    send_ar[3]=0x50;
    send_ar[4]=0x00;
    send_ar[5]=0x09;
    i= cc16->Get_CRC16(&send_ar[0],6);

    //根据pm_net的值，来将数据从对应的串口发出。
    if(pm_net==1){
        write(RS485_1_fd, &send_ar[0],8);
    }else if(pm_net==2){
        write(RS485_2_fd, &send_ar[0],8);
    }else if(pm_net==3){
        write(RS485_3_fd, &send_ar[0],8);
    }else if(pm_net==4){
        write(RS485_4_fd, &send_ar[0],8);
    }else{
        write(RS485_5_fd, &send_ar[0],8);
    }


   //  write(RS485_2_fd, &send_ar[0],8);

    timer_re->start(10); //发送8个数据，预计耗时8ms, 延时12ms

    if (Sys_Debug_State==true){
        if(pm_addr==M_fid){
            ui->textEdit->setText("");
           QString str;
           str="";
            for(i=0;i<8;i++){
              str.append(QString::number(send_ar[i],16));
              str.append(",");
            }
            if(ui->textEdit->textColor()==Qt::black){
                ui->textEdit->setTextColor(Qt::red);
            }else{
             ui->textEdit->setTextColor(Qt::black);
            }
            ui->textEdit ->append(str);
        }
    }
}


//发送复位命令，向0x49寄存器写1
void FFPMMainW ::  Send_Reset_Order(int pm_addr, unsigned char pm_net)
{
    BYTE send_ar[8];

    write(fd_GPIO3_4,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
    write(fd_GPIO5_6,GPIO_HIGH_LEVEL,sizeof(GPIO_HIGH_LEVEL));
    send_ar[0]= pm_addr%0xFF;
    send_ar[1]=0x06;
    send_ar[2]=0x00;
    send_ar[3]=0x49;
    send_ar[4]=0x00;
    send_ar[5]=0x01;
    cc16->Get_CRC16(&send_ar[0],6);

    //根据pm_net的值，来将数据从对应的串口发出。

    if(pm_net==1){
        write(RS485_1_fd, &send_ar[0],8);
    }else if(pm_net==2){
        write(RS485_2_fd, &send_ar[0],8);
    }else if(pm_net==3){
        write(RS485_3_fd, &send_ar[0],8);
    }else if(pm_net==4){
        write(RS485_4_fd, &send_ar[0],8);
    }else{
        write(RS485_5_fd, &send_ar[0],8);
    }

    timer_re->start(10); //发送8个数据，预计耗时8ms, 延时10ms

}

//发送查询和指示灯命令给MCU
void FFPMMainW ::  Send_Key_Order(qint8 lamp_id, qint8 lamp_sta)
{
    int sko_i,sko_k;
    quint8 send_ar[7];

    send_ar[0]= 0xfa; //arm报文头=0x16  mcu报文头=0x17

    //检查有无将要发出的指示灯等，如果有，就发出，同时标记需要确定，回响判断。
    send_ar[1]=lamp_id;   //指示灯编号 =0
    send_ar[2]=lamp_sta;  //亮灭控制字 =0
    send_ar[3]=0x00;      //预留1

    if(New_data_will_send && (First_data_send==false) ){ //如果有新的指示灯发送出去。
        New_data_have_send=true;
        send_ar[1]= Send_lamp;     //指示灯编号
        send_ar[2]= Send_onoff;     //亮灭控制字
        send_ar[3]= Send_laba;      //预留1-用于喇叭
    }

    if(First_data_send){    //上电初始化。
       send_ar[1]= 0xdd;
       send_ar[2]=0;
       send_ar[3]=0x00;      //预留1
       First_data_send=false;
    }

    if(Sys_Zj){
        send_ar[1]= 0xee;
        send_ar[2]=0;
        send_ar[3]=0x00;      //预留1
        Sys_Zj=false;   //先只发一次，后期改为，发3次。
    }

     send_ar[4]=0x00;      //预留2
     send_ar[5]=0x09;      //校验H
     send_ar[6]=0x06;      //校验L
     sko_k=0;
    for(sko_i=0;sko_i<=4;sko_i++){
        sko_k= send_ar[sko_i]+sko_k;
    }
    sko_k=sko_k%255;
    send_ar[5]=sko_k;
    send_ar[5]=send_ar[5] & 0xF0;
    send_ar[5]=send_ar[5] >>4;

    send_ar[6]=sko_k;
    send_ar[6]=send_ar[6] & 0x0F;

    write(RS485_key_lamp, &send_ar[0],7);
}

//接收MCU 回响的数据
bool  FFPMMainW ::  Rec_Key_Order()
{
    int len;
    int rko;
    int rko_i;

    BYTE rec_ar[20];

    len=read(RS485_key_lamp,rec_ar,20);

     // printf("key %d press!!!\n",len);

    if (len<7) { //至少应收到7个字节
        return false;
    }

   //1:判断MCU回响报文报头0xfb
    if(rec_ar[0]!=0xfb){
        return false;
    }
    //2:判断校验是否正确
    rko=0;
    for(rko_i=0;rko_i<=4;rko_i++){
        rko= rec_ar[rko_i]+rko;
    }
    rko=rko%255;
    rec_ar[18]=rko;
    rec_ar[18]=rec_ar[18] & 0xF0;
    rec_ar[18]=rec_ar[18] >>4;

    rec_ar[19]=rko;
    rec_ar[19]=rec_ar[19] & 0x0F;

    if (rec_ar[18]!=rec_ar[5]){
        return false;
    }

    if (rec_ar[19]!=rec_ar[6]){
        return false;
    }
    //如果接收到按键，则打印出来
     if(rec_ar[1]>0){

            printf("key %d press!!!\n",rec_ar[1]);

            Back_light_on(); //点亮屏幕

           // QMouseEvent event(QEvent::MouseButtonPress, pos, 0, 0, 0);
            //QKeyEvent envent(QEvent::KeyPress,Qt::Qt::Key_A,Qt::NoModifier,"A",0,0);
           // QApplication::sendEvent(this, &eaa);
            //以下，两行代码，可以实现在textEdit框内添加一个字符A,模拟键盘输入。
             //QKeyEvent *eaa=new QKeyEvent(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,"A",0,0);
            // QApplication::postEvent(ui->textEdit,eaa);
            //使用sendEvent,功能同上。
            //QKeyEvent eaa(QEvent::KeyPress,Qt::Key_A,Qt::NoModifier,"A",0,0);
            //QApplication::sendEvent(ui->textEdit, &eaa);
            //使用心得当写成sendEvent(this, &eaa),或者ui.centeralwidget 时，即使光标选在文本框，仍然得不A ,不知道为什么。
            //当把KeyPress 更改为KeyRelease，也得不到A

            //测试发现，可以通过下面focusWidget，来动态活得焦点控件。OK
//            QKeyEvent eaa(QEvent::KeyPress,qtk,Qt::NoModifier,"A",0,0);
//            QApplication::sendEvent( QApplication::focusWidget(), &eaa);

            Key_Work_Center(rec_ar[1]);

            //模拟回车按键
            //QKeyEvent eaa(QEvent::KeyPress,Qt::Key_Enter,Qt::NoModifier);
           // QApplication::sendEvent(ui->centralWidget, &eaa);
     }

     return true;
}


////按键事物处理中心，实现逻辑如下：
////1：模拟事件，发送给系统。
////2：自己定义按键
void FFPMMainW::Key_Work_Center(quint8 mkey){

    Qt::Key qtk;
    QString ks="A";
    qtk=Qt::Key_V;

    if(1==mkey){
        qtk=Qt::Key_1;
        ks="1";
    }else if(2==mkey){
        qtk=Qt::Key_2;
         ks="2";
    }else if(3==mkey){
        qtk=Qt::Key_3;
         ks="3";
    }else if(4==mkey){
        qtk=Qt::Key_Right;
         ks="R";
    }

//    else if(5==mkey){
//        qtk=Qt::Key_Up;
//        ks="";
//    }

    else if(6==mkey){
        qtk=Qt::Key_4;
         ks="4";
    }else if(7==mkey){
        qtk=Qt::Key_5;
         ks="5";
    }else if(8==mkey){
        qtk=Qt::Key_6;
         ks="6";
    }else if(9==mkey){
        qtk=Qt::Key_Left;
         ks="L";
    }

//    else if(10==mkey){
//        qtk=Qt::Key_Down;
//           ks="";
//    }

    else if(11==mkey){
        qtk=Qt::Key_7;
         ks="7";
    }else if(12==mkey){
        qtk=Qt::Key_8;
         ks="8";
    }else if(13==mkey){
        qtk=Qt::Key_9;
         ks="9";
    }else if(14==mkey){
        qtk=Qt::Key_Tab;
    }else if(15==mkey){
        qtk=Qt::Key_Enter;
    }else if(16==mkey){
        qtk=Qt::Key_Space;   //空格键，，，找不到值
         ks=" ";
    }else if(17==mkey){
        qtk=Qt::Key_0;
         ks="0";
    }else if(18==mkey){
        qtk=Qt::Key_Period;
         ks=".";
    }else if(19==mkey){
        qtk=Qt::Key_Backspace;
    }else if(20==mkey){
        qtk=Qt::Key_Escape;
         ks="";
    }

    if(qtk!=Qt::Key_V){          //按键值             //传递字符。
         QKeyEvent eaa(QEvent::KeyPress,qtk,Qt::NoModifier,ks,0,0);
        QApplication::sendEvent( QApplication::focusWidget(), &eaa);
        return;
    }

     if(21==mkey){
        //自检qtk=Qt::Key_Escape;
    }else if(22==mkey){
        //消音qtk=Qt::Key_Escape;

      //上一页，下一页，，
     }else if(5==mkey || 10==mkey){ //up

         if(Cur_Ui_Page==1){  //实时信息
            form_xx->My_Up_Down_Key(mkey);
         }else if(Cur_Ui_Page==2){
            form_bj->Bj_Up_Down_Key(mkey);
         }else if(Cur_Ui_Page==3){
           form_gz->Fa_Up_Down_Key(mkey);
         }else if(Cur_Ui_Page==4){
             form_his->His_Up_Down_Key(mkey);
         }
     }
    else{ //(23==mkey){
        //主页    qtk=Qt::Key_Escape;
         But_SSXX_clicked();
         But_SSXX->setFocus();
    }

}

//按键按下事件，无法获得方向键盘的值，
//监测按键按下，
//主要实现功能： 1：完成回车按键响应
//               2：完成在信息节目，报警，故障，历史报警界面上下键对应上一页和下一页
void FFPMMainW::keyPressEvent(QKeyEvent *ev){
    //监测回车按键。。。
    if(ev->key()==Qt::Key_Enter){
        Buttons_Enter();
        return ;
    }
    //else if(ev->key()==Qt::Key_Up){
     //   printf("get up down key!!!\n");
   // }
    else{
        QWidget::keyPressEvent(ev);  //其他的按键将被传送出去。
    }
}


bool FFPMMainW::Buttons_Enter(){
    //实时信息获得焦点。
    if(But_SSXX->hasFocus()){
        But_SSXX_clicked();
        return true;
    }
    if(But_DQBJ->hasFocus()){
        But_DQBJ_clicked();
        return true;
    }
    if(But_DQGZ->hasFocus()){
        But_DQGZ_clicked();
        return true;
    }
    if(But_LSBJ->hasFocus()){
        But_LSBJ_clicked();
        return true;
    }

    if(But_CSSZ->hasFocus()){
        But_CSSZ_clicked();
        return true;
    }

    if(But_XTFW->hasFocus()){
         But_XTFW_clicked();
          return true;
    }

    if(But_XTZJ->hasFocus()){
          But_XTZJ_clicked();
          return true;
    }

    if(ui->pushButton_5->hasFocus()){
         on_pushButton_5_clicked();
         return true;
    }

    if(ui->pushButton_2->hasFocus()){
        on_pushButton_2_clicked();
        return true;
    }

    if(ui->pushButton->hasFocus()){
        on_pushButton_clicked();
        return true;
    }
    if(ui->pushButton_3->hasFocus()){
        on_pushButton_3_clicked();
        return true;
    }
    if(ui->p_but_open->hasFocus()){
        on_p_but_open_clicked();
        return true;
    }

    if(ui->pushButton_4->hasFocus()){
        on_pushButton_4_clicked();
        return true;
    }
}



//接收串口数据，并对数据进行校验和解析
//完全正确=5  校验错误=4  地址报头错误=3  长度不足=2  未接收到任何数据=0
// 引用到的变量 Fpms[fpm_cur_id]
unsigned int  FFPMMainW :: Get_RS485_Input(int cur_id)
{
    int m_addr,len,len1;
    int gri,grk;
    int data32i;
    float dataf;
//    BYTE rec_ar[40];
//    BYTE rec_ar1[30];  调试测试时将其定义为全局变量，后来就定义为全局变量

    int m_net=5;

    memset(rec_ar,0,40);
    memset(rec_ar1,0,30);

    m_net= Fpms[cur_id]->net;

    if(m_net==1){
        len=read(RS485_1_fd,rec_ar,30);
    }else if(m_net==2){
        len=read(RS485_2_fd,rec_ar,30);
    }else if(m_net==3){
        len=read(RS485_3_fd,rec_ar,30);
    }else if(m_net==4){
        len=read(RS485_4_fd,rec_ar,30);
    }else{
        len=read(RS485_5_fd,rec_ar,30);
    }

    //接收到的数组长度不够，直接返回。
    if (len<6){
        return 0;
    }

    //正确的数组长度应为23个。串口接收30个数据,然后过滤报头。
    //报头过滤，addr+0x03  //报文头过滤采用双字节
    m_addr=Fpms[cur_id]->addr; //取到地址。

    //-----------------------现场调试程序--当开启现场调试功能后，代码才启动-------------------
    //---------代码功能，显示发送和接收到的制定模块地址的通信帧数据，供现场调试人员使用
    if (Sys_Debug_State==true){
         if(m_addr == M_fid){
           // ui->textEdit_2->setTexHide_Cur_Paget("");
            ui->textEdit_2->setText("");
           QString str;
           str="";
            for(gri=0;gri<len;gri++){
              str.append(QString::number(rec_ar[gri],16));
              str.append(",");
            }
            if(ui->textEdit_2->textColor()==Qt::black){
                ui->textEdit_2->setTextColor(Qt::red);
            }else{
                ui->textEdit_2->setTextColor(Qt::black);
            }
            ui->textEdit_2->append(str);
    }
    }
    //---------------------------------------------------------


   //对接收到的数据进行简单的滤波。此处代码仍需要完善，在2017-10-30号工厂
   //调试时，发现RS485自翻转电路信号反射，没有成功过滤到反射的数据，
    for(gri=0;gri<len;gri=gri+2){
        if(gri>(len-2)){
            return 4;
        }
        if(rec_ar[gri]!=m_addr){
            continue;
        }
        if(rec_ar[gri+1]!=0x03){
            continue;
        }
        break;
    }

    len1=len-gri;

    if(len1<6){ //第一次长度小于6.
         return 2;
     }

    //重新赋值数组。。
    grk=0;
    for(gri;gri<len;gri++){
        rec_ar1[grk]=rec_ar[gri];
        grk++;
    }


    //接收常规查询返回数据，读取9个寄存器遥测值。  qdb=QSqlDatabase::addDatabase("QSQLITE");
    if (1==Wait_rec_kind){

        //3:正确的数组长度应为23个。
        if (len1<23){
             return 2;
        }

        //4: 判断数据字节个数 9×2
        if(18!=rec_ar1[2]){
             return 2;
        }

        //5: CRC16校验,
        //先计算模块发过来的校验，
        grk= (rec_ar1[len1-1] << 8) | rec_ar1[len1-2] ;
        //然后计算本地的校验码，注意Get_CRC16,这个函数，会将本地校验吗同时复制到rec_ar1的len1,len-1位。
        gri=cc16->Get_CRC16(&rec_ar1[0], len1-2);

        if(gri!=grk){
            return 4;  //校验错误。
        }

        //5：提取9个数据
        gri=0;
        for(len=0;len<9;len++){
            data32i=rec_ar1[3+gri];

            //data32i=data32i*256;
            //data32i=data32i+rec_ar1[4+gri];
            //data32i=data32i/100;  //精度会丢失。。
            //Fpms[fpm_cur_id]->cur_data[len]=data32i;

            //2018-8-24 注释掉上面4行，改为浮点数运算。
            dataf=data32i*256+rec_ar1[4+gri];
            dataf=dataf/100;
            Fpms[fpm_cur_id]->cur_data[len]=dataf;
            gri=gri+2;
        }

            //2018-8-28 需要根据节点的型号，找到电流的值，然后乘以互感器的倍数。
            //kind 模块类型 1=M3-V2   2=M3-V2A  3=M3-V3  4=M3-VA  5=M2-V6  6=M2-V9
             
            if(Fpms[fpm_cur_id]->kind==2){  //V2A
                 Fpms[fpm_cur_id]->cur_data[6]=Fpms[fpm_cur_id]->cur_data[6]* Fpms[fpm_cur_id]->a1_rate; 
                 Fpms[fpm_cur_id]->cur_data[7]=Fpms[fpm_cur_id]->cur_data[7]* Fpms[fpm_cur_id]->a1_rate; 
                 Fpms[fpm_cur_id]->cur_data[8]=Fpms[fpm_cur_id]->cur_data[8]* Fpms[fpm_cur_id]->a1_rate; 
            }

          if(Fpms[fpm_cur_id]->kind==4){  //VA
                 Fpms[fpm_cur_id]->cur_data[3]=Fpms[fpm_cur_id]->cur_data[3]* Fpms[fpm_cur_id]->a1_rate; 
                 Fpms[fpm_cur_id]->cur_data[4]=Fpms[fpm_cur_id]->cur_data[4]* Fpms[fpm_cur_id]->a1_rate; 
                 Fpms[fpm_cur_id]->cur_data[5]=Fpms[fpm_cur_id]->cur_data[5]* Fpms[fpm_cur_id]->a1_rate; 
            }
          return 5;

        }else{
            return 4;
        }
    }


//首先把所有的按钮都设置为白色，然后将对应的按键搞黑。
void FFPMMainW::But_Backcolor_Set(quint8 ui_page){
        But_SSXX->setPalette(qp_bai);
        But_DQBJ->setPalette(qp_bai);
        But_DQGZ->setPalette(qp_bai);
        But_LSBJ->setPalette(qp_bai);
        But_CSSZ->setPalette(qp_bai);
        But_XTZJ->setPalette(qp_bai);
        But_XTFW->setPalette(qp_bai);

        if(ui_page==1){
           But_SSXX->setPalette(qp_hei);
          // But_SSXX->setEnabled(false);
        }else if(ui_page==2){
            But_DQBJ->setPalette(qp_hei);
             //But_DQBJ->setEnabled(false);
        }else if(ui_page==3){
             But_DQGZ->setPalette(qp_hei);
              //But_DQGZ->setEnabled(false);
        }else if(ui_page==4){
             But_LSBJ->setPalette(qp_hei);
             // But_LSBJ->setEnabled(false);
        }else if(ui_page==5){
             But_CSSZ->setPalette(qp_hei);
              //But_CSSZ->setEnabled(false);
        }else if(ui_page==6){
             But_XTZJ->setPalette(qp_hei);
             //But_XTZJ->setEnabled(false);
        }else if(ui_page==7){
             But_XTFW->setPalette(qp_hei);
             //But_XTFW->setEnabled(false);
        }

}

//实时信息-form_xx  Cur_Ui_Page=1
void FFPMMainW::But_SSXX_clicked()
{
        if(Cur_Ui_Page==1){
            return;
        }
        Hide_Cur_Page();
        form_xx->setAutoFillBackground(true);
        form_xx->show();
        Cur_Ui_Page=1;
        But_Backcolor_Set(Cur_Ui_Page);
        // QProcess::execute("echo echo 3 > /sys/class/backlight/backlight/brightness");

       // write(fd_backlight,"4",sizeof("4"));
       // Set_Back_Light_Level(4);
}

//当前报警-form_bj  Cur_Ui_Page=2
void  FFPMMainW:: But_DQBJ_clicked(){
        if(Cur_Ui_Page==2){
            return;
        }
        Hide_Cur_Page();
        form_bj->setAutoFillBackground(true);
        form_bj->show();
        Cur_Ui_Page=2;
        But_Backcolor_Set(Cur_Ui_Page);
       // QProcess::execute(" 7 > /sys/class/backlight/backlight/brightness");
        //  write(fd_backlight,"7",sizeof("7"));
        Set_Back_Light_Level(7);
}

//当前故障-form_gz  Cur_Ui_Page=3
void   FFPMMainW:: But_DQGZ_clicked(){
        if(Cur_Ui_Page==3){
            return;
        }
        Hide_Cur_Page();
      //  form_gz->setGeometry(0,0,800,410);
        form_gz->setAutoFillBackground(true);
        //form_gz->move(0,40);
        form_gz->show();
        Cur_Ui_Page=3;
        But_Backcolor_Set(Cur_Ui_Page);
}

//历史报警-form_his Cur_Ui_Page=4
void  FFPMMainW:: But_LSBJ_clicked(){
    if(Cur_Ui_Page==4){
        return;
    }
    Hide_Cur_Page();
    //form_his->setGeometry(0,0,800,410);
    form_his->setAutoFillBackground(true);
    //form_his->move(0,40);
    form_his->show();
     form_his->Meng_Xiang();
    Cur_Ui_Page=4;
    But_Backcolor_Set(Cur_Ui_Page);
}

//参数设置
void   FFPMMainW::But_CSSZ_clicked(){
        if(Cur_Ui_Page==5){
            return;
        }
        form_lg->setAutoFillBackground(true);
        form_lg->setGeometry(200,100,400,280);
        //form_lg->move(200,100);
        form_lg->show();
        form_lg->Haha(3);

        form_lg_show=true;
        Next_Ui_Page=1;
//       Hide_Cur_Page();
//       ui->centralWidget->show();
}

//密码验证成功后，调用显示。
void FFPMMainW::Show_Next_Page(){
      Hide_Cur_Page();
      if(Next_Ui_Page==1){  //参数设置窗体
        Cur_Ui_Page=5;
        form_cs->setAutoFillBackground(true);
        But_Backcolor_Set(Cur_Ui_Page);
       // But_CSSZ->setEnabled(false);
        form_cs->show();
      }

      if(Next_Ui_Page==2){ //系统自检窗体
          form_zj=new Form_SelfCheck(this);
          form_zj->setAutoFillBackground(true);
          form_zj->setGeometry(0,0,800,410);
          form_zj->move(0,40);
          form_zj->show();
          Cur_Ui_Page=6;
          But_Backcolor_Set(Cur_Ui_Page);
          //But_XTZJ->setEnabled(false);
      }

      if(Next_Ui_Page==3){  //系统复位窗体
          form_rs=new Form_Rset(this);
          form_rs->setAutoFillBackground(true);
          form_rs->setGeometry(0,0,800,410);
          form_rs->move(0,40);
          form_rs->show();
          Cur_Ui_Page=7;
          But_Backcolor_Set(Cur_Ui_Page);
          //But_XTFW->setEnabled(false);
      }
}

//系统自检，打开系统自检窗体。Cur_Ui_Page=6
//当技术人员在现场调试，开启Sys_Debug_State=true 时，此按钮为进入现场调试窗体。
void  FFPMMainW::But_XTZJ_clicked(){
    //以下注释的是正确的代码，带测试的代码完成后，恢复。
    if(Sys_Debug_State==true){
        Hide_Cur_Page();
        ui->centralWidget->show();
    }else{
        if(Cur_Ui_Page==6){
            return;
        }
        form_lg->setAutoFillBackground(true);
        form_lg->setGeometry(200,100,400,280);
        form_lg->show();
        form_lg->Haha(2);
        form_lg_show=true;
        Next_Ui_Page=2;
    }
}


//根据 Cur_Ui_Page的值，隐藏对应的窗体。
//同时使能对应的按钮。
void FFPMMainW::Hide_Cur_Page(){
    switch (Cur_Ui_Page){
        case 1:
            form_xx->hide();
            break;
        case 2:
            form_bj->hide();
            break;
        case 3:
            form_gz->hide();
            break;
        case 4:
            form_his->hide();
            break;
        case 5:
            form_cs->hide();
            break;
        case 6:
             form_zj->close();
              break;
        case 7:
             form_rs->close();
              break;
        default:
            break;
    }

    //如果登录窗体打开，则关闭。
    if(form_lg_show){
        form_lg->hide();
    }

}

//系统复位--以后增加一个界面，选择复位模块。
void FFPMMainW::But_XTFW_clicked(){
//   // QString pro="/opt/S85qt.sh";
//    QString pro="/opt/ffpm_start.sh";
//    QProcess::startDetached(pro);
//    QApplication::exit();
    if(Cur_Ui_Page==7){
        return;
    }
    form_lg->setAutoFillBackground(true);
    form_lg->setGeometry(200,100,400,280);
    form_lg->show();
    form_lg->Haha(2);
    form_lg_show=true;
    Next_Ui_Page=3;
}



//使用帮助
void  FFPMMainW:: But_SYBZ_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("使用帮助"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//    But_Backcolor_Set(Cur_Ui_Page);
}


//-消防电压模块集合初始化，以后将调用数据库
bool FFPMMainW:: Fpms_Init()
{
//    qdb=QSqlDatabase::addDatabase("QSQLITE");
//    qdb.setDatabaseName("/opt/ffpm.db");
//    bool dbok=qdb.open();

    try{
        if(qdb.isOpen()){
           //查询数据库中，ffpm_info表，按id升序排列。
           //因query.value( int index),并不可靠，所以使用record.value(name).
            QSqlQuery query=qdb.exec("select * from ffpm_info order by id");
            QSqlRecord rec;
            int i_t=0;
            int ii,kk,mm;
             while (query.next()) {
                 rec=query.record();
                // qDebug() << query.value(0).toString();
                // qDebug() << rec.value("id").toString() << "---" <<rec.value("name").toString();
                 ii=rec.value("addr").toInt(); //地址。
                 kk=rec.value("kind").toInt(); //模块类型
                 mm=rec.value("net").toInt();

                 Fpms[i_t]=new FFPM(ii,ii,kk,mm);
                 Fpms[i_t]->name= rec.value("name").toString();
                 //Fpms[i_t]->name_gbk= rec.value("name_gbk").toString();

                 Fpms[i_t]->enable=rec.value("enable").toBool();

                 //过欠压/流 值的百分比。
                 Fpms[i_t]->qy_v1=rec.value("qy_v1").toInt(); //欠压值比
                 Fpms[i_t]->qy_v2=rec.value("qy_v2").toInt();
                 Fpms[i_t]->qy_v3=rec.value("qy_v3").toInt();

                 Fpms[i_t]->gy_v1=rec.value("gy_v1").toInt();//过压值比
                 Fpms[i_t]->gy_v2=rec.value("gy_v2").toInt();
                 Fpms[i_t]->gy_v3=rec.value("gy_v3").toInt();

                 Fpms[i_t]->ql_a1= rec.value("ql_a1").toInt();//欠流值比
                 Fpms[i_t]->gl_a1= rec.value("gl_a1").toInt();

                 Fpms[i_t]->guoliu=rec.value("guoliu").toInt(); //报警使能
                 Fpms[i_t]->qianliu=rec.value("qianliu").toInt();
                 Fpms[i_t]->guoya=rec.value("guoya").toInt();
                 Fpms[i_t]->qianya=rec.value("qianya").toInt();

                 //2018年8月28日17:25:12 增加电流互感器倍数
                 Fpms[i_t]->a1_rate = rec.value("a1_rate").toInt();

                 MaxMinVAInit(); //初始化报警值。

                 Fpms[i_t]->comm_sta=0;
                 Fpms[i_t]->v1_alarm_pop=0;
                 Fpms[i_t]->v2_alarm_pop=0;
                 Fpms[i_t]->va_alarm_pop=0;
                 Fpms[i_t]->comm_fail_ct=0;
                 i_t++;

                 if(i_t>=500){  //如果数据超限，就退出。
                    break;
                 }
             }

             if(i_t< Fpm_Total ){
                 i_t=Fpm_Total;
             }

             if(i_t<1){
                return false;
             }
             return true;
        }
    }
    catch(...){
            return false;
    }
   }

//系统关键信息初始化。
//create table sys_main_info(
//sys_name nvarchar(50) ,
//sys_node_count smallint unsigned not null,
//sys_tcq_com tinyint unsigned,
//sys_printer_com tinyint unsigend,
//sys_renzheng tinyint unsigned
//);
bool FFPMMainW:: Sys_Main_Info_Init(){
    try{
        if(qdb.isOpen()){ //如果数据连接已经建立好。
            QSqlQuery query=qdb.exec("select * from sys_main_info");
            QSqlRecord rec;
              while (query.next()) {
                  rec=query.record();
                  Sys_name =rec.value("sys_name").toString(); //系统名称。
                  Fpm_Total=rec.value("sys_node_ct").toInt(); //系统节点总数量
                  Comm_Fail_Max=rec.value("sys_comm_fail_ct").toInt();
                  if(Comm_Fail_Max<=0){
                        Comm_Fail_Max=3;
                  }

                   sys_l1_pass=rec.value("sys_l1_pass").toString();
                   sys_l2_pass=rec.value("sys_l2_pass").toString();
                   sys_l3_pass=rec.value("sys_l3_pass").toString();
                  return true;
              }
            return false;
        }
    }catch(...){
        return false;
    }
    return false;
}


//向数据库中插入500条默认的数据，不覆盖原有的数据。
//模块类型M3-V2 =1, net=1,
bool FFPMMainW:: Ffpms_DataBase500_Init(){
    int i=0;
    int k=0;
    QString fdis;
    if(qdb.isOpen()){ //如果数据连接已经建立好。
        QSqlQuery query(qdb);
        query.prepare("INSERT INTO ffpm_info (id, addr, net, name, kind, enable, guoya, qianya, guoliu, qianliu, qy_v1, qy_v2, qy_v3, gy_v1, gy_v2, gy_v3,ql_a1,gl_a1,a1_rate) "
                         "VALUES (:id, :addr, :net, :name, 1,1, 1, 1, 0, 0, 80, 80, 80, 120, 120, 120,0,120,1)");
        for(i=1;i<=500;i++){
            query.bindValue(":id", i);
            query.bindValue(":addr", i);
            fdis=QString::number(i).append("-ALE");
            query.bindValue(":name", fdis);
          bool bl= query.exec();
          if(bl){
            k++;
          }
        }
        // qDebug() << query.value(0).toString();
        qDebug() << "success insert "<< k <<"条 ";
    }
   return true;
}

 //将报警信息存储到数据库中去。
//create table his_alarm(ffpm_id int,name nvarchar(30), alarm_kind tinyint,alarm_date text,alarm_time text,alarm_value text);
 bool FFPMMainW:: Add_Alarm_Infos(Alarm* m_al){
     try{

            if(qdb.isOpen()){ //如果数据连接已经建立好。
             QSqlQuery query(qdb);
             query.prepare("INSERT INTO his_alarm (ffpm_id, name, alarm_kind, alarm_date, alarm_time, alarm_value) "
                              "VALUES (:ffpm_id, :name, :alarm_kind, :alarm_date,:alarm_time,:alarm_value)");
             query.bindValue(":ffpm_id", m_al->fpm_id );
             query.bindValue(":name", m_al->fpm_name);
             query.bindValue(":alarm_kind",m_al->alarm_kind_str);
             query.bindValue(":alarm_date",m_al->date_str );
             query.bindValue(":alarm_time",m_al->time_str );
             query.bindValue(":alarm_value",m_al->value_str );
             query.exec();
             }

     }catch(...){
        return false;
     }
 }




void FFPMMainW::on_pushButton_5_clicked()
{
    bool op5b=false;
    quint16  iop5;
    iop5=ui->lineEdit->text().toInt(&op5b,10);

    if(op5b==false){
        ui->lineEdit->setText("1");
        ui->lineEdit->setFocus();
        return;
    }

    if(iop5<1 || iop5>=Fpm_Total){
        ui->lineEdit->setText("1");
        ui->lineEdit->setFocus();
        return;
    }

    M_fid=iop5;

}
