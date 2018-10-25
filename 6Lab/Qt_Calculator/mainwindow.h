#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




public slots:
    void add_func();
    void dif_func();
    void mul_func();
    void div_func();

private:
    Ui::MainWindow *ui;
    QStandardItem *item;
    QStandardItemModel *model = new QStandardItemModel;
    int counter=0;
};

#endif // MAINWINDOW_H
