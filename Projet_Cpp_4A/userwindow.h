#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "QStandardItemModel"
#include "profildialog.h"

using namespace std;


namespace Ui {
class UserWindow;
}

class UserWindow :public QDialog
{
    Q_OBJECT

private:
    Ui::UserWindow *ui;
        QStandardItemModel *modele;

private slots:
    void affichageProfilsUser();

    void on_DisconnectButton_clicked();
    void on_ShowBDDButton_clicked();

public:
    UserWindow();
    UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

    void setUser(string nom, string prenom);

};

#endif // M_USERS_H
