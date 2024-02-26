#ifndef PROFIL_H
#define PROFIL_H

#include "bdd.h"

class Profil
{
private:
    char* login;
    char* label;
    BDD* acces;
public:
    Profil();

};

#endif // PROFIL_H
