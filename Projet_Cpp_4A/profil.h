#ifndef PROFIL_H
#define PROFIL_H

#include "bdd.h"
#include <vector>

class Profil
{
private:
    string login;
    string label;
    vector<BDD> acces;
public:
    Profil();
    ~Profil();

    // Getters
    string getLogin() { return login; }
    string getLabel() { return label; }
    vector<BDD> getAcces() { return acces; }

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setAcces(vector<BDD> newAcces) { acces = newAcces; /*mieux gérer le pointeur*/}
};

#endif // PROFIL_H
