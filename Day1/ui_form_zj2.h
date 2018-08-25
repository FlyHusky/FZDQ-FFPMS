/********************************************************************************
** Form generated from reading UI file 'form_zj2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ZJ2_H
#define UI_FORM_ZJ2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ZJ2
{
public:
    QLabel *label;

    void setupUi(QWidget *Form_ZJ2)
    {
        if (Form_ZJ2->objectName().isEmpty())
            Form_ZJ2->setObjectName(QString::fromUtf8("Form_ZJ2"));
        Form_ZJ2->resize(631, 401);
        label = new QLabel(Form_ZJ2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 70, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(Form_ZJ2);

        QMetaObject::connectSlotsByName(Form_ZJ2);
    } // setupUi

    void retranslateUi(QWidget *Form_ZJ2)
    {
        Form_ZJ2->setWindowTitle(QApplication::translate("Form_ZJ2", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_ZJ2", "\347\272\242\350\211\262\357\274\201\357\274\201\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_ZJ2: public Ui_Form_ZJ2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ZJ2_H
