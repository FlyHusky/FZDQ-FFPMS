#include "form_set_pra.h"
#include "ui_form_set_pra.h"
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlDatabase>

#include <QProcess>
#include <QKeyEvent>
#include <QTime>
#include <QDate>


extern QSqlDatabase  qdb;

extern bool Sys_Debug_State;


extern qint16 Fpm_Total ;   //消防电源模块报警总数

extern unsigned int Comm_Fail_Max; //通讯失连次数。

Form_Set_Pra::Form_Set_Pra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Set_Pra)
{
        QTime qt1;
        QDate qd1;
        ui->setupUi(this);
        this->setGeometry(0,0,800,410);
        ui->tabWidget->setGeometry(5,5,790,400);

        connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Xiugai_Click()));
        connect(ui->But_sj,SIGNAL(clicked()),this,SLOT(But_sj_Click()));
        ui->label_3->hide();

        ui->lineEdit->setText(QString::number(Fpm_Total));
        ui->lineEdit_2->setText(QString::number(Comm_Fail_Max));

        ui->lineEdit->setFocus();

        qt1=QTime::currentTime();
        qd1=QDate::currentDate();

         ui->Le_year->setText(QString::number(qd1.year()));
         ui->Le_mon->setText(QString::number(qd1.month()));
         ui->Le_day->setText(QString::number(qd1.day()));

         ui->Le_time->setText(QString::number(qt1.hour()));
         ui->Le_min->setText(QString::number(qt1.minute()));
}

   void  Form_Set_Pra:: keyPressEvent(QKeyEvent *ev){
       if(ev->key()==Qt::Key_Enter){
           if(ui->pushButton->hasFocus()){
                  Xiugai_Click();
           }else if(ui->pushButton_8->hasFocus()){
               on_pushButton_8_clicked();
           }else if(ui->But_sj->hasFocus()){
               But_sj_Click();
           }else{
               //  Xiugai_Click();
           }
       }
   }
//修改节点数量，同学失连次数
void Form_Set_Pra:: Xiugai_Click(){
    qint16 mt_ct=0; //节点总数量
    qint16 ms_ct=0; //通讯失连值

    bool bo=false;
    bool b1=false;
    mt_ct=ui->lineEdit->text().toInt(&bo,10);
    ms_ct=ui->lineEdit_2->text().toInt(&b1,10);

    if(bo==false){
        ui->label_3->setText(tr("模块总数量值,不是有效数字，请重新输入！"));
        ui->label_3->show();
        ui->lineEdit->setText("");
        ui->lineEdit->setFocus();
        return;
    }

    if(b1==false){
        ui->label_3->setText(tr("通讯失连值,不在有效的范围内，请重新输入！"));
        ui->label_3->show();
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setFocus();
        return;
    }

    if(mt_ct<1 || mt_ct>500){
        ui->label_3->setText(tr(" 模块总数量值,不在有效的范围内，请重新输入！"));
        ui->label_3->show();
        ui->lineEdit->setText("");
        ui->lineEdit->setFocus();
       return;
    }

    if(ms_ct<1 || ms_ct>100){
        ui->label_3->setText(tr(" 通讯失连值,不在有效的范围内，请重新输入！"));
        ui->label_3->show();
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setFocus();
       return;
    }

    if (mt_ct==Fpm_Total && ms_ct==Comm_Fail_Max){
        return;
    }


    if(Change_Fpms_Ct(mt_ct,ms_ct)){
        QString pro="/opt/ffpm_start.sh";
        QProcess::startDetached(pro);
        QApplication::exit();
    }else{
        ui->label_3->setText(tr(" 修改数据库操作失败，请检查数据库！"));
        ui->label_3->show();
    }

}

Form_Set_Pra::~Form_Set_Pra()
{
    delete ui;
}

//修改数据中，模块的总数量。
bool Form_Set_Pra:: Change_Fpms_Ct(quint16 t_ct, quint16 s_ct){
    try{
        if(qdb.isOpen()){ //如果数据连接已经建立好。
            QSqlQuery query(qdb);
            QString sql_str="update sys_main_info set sys_node_ct=";
            sql_str.append(QString::number(t_ct));
            sql_str.append(", sys_comm_fail_ct=");
             sql_str.append(QString::number(s_ct));
             bool bo=false;
            bo= query.exec(sql_str);
            return bo;
        }
    }catch(...){
        return false;
    }
    return true;
}

//程序升级按钮，改为修改保存时间的按钮。
void Form_Set_Pra::But_sj_Click(){
    QString date_str;
    QString time_str;
    date_str="date -s ";
    date_str.append(ui->Le_year->text());
    date_str.append("-");
    date_str.append(ui->Le_mon->text());
    date_str.append("-");
    date_str.append(ui->Le_day->text());
    QProcess::startDetached(date_str);

    time_str="date -s ";
    time_str.append(ui->Le_time->text());
    time_str.append(":");
    time_str.append(ui->Le_min->text());
    time_str.append(":00");


    QProcess::startDetached(time_str);
    //hwclock -w 把系统时间写到硬件  -s 是硬件到系统。
    QProcess::startDetached("hwclock -w");
}

//查看通信数据
void Form_Set_Pra::on_pushButton_8_clicked()
{
    if(Sys_Debug_State==true){
            Sys_Debug_State=false;
//            QMessageBox msgBox;
//            msgBox.setText(tr("通信调试已关闭！"));
//            msgBox.setGeometry(350,180,150,80);
//            msgBox.exec();
              ui->label_8->show();
              ui->label_8->setText(tr("通信调试已关闭！"));
    }else{
           Sys_Debug_State=true;
//           QMessageBox msgBox;
//           msgBox.setText(tr("通信调试已开启，请点击 |系统自检| 进入！"));
//           msgBox.setGeometry(350,180,150,80);
//           msgBox.exec();

           ui->label_8->show();
           ui->label_8->setText(tr("通信调试已开启，请进入系统自检界面使用！"));
    }
}

////用户点击修改按钮。
////首先检查输入数据的合法性，
////节点数量不能大于500,不能小于1个。
void Form_Set_Pra::on_pushButton_clicked()
{
 Xiugai_Click();
}
