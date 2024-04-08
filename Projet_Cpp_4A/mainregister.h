#ifndef MAINREGISTER_H
#define MAINREGISTER_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class MainRegister;
}

class MainRegister : public QMainWindow
{
    Q_OBJECT

public:
    MainRegister(QWidget *parent = nullptr);
    ~MainRegister();

    vector<User> getUser(){return listUser;}
    void setUsers(vector<User> listUser){this->listUser = listUser;};

private slots:
    void on_ButtonValider_clicked();

private:
    Ui::MainRegister *ui;
    vector<User> listUser;
};

#endif // MAINREGISTER_H
