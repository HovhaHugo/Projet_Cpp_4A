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
    User user;

private slots:
    void affichageProfilsUser();

    void on_DisconnectButton_clicked();
    void on_tableView_clicked();
    void on_ShowBDDButton_clicked();

public:
    UserDialog();
    UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

    void setUser(User newUser){user = newUser; affichageProfilsUser();};
    User getUser(){return user;};

};

#endif // M_USERS_H
