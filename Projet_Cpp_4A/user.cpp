#include "user.h"
#include "ui_user.h"

User::User() {
    admin = false;
    profils = new Profil();
}

User::User(QWidget *parent): QDialog(parent), ui(new Ui::User)
{
    ui->setupUi(this);
}

User::User(const string login, const string nom, const string prenom, const string mdp, bool admin)
{
    this->login = login;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
    this->admin = admin;
    profils = new Profil();
}

User::~User(){
    delete(profils);
}

bool User::verifyLogin(const string loginTest, const string mdpTest){
    if(loginTest == login && mdpTest == mdp)
        return true;
    else return false;
}
