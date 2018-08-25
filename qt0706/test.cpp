#include "test.h"
#include "ui_test.h"
#include <QMessageBox>
#include <QtGui>
#include <QTimer>
#include <time.h>
#include <QTime>
#include <QString>
#include "form_baojin.h" //报警窗体。
#include "my_test.h"     //信息表格个窗体
//Form_Baojin  *form_bj1;
// My_Test     *form_xx;

 //页面标记变量
 //实时信息=1,当前报警=2,当前故障=3,历史报警=4,参数设置=5,系统信息=6,使用帮助=7
//qint8 Cur_Ui_Page=1;


//导航栏按钮
//QPushButton *But_SSXX;
//QPushButton *But_DQBJ;
//QPushButton *But_DQGZ;
//QPushButton *But_LSBJ;
//QPushButton *But_XTXX;
//QPushButton *But_CSSZ;
//QPushButton *But_SYBZ;

Test::Test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    this->setWindowState(Qt::WindowFullScreen);
    ui->setupUi(this);

//    form_bj1=new Form_Baojin(this);
//    form_bj1->setGeometry(0,40,800,410);
//    form_bj1->move(0,50);
//    form_bj1->hide();

//    form_xx=new My_Test(this);
//    form_xx->setGeometry(0,40,800,410);
//    ui->centralwidget->hide();
//    form_xx->show();

//    But_SSXX=new QPushButton();
//    But_SSXX->setText(tr("  实时信息  "));
//    But_SSXX->setGeometry(0,0,20,100);
//    But_SSXX->move(0,0);
//    But_SSXX->setFont(QFont("黑体",20,10,false));

//    But_DQBJ=new QPushButton();
//    But_DQBJ->setText(tr("  当前报警  "));
//    But_DQBJ->move(10,0);
//    But_DQBJ->setFont(QFont("黑体",20,10,false));

//    But_DQGZ=new QPushButton();
//    But_DQGZ->setText(tr("  当前故障  "));
//    But_DQGZ->move(200,0);
//    But_DQGZ->setFont(QFont("黑体",20,10,false));

//    But_LSBJ=new QPushButton();
//    But_LSBJ->setText(tr("  历史报警  "));
//    But_LSBJ->move(200,0);
//    But_LSBJ->setFont(QFont("黑体",20,10,false));

//    But_XTXX=new QPushButton();
//    But_XTXX->setText(tr("  系统信息  "));
//    But_XTXX->move(200,0);
//    But_XTXX->setFont(QFont("黑体",20,10,false));

//    But_CSSZ=new QPushButton();
//    But_CSSZ->setText(tr(" 参数设置 "));
//    But_CSSZ->move(200,0);
//    But_CSSZ->setFont(QFont("黑体",20,10,false));

//    But_SYBZ=new QPushButton();
//    But_SYBZ->setText(tr(" 使用帮助 "));
//    But_SYBZ->move(200,0);
//    But_SYBZ->setFont(QFont("黑体",20,10,false));



//    ui->toolBar->addWidget(But_SSXX);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_DQBJ);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_DQGZ);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_LSBJ);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_CSSZ);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_XTXX);
//    ui->toolBar->addSeparator();

//    ui->toolBar->addWidget(But_SYBZ);
//    ui->toolBar->addSeparator();


//    connect(But_SSXX,SIGNAL(clicked()),this,SLOT(But_SSXX_clicked()));
//    connect(But_DQBJ,SIGNAL(clicked()),this,SLOT(But_DQBJ_clicked()));
//    connect(But_DQGZ,SIGNAL(clicked()),this,SLOT(But_DQGZ_clicked()));
//    connect(But_LSBJ,SIGNAL(clicked()),this,SLOT(But_LSBJ_clicked()));
//    connect(But_XTXX,SIGNAL(clicked()),this,SLOT(But_XTXX_clicked()));
//    connect(But_CSSZ,SIGNAL(clicked()),this,SLOT(But_CSSZ_clicked()));
//    connect(But_SYBZ,SIGNAL(clicked()),this,SLOT(But_SYBZ_clicked()));
    //    void   But_LSBJ_clicked();
    //    void   But_XTXX_clicked();
    //    void   But_CSSZ_clicked();
    //    void   But_SYBZ_clicked();

}

Test::~Test()
{
    delete ui;
}

void Test::on_pushButton_clicked()
{
    QMessageBox msgBox;
        msgBox.setText("hahahha");
        msgBox.setGeometry(350,180,150,80);
       msgBox.exec();
}

////实时信息
//void Test::But_SSXX_clicked(){
////        QMessageBox msgBox;
////        msgBox.setText(tr("实时信息"));
////        msgBox.setGeometry(350,180,150,80);
////        msgBox.exec();
//    if(Cur_Ui_Page==2){
//        form_bj1->hide();
//        form_xx->show();
//        Cur_Ui_Page=1;
//    }
//}

////当前报警
//void  Test:: But_DQBJ_clicked(){
//    if(Cur_Ui_Page==1){
//        form_xx->hide();
//        form_bj1->setAutoFillBackground(true);
//        form_bj1->show();
//        form_bj1->move(0,50);
//        Cur_Ui_Page=2;
//    }

//}

////历史报警
//void  Test:: But_LSBJ_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("历史报警"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}

////当前故障
//void   Test:: But_DQGZ_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("当前故障"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}

// //参数设置
//void   Test::But_CSSZ_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("参数设置"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}

////系统信息
//void  Test::But_XTXX_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("系统信息"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}

////使用帮助
//void  Test:: But_SYBZ_clicked(){
//    QMessageBox msgBox;
//    msgBox.setText(tr("使用帮助"));
//    msgBox.setGeometry(350,180,150,80);
//    msgBox.exec();
//}

