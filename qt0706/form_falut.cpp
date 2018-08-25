#include "form_falut.h"
#include "ui_form_falut.h"
#include<QAbstractItemModel>
#include"ffpm.h"
#include <QTimer>
#include <time.h>
#include <QTime>
#include <QMessageBox>

#include "falut.h"
#include <vector>      //vetor
using namespace std;
extern   vector<Falut> vector_falut;

//当前的Ui界面。
extern quint8 Cur_Ui_Page;

//总的故障点数，先前值，历史的值。
quint16 Fa_Pre_Ct=0;

//页面编号1,2,3,4.。。。。。。
int fa_page_cur=1;

//总页面数量。
int fa_page_total=1;

//起始地址
int fa_id_stard=1;

//结束地址。
int fa_id_end=10;






QAbstractItemModel *qtm1;

QTimer *timer_fa;

Form_Falut::Form_Falut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Falut)
{
    ui->setupUi(this);

    quint8 i;
    QString s;

    //设置表格的尺寸。
    ui->tableWidget->setGeometry(10,5,780,361);

    //设置表格10行5列
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(5);

    qtm1=ui->tableWidget->model();

    ui->tableWidget->setColumnWidth(0,80);
    ui->tableWidget->setColumnWidth(1,130);
    ui->tableWidget->setColumnWidth(2,160);
    ui->tableWidget->setColumnWidth(3,160);
    ui->tableWidget->setColumnWidth(4,245);

  //初始化表格，注意一定要先给表格单元赋值，然后在设置单元格属性，否则报错。
for(i=0;i<10;i++){
      s=QString::number(i+1,10);
      qtm1->setData(qtm1->index(i,0),"",Qt::DisplayRole);
      s=s.append("ALE");
      qtm1->setData(qtm1->index(i,1),"",Qt::DisplayRole);
      s="ALE";
      qtm1->setData(qtm1->index(i,2),"",Qt::DisplayRole);
      s="ALE";
      qtm1->setData(qtm1->index(i,3),"",Qt::DisplayRole);
      s="ALE";
      qtm1->setData(qtm1->index(i,4),"",Qt::DisplayRole);

      // qt1[i]=ui->tableWidget->itemAt(i,0);
       //设置显示文本的位置，在表格的中间
      ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,0)->setTextColor(Qt::blue);

      ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setRowHeight(i,32);

  }

      ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

      //当前故障显示界面。如果为活动界面，则每2秒刷，看是否有新的故障产生，如果有则刷新表格，没有就不刷新
      //表格按时间倒序排列，即最故障发生时间最近的排到最前面

      //定时器，定时50ms,在定时器内部，发送和接收 模块发过来的数据。。
       timer_fa = new QTimer(this);
      //绑定，将timeout 溢出信号，绑定到槽---很重要
      connect(timer_fa, SIGNAL(timeout()), this, SLOT(Form_Falut_Timer_Out()));
      timer_fa->start(2000);  //定时器，定时2秒。

      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(FA_Pre_Page_Click()));
      connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(FA_Next_Page_Click()));



}

Form_Falut::~Form_Falut()
{
    delete ui;
}

// 定时器溢出，尝试，是否可以取消这个定时器，或者，在此页面隐藏后，关闭定时器，而
// 在页面处于显示状态时，打开定时器，这样可以减少资源的消耗。

void Form_Falut ::Form_Falut_Timer_Out(){

    if(Cur_Ui_Page!=3){ //如果不是当前活动界面，直接返回。
        return;
    }

    //1：首先判断，故障集合大小是否有变化。
    if(Fa_Pre_Ct==vector_falut.size()){
        return; //如果没有变化，则直接推出。
    }

    //Fa_Pre_Ct=vector_falut.size();
     Pages_Cac(); //计算分页。
     Rfresh_Falut_Table(fa_page_cur); //刷新显示
}

//
//显示指定页面page范围地址的数据。
void Form_Falut::Rfresh_Falut_Table(int m_page){


        quint8 rft;
        QString s;

        //1--先清除前十行的数据。
        for(rft=0;rft<10;rft++){
            qtm1->setData(qtm1->index(rft,0),"",Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,1),"",Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,2),"",Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,3),"",Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,4),"",Qt::DisplayRole);
        }

        if(fa_page_total==0){
            ui->label_2->setText(tr("当故障数量：0"));
            return ;  //如果总页面数量为0,则直接退出。
        }

        if(m_page>fa_page_total){
            m_page=1;
        }

        //根据m_page的值，计算id start end。

        fa_id_stard= (m_page-1)*10 + 1;  // 1,   11,  21
        fa_id_end=fa_id_stard+9;
        //void Fa_Up_Down_Key();
     //10,    20,  30

        if(fa_id_end>Fa_Pre_Ct){
             fa_id_end=Fa_Pre_Ct;    //修正fau_id_end
        }

        QString strll;
        strll=tr("当前第");
        strll.append(QString::number(fa_id_stard));
        strll.append("-");
        strll.append(QString::number(fa_id_end));
        strll.append(tr("条，总计共:"));
        strll.append(QString::number(Fa_Pre_Ct));
        strll.append(tr("条"));
        ui->label_2->setText(strll);




      vector<Falut>::reverse_iterator fa;

       fa=vector_falut.rbegin();         //fa=vector_falut.begin();
       fa=fa+fa_id_stard-1;
       rft=0;
     // for(fa=vector_falut.rbegin();fa!=vector_falut.rend();fa++){
     // for(fa;fa!=vector_falut.end();fa++){

   for(fa;fa!=vector_falut.rend();fa++){

            Falut fau=*(fa);
            s=QString::number(fau.fpm_id);
            qtm1->setData(qtm1->index(rft,0),s,Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,1),fau.fpm_name,Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,2),fau.date_str,Qt::DisplayRole);
            qtm1->setData(qtm1->index(rft,3),fau.time_str,Qt::DisplayRole);

             if(fau.fault_kind==1){
                 s=tr("通讯故障");
             }else{
                  s=tr("其它故障");
             }
             qtm1->setData(qtm1->index(rft,4),s,Qt::DisplayRole);

            rft++;
            if(rft>=10){
                break;
            }
        }

}

//分页计算，并对起始id赋值。
void Form_Falut::Pages_Cac(){

   Fa_Pre_Ct= vector_falut.size() ;

     if(Fa_Pre_Ct==0){
          fa_page_cur=0;
         //总页面数量。
          fa_page_total=0;
          return;
     }

    fa_page_cur=1; //当前界面=1
    fa_id_stard=1; //开始的id号。


     //确定 总分页数量
     fa_page_total=Fa_Pre_Ct / 10;
     if(Fa_Pre_Ct % 10){
         fa_page_total++;
     }

     if(fa_page_total>1){
        fa_id_end=10;
     }else{
        fa_id_end=Fa_Pre_Ct;  //修正id_end 的值。
     }
}


//前一页面
void Form_Falut::FA_Pre_Page_Click(){

    try{
        if(fa_page_total<=0){
            return;
        }

        if(fa_page_cur<=1){
            fa_page_cur=fa_page_total;

        }else{
         fa_page_cur=fa_page_cur-1;
        }

        Rfresh_Falut_Table(fa_page_cur);
    }catch(...){

    }

}


//后一页，
void  Form_Falut::FA_Next_Page_Click(){
    try{
        if(fa_page_total<=0){
            return;
        }

        if(fa_page_cur>=fa_page_total){
               fa_page_cur=1;
        }else{
            fa_page_cur=fa_page_cur+1;
        }

        Rfresh_Falut_Table(fa_page_cur);
    }catch(...){

    }

}

void Form_Falut::Fa_Up_Down_Key(quint8 ev){
    if(ev==5){
        FA_Pre_Page_Click();
    }else if(ev==10){
        FA_Next_Page_Click();
    }

}


