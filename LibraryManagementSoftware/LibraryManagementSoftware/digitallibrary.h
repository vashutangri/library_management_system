#ifndef DIGITALLIBRARY_H
#define DIGITALLIBRARY_H

#include <QDialog>

namespace Ui {
class digitalLibrary;
}

class digitalLibrary : public QDialog
{
    Q_OBJECT

public:
    explicit digitalLibrary(QWidget *parent = nullptr);
    ~digitalLibrary();

private:
    Ui::digitalLibrary *ui;
};

#endif // DIGITALLIBRARY_H
