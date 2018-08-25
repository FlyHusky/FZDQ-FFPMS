/********************************************************************************
** Form generated from reading UI file 'form_selfcheck.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SELFCHECK_H
#define UI_FORM_SELFCHECK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_SelfCheck
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QProgressBar *bar;
    QTextEdit *textt;
    QLabel *label;

    void setupUi(QWidget *Form_SelfCheck)
    {
        if (Form_SelfCheck->objectName().isEmpty())
            Form_SelfCheck->setObjectName(QString::fromUtf8("Form_SelfCheck"));
        Form_SelfCheck->resize(800, 410);
        Form_SelfCheck->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 192, 235);"));
        horizontalLayoutWidget = new QWidget(Form_SelfCheck);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 10, 651, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(18);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 214, 214);"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 214, 214);"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        bar = new QProgressBar(Form_SelfCheck);
        bar->setObjectName(QString::fromUtf8("bar"));
        bar->setGeometry(QRect(80, 330, 631, 41));
        bar->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 214, 214);"));
        bar->setMaximum(25);
        bar->setValue(0);
        textt = new QTextEdit(Form_SelfCheck);
        textt->setObjectName(QString::fromUtf8("textt"));
        textt->setGeometry(QRect(170, 80, 441, 231));
        textt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Form_SelfCheck);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 370, 281, 31));
        label->setFont(font);

        retranslateUi(Form_SelfCheck);

        QMetaObject::connectSlotsByName(Form_SelfCheck);
    } // setupUi

    void retranslateUi(QWidget *Form_SelfCheck)
    {
        Form_SelfCheck->setWindowTitle(QApplication::translate("Form_SelfCheck", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form_SelfCheck", "\344\270\273\346\234\272\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Form_SelfCheck", "\346\211\200\346\234\211\346\250\241\345\235\227\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_SelfCheck", "1:\346\211\200\346\234\211\346\214\207\347\244\272\347\201\257\351\227\252\347\203\201\357\274\201\357\274\201\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_SelfCheck: public Ui_Form_SelfCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SELFCHECK_H
