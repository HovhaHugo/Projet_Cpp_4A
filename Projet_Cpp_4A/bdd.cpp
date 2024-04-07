#include "bdd.h"

//CONSTRUCTEUR
BDD::BDD() {}

BDD::BDD(int newIdentifiant, string newLabel, string newPath){
    this->identifiant = newIdentifiant;
    this->label = newLabel;
    this->path = newPath;
}
