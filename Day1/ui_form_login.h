/********************************************************************************
** Form generated from reading UI file 'form_login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LOGIN_H
#define UI_FORM_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Login
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *But_OK;
    QPushButton *But_ESC;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *Line_Pass;
    QLabel *label_4;

    void setupUi(QWidget *Form_Login)
    {
        if (Form_Login->objectName().isEmpty())
            Form_Login->setObjectName(QString::fromUtf8("Form_Login"));
        Form_Login->resize(400, 280);
        Form_Login->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 208, 255);"));
        label = new QLabel(Form_Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 20, 121, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(Form_Login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 190, 271, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        But_OK = new QPushButton(layoutWidget);
        But_OK->setObjectName(QString::fromUtf8("But_OK"));
        But_OK->setMaximumSize(QSize(110, 60));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        But_OK->setFont(font1);
        But_OK->setAutoFillBackground(false);
        But_OK->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        horizontalLayout_3->addWidget(But_OK);

        But_ESC = new QPushButton(layoutWidget);
        But_ESC->setObjectName(QString::fromUtf8("But_ESC"));
        But_ESC->setMaximumSize(QSize(110, 60));
        But_ESC->setFont(font1);
        But_ESC->setAutoFillBackground(false);
        But_ESC->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        horizontalLayout_3->addWidget(But_ESC);

        label_2 = new QLabel(Form_Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 112, 44));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        comboBox = new QComboBox(Form_Login);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(159, 70, 141, 40));
        QFont font3;
        font3.setPointSize(18);
        comboBox->setFont(font3);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Form_Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 120, 81, 41));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setWeight(50);
        label_3->setFont(font4);
        Line_Pass = new QLineEdit(Form_Login);
        Line_Pass->setObjectName(QString::fromUtf8("Line_Pass"));
        Line_Pass->setGeometry(QRect(159, 120, 141, 40));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setWeight(75);
        Line_Pass->setFont(font5);
        Line_Pass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Form_Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 120, 81, 41));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);"));

        retranslateUi(Form_Login);

        QMetaObject::connectSlotsByName(Form_Login);
    } // setupUi

    void retranslateUi(QWidget *Form_Login)
    {
        Form_Login->setWindowTitle(QApplication::translate("Form_Login", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_Login", "\346\235\203\351\231\220\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        But_OK->setText(QApplication::translate("Form_Login", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        But_ESC->setText(QApplication::translate("Form_Login", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form_Login", "\347\224\250\346\210\267\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form_Login", "\345\257\206    \347\240\201:", 0, QApplication::UnicodeUTF8));
        Line_Pass->setText(QApplication::translate("Form_Login", "885200", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form_Login", "\345\257\206\347\240\201\351\224\231\350\257\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_Login: public Ui_Form_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LOGIN_H
