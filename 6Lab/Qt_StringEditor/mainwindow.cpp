#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    LineEdit1->setPlaceholderText("Enter your string 1");
    LineEdit2->setPlaceholderText("Enter your string 2");


    clearUpper->setText("Clear String 1");
    clearLower->setText("Clear String 2");
    clearAll->setText("Clear All strings");
    copy->setText("Copy 1 to 2");
    concat->setText("Add 1 to 2");
    move->setText("Move 1 to 2");

    vlayout->addWidget(LineEdit1);
    vlayout->addWidget(LineEdit2);
    vlayout->addWidget(clearUpper);
    vlayout->addWidget(clearLower);
    vlayout->addWidget(clearAll);
    vlayout->addWidget(copy);
    vlayout->addWidget(concat);
    vlayout->addWidget(move);

    QObject::connect(clearUpper,SIGNAL(clicked(bool)),this,SLOT(clearUpperFunc()));
    QObject::connect(clearLower,SIGNAL(clicked(bool)),this,SLOT(clearLowerFunc()));
    QObject::connect(clearAll,SIGNAL(clicked(bool)),this,SLOT(clearAllFunc()));
    QObject::connect(copy,SIGNAL(clicked(bool)),this,SLOT(copyFunc()));
    QObject::connect(concat,SIGNAL(clicked(bool)),this,SLOT(concatFunc()));
    QObject::connect(move,SIGNAL(clicked(bool)),this,SLOT(moveFunc()));

    QObject::connect(LineEdit1,SIGNAL(editingFinished()),this,SLOT(editString1()));
    QObject::connect(LineEdit2,SIGNAL(editingFinished()),this,SLOT(editString2()));

    setCentralWidget(mainWindow);
    mainWindow->setLayout(vlayout);
    mainWindow->resize(250,200);
    mainWindow->show();
}

MainWindow::~MainWindow()
{
    delete Line1;
    delete Line2;
    delete LineEdit1;
    delete LineEdit2;
    delete clearUpper;
    delete clearLower;
    delete clearAll;
    delete copy;
    delete concat;
    delete move;
    delete vlayout;
    delete mainWindow;
}

void MainWindow::clearUpperFunc()
{
    //str.clear();
    LineEdit1->clear();
    Line1->clear();
    qDebug()<<"ClearUpper";
}

void MainWindow::clearLowerFunc()
{
    LineEdit2->clear();
    Line2->clear();
    qDebug()<<"ClearLower";
}

void MainWindow::clearAllFunc()
{
    clearUpperFunc();
    clearLowerFunc();
}

void MainWindow::copyFunc()
{
    LineEdit2->clear();
    LineEdit2->setText(*Line1);
    *Line2=*Line1;
    qDebug()<<"Copy 1 to 2";
}

void MainWindow::editString1()
{
    *Line1 = LineEdit1->text();
    qDebug()<<"Read line 1";
}

void MainWindow::editString2()
{
    *Line2 = LineEdit2->text();
    qDebug()<<"Read line 2";
}

void MainWindow::concatFunc()
{
    *Line2 += *Line1;
    LineEdit2->setText(*Line2);
    qDebug()<<"Add 1 to 2";
}

void MainWindow::moveFunc()
{
    LineEdit2->setText(*Line1);
    LineEdit1->clear();
    Line1->clear();
    Line2->clear();
    qDebug()<<"move 1 to 2";
}

