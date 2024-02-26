#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_ButtonValider_clicked();

private:
    Ui::login *ui;
    User *user;

};

#endif
