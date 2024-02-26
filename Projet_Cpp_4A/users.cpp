#include "users.h"

Users::Users() {
    admin = false;
}

Users::Users(const string login, const string nom, const string prenom, const string mdp, bool admin)
{
    this->login = login;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
    this->admin = admin;
}

Users::~Users(){}

bool Users::verifyLogin(const string loginTest, const string mdpTest){
    if(loginTest == login && mdpTest == mdp)
        return true;
    else return false;
}
