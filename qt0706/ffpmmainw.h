#ifndef FFPMMAINW_H
#define FFPMMAINW_H

#include <QMainWindow>

#include<form_baojin.h>

#include "ffpm.h"    //ffpm模块头文件。
#include "alarm.h"


namespace Ui {
class FFPMMainW;
}

class FFPMMainW : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FFPMMainW(QWidget *parent = 0);
    ~FFPMMainW();

signals:
  void key_enter_presss();

  //发射信号
  void Key_Updown_Press();
    
private slots:
    void   on_pushButton_clicked();
    void   Form_BJ_but1_clicked();
    void   Date_Time_Fresh();
    void   Date_Time_Re();
    void   Date_Time_Ts();

    void   on_pushButton_2_clicked();
    void   on_p_but_open_clicked();
    void   But_SSXX_clicked();
    void   But_DQGZ_clicked();
    void   But_DQBJ_clicked();
    void   But_LSBJ_clicked();
    void   But_XTFW_clicked();
    void   But_CSSZ_clicked();
    void   But_SYBZ_clicked();
    void   But_XTZJ_clicked();
    void   Show_Next_Page();


   void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_5_clicked();

   void on_gao_clicked();

   void on_di_clicked();

public:
    Ui::FFPMMainW *ui;




private:
    //发送查询指令
    void Send_Chaxun_Order(int pm_addr,unsigned char pm_net);

    //发送复位指令
    void Send_Reset_Order(int pm_addr,unsigned char pm_net);

    //读取串口数据
     unsigned int  Get_RS485_Input(int ffd);

     //自己的界面初始化
     void My_Ui_Init();


     void    Send_Key_Order(qint8 lamp_id=0, qint8 lamp_sta=0);
     bool    Rec_Key_Order();

     //通讯事件处理-针对单个对象
     void Comm_Work_Center(unsigned int com_back);

     //报警事物处理 -针对单个对象
    void  Alarm_Work_Center(unsigned int com_back);

    unsigned int    RS485_Input_Test();



   void Chao_Xian_M3V1();//第1路3箱电压，超限报警判断
   void Chao_Xian_M3V2();//第2路为3相电压时，超限报警判断
   void Chao_Xian_M3VA();//第3路为电压/电流时超限判断，已舍弃不用了。
   void Chao_Xian_M3V3(); //第3路为电压时，超限报警判断
   void Chao_Xian_A2(); //第2路为电流时，超限报警判断
   void Chao_Xian_A3(); //第3路为电流时，超限报警判断
   

    //---------------------------数据操作函数-----------------------------
    bool Sys_Main_Info_Init();//------系统关键信息表初始化
    bool Fpms_Init();  //-------------fpms消防电压模块初始化
    bool Ffpms_DataBase500_Init();  //向ffpm_info表插入默认的500条数据
    bool Add_Alarm_Infos(Alarm *m_al);  //将报警信息存储到数据库中去。
    //-------------------------------------------------------------------

    void   Key_Work_Center(quint8 mkey);

    //按键事件重写。
    void   keyPressEvent(QKeyEvent *);

    bool  Buttons_Enter();

    void But_Backcolor_Set(quint8 ui_page);

    //删除故障集合，指定的故障对象。
    void Remove_Vector_Falut(quint16 m_fpm_id, quint8 m_fault_kind);

    //窗体界面切换时，隐藏当前的的界面。
    void Hide_Cur_Page();

    //设置屏幕背光亮度等级 0-7
    bool Set_Back_Light_Level(quint8 lev);

    //屏幕背光自动控制函数
    void Back_light_control();

    //点亮屏幕背光
    void Back_light_on();
};

#endif // FFPMMAINW_H
