/********************************************************************************
** Form generated from reading UI file 'pro_test.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRO_TEST_H
#define UI_PRO_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pro_test
{
public:
    QLabel *label;

    void setupUi(QWidget *pro_test)
    {
        if (pro_test->objectName().isEmpty())
            pro_test->setObjectName(QString::fromUtf8("pro_test"));
        pro_test->resize(400, 300);
        label = new QLabel(pro_test);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 130, 281, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        retranslateUi(pro_test);

        QMetaObject::connectSlotsByName(pro_test);
    } // setupUi

    void retranslateUi(QWidget *pro_test)
    {
        pro_test->setWindowTitle(QApplication::translate("pro_test", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pro_test", "Project envrioment test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pro_test: public Ui_pro_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRO_TEST_H
