#ifndef FORM_HIS_ALARM_H
#define FORM_HIS_ALARM_H



#include <QWidget>

namespace Ui {
class form_his_alarm;
}

class form_his_alarm : public QWidget
{
    Q_OBJECT
    
public:
    explicit form_his_alarm(QWidget *parent = 0);
    ~form_his_alarm();
    void  Meng_Xiang();

private slots:
    void  Pre_Page_Click();
    void  Next_Page_Click();

    
private:
    Ui::form_his_alarm *ui;


    //读取数据库中，his_alarm表，记录总的行数
    int   Get_Rows_Count();
    void  Get_Alarm_Info(int m_start, int m_end);
    void  Pages_ID();

public:
    void First_Into();
    void His_Up_Down_Key(quint8 ev);

};

#endif // FORM_HIS_ALARM_H
