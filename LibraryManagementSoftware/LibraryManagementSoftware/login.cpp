#include "login.h"
#include "ui_login.h"
#include<QDebug>

#define path_to_DB "H:/C++ QT/library_management_system/LibraryManagementSoftware/LibraryManagementSoftware/Database/signInInfo.db"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ptrMainWindow = new MainWindow();
    ptrSignUp = new signup();
}



void Login::on_pushButton_clicked()
{
    QString username, password;
    //1. EDIT OBJECT NAMES
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();


    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase mydb= QSqlDatabase::addDatabase("QSQLITE");
    //set database path
    mydb.setDatabaseName(path_to_DB);


    //Check if file exists
    if(QFile::exists(path_to_DB))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }


    if(!mydb.open())
    {
         qDebug() << "Error: Unable to open Database";

    }
    else
    {
       qDebug() <<"Database opened successfully";
    }

    /****************************************Adding SQL Query**************************/
    // Execute the SQL query to check if the username and password entered are valid
    QSqlQuery qry;
    if (qry.exec("SELECT * FROM signInInfo WHERE username='" + username + "' AND password='" + password + "'")) {
       if (qry.next()) {
           ui->status->setText("Valid username and password. Welcome!");
           ptrMainWindow->show();
           close();
           ;
       } else {
           ui->status->setText("Invalid username or password.");
       }
    } else {
       ui->status->setText("Failed to execute query.");
       qDebug() << qry.lastError().text();
    }
}





Login::~Login()
{
    delete ui;
    delete ptrSignUp;
    delete ptrMainWindow;
}




void Login::on_pushButton_2_clicked()
{
    ptrSignUp->show();
}

