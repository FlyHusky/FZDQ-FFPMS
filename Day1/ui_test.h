/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QString::fromUtf8("Test"));
        Test->resize(800, 600);
        Test->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(Test);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 98, 27));
        Test->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Test);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Test->setStatusBar(statusbar);
        menuBar = new QMenuBar(Test);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 28));
        Test->setMenuBar(menuBar);
        toolBar = new QToolBar(Test);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Test->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QMainWindow *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Test", "\345\256\236\346\227\266\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Test", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
