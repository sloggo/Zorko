/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *northBut;
    QPushButton *southBut;
    QPushButton *eastBut;
    QPushButton *westBut;
    QProgressBar *progressBar;
    QListWidget *listWidget;
    QTableWidget *tableWidget;
    QPushButton *attackBut;
    QPushButton *blockBut;
    QProgressBar *HealthBar;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1111, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(800, 360, 281, 131));
        northBut = new QPushButton(centralwidget);
        northBut->setObjectName("northBut");
        northBut->setGeometry(QRect(900, 70, 81, 81));
        southBut = new QPushButton(centralwidget);
        southBut->setObjectName("southBut");
        southBut->setGeometry(QRect(900, 240, 81, 81));
        eastBut = new QPushButton(centralwidget);
        eastBut->setObjectName("eastBut");
        eastBut->setGeometry(QRect(810, 150, 81, 81));
        westBut = new QPushButton(centralwidget);
        westBut->setObjectName("westBut");
        westBut->setGeometry(QRect(990, 150, 81, 81));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(70, 410, 651, 23));
        progressBar->setValue(24);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 30, 741, 371));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 440, 741, 131));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        attackBut = new QPushButton(centralwidget);
        attackBut->setObjectName("attackBut");
        attackBut->setGeometry(QRect(849, 90, 181, 91));
        blockBut = new QPushButton(centralwidget);
        blockBut->setObjectName("blockBut");
        blockBut->setGeometry(QRect(850, 190, 181, 91));
        HealthBar = new QProgressBar(centralwidget);
        HealthBar->setObjectName("HealthBar");
        HealthBar->setGeometry(QRect(880, 30, 118, 23));
        HealthBar->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(880, 20, 58, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1111, 43));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        northBut->setText(QCoreApplication::translate("MainWindow", "North", nullptr));
        southBut->setText(QCoreApplication::translate("MainWindow", "South", nullptr));
        eastBut->setText(QCoreApplication::translate("MainWindow", "East", nullptr));
        westBut->setText(QCoreApplication::translate("MainWindow", "West", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Item Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Item Description", nullptr));
        attackBut->setText(QCoreApplication::translate("MainWindow", "Attack", nullptr));
        blockBut->setText(QCoreApplication::translate("MainWindow", "Block", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Health", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
