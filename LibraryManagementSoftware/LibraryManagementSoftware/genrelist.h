#ifndef GENRELIST_H
#define GENRELIST_H

#include <QDialog>

namespace Ui {
class genrelist;
}

class genrelist : public QDialog
{
    Q_OBJECT

public:
    explicit genrelist(QWidget *parent = nullptr);
    ~genrelist();
    QString genre;

private:
    Ui::genrelist *ui;
};

#endif // GENRELIST_H
