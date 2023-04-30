#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "qsqldatabase.h"
#include <QDialog>

namespace Ui {
class returnBook;
}

class returnBook : public QDialog
{
    Q_OBJECT

public:
    explicit returnBook(QWidget *parent = nullptr);
    void showInfo();
    QSqlDatabase setDatabase();
    ~returnBook();

private slots:
    void on_returnBtn_clicked();

    void on_lostBtn_clicked();

    void on_deleteBtn_clicked();

    void on_bookStatus_currentIndexChanged(int index);

private:
    Ui::returnBook *ui;
};

#endif // RETURNBOOK_H
