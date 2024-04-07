#include "globals.h"

#include "userwindow.h"
#include "profil.h"
#include "ui_userwindow.h"
#include "login.h"

//CONSTRUCTEURS
UserWindow::UserWindow() {}

UserWindow::UserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
}


//DESTRUCTEUR
UserWindow::~UserWindow(){
    delete ui;
}

//AUTRES FONCTIONS

/**
 * @brief UserWindow::setUser
 * Permet de sauvegarder le nom et prenom de l'utilisateur actuellement connecter.
 * @param nom
 * Le nom de l'utilisateur actuelle
 * @param prenom
 * Le prenom de l'utilisateur actuelle
 */
void UserWindow::setUser(string login, string nom, string prenom){
    loginUser = login; //on enregistre le login de l'utilisateur actuellement connecté

    QString nomQT = QString::fromStdString(nom);
    QString prenomQT = QString::fromStdString(prenom);

    ui->NomLabel->setText(nomQT);
    ui->PrenomLabel->setText(prenomQT);

    affichageProfilsUser();
}

//FONCTIONS QT

/**
 * @brief UserWindow::affichageProfilsUser
 * Permet d'ajouter des donnéer dans le tableau pour afficher les profils.
 */
void UserWindow::affichageProfilsUser(){
    modele = new QStandardItemModel(0,3);

    //Creation du vecteur comprenant tous les profils
    User Utilisateur = globalUserManager.searchUserByLogin(loginUser);

    vector<Profil> vecteurProfil = Utilisateur.getProfil();

    //Parcours par lignes dans un elements :
    /*int row = 0;
    while(row<2){
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLogin())));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLabel())));
        if(profil1->getActif() == 1){
            modele->setItem(row,2, new QStandardItem("Actif"));
        }else{
            modele->setItem(row,2, new QStandardItem(""));
        }
        row++;
    }*/
    for(int row=0; row<int(vecteurProfil.size());row++){
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLogin())));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurProfil[row].getLabel())));
        if(vecteurProfil[row].getActif() == 1){
            modele->setItem(row,2, new QStandardItem("Actif"));
        }else{
            modele->setItem(row,2, new QStandardItem(""));
        }
    }

    //Labels des colonnes
    modele->setHeaderData(0,Qt::Horizontal,"Login");
    modele->setHeaderData(1,Qt::Horizontal,"Label");
    modele->setHeaderData(2,Qt::Horizontal,"Status");

    ui->tableView->setModel(modele);
}

/**
 * @brief UserWindow::on_DisconnectButton_clicked
 * fonction associee au bouton pour deconnecter le user de l'application
 */
void UserWindow::on_DisconnectButton_clicked()
{
    class login login;
    login.setModal(true);
    login.exec();
}


void UserWindow::on_ShowBDDButton_clicked()
{
    vector<BDD> acces;
    Profil *profil1 = new Profil("JDo", "Do", 1, acces);
    Profil *profil2 = new Profil("JSmith", "Smith", 0, acces);
    vector<Profil> vecteurProfil;
    vecteurProfil.push_back(*profil1);
    vecteurProfil.push_back(*profil2);

    //int selection = ui->tableView->selectionModel()->selectedRows().first().row();
    //ProfilDialog profilSelected = vecteurProfil[selection];

    ProfilDialog profil = new ProfilDialog(nullptr);
    profil.setModal(true);
    profil.exec();
}
