#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("Calculator");
    ui->menuBar->addAction("File");
    ui->menuBar->addAction("Edit");
    ui->menuBar->addAction("Window");
    ui->menuBar->addAction("Info");
    ui->mainToolBar->addAction("Addition",this,SLOT(add_func()));
    ui->mainToolBar->addAction("Difference",this,SLOT(dif_func()));
    ui->mainToolBar->addAction("Multiplication",this,SLOT(mul_func()));
    ui->mainToolBar->addAction("Division",this,SLOT(div_func()));
    ui->mainToolBar->setMovable(0);

    QStringList horizontalHeader;
    //horizontalHeader.append("№");
    horizontalHeader.append("Number 1");
    horizontalHeader.append("Number 2");
    horizontalHeader.append("Type");
    horizontalHeader.append("Result");
    model->setHorizontalHeaderLabels(horizontalHeader);

    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_func()
{
qDebug()<<"Addition";
item = new QStandardItem(ui->lineEdit->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,0,item);
item = new QStandardItem(ui->lineEdit_2->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,1,item);
item = new QStandardItem("+");
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,2,item);
int result =ui->lineEdit->text().toInt()+ui->lineEdit_2->text().toInt();
QString op_result;
item = new QStandardItem(op_result.number(result));
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,3,item);
counter++;
}

void MainWindow::dif_func()
{
qDebug()<<"Difference";
item = new QStandardItem(ui->lineEdit->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,0,item);
item = new QStandardItem(ui->lineEdit_2->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,1,item);
item = new QStandardItem("-");
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,2,item);
int result =ui->lineEdit->text().toInt()-ui->lineEdit_2->text().toInt();
QString op_result;
item = new QStandardItem(op_result.number(result));
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,3,item);
counter++;
}

void MainWindow::mul_func()
{
qDebug()<<"Multiplication";
item = new QStandardItem(ui->lineEdit->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,0,item);
item = new QStandardItem(ui->lineEdit_2->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,1,item);
item = new QStandardItem("*");
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,2,item);
int result =ui->lineEdit->text().toInt()*ui->lineEdit_2->text().toInt();
QString op_result;
item = new QStandardItem(op_result.number(result));
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,3,item);
counter++;
}

void MainWindow::div_func()
{
qDebug()<<"Division";
item = new QStandardItem(ui->lineEdit->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,0,item);
item = new QStandardItem(ui->lineEdit_2->text());
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,1,item);
item = new QStandardItem("/");
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,2,item);
try{
    if(ui->lineEdit_2->text().toInt()==0)
        throw 0;
    else
    {
        int result =ui->lineEdit->text().toInt()/ui->lineEdit_2->text().toInt();
        QString op_result;
        item = new QStandardItem(op_result.number(result));
    }
}
catch (int a)
{
    item = new QStandardItem("ERROR");
}
item->setTextAlignment(Qt::AlignCenter);
model->setItem(counter,3,item);
counter++;
}
