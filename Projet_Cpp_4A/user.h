#ifndef USER_H
#define USER_H

#include "profil.h"

using namespace std;

class User
{
private:
    string login;
    string mdp;
    string nom;
    string prenom;
    bool admin;
    vector<Profil> profils;

public:
    User();
    User(const User &user);
    User(const string login, const string mdp, const string nom, const string prenom, const bool admin, const vector<Profil> profils);
    ~User();

    // Getters
    string getLogin() { return login; }
    string getMdp() { return mdp; }
    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    bool isAdmin() { return admin; }
    vector<Profil> getProfil() { return profils; }

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setMdp(const string newMdp) { mdp = newMdp; }
    void setNom(const string newNom) { nom = newNom; }
    void setPrenom(const string newPrenom) { prenom = newPrenom; }
    void setAdmin(bool isAdmin) { admin = isAdmin; }
    void setProfil(vector<Profil> newProfils) { profils = newProfils;}
    void addProfil(Profil newProfil) { profils.push_back(newProfil); }
    void delProfil(Profil supProfil);

    bool verifyLogin(const string loginTest, const string mdpTest);
    Profil searchProfilByLogin(const string loginTest);
};

#endif // USER_H
