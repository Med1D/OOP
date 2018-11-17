#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    makeMenu();//Create menu
    EditAddWidget();//Create window for addition
    searchWidget();//Create window for search
    createTableView();//Create header of the table
    editCells();//Signal when cells were edited


}

MainWindow::~MainWindow()
{
    delete ui;
    delete FileMenu;
    delete newAct;
    delete openAct;
    delete saveAct;
    delete closeAct;
    delete addListAct;
    delete about;
    delete add;
    delete del;
    delete search;
    delete msg;
    delete hLayout;
    delete vLayout;
    delete rooms;
    delete area;
    delete cost;
    delete address;
    delete ok;
    delete cancel;
    delete addWidget;
    delete searchHLayout;
    delete searchVLayout;
    delete search_rooms;
    delete search_area;
    delete search_cost;
    delete search_address;
    delete search_button;
    delete search_cancel;
    delete search_Widget;
    delete m_model;
    delete list;
}

void MainWindow::makeMenu()
{
    CreateActions();//This function creates actions
    FileMenu = ui->menuBar->addMenu(tr("File"));//Adding tab with name "File"
    ui->menuBar->addAction(about);//Adding tab with name "about"
    FileMenu->addAction(newAct);//Adding action "new" into "File"
    FileMenu->addAction(openAct);//Adding action "open" into "File"
    FileMenu->addAction(saveAct);//Adding action "save" into "File"
    FileMenu->addAction(closeAct);//Adding action "close" into "File"
    //Toolbar
    ui->mainToolBar->addAction(add);//Adding action "add" on the toolbar
    ui->mainToolBar->addAction(del);//Adding action "del" on the toolbar
    ui->mainToolBar->addAction(search);//Adding action "search" on the toolbar
    ui->mainToolBar->addAction(addListAct);//Adding action "append" on the toolbar

    //Edit some widgets
    ui->label->setVisible(false);//Make label not visible
    ui->tableView->setVisible(false);//Make tableview not visible
}



void MainWindow::CreateActions()
{
    newAct = new QAction(tr("&new"),this);//Editing tab's text
    newAct->setShortcuts(QKeySequence::New);//Set shortcut
    newAct->setStatusTip(tr("Create new file"));//Set status tip
    newAct->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\newicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(newAct, SIGNAL(triggered(bool)),this,SLOT(newFile()));//Make signal of "new" tab

    openAct = new QAction(tr("&open"),this);//Editing tab's text
    openAct->setShortcuts(QKeySequence::Open);//Set shortcut
    openAct->setStatusTip(tr("Open file"));//Set status tip
    openAct->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\openicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(openAct,SIGNAL(triggered(bool)),this,SLOT(openFile()));//Make signal of "open" tab


    saveAct = new QAction(tr("&save"),this);//Editing tab's text
    saveAct->setShortcut(QKeySequence::Save);//Set shortcut
    saveAct->setStatusTip(tr("Save this file"));//Set status tip
    saveAct->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\saveicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(saveAct,SIGNAL(triggered(bool)),this,SLOT(saveFile()));//Make signal of "save" tab
    saveAct->setEnabled(false);//Make tab disabled

    closeAct = new QAction(tr("&close"),this);//Editing tab's text
    closeAct->setShortcut(QKeySequence::Close);//Set shortcut
    closeAct->setStatusTip(tr("Close current file"));//Set status tip
    closeAct->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\exiticon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(closeAct,SIGNAL(triggered(bool)),this,SLOT(closeFile()));//Make signal of "close" tab
    closeAct->setEnabled(false);//Make tab disabled

    add = new QAction(tr("&add"),this);//Editing tab's text
    add->setStatusTip(tr("Add new element"));//Set status tip
    add->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\addelementicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(add,SIGNAL(triggered(bool)),this,SLOT(addElement()));//Make signal of "add" tab
    add->setEnabled(false);//Make tab disabled

    del = new QAction(tr("&delete"),this);//Editing tab's text
    del->setStatusTip(tr("Delete element"));//Set status tip
    del->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\deleteicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(del,SIGNAL(triggered(bool)),this,SLOT(delElement()));//Make signal of "del" tab
    del->setEnabled(false);//Make tab disabled

    search = new QAction(tr("&search"),this);//Editing tab's text
    search->setStatusTip(tr("Search element"));//Set status tip
    search->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\searchicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(search,SIGNAL(triggered(bool)),this,SLOT(searchElement()));//Make signal of "search" tab
    search->setEnabled(false);//Make tab disabled

    addListAct = new QAction(tr("&append"),this);//Editing tab's text
    addListAct->setStatusTip(tr("Append data to current list"));//Set status tip
    addListAct->setIcon(QIcon("E:\\Qt\\PROJECTS\\Kurs2\\icons\\listicon"));//POINT TO THE DIRECTORY WITH ICONS
    connect(addListAct,SIGNAL(triggered(bool)),this,SLOT(addList()));//Make signal of "append" tab
    addListAct->setEnabled(false);//Make tab disabled

    about = new QAction(tr("&About"),this);//Editing tab's text
    about->setStatusTip(tr("Show information about this work"));//Set status tip
    connect(about,SIGNAL(triggered(bool)),this,SLOT(showAbout()));//Make signal of "about" tab
    msg->setWindowTitle("About");//Set window title
    msg->setText("This coursework belongs to Medvedev Ivan");//Set text in window
}

void MainWindow::newFile()
{
    qDebug()<<"New";
    add->setEnabled(true);
    del->setEnabled(true);
    search->setEnabled(true);
    addListAct->setEnabled(true);
    newAct->setEnabled(false);
    closeAct->setEnabled(true);
    saveAct->setEnabled(true);
    openAct->setEnabled(false);
    ui->label->setText("NewFile");
    ui->label->setVisible(true);
    ui->tableView->setVisible(true);
}

void MainWindow::openFile()
{
    QString str = QFileDialog::getOpenFileName(this,tr("Open"),"C:",tr("Text (*.txt);;Book (*.bk);;All Files (*)"));//Get file path
    QFile file(str);//File with file path (str)
    qDebug() << "Open file";

    if (!file.open(QIODevice::ReadOnly))
            return;
    else
    {
        openAct->setEnabled(false);
        newAct->setEnabled(false);
        saveAct->setEnabled(true);
        closeAct->setEnabled(true);
        add->setEnabled(true);
        del->setEnabled(true);
        search->setEnabled(true);
        addListAct->setEnabled(true);
        ui->label->setText(str);
        ui->label->setVisible(true);
        ui->tableView->setVisible(true);

        int counter=0;
        int column =0;
        QStringList currentObjectList;//Contain data for object
        QStringList tempObj;//Contain temporary object
        QString currentRooms;//Contain number of rooms
        QString currentArea;//Contain area
        QString currentCost;//Contain cost
        Apartment currentFlat;//Apartment's object
        while(!file.atEnd())
        {
            tempObj << file.readLine();//Read line into List tempObj
            currentObjectList = tempObj[counter].split(QRegExp("[\r\n\t ]+"), QString::SkipEmptyParts);//Spliting object to parts
            currentFlat.SetNumberOfRooms(currentObjectList[0].toInt());//Set number of rooms
            currentFlat.SetArea(currentObjectList[1].toFloat());//Set area
            currentFlat.SetCost(currentObjectList[2].toFloat());//Set cost
            currentFlat.SetAddress(currentObjectList[3].toStdString());//Set Address
            list->push_back(currentFlat);//Adding apartment to list

            currentRooms.setNum(currentFlat.GetNumberOfRooms());
            currentArea.setNum(currentFlat.GetArea(),'f', 1);
            currentCost.setNum(currentFlat.GetCost(),'f', 2);

            item = new QStandardItem(currentRooms);//Create item
            item->setTextAlignment(Qt::AlignCenter);//Set text alignment
            m_model->setItem(row,column,item);//Adding item to the model
            column++;//Next column

            item = new QStandardItem(currentArea);
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column++;

            item = new QStandardItem(currentCost);
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column++;

            item = new QStandardItem(QString::fromUtf8(currentFlat.GetAddress().c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column=0;
            row++;//Next row

            counter++;
        }
    }
}


void MainWindow::saveFile()
{   if(list->GetSize()!=0)
    {
    QString str = QFileDialog::getSaveFileName(this,tr("Open"),"C:",tr("Text (*.txt);;Book (*.bk);;All Files (*)"));//Get file path
    QFile *file = new QFile(str);//File with file path(str)
    ui->label->setText(str);

    file->open(QFile::WriteOnly);//Open file
    QTextStream out(file);//Make text stream
    out.setFieldAlignment(QTextStream::AlignLeft);//Set alignment
    out.setFieldWidth(2);//Set space between elements
    for(List<Apartment>::iterator it= list->begin();it!= list->end();++it)//Write data into file
    {
        out <<(*it).GetNumberOfRooms()<< qSetFieldWidth(6) << QString::number((*it).GetArea(),'f',1) << qSetFieldWidth(13) << QString::number((*it).GetCost(),'f',2) << qSetFieldWidth(15) << (*it).GetAddress().c_str() << qSetFieldWidth(0) << "\r\n" << qSetFieldWidth(2);
    }
    file->close();
    qDebug()<<"Save";
    }
    else
    {
        QMessageBox message(QMessageBox::Critical, "Your list is empty","Add something and then you can save this list");
        message.exec();
    }
}

void MainWindow::closeFile()
{
    qDebug()<<"Close";
    add->setEnabled(false);
    del->setEnabled(false);
    search->setEnabled(false);
    addListAct->setEnabled(false);
    newAct->setEnabled(true);
    closeAct->setEnabled(false);
    saveAct->setEnabled(false);
    openAct->setEnabled(true);
    ui->label->setVisible(false);
    ui->tableView->setVisible(false);
    row = 0;
    m_model->removeRows(0,list->GetSize());
    list->clear();
}

void MainWindow::addElement()
{
    qDebug()<<"Add element";


    addWidget->show();
}

void MainWindow::delElement()
{
    if(ui->tableView->selectionModel()->hasSelection())
    {
    qDebug()<<"Delete element";
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    std::sort(selection.begin(),selection.end());//Sort array of indexes

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        qDebug() << index.row();
    }
    int indexListSelection=0;
    int counterSelection = selection.size();
    while(counterSelection!=0)
    {
        list->remove(selection[indexListSelection].row()-indexListSelection);//Remove element from list
        m_model->removeRow(selection[indexListSelection].row()-indexListSelection);//Remove element from model
        indexListSelection++;//next row
        counterSelection--;
        row--;
    }
}
}

void MainWindow::searchElement()
{
    qDebug() << "Search";
    search_Widget->show();
}

void MainWindow::searchWidget()
{
    search_Widget->setWindowTitle("Search");
    search_Widget->resize(225,150);
    search_rooms->setPlaceholderText("Number of rooms");
    search_area->setPlaceholderText("Area");
    search_cost->setPlaceholderText("Cost");
    search_address->setPlaceholderText("Address");
    search_button->setText("search");
    search_cancel->setText("cancel");
    connect(search_button,SIGNAL(clicked(bool)),this,SLOT(searchButton()));//Make signal of search button
    connect(search_cancel,SIGNAL(clicked(bool)),this,SLOT(cancelSearchButton()));//Make signal of cancel button
    search_Widget->setLayout(searchVLayout);
    searchVLayout->addWidget(search_rooms);
    searchVLayout->addWidget(search_area);
    searchVLayout->addWidget(search_cost);
    searchVLayout->addWidget(search_address);
    searchHLayout->addWidget(search_button);
    searchHLayout->addWidget(search_cancel);
    searchVLayout->addLayout(searchHLayout);
}

void MainWindow::searchButton()
{
    qDebug() << "search";
    ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);
    int j=0;
    for(int i=0;i<ui->tableView->model()->rowCount();i++)//Select rows
    {

        if(ui->tableView->model()->index(i,j).data().toString()== search_rooms->text() || ui->tableView->model()->index(i,j+1).data().toString()== search_area->text() || ui->tableView->model()->index(i,j+2).data().toString()== search_cost->text() || ui->tableView->model()->index(i,j+3).data().toString()== search_address->text())
        {
            ui->tableView->selectRow(i);
        }
    }
    search_Widget->close();
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    search_rooms->setText("");
    search_area->setText("");
    search_cost->setText("");
    search_address->setText("");
}

void MainWindow::cancelSearchButton()
{
    qDebug() << "cancel";
    search_Widget->close();
    search_rooms->setText("");
    search_area->setText("");
    search_cost->setText("");
    search_address->setText("");
}

void MainWindow::showAbout()
{
    qDebug()<<"About";
    msg->show();
}

void MainWindow::EditAddWidget()
{
    addWidget->setWindowTitle("Addition");
    addWidget->resize(225,150);
    rooms->setPlaceholderText("Number of rooms");
    area->setPlaceholderText("Area");
    cost->setPlaceholderText("Cost");
    address->setPlaceholderText("Address");
    ok->setText("accept");
    cancel->setText("cancel");
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(okButton()));//Make signal of "ok" button
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(cancelButton()));//Make signal of cancel button
    addWidget->setLayout(vLayout);
    vLayout->addWidget(rooms);
    vLayout->addWidget(area);
    vLayout->addWidget(cost);
    vLayout->addWidget(address);
    vLayout->addLayout(hLayout);
    hLayout->addWidget(ok);
    hLayout->addWidget(cancel);
}

void MainWindow::okButton()
{
    int column = 0;
    Apartment currentFlat;//Apartment's object
    QString currentRooms;//Contain number of rooms
    QString currentArea;//Contain area
    QString currentCost;//Contain cost
    currentFlat.SetNumberOfRooms(rooms->text().toInt());//Set number of rooms
    currentFlat.SetArea(area->text().toFloat());//Set area
    currentFlat.SetCost(cost->text().toFloat());//Set cost
    currentFlat.SetAddress(address->text().toStdString());//Set address
    list->push_back(currentFlat);//Adding object to list

    currentRooms.setNum(currentFlat.GetNumberOfRooms());
    currentArea.setNum(currentFlat.GetArea(),'f', 1);
    currentCost.setNum(currentFlat.GetCost(),'f', 2);

    item = new QStandardItem(currentRooms);//Create item
    item->setTextAlignment(Qt::AlignCenter);//Set alignment
    m_model->setItem(row,column,item);//Adding item into model
    column++;//Next column

    item = new QStandardItem(currentArea);
    item->setTextAlignment(Qt::AlignCenter);
    m_model->setItem(row,column,item);
    column++;

    item = new QStandardItem(currentCost);
    item->setTextAlignment(Qt::AlignCenter);
    m_model->setItem(row,column,item);
    column++;

    item = new QStandardItem(QString::fromUtf8(currentFlat.GetAddress().c_str()));
    item->setTextAlignment(Qt::AlignCenter);
    m_model->setItem(row,column,item);
    column=0;
    row++;//Next row

    addWidget->close();
    rooms->setText("");
    area->setText("");
    cost->setText("");
    address->setText("");
    qDebug()<<"accept";
}

void MainWindow::cancelButton()
{
    qDebug()<<"cancel";
    addWidget->close();
    rooms->setText("");
    area->setText("");
    cost->setText("");
    address->setText("");
}

void MainWindow::createTableView()
{
    QStringList header;
    header.append("Rooms");
    header.append("Area");
    header.append("Cost");
    header.append("Address");
    m_model->setHorizontalHeaderLabels(header);
    ui->tableView->setModel(m_model);
}

void MainWindow::editCell()
{
    qDebug() << "Edit cell";
    List<Apartment>::iterator it = list->begin();
    int j=0;
    for(int i=0;i<m_model->rowCount();i++)
    {
            if((*it).GetNumberOfRooms()!=m_model->index(i,j).data().toInt())
            {
                (*it).SetNumberOfRooms(m_model->index(i,j).data().toInt());
            }
            if((*it).GetArea()!=m_model->index(i,j+1).data().toFloat())
            {
                (*it).SetArea(m_model->index(i,j+1).data().toFloat());
            }
            if((*it).GetCost()!=m_model->index(i,j+2).data().toFloat())
            {
                (*it).SetCost(m_model->index(i,j+2).data().toFloat());
            }
            if((*it).GetAddress()!=m_model->index(i,j+3).data().toString().toStdString())
            {
                (*it).SetAddress(m_model->index(i,j+3).data().toString().toStdString());
            }

        ++it;
    }
}

void MainWindow::editCells()
{
    QObject::connect(ui->tableView->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),this,SLOT(editCell()));//Make signal for editing cells
}

void MainWindow::addList()//Similar to openFile
{
    qDebug() << "Add List";
    QString str = QFileDialog::getOpenFileName(this,tr("Open"),"C:",tr("Text (*.txt);;Book (*.bk);;All Files (*)"));//Get file path
    QFile file(str);//File with file path(str)
    if (!file.open(QIODevice::ReadOnly))
            return;
    else
    {
        int counter=0;
        int column =0;
        QStringList currentObjectList;
        QStringList tempObj;
        QString currentRooms;
        QString currentArea;
        QString currentCost;
        Apartment currentFlat;
        while(!file.atEnd())
        {
            tempObj << file.readLine();
            currentObjectList = tempObj[counter].split(QRegExp("[\r\n\t ]+"), QString::SkipEmptyParts);
            currentFlat.SetNumberOfRooms(currentObjectList[0].toInt());
            currentFlat.SetArea(currentObjectList[1].toFloat());
            currentFlat.SetCost(currentObjectList[2].toFloat());
            currentFlat.SetAddress(currentObjectList[3].toStdString());
            list->push_back(currentFlat);

            currentRooms.setNum(currentFlat.GetNumberOfRooms());
            currentArea.setNum(currentFlat.GetArea(),'f', 1);
            currentCost.setNum(currentFlat.GetCost(),'f', 2);

            item = new QStandardItem(currentRooms);
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column++;

            item = new QStandardItem(currentArea);
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column++;

            item = new QStandardItem(currentCost);
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column++;

            item = new QStandardItem(QString::fromUtf8(currentFlat.GetAddress().c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            m_model->setItem(row,column,item);
            column=0;
            row++;

            counter++;
        }
    }
}
