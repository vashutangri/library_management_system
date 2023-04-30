#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include <QDialog>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
    QSqlDatabase myDB;
};

#endif // SIGNUP_H
