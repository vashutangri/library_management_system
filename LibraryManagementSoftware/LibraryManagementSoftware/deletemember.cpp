#include "deletemember.h"
#include "ui_deletemember.h"

#define PathToDB "H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/members_info.db"

DeleteMember::DeleteMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteMember)
{
    ui->setupUi(this);

    //connect the database
    myDB = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    myDB.setDatabaseName(PathToDB);
    QFileInfo checkfile(PathToDB);

    if(checkfile.isFile()){
        if(myDB.open()){
            ui->status->setText("connected");
        }
        else{
            ui->status->setText("not connected");
        }
    }
    else{
        ui->status->setText("file not open...");
    }
}

DeleteMember::~DeleteMember()
{
    delete ui;
}


void DeleteMember::on_Delete_btn_clicked()
{
    QString Memberid = ui->Id_lineEdit->text(); // Get the Memberid value from a form field

    if (!myDB.isOpen()) {
        qDebug() << "No connection to db...";
        return;
    }
    else {
        //query execution to delete entries
        QSqlQuery qry(myDB);
        qry.prepare("DELETE FROM Members WHERE Member_ID = ?");
        qry.addBindValue(Memberid);
        if (qry.exec()) {
            ui->status->setText("Member deleted successfully.");
        }
        else {
            ui->status->setText("Failed to delete member.");
        }
    }
}



void DeleteMember::on_pushButton_2_clicked()
{
    close();
}

