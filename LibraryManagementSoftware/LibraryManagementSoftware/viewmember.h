#ifndef VIEWMEMBER_H
#define VIEWMEMBER_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class ViewMember;
}

class ViewMember : public QDialog
{
    Q_OBJECT

public:
    explicit ViewMember(QWidget *parent = nullptr);
    ~ViewMember();

private slots:
    void on_Load_btn_clicked();

private:
    QSqlDatabase myDB;
    Ui::ViewMember *ui;
};

#endif // VIEWMEMBER_H
