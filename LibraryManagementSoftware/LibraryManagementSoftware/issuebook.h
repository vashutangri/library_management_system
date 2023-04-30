#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QDialog>

namespace Ui {
class issueBook;
}

class issueBook : public QDialog
{
    Q_OBJECT

public:
    explicit issueBook(QWidget *parent = nullptr);
    ~issueBook();

private slots:
    void on_searchBook_clicked();

    void on_searchMember_clicked();

    void on_issue_2_clicked();

    void on_cancel_clicked();

private:
    Ui::issueBook *ui;
};

#endif // ISSUEBOOK_H
