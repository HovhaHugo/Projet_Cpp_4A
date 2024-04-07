#ifndef PROFIL_H
#define PROFIL_H

#include "bdd.h"
#include <vector>

class Profil
{
private:

    string login;
    string label;
    bool actif;
    vector<BDD> acces;


public:
    Profil();
    Profil(const Profil &profil);
    Profil(const string newLogin,const string newLabel,const bool newStatus, const vector<BDD> newAcces);
    ~Profil();

    //Operators
    Profil operator=(const Profil& profil);

    // Getters
    string getLogin() { return login; }
    string getLabel() { return label; }
    vector<BDD> getAcces() { return acces; }
    bool getActif(){return actif;}

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setActif(const bool newStatus) { actif = newStatus; }
    void setAcces(vector<BDD> newAcces) { acces = newAcces;}
    void addBDD(BDD newBDD) { acces.push_back(newBDD);}
    void delBDD(BDD delBDD);
};

#endif // PROFIL_H
