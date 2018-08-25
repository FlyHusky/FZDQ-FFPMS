/********************************************************************************
** Form generated from reading UI file 'form_set_pra.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SET_PRA_H
#define UI_FORM_SET_PRA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Set_Pra
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_sys;
    QPushButton *pushButton;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QFrame *line;
    QPushButton *But_sj;
    QPushButton *pushButton_8;
    QLabel *label_8;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *Le_year;
    QLineEdit *Le_mon;
    QLineEdit *Le_day;
    QLineEdit *Le_time;
    QLineEdit *Le_min;

    void setupUi(QWidget *Form_Set_Pra)
    {
        if (Form_Set_Pra->objectName().isEmpty())
            Form_Set_Pra->setObjectName(QString::fromUtf8("Form_Set_Pra"));
        Form_Set_Pra->resize(803, 469);
        Form_Set_Pra->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 189, 255);"));
        tabWidget = new QTabWidget(Form_Set_Pra);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 791, 451));
        tabWidget->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(20);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 255, 244);"));
        tab_sys = new QWidget();
        tab_sys->setObjectName(QString::fromUtf8("tab_sys"));
        pushButton = new QPushButton(tab_sys);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 131, 41));
        QFont font1;
        font1.setPointSize(18);
        pushButton->setFont(font1);
        label_2 = new QLabel(tab_sys);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 10, 511, 44));
        QFont font2;
        font2.setPointSize(16);
        label_2->setFont(font2);
        horizontalLayoutWidget = new QWidget(tab_sys);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 221, 46));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(80, 30));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit->setFont(font3);

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(tab_sys);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 110, 431, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font4.setPointSize(16);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_5 = new QLabel(tab_sys);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 70, 661, 31));
        label_5->setFont(font4);
        label_6 = new QLabel(tab_sys);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 140, 371, 31));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        horizontalLayoutWidget_2 = new QWidget(tab_sys);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 60, 221, 46));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 30));
        lineEdit_2->setFont(font3);

        horizontalLayout_2->addWidget(lineEdit_2);

        line = new QFrame(tab_sys);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 170, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        But_sj = new QPushButton(tab_sys);
        But_sj->setObjectName(QString::fromUtf8("But_sj"));
        But_sj->setGeometry(QRect(420, 200, 71, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font5.setPointSize(18);
        But_sj->setFont(font5);
        pushButton_8 = new QPushButton(tab_sys);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(560, 80, 211, 41));
        pushButton_8->setFont(font1);
        label_8 = new QLabel(tab_sys);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(460, 130, 351, 31));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_15 = new QLabel(tab_sys);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 180, 21, 31));
        label_15->setFont(font5);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_16 = new QLabel(tab_sys);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(130, 180, 21, 31));
        label_16->setFont(font5);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_17 = new QLabel(tab_sys);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(200, 180, 21, 31));
        label_17->setFont(font5);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_18 = new QLabel(tab_sys);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(280, 180, 21, 31));
        label_18->setFont(font5);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_19 = new QLabel(tab_sys);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(360, 180, 21, 31));
        label_19->setFont(font5);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        Le_year = new QLineEdit(tab_sys);
        Le_year->setObjectName(QString::fromUtf8("Le_year"));
        Le_year->setGeometry(QRect(20, 210, 69, 30));
        Le_year->setMaximumSize(QSize(80, 30));
        Le_year->setFont(font3);
        Le_mon = new QLineEdit(tab_sys);
        Le_mon->setObjectName(QString::fromUtf8("Le_mon"));
        Le_mon->setGeometry(QRect(110, 210, 51, 30));
        Le_mon->setMaximumSize(QSize(80, 30));
        Le_mon->setFont(font3);
        Le_day = new QLineEdit(tab_sys);
        Le_day->setObjectName(QString::fromUtf8("Le_day"));
        Le_day->setGeometry(QRect(190, 210, 51, 30));
        Le_day->setMaximumSize(QSize(80, 30));
        Le_day->setFont(font3);
        Le_time = new QLineEdit(tab_sys);
        Le_time->setObjectName(QString::fromUtf8("Le_time"));
        Le_time->setGeometry(QRect(270, 210, 51, 30));
        Le_time->setMaximumSize(QSize(80, 30));
        Le_time->setFont(font3);
        Le_min = new QLineEdit(tab_sys);
        Le_min->setObjectName(QString::fromUtf8("Le_min"));
        Le_min->setGeometry(QRect(350, 210, 51, 30));
        Le_min->setMaximumSize(QSize(80, 30));
        Le_min->setFont(font3);
        tabWidget->addTab(tab_sys, QString());

        retranslateUi(Form_Set_Pra);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_Set_Pra);
    } // setupUi

    void retranslateUi(QWidget *Form_Set_Pra)
    {
        Form_Set_Pra->setWindowTitle(QApplication::translate("Form_Set_Pra", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form_Set_Pra", "\347\241\256\345\256\232\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form_Set_Pra", "\346\263\250\357\274\232\346\225\260\351\207\217\344\270\215\350\203\275\350\266\205\350\277\207500,\344\277\256\346\224\271\345\256\214\346\210\220\345\220\216\357\274\214\347\250\213\345\272\217\345\260\206\350\207\252\345\212\250\351\207\215\345\220\257\357\274\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form_Set_Pra", "\346\250\241\345\235\227\346\200\273\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Form_Set_Pra", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form_Set_Pra", "\346\202\250\350\276\223\345\205\245\347\232\204\344\270\215\346\230\257\346\234\211\346\225\210\347\232\204\346\225\260\345\200\274\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\357\274\201\357\274\201\357\274\201", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form_Set_Pra", "\346\263\250\357\274\232\350\257\267\345\220\210\347\220\206\350\256\276\347\275\256\346\255\244\345\200\274\357\274\214\345\273\272\350\256\2563-10", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form_Set_Pra", "\344\277\256\346\224\271\346\210\220\345\212\237\345\220\216\357\274\214\347\263\273\347\273\237\345\260\206\350\207\252\345\212\250\351\207\215\345\220\257\357\274\201\357\274\201\357\274\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form_Set_Pra", "\351\200\232\350\256\257\345\244\261\350\201\224\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("Form_Set_Pra", "0", 0, QApplication::UnicodeUTF8));
        But_sj->setText(QApplication::translate("Form_Set_Pra", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Form_Set_Pra", "\345\274\200\345\220\257/\345\205\263\351\227\255\351\200\232\350\256\257\350\260\203\350\257\225", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form_Set_Pra", "\351\200\232\344\277\241\350\260\203\350\257\225\357\274\214\350\257\267\350\277\233\345\205\245\347\263\273\347\273\237\350\207\252\346\243\200\347\225\214\351\235\242\344\275\277\347\224\250", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Form_Set_Pra", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Form_Set_Pra", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Form_Set_Pra", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Form_Set_Pra", "\346\227\266", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Form_Set_Pra", "\345\210\206", 0, QApplication::UnicodeUTF8));
        Le_year->setText(QApplication::translate("Form_Set_Pra", "2018", 0, QApplication::UnicodeUTF8));
        Le_mon->setText(QApplication::translate("Form_Set_Pra", "1", 0, QApplication::UnicodeUTF8));
        Le_day->setText(QApplication::translate("Form_Set_Pra", "1", 0, QApplication::UnicodeUTF8));
        Le_time->setText(QApplication::translate("Form_Set_Pra", "15", 0, QApplication::UnicodeUTF8));
        Le_min->setText(QApplication::translate("Form_Set_Pra", "30", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_sys), QApplication::translate("Form_Set_Pra", "\347\263\273\347\273\237\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_Set_Pra: public Ui_Form_Set_Pra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SET_PRA_H
