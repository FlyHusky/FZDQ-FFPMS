#ifndef FORM_BAOJIN_H
#define FORM_BAOJIN_H

#include <QWidget>

#include "ffpmmainw.h"


namespace Ui {
class Form_Baojin;
}

class Form_Baojin : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Baojin(QWidget *parent = 0);
    ~Form_Baojin();

signals:
  void back_to_main_singal();

private:
    Ui::Form_Baojin *ui;


public:
    void My_Printer(QString str);
    void  Rfresh_Baojin_Table(int m_page);
    void Pages_Cac1();
    void Get_GBK_Array(QString src);
    void Bj_Up_Down_Key(quint8 ev);




private slots:  //声明槽，返回main
    void Form_Baojin_Timer_Out();
    void But_Print_Today_Click();
    void But_Print_All_Click();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    //按键事件重写。
    void   keyPressEvent(QKeyEvent *);
};

#endif // FORM_BAOJIN_H




