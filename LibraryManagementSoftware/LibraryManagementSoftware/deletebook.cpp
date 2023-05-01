#include "deletebook.h"
#include "ui_deletebook.h"

#define path_to_DB "H:/C++ QT/library_management_system/LibraryManagementSoftware/LibraryManagementSoftware/Database/LibraryManagement.db"

DeleteBook::DeleteBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBook)
{
    ui->setupUi(this);
    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName(path_to_DB);

    //Check if file exists
    if(QFile::exists(path_to_DB))
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
}

DeleteBook::~DeleteBook()
{
    delete ui;
}

void DeleteBook::on_btnDeleteBook_clicked()
{
    //Following code is for Database Connectivity.
    //First Define database object name
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    //Set database path
    database.setDatabaseName(path_to_DB);

    //Check if file exists
    if(QFile::exists(path_to_DB))
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

    QString bookID= ui->txtBookID->text();
    if (!database.isOpen()) {
        qDebug() << "No connection to db...";
        return;
    }
    else {
        //query execution to delete entries
        QSqlQuery qry(database);
        qry.prepare("DELETE FROM BookDetails WHERE ID = ?");
        qry.addBindValue(bookID);
        if (qry.exec()) {
            ui->status->setText("Book deleted successfully.");
        }
        else {
            ui->status->setText("Failed to delete Book.");
        }
    }
}


void DeleteBook::on_btnCancel_clicked()
{
    this->hide();
}

