#ifndef USERS_H
#define USERS_H

#include "profil.h"


class Users
{
private:
    string login;
    string nom;
    string prenom;
    string mdp;
    bool admin;
    Profil* profils;
public:
    Users();
    Users(const string login, const string nom, const string prenom, const string mdp, bool admin);
    ~Users();

    // Getters
    string getLogin() { return login; }
    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    string getMdp() { return mdp; }
    bool isAdmin() { return admin; }
    Profil* getProfil() { return profils; }

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setNom(const string newNom) { nom = newNom; }
    void setPrenom(const string newPrenom) { prenom = newPrenom; }
    void setMdp(const string newMdp) { mdp = newMdp; }
    void setAdmin(bool isAdmin) { admin = isAdmin; }
    void setProfil(Profil* newProfils) { profils = newProfils; /*mieux gérer le pointeur*/}

    bool verifyLogin(const string loginTest, const string mdpTest);
};

#endif // M_USERS_H
