#include "form_zj2.h"
#include "ui_form_zj2.h"
#include <QTimer>

QTimer *timer_zj2;
  QPalette pal;
quint8 timer_zj2_ct;

Form_ZJ2::Form_ZJ2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ZJ2)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    timer_zj2 = new QTimer(this);
    connect(timer_zj2, SIGNAL(timeout()), this, SLOT(ZJ2_Time_Fresh()));
    timer_zj2->start(1000);
    this->setAutoFillBackground(true);
      pal=this->palette();
    pal.setColor(QPalette::Background, Qt::red);
    this->setPalette(pal);
    timer_zj2_ct=0;
    ui->label->move(200,150);
}


void Form_ZJ2::ZJ2_Time_Fresh(){

    timer_zj2_ct++;

    if(timer_zj2_ct==3){
        pal.setColor(QPalette::Background, Qt::green);
        this->setPalette(pal);
          ui->label->move(200,250);
          ui->label->setText(tr("绿色"));
    }

    if(timer_zj2_ct==6){
        pal.setColor(QPalette::Background, Qt::black);
        this->setPalette(pal);
           ui->label->move(200,350);
             ui->label->setText(tr("黑色"));
    }

    if(timer_zj2_ct==9){
        timer_zj2->stop();
        this->hide();
    }



}

Form_ZJ2::~Form_ZJ2()
{
    delete ui;
}
