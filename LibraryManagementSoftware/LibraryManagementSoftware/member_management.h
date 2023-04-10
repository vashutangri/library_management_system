#ifndef MEMBER_MANAGEMENT_H
#define MEMBER_MANAGEMENT_H

#include <QDialog>
#include "addmember.h"
#include "edit_member.h"
#include "deletemember.h"
#include "viewmember.h"


namespace Ui {
class Member_management;
}

class Member_management : public QDialog
{
    Q_OBJECT

public:
    explicit Member_management(QWidget *parent = nullptr);
    ~Member_management();

private slots:
    void on_AddMember_btn_clicked();

    void on_EditInfo_btn_clicked();

    void on_MemberList_btn_clicked();

    void on_Delete_btn_clicked();

private:
    Ui::Member_management *ui;
    AddMember * ptrAddMember;
    Edit_member * ptrEditMember;
    DeleteMember * ptrDeleteMember;
    ViewMember * ptrViewMember;
};

#endif // MEMBER_MANAGEMENT_H
