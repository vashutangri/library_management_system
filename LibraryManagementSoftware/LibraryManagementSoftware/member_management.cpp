#include "member_management.h"
#include "ui_member_management.h"



Member_management::Member_management(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Member_management)
{
    ui->setupUi(this);
    ptrAddMember = new AddMember;
    ptrDeleteMember = new DeleteMember;
    ptrEditMember = new Edit_member;
    ptrViewMember = new ViewMember;

}

Member_management::~Member_management()
{
    delete ptrAddMember;
    delete ptrDeleteMember;
    delete ptrEditMember;
    delete ptrViewMember;
    delete ui;
}





void Member_management::on_Delete_btn_clicked()
{
    ptrDeleteMember->show();
}


void Member_management::on_MemberList_btn_clicked()
{
    ptrViewMember->show();
}


void Member_management::on_AddMember_btn_clicked()
{
    ptrAddMember->show();
}


void Member_management::on_EditInfo_btn_clicked()
{
    ptrEditMember->show();
}
