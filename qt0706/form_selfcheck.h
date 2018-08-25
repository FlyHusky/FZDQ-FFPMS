#ifndef FORM_SELFCHECK_H
#define FORM_SELFCHECK_H

#include <QWidget>

namespace Ui {
class Form_SelfCheck;
}

class Form_SelfCheck : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_SelfCheck(QWidget *parent = 0);
    ~Form_SelfCheck();
    
private slots:
    void on_pushButton_clicked();
    void   ZJ_Time_Fresh();

private:
    Ui::Form_SelfCheck *ui;
};

#endif // FORM_SELFCHECK_H
