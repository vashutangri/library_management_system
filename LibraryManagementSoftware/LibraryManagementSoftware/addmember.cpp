#include "addmember.h"
#include "ui_addmember.h"

#include <QDebug>

#define PathToDB "H:/C++ QT/library_management_system/LibraryManagementSoftware/LibraryManagementSoftware/Database/members_info.db"

AddMember::AddMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);
    myDB.setDatabaseName(PathToDB);
    QFileInfo checkfile(PathToDB);

    if(checkfile.isFile()){
        if(myDB.open()){
            ui->status->setText("connected");

        }
        else{
            ui->status ->setText("not connected");

        }
    }
    else{
        ui ->status ->setText("file not open...");
    }


}

AddMember::~AddMember()
{
    delete ui;
    myDB.close();
}

void AddMember::on_Gender_comboBox_currentTextChanged(const QString &arg1)
{
    // Update Gender when the combo box changes
    Gender = ui->Gender_comboBox->currentText();
}

void AddMember::on_Add_pushButton_clicked()
{
    QString name = ui->Name_lineEdit->text();
    QString Memberid = ui->MemberID_lineEdit->text();
    QString Phone_no = ui->PNo_lineEdit->text();
    QString Emailid = ui->Email_lineEdit->text();

    if (!myDB.isOpen()) {
        qDebug() << "No connection to db...";
        return;
    }
    else {
        QSqlQuery qry(myDB);
        if (qry.exec("INSERT INTO Members (Member_name,Member_ID,Phone_Number,email,Gender) VALUES ('" + name + "', '" + Memberid + "', '" + Phone_no + "','" + Emailid +"','"+Gender+"')")) {
            ui->status->setText("you did it bro!!!!");
        }
        else {
            ui->status->setText("you messed up bro");
        }
    }
}


//                    AddMember::~AddMember()
//        {
//                    delete ui;
//                    myDB.close();
//}

void AddMember::on_pushButton_2_clicked()
{
    close();
}

