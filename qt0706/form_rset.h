#ifndef FORM_RSET_H
#define FORM_RSET_H

#include <QWidget>

namespace Ui {
class Form_Rset;
}

class Form_Rset : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Rset(QWidget *parent = 0);
    ~Form_Rset();

private slots:
    void But_all_ffpms_reset_clicked();
    void But_just_sys_reset_clicked();
    void RS_Time_Fresh();
    
private:
    Ui::Form_Rset *ui;
    //按键事件重写。
      void   keyPressEvent(QKeyEvent *);
};

#endif // FORM_RSET_H
