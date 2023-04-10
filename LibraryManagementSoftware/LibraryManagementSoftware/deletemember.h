#ifndef DELETEMEMBER_H
#define DELETEMEMBER_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>


namespace Ui {
class DeleteMember;
}

class DeleteMember : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteMember(QWidget *parent = nullptr);
    ~DeleteMember();
    QSqlDatabase myDB = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");

private slots:
    void on_Delete_btn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DeleteMember *ui;
};

#endif // DELETEMEMBER_H
