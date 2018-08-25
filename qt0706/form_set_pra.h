#ifndef FORM_SET_PRA_H
#define FORM_SET_PRA_H

#include <QWidget>

namespace Ui {
class Form_Set_Pra;
}

class Form_Set_Pra : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Set_Pra(QWidget *parent = 0);
    ~Form_Set_Pra();

private slots:
    void Xiugai_Click();
    void But_sj_Click();
    
    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form_Set_Pra *ui;

    bool  Change_Fpms_Ct(quint16 t_ct, quint16 s_ct);

    //按键事件重写。
    void   keyPressEvent(QKeyEvent *);

};

#endif // FORM_SET_PRA_H
