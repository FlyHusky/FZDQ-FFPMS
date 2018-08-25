#include "form_login.h"
#include"ui_form_login.h"
#include<QComboBox>

#include "ffpmmainw.h"
#include <QProcess>

#include <QMessageBox>
#include<QKeyEvent>


extern QString sys_l1_pass;  //权利最高，1级密码
extern QString sys_l2_pass;  //第2,级密码
extern QString sys_l3_pass;  //第3级密码。
extern const QString sys_super_pass;
extern quint8 Next_Ui_Page;

Form_Login::Form_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Login)
{
    ui->setupUi(this);
    ui->comboBox->insertItem(0,tr("操作员"),Qt::DisplayRole);
    ui->comboBox->insertItem(1,tr("管理员"),Qt::DisplayRole);
    ui->label_4->hide();
    ui->Line_Pass->setText("885200");

    connect(ui->But_ESC,SIGNAL(clicked()),this,SLOT(on_But_ESC_clicked()));
   // connect(ui->But_OK,SIGNAL(clicked()),this,SLOT(on_But_OK_clicked()));

}

//取消案件。。
void Form_Login::on_But_ESC_clicked(){
   this->hide();
    //emit Pass_Is_Ok();
}

//进入登录窗体后，需要的权限。
void Form_Login::Haha(int lev){
    if(lev>=3){
        ui->comboBox->setCurrentIndex(1);

    }else{
      ui->comboBox->setCurrentIndex(0);
    }

    ui->Line_Pass->setText("");
    ui->Line_Pass->setFocus();
    ui->label_4->hide();
}


void Form_Login::on_But_OK_clicked(){
    QString instr="";
    int obc=1;
    instr=ui->Line_Pass->text();
    obc=instr.compare(sys_l1_pass, Qt::CaseInsensitive);

    if(obc==0){
      //发送 用户密码已经验证正确的信号。。。接收信号的窗体是ffpmmainw.cpp
      emit Pass_Is_Ok();
    }else{
        ui->label_4->show();
        ui->Line_Pass->setText("");
        ui->Line_Pass->setFocus();
    }
}

//按键按下事件，无法获得方向键盘的值，
//监测按键按下，
void Form_Login::keyPressEvent(QKeyEvent *ev){
    //监测回车按键,回车按键模拟，点击 确定按键。
    if(ev->key()==Qt::Key_Enter){
        on_But_OK_clicked();
        return;
    }

    //取消的实体按键
    if(ev->key()==Qt::Key_Escape){
        on_But_ESC_clicked();
        return;
    }


//    }else if((ev->key()==Qt::Key_Right) |(ev->key()==Qt::Key_Left)|(ev->key()==Qt::Key_Up)|(ev->key()==Qt::Key_Down)){
//        QWidget::keyPressEvent(ev);  //其他的按键将被传送出去。
//       return;
//    }
//    else{
//        QWidget::keyPressEvent(ev);  //其他的按键将被传送出去。
//    }
}

Form_Login::~Form_Login()
{
    delete ui;
}
