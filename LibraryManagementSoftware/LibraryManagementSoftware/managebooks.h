#ifndef MANAGEBOOKS_H
#define MANAGEBOOKS_H

#include <QDialog>
#include <addbook.h>
#include <editbook.h>
#include <deletebook.h>
#include <findbook.h>
#include <issuebook.h>


namespace Ui {
class ManageBooks;
}

class ManageBooks : public QDialog
{
    Q_OBJECT

public:
    explicit ManageBooks(QWidget *parent = nullptr);
    ~ManageBooks();

private slots:
    void on_AddBook_clicked();

 //   void on_EditBook_clicked();

    void on_DeleteBook_clicked();

    void on_FindBook_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ManageBooks *ui;
    AddBook * ptrAddBook;
 //   EditBook * ptrEditBook;
    DeleteBook * ptrDeleteBook;
    FindBook * ptrFindBook;
    issueBook * ptrIssueBook;
};

#endif // MANAGEBOOKS_H
