#include "form_selfcheck.h"
#include "ui_form_selfcheck.h"
#include <QTimer>
#include "form_zj2.h"

#include <cstring>
#include <stdio.h>
#include<QTextCodec>

extern bool Sys_Zj;


QTimer *timer_zj;

qint16 zj_timer_ct;

Form_ZJ2 *Form_Color;

Form_SelfCheck::Form_SelfCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_SelfCheck)
{
     ui->setupUi(this);
     ui->label->hide();
}

Form_SelfCheck::~Form_SelfCheck()
{
    delete ui;
}

//主机自检按钮
//自检流程：1指示灯闪烁，   2：扬声器报警声，    3：扬声器故障声。   4：显示屏颜色变换。
//  耗时       5秒                 5秒                  5秒               9秒（黄绿红）
// 实现逻辑： 主机发送自检指令给按键板，并接收ARM 板子回响
void Form_SelfCheck::on_pushButton_clicked()
{
    //首先标记自检，然后使能所有的按钮，和键盘，不允许操作。
    Sys_Zj=true;
    //然后开启定时器，进度条推进，
    //定时器，定时50ms,在定时器内部，发送和接收 模块发过来的数据。。
     timer_zj = new QTimer(this);
     connect(timer_zj, SIGNAL(timeout()), this, SLOT(ZJ_Time_Fresh()));
     timer_zj->start(1000);
     ui->label->show();
     zj_timer_ct=0;
     ui->bar->setValue(0);
}

//自检定时器，定时时间1秒。
void Form_SelfCheck::ZJ_Time_Fresh(){
    zj_timer_ct++;

    if(zj_timer_ct==5){
        ui->label->setText(tr("2:监控报警喇叭发声!!!"));
    }
    if(zj_timer_ct==10){
         ui->label->setText(tr("3:故障报警喇叭发声!!!"));
    }
    if(zj_timer_ct==15){
        ui->label->setText(tr("4:液晶屏颜色显示测试!!!"));
        Form_Color=new Form_ZJ2();
        Form_Color->show();
    }

    if(zj_timer_ct>=ui->bar->maximum()){
        ui->bar->setValue(ui->bar->maximum());
        timer_zj->stop();
        ui->label->setText(tr("5:自检测完成!!!"));
        Form_Color->close();


    }else{
        ui->bar->setValue(zj_timer_ct);
    }


}
