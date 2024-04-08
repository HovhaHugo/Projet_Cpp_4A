#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"
#include "userdialog.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

    void setProfil(string loginUserSelect, string loginProfilSelect);
    void setUsers(vector<User> listUser){users = listUser;};

private slots:
    void on_ButtonValider_clicked();

private:
    Ui::login *ui;
    UserDialog *user;
    vector<User> users;

};

#endif
