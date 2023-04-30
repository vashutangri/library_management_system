#include "signup.h"
#include "ui_signup.h"

#define path_to_DB "H:/C++ QT/library_management_system/pesonal_Info.db"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    myDB.setDatabaseName(path_to_DB);
    QFileInfo checkFile(path_to_DB);

    if(checkFile.isFile())
    {
        if(myDB.open()){
          ui ->status-> setText("Connected...");
        }
        else{
            ui ->status ->setText("connection failed...");
        }
    }
    else{
        ui ->status ->setText("file not open...");
    }
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    QString username = ui->lineEdit_User->text();
    QString name = ui->lineEdit_Name->text();
    QString password = ui->lineEdit_pass->text();
    if(!myDB.isOpen()){
        qDebug() << "No connection to db...";
        return;
    }
    else{
        QSqlQuery qry(myDB);
        if(qry.exec("INSERT INTO signIninfo (username, name, password) VALUES ('" + username + "', '" + name + "', '" + password + "')")){
            ui->status->setText("you did it bro!!!!");
        }
        else{
            ui->status->setText("you messed up bro");
        }
    }
}

