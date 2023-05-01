#include "edit_member.h"
#include "ui_edit_member.h"

#define PathToDB "H:/C++ QT/library_management_system/LibraryManagementSoftware/LibraryManagementSoftware/Database/members_info.db"

Edit_member::Edit_member(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_member)
{
    ui->setupUi(this);


    //connecting databse
    myDB = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
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

    // Initialize Gender as an empty string
    Gender = "";
}




Edit_member::~Edit_member()
{
    delete ui;
}




//function to take input from the combobox
void Edit_member::on_Gender_comboBox_currentTextChanged(const QString &arg1)
{
    Gender = ui->Gender_comboBox->currentText();
}




/****Function to edit info when the button is clicked****/

void Edit_member::on_Edit_btn_clicked()
{
    QString ConMemID = ui->IDToConfirm_lineEdit->text();
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
        if (qry.exec("UPDATE Members SET Member_name='" + name + "', Member_ID='" + Memberid + "', Phone_Number='" + Phone_no + "', email='" + Emailid +"', Gender='" + Gender + "' WHERE Member_ID='" + ConMemID + "'")) {
            ui->status->setText("you did it bro!!!!");
        }
        else {
            ui->status->setText("you messed up bro");
        }
    }
}








//close the window
void Edit_member::on_cancel_btn_clicked()
{
    close();
}

