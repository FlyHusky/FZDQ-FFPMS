#include "form_baojin.h"
#include "ui_form_baojin.h"
#include<QAbstractItemModel>
#include"ffpm.h"
#include <QTimer>
#include "alarm.h"
#include <vector>      //vetor

#include <cstring>
#include <stdio.h>
#include <QTextCodec>
#include<QMessageBox>
#include<QKeyEvent>


#include "serial.h"  //加入串口 的 头文件

using namespace std;
extern    vector<Alarm> vector_alarm;

//当前的Ui界面。
extern quint8 Cur_Ui_Page;

//页面编号1,2,3,4.。。。。。。
int bj_page_cur=1;

//总页面数量。
int bj_page_total=1;

//起始地址
int bj_id_stard=1;

//结束地址。
int bj_id_end=10;




extern FFPM *Fpms[500];

//报警点数，先前值。
quint16 Bj_Pre_Ct=0;

QAbstractItemModel *qtm_bj;
QTimer *timer_bj;
#define RS232_PRINT_NAME "/dev/ttymxc6"
int RS232_Printer=0; //RS232 打印机接口

quint8 gbk[40];
int  len;



Form_Baojin::Form_Baojin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Baojin)
{
    ui->setupUi(this);

    quint8 i;

    ui->te1->hide();
    ui->te2->hide();

    //设置表格的尺寸。
    ui->tableWidget->setGeometry(10,5,780,361);
    //设置表格10行6列
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(6);
    qtm_bj=ui->tableWidget->model();
    ui->tableWidget->setColumnWidth(0,80);    //编号
    ui->tableWidget->setColumnWidth(1,130);
    ui->tableWidget->setColumnWidth(2,120);  //         40
    ui->tableWidget->setColumnWidth(3,120);  //120      40  80
    ui->tableWidget->setColumnWidth(4,185);  //245-150---95  40 55
    ui->tableWidget->setColumnWidth(5,140);

  //初始化表格，注意一定要先给表格单元赋值，然后在设置单元格属性，否则报错。
for(i=0;i<10;i++){
      qtm_bj->setData(qtm_bj->index(i,0),"",Qt::DisplayRole);
      qtm_bj->setData(qtm_bj->index(i,1),"",Qt::DisplayRole);
      qtm_bj->setData(qtm_bj->index(i,2),"",Qt::DisplayRole);
      qtm_bj->setData(qtm_bj->index(i,3),"",Qt::DisplayRole);
      qtm_bj->setData(qtm_bj->index(i,4),"",Qt::DisplayRole);
      qtm_bj->setData(qtm_bj->index(i,5),"",Qt::DisplayRole);

      // qt1[i]=ui->tableWidget->itemAt(i,0);
       //设置显示文本的位置，在表格的中间
      ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,0)->setTextColor(Qt::blue);
      ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setRowHeight(i,32);
  }

      ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
      //定时器，定时50ms,在定时器内部，发送和接收 模块发过来的数据。。
       timer_bj = new QTimer(this);

      //绑定，将timeout 溢出信号，绑定到槽---很重要
      connect(timer_bj, SIGNAL(timeout()), this, SLOT(Form_Baojin_Timer_Out()));
      connect(ui->but_print_today,SIGNAL(clicked()),this,SLOT(But_Print_Today_Click()));
      connect(ui->but_print_all,SIGNAL(clicked()),this,SLOT(But_Print_All_Click()));

      timer_bj->start(2000);  //定时器，定时2秒。

      RS232_Printer=openSerial(RS232_PRINT_NAME);    //打印机串口
}


void Form_Baojin::keyPressEvent(QKeyEvent *ev){
    //监测回车按键。。。
    if(ev->key()==Qt::Key_Enter){
        if(ui->but_print_all->hasFocus()){  //打印所有的报警信息。
               //printf("get enter key on printf all !!!\n");
               But_Print_All_Click();
        }

        if(ui->but_print_today->hasFocus()){ //打印今天的信息
               printf("get enter key on printf today !!!\n");
               But_Print_Today_Click();
        }

   }

}


//把打印今天报警信息，改为打印当前页面报警信息。
void Form_Baojin::But_Print_Today_Click(){
  QString sss;
  int rft;
  quint8 ssr[40];

    if(bj_page_total==0){
//        QMessageBox msgBox;
//         msgBox.setText(tr("当前无报警信息!"));
//        msgBox.setGeometry(350,180,150,80);
//        msgBox.exec();
    }

    vector<Alarm>::reverse_iterator fa;
      fa=vector_alarm.rbegin();
      fa=fa+bj_id_stard-1;

    rft=0;

    ui->te1->setText("");

  for(fa;fa!=vector_alarm.rend();fa++){
       QByteArray  bary;
      Alarm fau=*(fa);
     int ii,k;

      //接着打印“电压1欠压” 字符。
      Get_GBK_Array(fau.alarm_kind_str);
       write(RS232_Printer, &gbk,len+1);

     //接着打印值：
        ssr[0]=0x20;
        ssr[1]=0x20;
       write(RS232_Printer, &ssr,2);  //空格。


       bary=fau.value_str.toAscii();
       sss="";
       for(ii=0;ii<bary.size();ii++){
           k=bary[ii];
           ssr[ii]=k;
       }
      write(RS232_Printer, &ssr,bary.size());

      ssr[0]=0x0a;
      write(RS232_Printer, &ssr,1);  //打印一行。


     // s=QString::number(fau.fpm_id+1);
    sss= fau.fpm_name;
    sss.append(" ");
    sss.append( fau.date_str);
    sss.append(" ");
    sss.append(fau.time_str);
     //sss.append(" ");  电压1欠压。 GBK编码处理，暂不实现。

     bary=sss.toAscii();


     sss="";
     for(ii=0;ii<bary.size();ii++){
         k=bary[ii];
         ssr[ii]=k;
     }
    write(RS232_Printer, &ssr,bary.size());
    ssr[0]=0x0a;
    write(RS232_Printer, &ssr,1);  //打印一行。

    write(RS232_Printer, &ssr,1);  //打印一行。

       rft++;
       if(rft>=10){
           break;
       }
    }

  ssr[0]=0x1b;
  ssr[1]=0x4a;
  ssr[2]=0x1a;
  write(RS232_Printer, &ssr,3);  //走纸31行

  write(RS232_Printer, &ssr,3);  //走纸31行

}

void Form_Baojin::Get_GBK_Array(QString src){
    QString ss;
    int i;

    len=-1;

     for(i=0;i<src.size();i++){

         ss=src.at(i);

         if(ss.compare(tr("电"))==0){
             len++;
             gbk[len]=0xb5;
             len++;
             gbk[len]=0xe7;
         }else if(ss.compare(tr("压"))==0){
             len++;
             gbk[len]=0xd1;
             len++;
             gbk[len]=0xb9;
         }else if(ss.compare(tr("流"))==0){
             len++;
             gbk[len]=0xc1;
             len++;
             gbk[len]=0xf7;

         }else if(ss.compare(tr("欠"))==0){
             len++;
             gbk[len]=0xc7;
             len++;
             gbk[len]=0xb7;
         }else if(ss.compare(tr("过"))==0){
             len++;
             gbk[len]=0xb9;
             len++;
             gbk[len]=0xfd;
         }else {
             len++;
             QByteArray qar;
             qar=ss.toAscii();
             gbk[len]=qar.at(0);
         }
     }
}

//打印所有的报警信息
void Form_Baojin::But_Print_All_Click(){
    QString sss;
    int rft;
    quint8 ssr[40];

      if(bj_page_total==0){
//          QMessageBox msgBox;
//           msgBox.setText(tr("当前无报警信息!"));
//          msgBox.setGeometry(350,180,150,80);
//          msgBox.exec();
      }

      vector<Alarm>::reverse_iterator fa;
        fa=vector_alarm.rbegin();
       // fa=fa+bj_id_stard-1;

      rft=0;

      ui->te1->setText("");

    for(fa;fa!=vector_alarm.rend();fa++){
         QByteArray  bary;
        Alarm fau=*(fa);
       int ii,k;

        //接着打印“电压1欠压” 字符。
        Get_GBK_Array(fau.alarm_kind_str);
         write(RS232_Printer, &gbk,len+1);

       //接着打印值：
          ssr[0]=0x20;
          ssr[1]=0x20;
         write(RS232_Printer, &ssr,2);  //空格。


         bary=fau.value_str.toAscii();
         sss="";
         for(ii=0;ii<bary.size();ii++){
             k=bary[ii];
             ssr[ii]=k;
         }
        write(RS232_Printer, &ssr,bary.size());

        ssr[0]=0x0a;
        write(RS232_Printer, &ssr,1);  //打印一行。


       // s=QString::number(fau.fpm_id+1);
      sss= fau.fpm_name;
      sss.append(" ");
      sss.append( fau.date_str);
      sss.append(" ");
      sss.append(fau.time_str);
       //sss.append(" ");  电压1欠压。 GBK编码处理，暂不实现。

       bary=sss.toAscii();


       sss="";
       for(ii=0;ii<bary.size();ii++){
           k=bary[ii];
           ssr[ii]=k;
       }
      write(RS232_Printer, &ssr,bary.size());
      ssr[0]=0x0a;
      write(RS232_Printer, &ssr,1);  //打印一行。

      write(RS232_Printer, &ssr,1);  //打印一行。

     rft++;
        // if(rft>=10){
       //      break;
       //  }
      }

    ssr[0]=0x1b;
    ssr[1]=0x4a;
    ssr[2]=0x1a;
    write(RS232_Printer, &ssr,3);  //走纸31行

    write(RS232_Printer, &ssr,3);  //走纸31行
}

//打印函数，打印数据导成GBK编码，然后发送给打印机。
/*
void Form_Baojin::My_Printer(QString str){
    quint8 ssr[40];
    ssr[0]=0x1b;
    ssr[1]=0x4a;
    ssr[2]=0x1a;
    write(RS232_Printer, &ssr,3);  //走纸31行



     ssr[0]=0x0a;
     write(RS232_Printer, &ssr,1);

     ssr[0]=0x1b;
     ssr[1]=0x4a;
     ssr[2]=0x3a;
     write(RS232_Printer, &ssr,3);  //走纸

     ssr[0]=0x1b;
     ssr[1]=0x4a;
     ssr[2]=0x3a;
     write(RS232_Printer, &ssr,3); //走纸
}

*/


void Form_Baojin::Form_Baojin_Timer_Out(){

    if(Cur_Ui_Page!=2){ //如果不是当前活动界面，直接返回。
        return;
    }

    //1：首先判断，故障集合大小是否有变化。
    if(Bj_Pre_Ct==vector_alarm.size()){
        return; //如果没有变化，则直接推出。
    }


     Pages_Cac1(); //计算分页。
     Rfresh_Baojin_Table(bj_page_cur); //刷新显示

}


//查询，上一页按钮。
void Form_Baojin::on_pushButton_2_clicked()
{
    try{
        if(bj_page_total<=0){
            return;
        }

        if(bj_page_cur<=1){
            bj_page_cur=bj_page_total;

        }else{
         bj_page_cur=bj_page_cur-1;
        }

        Rfresh_Baojin_Table(bj_page_cur);
    }catch(...){

    }
}

//查询，下一页按钮。
void Form_Baojin::on_pushButton_3_clicked()
{
    try{
        if(bj_page_total<=0){
            return;
        }

        if(bj_page_cur>=bj_page_total){
               bj_page_cur=1;
        }else{
            bj_page_cur=bj_page_cur+1;
        }

        Rfresh_Baojin_Table(bj_page_cur);
    }catch(...){

    }
}


//分页计算，并对起始id赋值。
void Form_Baojin::Pages_Cac1(){

   Bj_Pre_Ct= vector_alarm.size() ;

     if(Bj_Pre_Ct==0){
          bj_page_cur=0;
         //总页面数量。
          bj_page_total=0;
          return;
     }

    bj_page_cur=1; //当前界面=1
    bj_id_stard=1; //开始的id号。


     //确定 总分页数量
     bj_page_total=Bj_Pre_Ct / 10;
     if(Bj_Pre_Ct % 10){
         bj_page_total++;
     }

     if(bj_page_total>1){
        bj_id_end=10;
     }else{
        bj_id_end=Bj_Pre_Ct;  //修正id_end 的值。
     }
}

//显示指定页面page范围地址的数据。
void Form_Baojin::Rfresh_Baojin_Table(int m_page){
        quint8 rft;
        QString s;
        //1--先清除前十行的数据。
        for(rft=0;rft<10;rft++){
            qtm_bj->setData(qtm_bj->index(rft,0),"",Qt::DisplayRole);
            qtm_bj->setData(qtm_bj->index(rft,1),"",Qt::DisplayRole);
            qtm_bj->setData(qtm_bj->index(rft,2),"",Qt::DisplayRole);
            qtm_bj->setData(qtm_bj->index(rft,3),"",Qt::DisplayRole);
            qtm_bj->setData(qtm_bj->index(rft,4),"",Qt::DisplayRole);
            qtm_bj->setData(qtm_bj->index(rft,5),"",Qt::DisplayRole);
        }

        if(bj_page_total==0){
            ui->label_2->setText(tr("当报警点数：0"));
            return ;  //如果总页面数量为0,则直接退出。
        }

        if(m_page>bj_page_total){
            m_page=1;
        }

        //根据m_page的值，计算id start end。
        bj_id_stard= (m_page-1)*10 + 1;  // 1,   11,  21
        bj_id_end=bj_id_stard+9;        //10,    20,  30

        if(bj_id_end>Bj_Pre_Ct){
             bj_id_end=Bj_Pre_Ct;    //修正fau_id_end
        }

        QString strll;
        strll=tr("当前第");
        strll.append(QString::number(bj_id_stard));
        strll.append("-");
        strll.append(QString::number(bj_id_end));
        strll.append(tr("条，总计共:"));
        strll.append(QString::number(Bj_Pre_Ct));
        strll.append(tr("条"));
        ui->label_2->setText(strll);

     vector<Alarm>::reverse_iterator fa;
       fa=vector_alarm.rbegin();         //fa=vector_falut.begin();
       fa=fa+bj_id_stard-1;
       rft=0;

   for(fa;fa!=vector_alarm.rend();fa++){
       Alarm fau=*(fa);
       s=QString::number(fau.fpm_id);
       qtm_bj->setData(qtm_bj->index(rft,0),s,Qt::DisplayRole);
       qtm_bj->setData(qtm_bj->index(rft,1),fau.fpm_name,Qt::DisplayRole);
       qtm_bj->setData(qtm_bj->index(rft,2),fau.date_str,Qt::DisplayRole);
       qtm_bj->setData(qtm_bj->index(rft,3),fau.time_str,Qt::DisplayRole);
       qtm_bj->setData(qtm_bj->index(rft,5),fau.value_str,Qt::DisplayRole);
       qtm_bj->setData(qtm_bj->index(rft,4),fau.alarm_kind_str,Qt::DisplayRole);

            rft++;
            if(rft>=10){
                break;
            }
        }

}

void Form_Baojin:: Bj_Up_Down_Key(quint8 ev){
    if(ev==5){
        on_pushButton_2_clicked();
    }else if(ev==10){
        on_pushButton_3_clicked();
    }
}





Form_Baojin::~Form_Baojin()
{
    delete ui;
}


//QByteArray temptoascii ;  //字节数组
//QString id_print;
//QString  strtext;
//QByteArray  temp2toascii;

//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK2312"));
//QTextCodec *gbkcode=QTextCodec::codecForName("UTF-8");
//QTextCodec::setCodecForCStrings(gbkcode);



//id_print=tr("我是你大爷");

//// id_print="ABCDEFGHIJKLMN";

////1：将包含有汉字的字符串，转换为ASCII码字节数组。
//temptoascii= id_print.toAscii();

////2：定义一个字符指针，指向一个字符数组。
//char *data_1 = new char[temptoascii.size()];

////3：字符串拷贝。将byte数组导成char数组。
//strcpy(data_1 , temptoascii.data());

////4：调用fromLocal8Bit函数
//strtext = QString::fromLocal8Bit(data_1);

////5：在将strtext 导成ascii码。
//temp2toascii=strtext.toAscii();
////经调试后，得知，temp2toascii 数组内保存的就是 gbk的 编码。后面的代码都可以不要了。


//str="c8|ba|c2|a5|33|b2|e3|d6|f7|c5|e4";

//QStringList list2 = str.split("|", QString::SkipEmptyParts);

//int i;
//bool b;
//for(i=0;i<list2.size();i++){
//    ssr[i] =list2.at(i).toInt();

//}


//quint8 ssr[20];
// ss="";
//  for(i=1;i<=len;i++){
//      ss.append(QString::number(ssr[i],16));
//      ss.append(" ");
//  }
//  ui->te2->append(ss);



