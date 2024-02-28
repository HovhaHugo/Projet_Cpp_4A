#include "user.h"
#include "ui_user.h"
#include "login.h"

//CONSTRUCTEURS
User::User() {
    admin = false;
}

User::User(QWidget *parent): QDialog(parent), ui(new Ui::User)
{
    ui->setupUi(this);
    affichageProfilsUser();
}

User::User(const User &user)
{
    this->login = user.login;
    this->nom = user.nom;
    this->prenom = user.prenom;
    this->mdp = user.mdp;
    this->admin = user.admin;
    this->profils = user.profils;
}

User::User(const string login, const string nom, const string prenom, const string mdp, bool admin)
{
    this->login = login;
    this->nom = nom;
    this->prenom = prenom;
    this->mdp = mdp;
    this->admin = admin;
}

//DESTRUCTEUR
User::~User(){
    delete ui;
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
void User::setUser(string login, string nom, string prenom){

    QString nomQT = QString::fromStdString(nom);
    QString prenomQT = QString::fromStdString(prenom);

    ui->NomLabel->setText(nomQT);
    ui->PrenomLabel->setText(prenomQT);

}

/**
 * @brief User::affichageProfilsUser
 * Permet d'ajouter des donnéer dans le tableau pour afficher les profils.
 */
void User::affichageProfilsUser(){
    modele = new QStandardItemModel(0,4);
    /*
    Parcours par lignes dans un elements :
    int row = 0;
    while(il y a des élements){
        for(int j=0, j<4, j++){
            QStandardItem *item = new QStandardItem(String);
            model->setItem(row,j, item);
        }
    }
    row++;
    */

    Profil *profil1 = new Profil("JDo", "Test", 1);
    QStandardItem *profils1Nom = new QStandardItem("John");
    QStandardItem *profils1Prenom = new QStandardItem("Do");
    modele->setItem(0,0, profils1Nom);
    modele->setItem(0,1, profils1Prenom);
    modele->setItem(0,2, new QStandardItem(QString::fromStdString(profil1->getLogin())));
    if(profil1->getActif() == 1){
        modele->setItem(0,3, new QStandardItem("Actif"));
    }else{
        modele->setItem(0,3, new QStandardItem(""));
    }

    QStandardItem *profils2Nom = new QStandardItem("James");
    QStandardItem *profils2Prenom = new QStandardItem("Smith");
    QStandardItem *profils2Login = new QStandardItem("JSmith");
    bool profil2Status = 0;
    modele->setItem(1,0, profils2Nom);
    modele->setItem(1,1, profils2Prenom);
    modele->setItem(1,2, profils2Login);
    if(profil2Status == 1){
        modele->setItem(1,3, new QStandardItem("Actif"));
    }else{
        modele->setItem(1,3, new QStandardItem(""));
    }

    modele->setHeaderData(0,Qt::Horizontal,"Nom");
    modele->setHeaderData(1,Qt::Horizontal,"Prenom");
    modele->setHeaderData(2,Qt::Horizontal,"Login");
    modele->setHeaderData(3,Qt::Horizontal,"Status");

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

