#include "form_rset.h"
#include "ui_form_rset.h"
#include <QPushButton>
#include <mybutton.h>
#include <QPalette>
#include <QTimer>
#include<QProcess>

#include<QKeyEvent>

QTimer *timer_rs;
quint8 timer_rs_ct;

QPushButton *But_all_ffpms_reset;// Cur_Ui_Page=1

QPushButton *But_just_sys_reset;

//通讯任务1=常规查询， 2=复位命令 ， 3=自检命令 ，  4=参数设置 ， 5.。。。。。
extern quint8 Send_work_kind;

//发送复位命令是ffpm的下标
extern qint16 Send_reset_id;

extern unsigned int Fpm_Total;  //消防电压模块总数量


Form_Rset::Form_Rset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Rset)
{
    ui->setupUi(this);

    But_all_ffpms_reset=new MyButton();
    But_all_ffpms_reset->setText(tr("复位所有模块"));
    But_all_ffpms_reset->move(10,0);
    But_all_ffpms_reset->setFont(QFont("黑体",20,10,false));

//    rs_hei=But_all_ffpms_reset->palette();
//    rs_hei.setColor(QPalette::Button,Qt::black);
//    rs_hei.setColor(QPalette::ButtonText,Qt::white);
//    rs_bai=But_all_ffpms_reset->palette();
//    rs_bai.setColor(QPalette::Button,Qt::white);
//    rs_bai.setColor(QPalette::ButtonText,Qt::black);
//    But_all_ffpms_reset->setPalette(rs_bai);

    But_just_sys_reset=new MyButton();
    But_just_sys_reset->setText(tr("仅复位主机"));
    But_just_sys_reset->move(10,0);
    But_just_sys_reset->setFont(QFont("黑体",20,10,false));

    ui->hboxl->addWidget(But_all_ffpms_reset);
    ui->hboxl_2->addWidget(But_just_sys_reset);

    connect(But_all_ffpms_reset,SIGNAL(clicked()),this,SLOT(But_all_ffpms_reset_clicked()));
    connect(But_just_sys_reset,SIGNAL(clicked()),this,SLOT(But_just_sys_reset_clicked()));

    timer_rs = new QTimer(this);
    connect(timer_rs, SIGNAL(timeout()), this, SLOT(RS_Time_Fresh()));

    ui->label->hide();

}

void Form_Rset::  RS_Time_Fresh(){
    if(Send_reset_id>=ui->progressBar->maximum()){
        ui->progressBar->setValue(ui->progressBar->maximum());
        ui->label->show();
        timer_rs->stop();
        But_all_ffpms_reset->setEnabled(true);
    }else{
         ui->progressBar->setValue(Send_reset_id);
    }
}

//复位所有的模块
void Form_Rset:: But_all_ffpms_reset_clicked(){
    Send_work_kind=2;
    Send_reset_id=0;
    ui->progressBar->setMaximum(Fpm_Total);
    timer_rs->start(500);
    ui->label->hide();
    ui->progressBar->setValue(0);

    But_all_ffpms_reset->setEnabled(false);
}

//只复位主机
void Form_Rset::  But_just_sys_reset_clicked(){
    QString pro="/opt/ffpm_start.sh";
    QProcess::startDetached(pro);
    QApplication::exit();

}

//监测按键按下，
void Form_Rset::keyPressEvent(QKeyEvent *ev){
    //监测回车按键,回车按键模拟，点击 确定按键。
    if(ev->key()==Qt::Key_Enter){
        if(But_all_ffpms_reset->hasFocus()){
            But_all_ffpms_reset_clicked();
        }else if(But_just_sys_reset->hasFocus()){
            But_just_sys_reset_clicked();
        }
    }
}

Form_Rset::~Form_Rset()
{
    delete ui;
}
