#include "profil.h"
#include "ui_profil.h"

//CONSTRUCTEURS
Profil::Profil() {}

Profil::Profil(const Profil &profil)
{
    this->login = profil.login;
    this->label = profil.label;
    this->acces = profil.acces;
    this->actif = profil.actif;
}

Profil::Profil(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Profil)
{
    ui->setupUi(this);
}

Profil::Profil(const string newLogin,const string newLabel,const bool newStatus) {
    this->login = newLogin;
    this->label = newLabel;
    this->actif = newStatus;
}

//DESTRUCTEUR
Profil::~Profil() {}

//OPERATEURS
Profil Profil::operator=(const Profil& profil){
    Profil* newProfil = new Profil(profil);
    return *newProfil;
}

//AUTRES FONCTIONS

//FONCTIONS QT
