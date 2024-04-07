#include "profil.h"


//CONSTRUCTEURS
Profil::Profil() {}

Profil::Profil(const Profil &profil)
{
    this->login = profil.login;
    this->label = profil.label;
    this->acces = profil.acces;
    this->actif = profil.actif;
}

Profil::Profil(const string newLogin,const string newLabel,const bool newStatus, const vector<BDD> newAcces) {
    this->login = newLogin;
    this->label = newLabel;
    this->actif = newStatus;
    this->acces = newAcces;
}

//DESTRUCTEUR
Profil::~Profil() {}

//OPERATEURS
Profil Profil::operator=(const Profil& profil){
    Profil* newProfil = new Profil(profil);
    return *newProfil;
}

//AUTRES FONCTIONS

void Profil::delBDD(BDD supBDD){
    int iteration = 0;
    bool find = false;
    while(iteration<=int(acces.size()) && find==false){
        //on cherche si l'iteration a le meme login que l'element a supprimer
        if(acces[iteration].getIdentifiant()==supBDD.getIdentifiant()) find=true;
        else iteration++;
    }
    //if(find) acces.erase(iteration);
}
