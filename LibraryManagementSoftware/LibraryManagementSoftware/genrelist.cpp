#include "genrelist.h"
#include "ui_genrelist.h"

genrelist::genrelist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::genrelist)
{
    ui->setupUi(this);
}

genrelist::~genrelist()
{
    delete ui;
}
