#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class AddMember;
}

class AddMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent = nullptr);
    ~AddMember();
    QSqlDatabase myDB = QSqlDatabase::addDatabase("QSQLITE","SQLITE");
    QString Gender;
private slots:
    void on_Gender_comboBox_currentTextChanged(const QString &arg1);

    void on_Add_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddMember *ui;
};

#endif // ADDMEMBER_H
