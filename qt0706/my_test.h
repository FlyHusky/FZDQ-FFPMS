#ifndef MY_TEST_H
#define MY_TEST_H

#include <QWidget>

namespace Ui {
class My_Test;
}

class My_Test : public QWidget
{
    Q_OBJECT
    
public:
    explicit My_Test(QWidget *parent = 0);
    ~My_Test();

private slots:
    //定时器溢出
    void My_Timer_Out();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::My_Test *ui;

   //刷新表格
   void Refresh_Table(quint8 cur_page);
   //按键事件重写。
   void   keyPressEvent(QKeyEvent *);

public:
   void My_Up_Down_Key(quint8 ev);





};

#endif // MY_TEST_H
