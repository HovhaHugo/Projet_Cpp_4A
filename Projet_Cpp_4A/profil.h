#ifndef PROFIL_H
#define PROFIL_H

#include "bdd.h"

class Profil
{
private:
    string login;
    string label;
    BDD* acces;
public:
    Profil();
    ~Profil();

    // Getters
    string getLogin() { return login; }
    string getLabel() { return label; }
    BDD* getAcces() { return acces; }

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setAcces(BDD* newAcces) { acces = newAcces; /*mieux gérer le pointeur*/}
};

#endif // PROFIL_H
