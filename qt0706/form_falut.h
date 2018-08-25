#ifndef FORM_FALUT_H
#define FORM_FALUT_H

#include <QWidget>

namespace Ui {
class Form_Falut;
}

class Form_Falut : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Falut(QWidget *parent = 0);
    ~Form_Falut();
    
private slots:
    void Form_Falut_Timer_Out();

    void  FA_Pre_Page_Click();
    void  FA_Next_Page_Click();
public:
    void Fa_Up_Down_Key(quint8 ev);

private:
    Ui::Form_Falut *ui;

//故障界面刷新
    void Rfresh_Falut_Table(int m_page);

    void Pages_Cac(); //计算分页。

};

#endif // FORM_FALUT_H
