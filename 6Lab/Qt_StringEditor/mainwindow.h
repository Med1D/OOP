#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QWidget *mainWindow = new QWidget;
    QVBoxLayout *vlayout = new QVBoxLayout;
    QString *Line1 = new QString;
    QString *Line2 = new QString;
    QLineEdit *LineEdit1 = new QLineEdit;
    QLineEdit *LineEdit2 = new QLineEdit;
    QPushButton *clearUpper = new QPushButton;
    QPushButton *clearLower = new QPushButton;
    QPushButton *clearAll = new QPushButton;
    QPushButton *copy = new QPushButton;
    QPushButton *concat = new QPushButton;
    QPushButton *move = new QPushButton;

private slots:
    void clearUpperFunc();
    void clearLowerFunc();
    void clearAllFunc();
    void copyFunc();
    void concatFunc();
    void moveFunc();

    void editString1();
    void editString2();
};

#endif // MAINWINDOW_H
