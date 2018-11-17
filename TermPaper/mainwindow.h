#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFile>
#include <QFileDialog>
#include "List.h"
#include "Apartment.h"


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

private:
    Ui::MainWindow *ui;
    QMenu *FileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *closeAct;
    QAction *about;
    QAction *add;
    QAction *del;
    QAction *search;
    QAction *addListAct;

    QMessageBox *msg = new QMessageBox();
    QWidget *addWidget = new QWidget;
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QLineEdit *rooms = new QLineEdit;
    QLineEdit *area = new QLineEdit;
    QLineEdit *cost = new QLineEdit;
    QLineEdit *address = new QLineEdit;
    QPushButton *ok = new QPushButton;
    QPushButton *cancel = new QPushButton;
    QWidget *search_Widget = new QWidget;
    QVBoxLayout *searchVLayout = new QVBoxLayout;
    QHBoxLayout *searchHLayout = new QHBoxLayout;
    QLineEdit *search_rooms = new QLineEdit;
    QLineEdit *search_area = new QLineEdit;
    QLineEdit *search_cost = new QLineEdit;
    QLineEdit *search_address = new QLineEdit;


    QPushButton *search_button = new QPushButton;
    QPushButton *search_cancel = new QPushButton;


    QStandardItem *item;
    QStandardItemModel *m_model = new QStandardItemModel;
    List<Apartment> *list = new List<Apartment>;


    int row = 0;
    int column = 0;




    private slots:
    void makeMenu();
    void CreateActions();
    void EditAddWidget();
    void showAbout();
    void closeFile();
    void newFile();
    void openFile();
    void saveFile();
    void addElement();
    void delElement();
    void searchElement();
    void searchWidget();
    void searchButton();
    void cancelSearchButton();
    void okButton();
    void cancelButton();
    void createTableView();
    void editCell();
    void editCells();
    void addList();
};

#endif // MAINWINDOW_H
