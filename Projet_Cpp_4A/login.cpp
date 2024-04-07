#include "globals.h"

#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "user.h"

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
    //On créer 2 utilisateurs pour tester si l'application fonctionne.
    vector<Profil> profils;
    User test1 = User("Test", "test1234", "Do", "John", 1, profils);
    User test2 = User("Test2", "test", "Smith", "James", 1, profils);

    //On récupére les lignes de saisie pour le mots de passe et l'identifiant
    QString idLine = ui->idLine->text();
    QString mdpLine = ui->mdpLine->text();


    bool Connexion = false;
    vector<User> listeUsers = globalUserManager.getListeUsers();    //la liste des Users tirées du json
        //On verifie que le mdp et le login soit correct
        if (idLine.toStdString() == test1.getLogin() && mdpLine.toStdString() == test1.getMdp()){
            Connexion = true;
            hide();
            User user = new User(nullptr);
            user.setUser( test1.getNom(), test1.getPrenom());
            user.setModal(true);
            user.exec();
        }else{
            if (idLine.toStdString() == test2.getLogin() && mdpLine.toStdString() == test2.getMdp()){
                Connexion = true;
                hide();
                User user = new User(nullptr);
                user.setUser( test2.getNom(), test2.getPrenom());
                user.setModal(true);
                user.exec();
            }
        }
        if(Connexion == false) QMessageBox::warning(this,"Login","Le login n'est pas bon !");

    /*
    for(int ItUser=0; ItUser<listeUsers.size(); ItUser++){
        if (idLine.toStdString() == listeUsers[ItUser].getLogin() && mdpLine.toStdString() == listeUsers[ItUser].getMdp()){
            Connexion = true;
            hide();
            User user = new User(nullptr);
            user.setUser(listeUsers[ItUser].getLogin(), listeUsers[ItUser].getNom(), listeUsers[ItUser].getPrenom());
            user.setModal(true);
            user.exec();
        }
    }*/
}

