#include "user.h"
//#include "login.h"

//CONSTRUCTEURS
User::User() {
    admin = false;
}

User::User(const User &user)
{
    this->login = user.login;
    this->mdp = user.mdp;
    this->nom = user.nom;
    this->prenom = user.prenom;
    this->admin = user.admin;
    this->profils = user.profils;
}

User::User(const string login, const string mdp, const string nom, const string prenom, bool admin, vector<Profil> profils)
{
    this->login = login;
    this->mdp = mdp;
    this->nom = nom;
    this->prenom = prenom;
    this->admin = admin;
    this->profils = profils;
}

//DESTRUCTEUR
User::~User(){}

//AUTRES FONCTIONS

void User::delProfil(Profil supProfil){
    int iteration = 0;
    bool find = false;
    while(iteration<=int(profils.size()) && find==false){
        //on cherche si l'iteration a le meme login que l'element a supprimer
        if(profils[iteration].getLogin()==supProfil.getLogin()) find=true;
        else iteration++;
    }
    //if(find) profils.erase(iteration);
}

/**
 * @brief User::verifyLogin
 * verifie si un login et un mot de passe correspondent a ceux de l'objet de la classe
 * @param loginTest
 * string comprenant le login a tester
 * @param mdpTest
 * string comprenant le mot de passe a tester
 * @return
 * un booleen vrai si il y a correspondance, faux sinon
 */
bool User::verifyLogin(const string loginTest, const string mdpTest){
    if(loginTest == login && mdpTest == mdp)
        return true;
    else return false;
}
