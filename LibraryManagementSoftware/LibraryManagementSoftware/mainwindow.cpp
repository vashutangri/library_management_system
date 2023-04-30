#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrManageBooks = new ManageBooks();
    ptrLogin = new Login();
    ptrMemberManagement = new Member_management();
    ptrIssueBook = new issueBook();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrManageBooks;
    delete ptrLogin;
    delete ptrMemberManagement;
    delete ptrIssueBook;
}



void MainWindow::on_ManageBooks_clicked()
{
    ptrManageBooks->show();
}


void MainWindow::on_pushButton_clicked()
{
    ptrLogin->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrMemberManagement->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrIssueBook->show();
}

