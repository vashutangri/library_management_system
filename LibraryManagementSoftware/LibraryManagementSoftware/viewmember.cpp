#include "viewmember.h"
#include "ui_viewmember.h"

#define PathToDB "H:/C++ QT/library_management_system/LibraryManagementSoftware/LibraryManagementSoftware/Database/members_info.db"

ViewMember::ViewMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);
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



ViewMember::~ViewMember()
{
    delete ui;
}

void ViewMember::on_Load_btn_clicked()
{

    QSqlQueryModel *Modal = new QSqlQueryModel();
    if (!myDB.isOpen()) {
        qDebug() << "No connection to db...";
        return;
    }
    else {
        QSqlQuery qry(myDB);
        qry.prepare("select * from Members ");
//        qry.addBindValue(Memberid);
        if (qry.exec()) {
            Modal ->setQuery(qry);
            ui->tableView->setModel(Modal);

            ui->status->setText(" ");
        }
        else {
            ui->status->setText("Failed to view memebers");
        }
    }
}
