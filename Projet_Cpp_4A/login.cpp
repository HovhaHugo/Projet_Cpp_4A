#include "globals.h"

#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "user.h"
#include "userwindow.h"

login::login(QWidget *parent): QDialog(parent), ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

/**
 * @brief login::on_ButtonValider_clicked
 * Permet de faire la vérification des logins/mdp à la connexion.
 */
void login::on_ButtonValider_clicked()
{
    //On récupére les lignes de saisie pour le mots de passe et l'identifiant
    QString idLine = ui->idLine->text();
    QString mdpLine = ui->mdpLine->text();

    //On verifie que le mdp et le login soit correct
    bool Connexion = false;
    vector<User> listeUsers = globalUserManager.getListeUsers();    //la liste des Users tirées du json

    for(int ItUser=0; ItUser<int(listeUsers.size()); ItUser++){
        if (idLine.toStdString() == listeUsers[ItUser].getLogin() && mdpLine.toStdString() == listeUsers[ItUser].getMdp()){
            Connexion = true;
            hide();
            UserWindow userWindow = new UserWindow(nullptr);
            userWindow.setUser(listeUsers[ItUser].getLogin(), listeUsers[ItUser].getNom(), listeUsers[ItUser].getPrenom());
            userWindow.setModal(true);
            userWindow.exec();
        }
    }
    if(Connexion == false) QMessageBox::warning(this,"Login","Le login n'est pas bon !");
}

