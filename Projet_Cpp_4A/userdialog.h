#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "QStandardItemModel"
#include "user.h"

using namespace std;


namespace Ui {
class UserDialog;
}

class UserDialog :public QDialog
{
    Q_OBJECT

private:
    Ui::UserDialog *ui;
    QStandardItemModel *modele;

    string loginUser;
    vector<User> users;

private slots:
    void affichageProfilsUser();

    void on_DisconnectButton_clicked();
    void on_tableView_clicked();
    void on_ShowBDDButton_clicked();
    void on_AdminButton_clicked();

public:
    UserDialog();
    UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

    void setUser(string login, string nom, string prenom);
    void setUsers(vector<User> listUser){users = listUser;};
    vector<User> getUser(){return users;};

};

#endif // M_USERS_H
