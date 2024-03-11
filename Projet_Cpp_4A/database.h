#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>

namespace Ui {
class database;
}

class database : public QDialog
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = nullptr);
    ~database();

private:
    Ui::database *ui;
};

#endif // DATABASE_H
