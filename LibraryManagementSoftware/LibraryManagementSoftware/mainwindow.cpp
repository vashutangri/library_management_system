#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrManageBooks = new ManageBooks();
    ptrMemberManagement = new Member_management();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrManageBooks;
    delete ptrMemberManagement;
}



void MainWindow::on_ManageBooks_clicked()
{
    ptrManageBooks->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrMemberManagement->show();
}




