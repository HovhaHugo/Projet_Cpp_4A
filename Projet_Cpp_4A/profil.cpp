#include "profil.h"

Profil::Profil() {
    acces = new BDD();
}

Profil::~Profil() {
    delete(acces);
}
