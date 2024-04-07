#include "user.h"
#include "ui_user.h"
#include "login.h"

//CONSTRUCTEURS
User::User() {
    admin = false;
}

User::User(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
    affichageProfilsUser();
}

User::User(const User &user)
{
    this->login = user.login;
    this->mdp = user.mdp;
    this->nom = user.nom;
    this->prenom = user.prenom;
    this->admin = user.admin;
    this->profils = user.profils;
}

User::User(const string login, const string mdp, const string nom, const string prenom, bool admin, vector<Profil> profils)
{
    this->login = login;
    this->mdp = mdp;
    this->nom = nom;
    this->prenom = prenom;
    this->admin = admin;
    this->profils = profils;
}

//DESTRUCTEUR
User::~User(){
    delete ui;
}

//AUTRES FONCTIONS

void User::delProfil(Profil supProfil){
    int iteration = 0;
    bool find = false;
    while(iteration<=int(profils.size()) && find==false){
        //on cherche si l'iteration a le meme login que l'element a supprimer
        if(profils[iteration].getLogin()==supProfil.getLogin()) find=true;
        else iteration++;
    }
    //if(find) profils.erase(iteration);
}

/**
 * @brief User::verifyLogin
 * verifie si un login et un mot de passe correspondent a ceux de l'objet de la classe
 * @param loginTest
 * string comprenant le login a tester
 * @param mdpTest
 * string comprenant le mot de passe a tester
 * @return
 * un booleen vrai si il y a correspondance, faux sinon
 */
bool User::verifyLogin(const string loginTest, const string mdpTest){
    if(loginTest == login && mdpTest == mdp)
        return true;
    else return false;
}

/**
 * @brief User::setUser
 * Permet de sauvegarder le nom, prenom et login de l'utilisateur actuellement connecter.
 * @param login
 * Le login de l'utilisateur actuelle
 * @param nom
 * Le nom de l'utilisateur actuelle
 * @param prenom
 * Le prenom de l'utilisateur actuelle
 */
void User::setUser(string nom, string prenom){

    QString nomQT = QString::fromStdString(nom);
    QString prenomQT = QString::fromStdString(prenom);

    ui->NomLabel->setText(nomQT);
    ui->PrenomLabel->setText(prenomQT);

}

//FONCTIONS QT

/**
 * @brief User::affichageProfilsUser
 * Permet d'ajouter des donnéer dans le tableau pour afficher les profils.
 */
void User::affichageProfilsUser(){
    modele = new QStandardItemModel(0,3);

    //Creation du vecteur comprenant tous les profils
    vector<BDD> acces;
    Profil *profil1 = new Profil("JDo", "Do", 1, acces);
    Profil *profil2 = new Profil("JSmith", "Smith", 0, acces);
    vector<Profil> vecteurProfil;
    vecteurProfil.push_back(*profil1);
    vecteurProfil.push_back(*profil2);

    //Parcours par lignes dans un elements :
    int row = 0;
    while(row<2){
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLogin())));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLabel())));
        if(profil1->getActif() == 1){
            modele->setItem(row,2, new QStandardItem("Actif"));
        }else{
            modele->setItem(row,2, new QStandardItem(""));
        }
        row++;
    }

    //Labels des colonnes
    modele->setHeaderData(0,Qt::Horizontal,"Login");
    modele->setHeaderData(1,Qt::Horizontal,"Label");
    modele->setHeaderData(2,Qt::Horizontal,"Status");

    ui->tableView->setModel(modele);
}

/**
 * @brief User::on_DisconnectButton_clicked
 * fonction associee au bouton pour deconnecter le user de l'application
 */
void User::on_DisconnectButton_clicked()
{
    class login login;
    login.setModal(true);
    login.exec();
}


void User::on_ShowBDDButton_clicked()
{
    /*vector<BDD> acces;
    Profil *profil1 = new Profil("JDo", "Do", 1, acces);
    Profil *profil2 = new Profil("JSmith", "Smith", 0, acces);
    vector<Profil> vecteurProfil;
    vecteurProfil.push_back(*profil1);
    vecteurProfil.push_back(*profil2);*/

    //int selection = ui->tableView->selectionModel()->selectedRows().first().row();
    //Profil profilSelected = vecteurProfil[selection];

    Profil profil = new Profil(nullptr);
    profil.setModal(true);
    profil.exec();
}
