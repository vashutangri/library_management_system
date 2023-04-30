#include "digitallibrary.h"
#include "ui_digitallibrary.h"

digitalLibrary::digitalLibrary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::digitalLibrary)
{
    ui->setupUi(this);
}

digitalLibrary::~digitalLibrary()
{
    delete ui;
}
