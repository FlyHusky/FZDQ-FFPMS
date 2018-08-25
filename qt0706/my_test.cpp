/*
  窗体类：My_Test --此类用于模块的信息表格显示，按时刷新
  函数起名规则：首字母大写，单词下划线隔开。
  全局变量/对象起名规则：首个单次的首字母大写， 单词下划线隔开。。
 */

#include "my_test.h"
#include "ui_my_test.h"
#include <QStandardItemModel>
#include <QAbstractTableModel>
#include<QAbstractItemModel>
#include"ffpm.h"
#include <QTimer>
#include <time.h>
#include <QTime>
#include <QMessageBox>
#include "serial.h"  //加入串口 的 头文件
#include "falut.h"
#include "alarm.h"
#include "mybutton.h"

#include <QKeySequence>
#include <vector>      //vetor
#include<QKeyEvent>
#include<mybutton.h>

using namespace std;

extern   vector<Falut> vector_falut;
extern   vector<Alarm> vector_alarm;

extern quint16 Bj_Pre_Ct; //报警点数。
extern quint16 Fa_Pre_Ct;//故障点数
extern qint16 Tatol_Alarm_Ct;
extern  qint16 Tatol_Falut_Ct;

//当前的Ui界面。
extern quint8 Cur_Ui_Page;

extern QString FormatFloat(float f);

QAbstractItemModel *qtm;

//引用ffpmmainw中的消防电压模块对象数组。
extern  FFPM *Fpms[100];
extern  unsigned int Fpm_Total;


QTimer *My_timer;    //用于定时刷新的定时器
quint8 Second_ct=0;  //1秒定时累加单元
extern quint8 Page_tatol; //表格显示总的页面数量,暂定3个
quint8 Page_cur=0;   //当前页面从0开始，0,1,2

bool Auto_fanye=true;

QPushButton *But_Fanye;  //手动自动翻页选择按钮
QPalette qp_hei1;
QPalette qp_bai1;

My_Test::My_Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::My_Test)
{
    printf("enter my_test init() \n");
     ui->setupUi(this);
     quint8 i;
     QString s;

     printf("my_test init()   67 \n");
    // ui->pushButton=new MyButton();
    // ui->pushButton_2=new MyButton();
     //ui->pushButton_3=new MyButton();
     printf("my_test init()   71 \n");
    // qp_bai1=But_Fanye->palette();
     //qp_bai1.setColor(QPalette::Button,Qt::white);
     //qp_bai1.setColor(QPalette::ButtonText,Qt::black);
     printf("my_test init()   75 \n");

     //But_Fanye=new MyButton();
     //But_Fanye->setText(tr("自动翻页"));

     //But_Fanye->setFont(QFont("黑体",20,10,false));
     //But_Fanye->setPalette(qp_bai1);
     //ui->horizontalLayout->addWidget(But_Fanye);
    // But_Fanye->repaint();


     printf("my_test init()   84 \n");
     //ui->pushButton->hide();
     //ui->pushButton_2->hide();
     //ui->pushButton_3->hide();
     printf("my_test init()   88 \n");
     Auto_fanye=true;
    qtm=ui->tableWidget->model();
     printf("my_test init()   91 \n");
    ui->tableWidget->setColumnWidth(0,55);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(3,150);
    ui->tableWidget->setColumnWidth(4,155);
    ui->tableWidget->setColumnWidth(5,70);
    ui->tableWidget->setColumnWidth(6,75);

     //显示行号，1---10，并设置文本的位置
     for(i=0;i<10;i++){
        s=QString::number(i+1,10);
       qtm->setData(qtm->index(i,0),s,Qt::DisplayRole);

       s=s.append("ALE");
       qtm->setData(qtm->index(i,1),s,Qt::DisplayRole);

       s="999/999/999";
       qtm->setData(qtm->index(i,2),s,Qt::DisplayRole);

       s="999/999/999";
       qtm->setData(qtm->index(i,3),s,Qt::DisplayRole);

       s="999/999/999";
       qtm->setData(qtm->index(i,4),s,Qt::DisplayRole);

       s=tr("检测中");
       qtm->setData(qtm->index(i,5),s,Qt::DisplayRole);

       s=tr("等待");
       qtm->setData(qtm->index(i,6),s,Qt::DisplayRole);

       // qt1[i]=ui->tableWidget->itemAt(i,0);
        //设置显示文本的   void My_Up_Down_Key(QKeyEvent *);位置，在表格的中间
       ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,0)->setTextColor(Qt::blue);
       ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->item(i,6)->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->setRowHeight(i,32);
     }
          printf("my_test init()   153 \n");
     //设置表格不可被编辑,seteanbale 控件变灰色。
   //  ui->tableWidget->setEnabled(false);
     //设置表格不可被选中，代码如下，但单元格，仍然可以活得光标框,和键盘输入。
     ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
     My_timer = new QTimer(this);
     connect(My_timer, SIGNAL(timeout()), this, SLOT(My_Timer_Out()));
     My_timer->start(1000);
     Second_ct=0;
     printf("my_test init()   144 \n");
}

My_Test::~My_Test()
{
    delete ui;
}

//表格数据刷新函数
//用到的参数：Fpm_Total
void My_Test::Refresh_Table(quint8 cur_page){
    quint16 rti=0;
    quint16 rtk=0;
    QString rts;
    unsigned char alarm_sta;
    rti=cur_page*10; //0, 10, 20 30
    alarm_sta=0;

    rts=tr("当前报警点数:");
    rts.append(QString::number(vector_alarm.size() ));
    ui->label->setText(rts);

    rts=tr("当前故障点数:");
    rts.append(QString::number(vector_falut.size()));
    ui->label_2->setText(rts);

    for(rtk=0;rtk<10;rtk++){
        alarm_sta=0;
        if(rti>=Fpm_Total){
            qtm->setData(qtm->index(rtk,0),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,1),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,2),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,3),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,4),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,5),"" ,Qt::DisplayRole);
            qtm->setData(qtm->index(rtk,6),"" ,Qt::DisplayRole);
            continue;
        }
      rts=QString::number(rti+1,10);  //序号 1, 11, 21,31
      qtm->setData(qtm->index(rtk,0),rts,Qt::DisplayRole);

     // s=s.append("ALE");            //箱号
      qtm->setData(qtm->index(rtk,1),Fpms[rti]->name ,Qt::DisplayRole);
      //cur_data 以前是整数，现在改为浮点数，
      //电压电流显示原则，5位有效数（包含小数）
      //电压1.345V.

     // rts=QString::number(Fpms[rti]->cur_data[0],'f',1);

      rts=FormatFloat(Fpms[rti]->cur_data[0]);
      rts.append("/");

      //rts.append(QString::number(Fpms[rti]->cur_data[1]));

      rts.append(FormatFloat(Fpms[rti]->cur_data[1]));
      rts.append("/");

     //rts.append(QString::number(Fpms[rti]->cur_data[2]));

      rts.append(FormatFloat(Fpms[rti]->cur_data[2]));
      qtm->setData(qtm->index(rtk,2),rts,Qt::DisplayRole);   //电压1

      if(Fpms[rti]->v1_alarm_pop!=0){
          ui->tableWidget->item(rtk,2)->setTextColor(Qt::red);
          alarm_sta=1;
      }else{
          ui->tableWidget->item(rtk,2)->setTextColor(Qt::black);
      }

      //第2路电压显示
      //kind 模块类型 1=M3-V2   2=M3-V2A  3=M3-V3  4=M3-VA  5=M2-V6  6=M2-V9
      //如果第2部分是电压显示。。
    if(Fpms[rti]->kind>=3 || Fpms[rti]->kind==5 || Fpms[rti]->kind==6)
    {
        //rts=QString::number(Fpms[rti]->cur_data[3]);
        rts=FormatFloat(Fpms[rti]->cur_data[3]);
        rts.append("/");

        //rts.append(QString::number(Fpms[rti]->cur_data[4]));
          rts.append(FormatFloat(Fpms[rti]->cur_data[4]));

          rts.append("/");

       // rts.append(QString::number(Fpms[rti]->cur_data[5]));
          rts.append(FormatFloat(Fpms[rti]->cur_data[5]));


        if(Fpms[rti]->v2_alarm_pop!=0){
            ui->tableWidget->item(rtk,3)->setTextColor(Qt::red);
              alarm_sta=1;
        }else{
            ui->tableWidget->item(rtk,3)->setTextColor(Qt::black);
        }

    }else{ //如果不是电流，则直接置---，  模块电流只会在第3部分显示。
          rts=tr("---/---/---");
          ui->tableWidget->item(rtk,3)->setTextColor(Qt::black);
    }
     qtm->setData(qtm->index(rtk,3),rts,Qt::DisplayRole); //电压2


      //第3部分显示。应区分电压3或者电流     //kind 模块类型 1=M3-V2   2=M3-V2A  3=M3-V3  4=M3-VA  5=M2-V6  6=M2-V9
      //先判断显示电压。
      if(Fpms[rti]->kind==3 ||  Fpms[rti]->kind==6){
          rts=FormatFloat(Fpms[rti]->cur_data[6]);
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[7]));
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[8]));
          rts.append("V");
       //在判断显示电流-V2A。
      }else if(Fpms[rti]->kind==2){
          rts=FormatFloat(Fpms[rti]->cur_data[6]);
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[7]));
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[8]));
          rts.append("A");
      }else if(Fpms[rti]->kind==4){
          rts=FormatFloat(Fpms[rti]->cur_data[3]);
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[4]));
          rts.append("/");
          rts.append(FormatFloat(Fpms[rti]->cur_data[5]));
          rts.append("A");
      }
      //最后的置---
      else{
         rts=tr("---/---/---");
      }

      qtm->setData(qtm->index(rtk,4),rts,Qt::DisplayRole);
      if(Fpms[rti]->va_alarm_pop!=0){
          ui->tableWidget->item(rtk,4)->setTextColor(Qt::red);
            alarm_sta=1;
      }else{
          ui->tableWidget->item(rtk,4)->setTextColor(Qt::black);
      }

      if( alarm_sta==0){
          if(Fpms[rti]->comm_sta==1){ //通讯正常。
              rts=tr("正常");
              ui->tableWidget->item(rtk,5)->setTextColor(Qt::blue);
          }else{
              rts=tr("---");
              ui->tableWidget->item(rtk,5)->setTextColor(Qt::black);
          }
      }
      else if(alarm_sta==1) {
          rts=tr("报警");
          ui->tableWidget->item(rtk,5)->setTextColor(Qt::red);
      }

         qtm->setData(qtm->index(rtk,5),rts,Qt::DisplayRole);

     //如果模块通讯异常，并且未报警状态，则清零所有的值。
     if (Fpms[rti]->comm_sta==2) {
             rts=tr("---/---/---");
             qtm->setData(qtm->index(rtk,2),rts,Qt::DisplayRole);
             qtm->setData(qtm->index(rtk,3),rts,Qt::DisplayRole);
             qtm->setData(qtm->index(rtk,4),rts,Qt::DisplayRole);
              ui->tableWidget->item(rtk,2)->setTextColor(Qt::black);
             ui->tableWidget->item(rtk,3)->setTextColor(Qt::black);
              ui->tableWidget->item(rtk,4)->setTextColor(Qt::black);
        }

      //通讯状态 0=通讯等待  1=通讯正常   2=通讯异常   3=通讯校验
     if( Fpms[rti]->comm_sta==1){
          rts=tr("正常");
          ui->tableWidget->item(rtk,6)->setTextColor(Qt::blue);
     }else if (Fpms[rti]->comm_sta==3) {
         rts=tr("校验错");
         ui->tableWidget->item(rtk,6)->setTextColor(Qt::black);
     }else if (Fpms[rti]->comm_sta==2) {

         rts=tr("未连接");
         ui->tableWidget->item(rtk,6)->setTextColor(Qt::red);

     }else{
         rts=tr("等待");
         ui->tableWidget->item(rtk,6)->setTextColor(Qt::black);
     }
     qtm->setData(qtm->index(rtk,6),rts,Qt::DisplayRole);

      rti++;
    }
}

//定时定时1秒后溢出进入函数，2秒数据刷新，10秒翻页。
void My_Test ::  My_Timer_Out(){
        if(Cur_Ui_Page!=1 ){
            return;
        }
        Second_ct=Second_ct+1;
        //暂定10秒定时翻页，后期改为变量
        if(10<=Second_ct){ //翻页
            if(Auto_fanye){
                Page_cur=Page_cur+1;
                if(Page_cur>=Page_tatol){
                    Page_cur=0;//翻页复位。
                }
            }
           Second_ct=0;
           //界面刷新。
           Refresh_Table(Page_cur);

        }else{
            if ((Second_ct % 2) == 0){ //定时2秒刷新
                 Refresh_Table(Page_cur);
            }
        }
}


//监测按键按下，  下一页，对应实体按键 下方向箭头。
//                 上一页 对应实体按键 上方向箭头。
void My_Test::keyPressEvent(QKeyEvent *ev){
    //监测回车按键,回车按键模拟，点击 确定按键。
    if(ev->key()==Qt::Key_Up){
        on_pushButton_clicked();
        return;
    }

    //取消的实体按键
    if(ev->key()==Qt::Key_Down){
        on_pushButton_2_clicked();
        return;
    }
}

void My_Test::My_Up_Down_Key(quint8  ev){
    if(ev==5){
        on_pushButton_clicked();
    }
    else if(ev==10){
        on_pushButton_2_clicked();
    }
}

//上一页，翻页按钮，自动翻页状态下，翻到上一页，清零Second_ct
//手动状态下，直接翻到上一页。
void My_Test::on_pushButton_clicked()
{
    if(Page_cur<=0){
        Second_ct=0;
        return ;
    }

    Page_cur=Page_cur-1;
    Refresh_Table(Page_cur);
    Second_ct=1;
}



//自动翻页 停止，开始
void My_Test::on_pushButton_3_clicked()
{
    if(Auto_fanye){
       Auto_fanye=false;
       ui->pushButton_3->setText(tr("手动翻页"));
    }else{
        Auto_fanye=true;
        ui->pushButton_3->setText(tr("自动翻页"));
    }
}

//下一页
void My_Test::on_pushButton_2_clicked()
{
    //0,1,2   3
   quint8 op2;
   op2=Page_tatol-1;

    if(Page_cur>=op2){
        Second_ct=0;
        return;
    }
     Page_cur=Page_cur+1;
     Refresh_Table(Page_cur);
     Second_ct=1;
}



//void My_Test::keyPressEvent(QKeyEvent *ev){
//    if(ev->key()==Qt::Key_Enter){

//      //emit key_enter_presss();
////        QPoint qp=QApplication::focusWidget()->pos();
////        QMouseEvent  me(QEvent::MouseButtonPress,qp,Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
////        QMouseEvent  me2(QEvent::MouseButtonRelease,qp,Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);

////        QCursor::setPos(qp);

////        QApplication::sendEvent( QApplication::focusWidget(), &me);
////        QApplication::sendEvent( QApplication::focusWidget(), &me2);

////        return ;
//  QMessageBox msgBox;

//        msgBox.setText(tr("ssxx enter press!!!"));
//        msgBox.setGeometry(350,180,150,80);
//        msgBox.edxec();

//    }else{
//        QWidget::keyPressEvent(ev);  //其他的按键将被传送出去。
//    }
//}
