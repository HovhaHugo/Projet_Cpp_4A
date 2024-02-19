#include "users.h"

Users::Users() {
    admin = false;
    profils = new Profil();
}

Users::Users(const string login, const string nom, const string prenom, const string mdp, bool admin)
{
    this->login = login;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
    this->admin = admin;
    profils = new Profil();
}

Users::~Users(){
    delete(profils);
}

bool Users::verifyLogin(const string loginTest, const string mdpTest){
    if(loginTest == login && mdpTest == mdp)
        return true;
    else return false;
}
