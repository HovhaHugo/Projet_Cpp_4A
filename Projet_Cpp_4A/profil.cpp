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
    affichageBDDProfil();
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

//FONCTIONS QT

void Profil::affichageBDDProfil(){
    modele = new QStandardItemModel(0,2);

    //creation du vecteur comprenant toutes les BDD
    BDD *db1 = new BDD(1, "bdd1", "C:/Users/benja/OneDrive/Bureau/test/test.SQLite");
    BDD *db2 = new BDD(2, "bdd2", "C:/Users/benja/OneDrive/Bureau/test/test2.SQLite");
    vector<BDD> vecteurBDD;
    vecteurBDD.push_back(*db1);
    vecteurBDD.push_back(*db2);

    //Parcours par lignes dans un elements :
    int row = 0;
    while(row<2){
        string id = to_string(vecteurBDD[row].getIdentifiant());
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(id)));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurBDD[row].getLabel())));
        row++;
    }

    //Labels des colonnes
    modele->setHeaderData(0,Qt::Horizontal,"Identifiant");
    modele->setHeaderData(1,Qt::Horizontal,"Label");

    ui->tableView->setModel(modele);
}
