#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "QStandardItemModel"

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

private slots:
    void affichageProfilsUser();

    void on_DisconnectButton_clicked();
    void on_tableView_clicked();
    void on_ShowBDDButton_clicked();

public:
    UserDialog();
    UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

    void setUser(string login, string nom, string prenom);

};

#endif // M_USERS_H