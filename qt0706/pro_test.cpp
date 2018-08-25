#include "pro_test.h"
#include "ui_pro_test.h"

pro_test::pro_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pro_test)
{
    ui->setupUi(this);
}

pro_test::~pro_test()
{
    delete ui;
}
