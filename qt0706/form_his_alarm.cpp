#include "form_his_alarm.h"
#include "ui_form_his_alarm.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>



//当前的Ui界面。
extern quint8 Cur_Ui_Page;

extern QSqlDatabase  qdb;

//his_alarm 表中报警节点总数量。
int Total_Alarm_Count;

//页面编号1,2,3,4.。。。。。。
int His_page_cur=1;

//总页面数量。
int His_page_total=1;

//起始地址
int His_id_stard=1;

//结束地址。
int His_id_end=10;



//报警点数，先前值。
//quint16 Bj_Pre_Ct=0;

QAbstractItemModel *qtm_ha;


form_his_alarm::form_his_alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_his_alarm)
{
    ui->setupUi(this);

    quint8 i;

    //设置表格的尺寸。
    ui->tableWidget->setGeometry(10,5,780,361);
    //设置表格10行6列
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(6);
    qtm_ha=ui->tableWidget->model();
    ui->tableWidget->setColumnWidth(0,80);    //编号
    ui->tableWidget->setColumnWidth(1,130);
    ui->tableWidget->setColumnWidth(2,120);  //         40
    ui->tableWidget->setColumnWidth(3,120);  //120      40  80
    ui->tableWidget->setColumnWidth(4,185);  //245-150---95  40 55
    ui->tableWidget->setColumnWidth(5,140);

  //初始化表格，注意一定要先给表格单元赋值，然后在设置单元格属性，否则报错。
for(i=0;i<10;i++){
      qtm_ha->setData(qtm_ha->index(i,0),"",Qt::DisplayRole);
      qtm_ha->setData(qtm_ha->index(i,1),"",Qt::DisplayRole);
      qtm_ha->setData(qtm_ha->index(i,2),"",Qt::DisplayRole);
      qtm_ha->setData(qtm_ha->index(i,3),"",Qt::DisplayRole);
      qtm_ha->setData(qtm_ha->index(i,4),"",Qt::DisplayRole);
      qtm_ha->setData(qtm_ha->index(i,5),"",Qt::DisplayRole);

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

      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Pre_Page_Click()));
      connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Next_Page_Click()));
}

form_his_alarm::~form_his_alarm()
{
    delete ui;
}


//前一页面
void form_his_alarm::Pre_Page_Click(){
    if(His_page_cur<=1){
        return;
    }
    His_page_cur=His_page_cur-1;

    His_id_end=His_page_cur*10;
    His_id_stard=His_id_end-9;
   Get_Alarm_Info(His_id_stard, His_id_end);

}


//后一页，
void  form_his_alarm::Next_Page_Click(){
    if(His_page_cur>=His_page_total){
           return;
    }

    His_id_stard=His_page_cur*10+1;
    His_id_end=His_id_stard+9;
    His_page_cur=His_page_cur+1;
    Get_Alarm_Info(His_id_stard, His_id_end);

}

    void form_his_alarm::His_Up_Down_Key(quint8 ev){
        if(ev==5){
            Pre_Page_Click();
        }else if(ev==10){
            Next_Page_Click();
        }
    }


//从数据库读取指定的数据，到record, 1-10,,  11-20,, 分页显示。
void  form_his_alarm::Meng_Xiang(){
    Pages_ID();
    Get_Alarm_Info(His_id_stard, His_id_end);
}

//根据从数据库查询到的信息数量，然后处理分页。
void form_his_alarm::Pages_ID(){
     Total_Alarm_Count=Get_Rows_Count();
     if(Total_Alarm_Count==0){
         //数据库内没有报警信息，或者数据库连接失败。
          His_page_cur=0;
         //总页面数量。
          His_page_total=0;
         //起始地址
          His_id_stard=0;
         //结束地址。
          His_id_end=0;
          return;
     }
     His_page_cur=1; //当前界面=1
     His_id_stard=1; //开始的id号。


     //确定 总分页数量
     His_page_total=Total_Alarm_Count / 10;
     if(Total_Alarm_Count % 10){
         His_page_total++;
     }

     if(His_page_total>1){
        His_id_end=10;
     }else{
        His_id_end=Total_Alarm_Count;
     }
}

//读取数据库中信息，同时显示数据到tableview
void form_his_alarm::Get_Alarm_Info(int m_start, int m_end){
    //如果-His_page_total=0则清零表

  int gai=0;

    //初始化表格，注意一定要先给表格单元赋值，然后在设置单元格属性，否则报错。
  for(gai=0;gai<10;gai++){
        qtm_ha->setData(qtm_ha->index(gai,0),"",Qt::DisplayRole);
        qtm_ha->setData(qtm_ha->index(gai,1),"",Qt::DisplayRole);
        qtm_ha->setData(qtm_ha->index(gai,2),"",Qt::DisplayRole);
        qtm_ha->setData(qtm_ha->index(gai,3),"",Qt::DisplayRole);
        qtm_ha->setData(qtm_ha->index(gai,4),"",Qt::DisplayRole);
        qtm_ha->setData(qtm_ha->index(gai,5),"",Qt::DisplayRole);
    }

    if(His_page_total==0){
        ui->label_2->setText("查询到历史报警信息0条！");
          return;
    }

    QString strll;

    strll=tr("当前第");
    strll.append(QString::number(m_start));
    strll.append("-");
    strll.append(QString::number(m_end));
    strll.append(tr("条，总计共:"));
    strll.append(QString::number(Total_Alarm_Count));
    strll.append(tr("条"));
    ui->label_2->setText(strll);

    try{
        if(qdb.isOpen()){

            QSqlQuery query(qdb);
            QString sls="select * from his_alarm order by date(alarm_date) desc limit ";
            sls.append(QString::number(m_end));
            sls.append(" offset ");
            sls.append(QString::number(m_start-1));

            if( query.exec(sls)==false){
                return;
            }

           QSqlRecord rec;
            gai=0;
            while(query.next()){
              rec=query.record();
              qtm_ha->setData(qtm_ha->index(gai,0),rec.value("ffpm_id").toString(),Qt::DisplayRole);
              qtm_ha->setData(qtm_ha->index(gai,1),rec.value("name").toString(),Qt::DisplayRole);
              qtm_ha->setData(qtm_ha->index(gai,2),rec.value("alarm_date").toString(),Qt::DisplayRole);
              qtm_ha->setData(qtm_ha->index(gai,3),rec.value("alarm_time").toString(),Qt::DisplayRole);
              qtm_ha->setData(qtm_ha->index(gai,4),rec.value("alarm_kind").toString(),Qt::DisplayRole);
              qtm_ha->setData(qtm_ha->index(gai,5),rec.value("alarm_value").toString(),Qt::DisplayRole);
              gai=gai+1;
            }
           }
    }catch(...){
        return ;
    }
}


//读取数据库中，his_alarm表，记录总的行数
int form_his_alarm::Get_Rows_Count(){
    int total_ct;
    total_ct=0;
    try{
        if(qdb.isOpen()){ //如果数据连接已经建立好。
            QSqlQuery query=qdb.exec("select count(*) from his_alarm");
              while (query.next()) {
                total_ct=query.value(0).toInt();
                return total_ct;
             }
            return total_ct;
        }
    }catch(...){
        return total_ct;
    }
    return total_ct;
}
