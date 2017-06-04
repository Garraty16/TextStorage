/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lab_title;
    QListWidget *listTexts;
    QPushButton *btnAdd;
    QTextEdit *textEdit;
    QPushButton *btnDelete;
    QLineEdit *textCommit;
    QPushButton *btnCommit;
    QListWidget *listCommits;
    QPushButton *btnMerge;
    QPushButton *btnCheckout;
    QPushButton *btnSave;
    QLineEdit *textFilename;
    QLabel *labFilename;
    QPushButton *btnCancel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(738, 663);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lab_title = new QLabel(centralWidget);
        lab_title->setObjectName(QStringLiteral("lab_title"));
        lab_title->setGeometry(QRect(280, 0, 161, 41));
        lab_title->setStyleSheet(QStringLiteral(""));
        listTexts = new QListWidget(centralWidget);
        listTexts->setObjectName(QStringLiteral("listTexts"));
        listTexts->setGeometry(QRect(20, 110, 201, 481));
        QFont font;
        font.setPointSize(14);
        listTexts->setFont(font);
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(20, 70, 85, 27));
        btnAdd->setStyleSheet(QStringLiteral("background-color: #7F9;"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(240, 110, 481, 291));
        textEdit->setFont(font);
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(140, 70, 80, 27));
        btnDelete->setStyleSheet(QStringLiteral("background-color: #fab"));
        textCommit = new QLineEdit(centralWidget);
        textCommit->setObjectName(QStringLiteral("textCommit"));
        textCommit->setGeometry(QRect(240, 420, 380, 27));
        btnCommit = new QPushButton(centralWidget);
        btnCommit->setObjectName(QStringLiteral("btnCommit"));
        btnCommit->setGeometry(QRect(635, 420, 90, 27));
        listCommits = new QListWidget(centralWidget);
        listCommits->setObjectName(QStringLiteral("listCommits"));
        listCommits->setGeometry(QRect(240, 470, 380, 121));
        btnMerge = new QPushButton(centralWidget);
        btnMerge->setObjectName(QStringLiteral("btnMerge"));
        btnMerge->setGeometry(QRect(635, 510, 90, 30));
        btnCheckout = new QPushButton(centralWidget);
        btnCheckout->setObjectName(QStringLiteral("btnCheckout"));
        btnCheckout->setGeometry(QRect(635, 470, 90, 30));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(630, 70, 85, 27));
        textFilename = new QLineEdit(centralWidget);
        textFilename->setObjectName(QStringLiteral("textFilename"));
        textFilename->setEnabled(true);
        textFilename->setGeometry(QRect(350, 70, 171, 27));
        textFilename->setFont(font);
        labFilename = new QLabel(centralWidget);
        labFilename->setObjectName(QStringLiteral("labFilename"));
        labFilename->setGeometry(QRect(240, 70, 100, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        labFilename->setFont(font1);
        btnCancel = new QPushButton(centralWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(530, 70, 71, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 738, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Text Storage", 0));
        lab_title->setText(QApplication::translate("MainWindow", "<h1> Text Storage </h1>", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p></body></html>", 0));
        btnDelete->setText(QApplication::translate("MainWindow", "Delete", 0));
        btnCommit->setText(QApplication::translate("MainWindow", "Commit", 0));
        btnMerge->setText(QApplication::translate("MainWindow", "Merge", 0));
        btnCheckout->setText(QApplication::translate("MainWindow", "Checkout", 0));
        btnSave->setText(QApplication::translate("MainWindow", "Save", 0));
        labFilename->setText(QApplication::translate("MainWindow", "File name:", 0));
        btnCancel->setText(QApplication::translate("MainWindow", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
