/********************************************************************************
** Form generated from reading UI file 'ffpmmainw.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFPMMAINW_H
#define UI_FFPMMAINW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FFPMMainW
{
public:
    QAction *actionSss;
    QAction *actionLsbj;
    QAction *action;
    QAction *actionSssss;
    QAction *actionDddd;
    QAction *action_2;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *p_but_open;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QPushButton *gao;
    QPushButton *di;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *FFPMMainW)
    {
        if (FFPMMainW->objectName().isEmpty())
            FFPMMainW->setObjectName(QString::fromUtf8("FFPMMainW"));
        FFPMMainW->resize(800, 480);
        FFPMMainW->setMaximumSize(QSize(800, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(17);
        FFPMMainW->setFont(font);
        actionSss = new QAction(FFPMMainW);
        actionSss->setObjectName(QString::fromUtf8("actionSss"));
        actionLsbj = new QAction(FFPMMainW);
        actionLsbj->setObjectName(QString::fromUtf8("actionLsbj"));
        action = new QAction(FFPMMainW);
        action->setObjectName(QString::fromUtf8("action"));
        actionSssss = new QAction(FFPMMainW);
        actionSssss->setObjectName(QString::fromUtf8("actionSssss"));
        actionDddd = new QAction(FFPMMainW);
        actionDddd->setObjectName(QString::fromUtf8("actionDddd"));
        action_2 = new QAction(FFPMMainW);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralWidget = new QWidget(FFPMMainW);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 30, 151, 41));
        QFont font1;
        font1.setPointSize(14);
        pushButton->setFont(font1);
        p_but_open = new QPushButton(centralWidget);
        p_but_open->setObjectName(QString::fromUtf8("p_but_open"));
        p_but_open->setGeometry(QRect(580, 250, 171, 41));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        p_but_open->setFont(font2);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 110, 121, 41));
        pushButton_2->setFont(font1);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 100, 401, 131));
        textEdit->setFocusPolicy(Qt::StrongFocus);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 260, 531, 151));
        textEdit_2->setFocusPolicy(Qt::StrongFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 131, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 220, 231, 51));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 491, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(590, 80, 151, 41));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 330, 121, 41));
        pushButton_4->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 190, 341, 21));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 30, 61, 41));
        pushButton_5->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 391, 41));
        gao = new QPushButton(centralWidget);
        gao->setObjectName(QString::fromUtf8("gao"));
        gao->setGeometry(QRect(550, 140, 80, 27));
        di = new QPushButton(centralWidget);
        di->setObjectName(QString::fromUtf8("di"));
        di->setGeometry(QRect(650, 140, 80, 27));
        FFPMMainW->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FFPMMainW);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FFPMMainW->setStatusBar(statusBar);
        toolBar = new QToolBar(FFPMMainW);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        FFPMMainW->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(FFPMMainW);

        QMetaObject::connectSlotsByName(FFPMMainW);
    } // setupUi

    void retranslateUi(QMainWindow *FFPMMainW)
    {
        FFPMMainW->setWindowTitle(QString());
        actionSss->setText(QApplication::translate("FFPMMainW", "sss", 0, QApplication::UnicodeUTF8));
        actionLsbj->setText(QApplication::translate("FFPMMainW", "\346\225\205\351\232\234\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("FFPMMainW", "\345\275\223\345\211\215\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        actionSssss->setText(QApplication::translate("FFPMMainW", "sssss", 0, QApplication::UnicodeUTF8));
        actionDddd->setText(QApplication::translate("FFPMMainW", "dddd", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("FFPMMainW", "\344\270\211\345\215\201\344\270\211\345\210\206", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FFPMMainW", "\345\201\234\346\255\242\344\270\273\347\250\213\345\272\217\351\200\232\344\277\241", 0, QApplication::UnicodeUTF8));
        p_but_open->setText(QApplication::translate("FFPMMainW", "\345\205\263\351\227\255\351\200\232\344\277\241\350\260\203\350\257\225\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("FFPMMainW", "\345\217\221\351\200\201\346\237\245\350\257\2421\346\254\241", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("FFPMMainW", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221'; font-size:17pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        textEdit_2->setHtml(QApplication::translate("FFPMMainW", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221'; font-size:17pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FFPMMainW", "\345\217\221\351\200\201\346\225\260\346\215\256\345\214\272", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FFPMMainW", "\346\216\245\346\224\266\346\225\260\346\215\256\345\214\272-\345\221\250\346\234\2371\347\247\222", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FFPMMainW", "\346\267\273\345\212\240\350\246\201\347\233\221\346\265\213\351\200\232\344\277\241\347\232\204\346\250\241\345\235\227\345\234\260\345\235\200-\345\275\223\345\211\215\344\273\205\346\224\257\346\214\2011\344\270\252\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("FFPMMainW", "\345\274\200\345\220\257\344\270\273\347\250\213\345\272\217\351\200\232\344\277\241", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("FFPMMainW", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FFPMMainW", "\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("FFPMMainW", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("FFPMMainW", "1", 0, QApplication::UnicodeUTF8));
        gao->setText(QApplication::translate("FFPMMainW", "gao", 0, QApplication::UnicodeUTF8));
        di->setText(QApplication::translate("FFPMMainW", "di", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("FFPMMainW", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FFPMMainW: public Ui_FFPMMainW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFPMMAINW_H
