#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QWidget>

namespace Ui {
class Form_Login;
}

class Form_Login : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Login(QWidget *parent = 0);
    ~Form_Login();
    void   Haha(int lev);

  signals:
    void Pass_Is_Ok();

private slots:
    void   on_But_ESC_clicked();
    void   on_But_OK_clicked();
    
private:
    Ui::Form_Login *ui;

    //按键事件重写。
      void   keyPressEvent(QKeyEvent *);


};

#endif // FORM_LOGIN_H
