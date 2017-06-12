/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Run;
    QAction *actionExit;
    QAction *actionstart_run;
    QAction *exitAction;
    QAction *ActionExit;
    QAction *ActionRun;
    QWidget *centralWidget;
    QLineEdit *EditTitle;
    QLabel *LabelTitle;
    QTextEdit *EditQuestion;
    QLabel *LabelTag;
    QLineEdit *EditTag;
    QMenuBar *menuBar;
    QMenu *menuRun;
    QMenu *menuOption;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(716, 417);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionStart_Run = new QAction(MainWindow);
        actionStart_Run->setObjectName(QStringLiteral("actionStart_Run"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionstart_run = new QAction(MainWindow);
        actionstart_run->setObjectName(QStringLiteral("actionstart_run"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        ActionExit = new QAction(MainWindow);
        ActionExit->setObjectName(QStringLiteral("ActionExit"));
        ActionRun = new QAction(MainWindow);
        ActionRun->setObjectName(QStringLiteral("ActionRun"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EditTitle = new QLineEdit(centralWidget);
        EditTitle->setObjectName(QStringLiteral("EditTitle"));
        EditTitle->setGeometry(QRect(70, 20, 311, 31));
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro [ADBE]"));
        font.setPointSize(10);
        EditTitle->setFont(font);
        LabelTitle = new QLabel(centralWidget);
        LabelTitle->setObjectName(QStringLiteral("LabelTitle"));
        LabelTitle->setGeometry(QRect(10, 10, 61, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Source Code Pro [ADBO]"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        LabelTitle->setFont(font1);
        EditQuestion = new QTextEdit(centralWidget);
        EditQuestion->setObjectName(QStringLiteral("EditQuestion"));
        EditQuestion->setGeometry(QRect(20, 80, 361, 161));
        EditQuestion->setFont(font);
        LabelTag = new QLabel(centralWidget);
        LabelTag->setObjectName(QStringLiteral("LabelTag"));
        LabelTag->setGeometry(QRect(10, 250, 71, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Source Code Pro [ADBE]"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        LabelTag->setFont(font2);
        EditTag = new QLineEdit(centralWidget);
        EditTag->setObjectName(QStringLiteral("EditTag"));
        EditTag->setGeometry(QRect(70, 260, 201, 31));
        EditTag->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("Source Code Pro Semibold"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        menuBar->setFont(font3);
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        QFont font4;
        font4.setPointSize(10);
        menuRun->setFont(font4);
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuOption->setFont(font4);
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuRun->addAction(ActionRun);
        menuOption->addAction(ActionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionStart_Run->setText(QApplication::translate("MainWindow", "Start Run", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionstart_run->setText(QApplication::translate("MainWindow", "Start Run", Q_NULLPTR));
        exitAction->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        ActionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        ActionRun->setText(QApplication::translate("MainWindow", "Start Run", Q_NULLPTR));
        EditTitle->setText(QString());
        LabelTitle->setText(QApplication::translate("MainWindow", "Title", Q_NULLPTR));
        LabelTag->setText(QApplication::translate("MainWindow", "Tags", Q_NULLPTR));
        menuRun->setTitle(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
