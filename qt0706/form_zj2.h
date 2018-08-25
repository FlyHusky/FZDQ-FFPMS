#ifndef FORM_ZJ2_H
#define FORM_ZJ2_H

#include <QWidget>

namespace Ui {
class Form_ZJ2;
}

class Form_ZJ2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_ZJ2(QWidget *parent = 0);
    ~Form_ZJ2();

private slots:
   void ZJ2_Time_Fresh(void);
    
private:
    Ui::Form_ZJ2 *ui;
};

#endif // FORM_ZJ2_H
