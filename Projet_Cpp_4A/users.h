#ifndef USERS_H
#define USERS_H

#include "profil.h"

class Users
{

private:
    char* login;
    char* nom;
    char* prenom;
    char* mdp;
    bool admin;
    Profil* profils;
public:
    Users();
};

#endif // M_USERS_H
