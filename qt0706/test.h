#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Test(QWidget *parent = 0);
    ~Test();
    
private slots:
    void on_pushButton_clicked();

//     void   But_SSXX_clicked();
//     void   But_DQGZ_clicked();
//     void   But_DQBJ_clicked();
//     void   But_LSBJ_clicked();
//     void   But_XTXX_clicked();
//     void   But_CSSZ_clicked();
//     void   But_SYBZ_clicked();

private:
    Ui::Test *ui;
};

#endif // TEST_H
