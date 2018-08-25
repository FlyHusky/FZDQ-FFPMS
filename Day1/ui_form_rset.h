/********************************************************************************
** Form generated from reading UI file 'form_rset.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_RSET_H
#define UI_FORM_RSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Rset
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hboxl;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hboxl_2;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QWidget *Form_Rset)
    {
        if (Form_Rset->objectName().isEmpty())
            Form_Rset->setObjectName(QString::fromUtf8("Form_Rset"));
        Form_Rset->resize(690, 395);
        horizontalLayoutWidget = new QWidget(Form_Rset);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 30, 171, 41));
        hboxl = new QHBoxLayout(horizontalLayoutWidget);
        hboxl->setObjectName(QString::fromUtf8("hboxl"));
        hboxl->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(Form_Rset);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(380, 30, 171, 41));
        hboxl_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        hboxl_2->setObjectName(QString::fromUtf8("hboxl_2"));
        hboxl_2->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(Form_Rset);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(80, 170, 541, 41));
        progressBar->setValue(0);
        label = new QLabel(Form_Rset);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 220, 201, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(Form_Rset);

        QMetaObject::connectSlotsByName(Form_Rset);
    } // setupUi

    void retranslateUi(QWidget *Form_Rset)
    {
        Form_Rset->setWindowTitle(QApplication::translate("Form_Rset", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_Rset", "\345\267\262\345\256\214\346\210\220\357\274\201\357\274\201\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_Rset: public Ui_Form_Rset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_RSET_H
