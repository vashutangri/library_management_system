#include "issuebook.h"
#include "qsqlquery.h"
#include "ui_issuebook.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QFile>

issueBook::issueBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::issueBook)
{
    ui->setupUi(this);

    this->setWindowTitle("Issue Book");

    ui->issueDate->setDate(QDate::currentDate());
    ui->returnDate->setDate(QDate::currentDate());
}

issueBook::~issueBook()
{
    delete ui;
}

void issueBook::on_searchBook_clicked()
{
    //Get the ID
    QString bookID = ui->bookID->text();
    QString bookName;
    int quantity;

    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db");

    //Check if file exists
    if(QFile::exists("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db"))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }

    //OPEN DATABASE FILE
    if(!database.open()) {
        qDebug() << "Error: Unable to open Database";
    }
    else {
        qDebug() <<"Database opened successfully";
    }

    //search the book
    auto query = QSqlQuery(database);
    QString searchBook{"SELECT * FROM books WHERE ID = '%1'"};
    if(!query.exec(searchBook.arg(bookID)))
        qDebug() << "Cannot select from  books";

    int count = 0;
    while(query.next())
        count++;
    if(count > 0)
    {
        if(query.first())
        {
            bookName = query.value(2).toString();

            ui->bookName->setText(bookName);



            quantity = query.value(5).toInt();
            if(quantity > 0)
            {
                 ui->available->setText("Yes");
                 ui->available->setStyleSheet("QLabel {color : green; font: 10pt Comic Sans MS;}");
            }
            else
            {
                ui->available->setText("No");
                ui->available->setStyleSheet("QLabel {color : red; font: 10pt Comic Sans MS;}");
            }

        }
    }
    else
        QMessageBox::critical(this,"Failed", "Book Not found");

}


void issueBook::on_searchMember_clicked()
{
    //Get the ID
    QString memberID = ui->memberID->text();
    QString memberName;

    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db");

    //Check if file exists
    if(QFile::exists("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db"))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }

    //OPEN DATABASE FILE
    if(!database.open()) {
        qDebug() << "Error: Unable to open Database";
    }
    else {
        qDebug() <<"Database opened successfully";
    }

    //search the member
    auto query = QSqlQuery(database);
    QString searchMember{"SELECT * FROM members WHERE ID = '%1'"};
    if(!query.exec(searchMember.arg(memberID)))
        qDebug() << "Cannot select from  members";

    int count = 0;
    while(query.next())
        count++;

    if(count > 0)
    {
        if(query.first())
        {
            memberName = query.value(1).toString();
            ui->memberName->setText(memberName);
        }
    }
    else
        QMessageBox::critical(this,"Failed", "Member Not found");


}


void issueBook::on_issue_2_clicked()
{
    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db");

    //Check if file exists
    if(QFile::exists("H:/C++ QT/library_management_system/LibraryManagementSoftware/Database/LibraryManagement.db"))
        qDebug() << "Database File Exists";
    else
    {
        qDebug() << "Database File Does Not Exist";
        return;
    }

    //OPEN DATABASE FILE
    if(!database.open()) {
        qDebug() << "Error: Unable to open Database";
    }
    else {
        qDebug() <<"Database opened successfully";
    }

    //retrieve the IDs
    QString bookID = ui->bookID->text();
    QString memberID = ui->memberID->text();
    QString status{"Issued"};
    QString issueDate = ui->issueDate->text();
    QString returnDate = ui->returnDate->text();
    QString notes = ui->notes->toPlainText();

    //retrieve the issueDate
    QStringList dateList_1 = issueDate.split("/");
    QDate Date_1;
    if(dateList_1.length() == 3)
        Date_1 = QDate(dateList_1[2].toInt(), dateList_1[1].toInt(), dateList_1[0].toInt());

    //Retrieve the return Date
    QStringList dateList_2 = returnDate.split("/");
    QDate Date_2;
    if(dateList_2.length() == 3)
        Date_2 = QDate(dateList_2[2].toInt(), dateList_2[1].toInt(), dateList_2[0].toInt());

    //test
    if(Date_1 > Date_2)
        QMessageBox::critical(this, "Failed", "The return date must be after the issue Date");
    else{
        auto query = QSqlQuery(database);
        QString insert{"INSERT INTO bookStatus (Book, Member, Status, IssueDate, ReturnDate, Note) VALUES ('%1', '%2','%3', '%4', '%5','%6')"};
        if(!query.exec(insert.arg(bookID.toInt()).arg(memberID.toInt()).arg(status).arg(issueDate).arg(returnDate).arg(notes)))
        {
            qDebug() << "cannot fill bookStatus";
        }
        else
            QMessageBox::information(this, "SUCCESS", "Book issued successfully");
    }
}


void issueBook::on_cancel_clicked()
{
    this->hide();
}

