#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>
#include <managebooks.h>
#include <member_management.h>
#include <issuebook.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ManageBooks_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    ManageBooks * ptrManageBooks;
    Login * ptrLogin;
    Member_management * ptrMemberManagement;
    issueBook * ptrIssueBook;

};
#endif // MAINWINDOW_H
