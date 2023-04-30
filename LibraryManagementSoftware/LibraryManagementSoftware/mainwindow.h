#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <managebooks.h>
#include <member_management.h>


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

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    ManageBooks * ptrManageBooks;
    Member_management * ptrMemberManagement;
};
#endif // MAINWINDOW_H
