#ifndef EDIT_MEMBER_H
#define EDIT_MEMBER_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class Edit_member;
}

class Edit_member : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_member(QWidget *parent = nullptr);
    ~Edit_member();

private slots:
    void on_Gender_comboBox_currentTextChanged(const QString &arg1);

    void on_Edit_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Edit_member *ui;
     QSqlDatabase myDB;
     QString Gender;
};

#endif // EDIT_MEMBER_H
