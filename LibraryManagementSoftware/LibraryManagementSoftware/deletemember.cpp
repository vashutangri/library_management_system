#include "deletemember.h"
#include "ui_deletemember.h"

deleteMember::deleteMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteMember)
{
    ui->setupUi(this);
}

deleteMember::~deleteMember()
{
    delete ui;
}
