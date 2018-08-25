/********************************************************************************
** Form generated from reading UI file 'form_his_alarm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_HIS_ALARM_H
#define UI_FORM_HIS_ALARM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_his_alarm
{
public:
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QLabel *label_2;

    void setupUi(QWidget *form_his_alarm)
    {
        if (form_his_alarm->objectName().isEmpty())
            form_his_alarm->setObjectName(QString::fromUtf8("form_his_alarm"));
        form_his_alarm->resize(701, 457);
        tableWidget = new QTableWidget(form_his_alarm);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QBrush brush(QColor(85, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setPointSize(18);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(4, 4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(4, 5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(5, 4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(5, 5, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(6, 2, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(6, 3, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(6, 4, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(6, 5, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setItem(7, 2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setItem(7, 3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setItem(7, 4, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setItem(7, 5, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setItem(8, 2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setItem(8, 3, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget->setItem(8, 4, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget->setItem(8, 5, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget->setItem(9, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget->setItem(9, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget->setItem(9, 4, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget->setItem(9, 5, __qtablewidgetitem65);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 621, 361));
        tableWidget->setMaximumSize(QSize(800, 800));
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(10);
        tableWidget->verticalHeader()->setVisible(false);
        horizontalLayoutWidget = new QWidget(form_his_alarm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(380, 370, 281, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(pushButton_3);

        label_2 = new QLabel(form_his_alarm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 380, 271, 32));
        label_2->setFont(font1);

        retranslateUi(form_his_alarm);

        QMetaObject::connectSlotsByName(form_his_alarm);
    } // setupUi

    void retranslateUi(QWidget *form_his_alarm)
    {
        form_his_alarm->setWindowTitle(QApplication::translate("form_his_alarm", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("form_his_alarm", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("form_his_alarm", "\347\256\261\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("form_his_alarm", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("form_his_alarm", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("form_his_alarm", "\346\212\245\350\255\246\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("form_his_alarm", "\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("form_his_alarm", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 4);
        ___qtablewidgetitem10->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 5);
        ___qtablewidgetitem11->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("form_his_alarm", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 4);
        ___qtablewidgetitem16->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 5);
        ___qtablewidgetitem17->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(2, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("form_his_alarm", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 3);
        ___qtablewidgetitem21->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 4);
        ___qtablewidgetitem22->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 5);
        ___qtablewidgetitem23->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("form_his_alarm", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 3);
        ___qtablewidgetitem27->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 4);
        ___qtablewidgetitem28->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(3, 5);
        ___qtablewidgetitem29->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(4, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("form_his_alarm", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(4, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(4, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(4, 3);
        ___qtablewidgetitem33->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(4, 4);
        ___qtablewidgetitem34->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(4, 5);
        ___qtablewidgetitem35->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(5, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("form_his_alarm", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(5, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(5, 2);
        ___qtablewidgetitem38->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(5, 3);
        ___qtablewidgetitem39->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(5, 4);
        ___qtablewidgetitem40->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(5, 5);
        ___qtablewidgetitem41->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(6, 0);
        ___qtablewidgetitem42->setText(QApplication::translate("form_his_alarm", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(6, 1);
        ___qtablewidgetitem43->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(6, 2);
        ___qtablewidgetitem44->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(6, 3);
        ___qtablewidgetitem45->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(6, 4);
        ___qtablewidgetitem46->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(6, 5);
        ___qtablewidgetitem47->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(7, 0);
        ___qtablewidgetitem48->setText(QApplication::translate("form_his_alarm", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(7, 1);
        ___qtablewidgetitem49->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(7, 2);
        ___qtablewidgetitem50->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->item(7, 3);
        ___qtablewidgetitem51->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->item(7, 4);
        ___qtablewidgetitem52->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(7, 5);
        ___qtablewidgetitem53->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->item(8, 0);
        ___qtablewidgetitem54->setText(QApplication::translate("form_his_alarm", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->item(8, 1);
        ___qtablewidgetitem55->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->item(8, 2);
        ___qtablewidgetitem56->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->item(8, 3);
        ___qtablewidgetitem57->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->item(8, 4);
        ___qtablewidgetitem58->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->item(8, 5);
        ___qtablewidgetitem59->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->item(9, 0);
        ___qtablewidgetitem60->setText(QApplication::translate("form_his_alarm", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->item(9, 1);
        ___qtablewidgetitem61->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->item(9, 2);
        ___qtablewidgetitem62->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->item(9, 3);
        ___qtablewidgetitem63->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->item(9, 4);
        ___qtablewidgetitem64->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->item(9, 5);
        ___qtablewidgetitem65->setText(QApplication::translate("form_his_alarm", "1ALE", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("form_his_alarm", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("form_his_alarm", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("form_his_alarm", "\345\275\223\345\211\215\347\254\25411-20\346\235\241\357\274\214\345\205\261\350\256\241200\346\235\241\343\200\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class form_his_alarm: public Ui_form_his_alarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_HIS_ALARM_H
