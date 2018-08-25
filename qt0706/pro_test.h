#ifndef PRO_TEST_H
#define PRO_TEST_H

#include <QWidget>

namespace Ui {
class pro_test;
}

class pro_test : public QWidget
{
    Q_OBJECT
    
public:
    explicit pro_test(QWidget *parent = 0);
    ~pro_test();
    
private:
    Ui::pro_test *ui;
};

#endif // PRO_TEST_H
