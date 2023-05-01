#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class DeleteBook;
}

class DeleteBook : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBook(QWidget *parent = nullptr);
    ~DeleteBook();

private slots:
    void on_btnDeleteBook_clicked();

    void on_btnCancel_clicked();

private:
    Ui::DeleteBook *ui;
};

#endif // DELETEBOOK_H
