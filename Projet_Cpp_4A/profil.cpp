#include "profil.h"

Profil::Profil() {}

Profil::~Profil() {}

Profil::Profil(const string newLogin,const string newLabel,const bool newStatus) {
    this->login = newLogin;
    this->label = newLabel;
    this->actif = newStatus;
}

