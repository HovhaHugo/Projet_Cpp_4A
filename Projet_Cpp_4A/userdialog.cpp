#include "globals.h"

#include "userdialog.h"
#include "profil.h"
#include "profildialog.h"
#include "ui_userdialog.h"
#include "login.h"

//CONSTRUCTEURS
UserDialog::UserDialog() {}

UserDialog::UserDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDialog)
{
    ui->setupUi(this);
}


//DESTRUCTEUR
UserDialog::~UserDialog(){
    delete ui;
}

//AUTRES FONCTIONS

/**
 * @brief UserDialog::setUser
 * Permet de sauvegarder le nom et prenom de l'utilisateur actuellement connecter.
 * @param nom
 * Le nom de l'utilisateur actuelle
 * @param prenom
 * Le prenom de l'utilisateur actuelle
 */
void UserDialog::setUser(string login, string nom, string prenom){
    loginUser = login; //on enregistre le login de l'utilisateur actuellement connecté

    QString nomQT = QString::fromStdString(nom);
    QString prenomQT = QString::fromStdString(prenom);

    ui->NomLabel->setText(nomQT);
    ui->PrenomLabel->setText(prenomQT);

    affichageProfilsUser();
}

//FONCTIONS QT

/**
 * @brief UserDialog::affichageProfilsUser
 * Permet d'ajouter des donnéer dans le tableau pour afficher les profils.
 */
void UserDialog::affichageProfilsUser(){
    modele = new QStandardItemModel(0,3);

    //Creation du vecteur comprenant tous les profils de l'utilisateur connecté
    User Utilisateur = globalUserManager.searchUserByLogin(loginUser);
    vector<Profil> vecteurProfil = Utilisateur.getProfil();

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
 * @brief UserDialog::on_DisconnectButton_clicked
 * fonction associee au bouton pour deconnecter le user de l'application
 */
void UserDialog::on_DisconnectButton_clicked()
{
    class login login;
    login.setModal(true);
    login.exec();
}

void UserDialog::on_tableView_clicked(){
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    // On veut accéder à la première colonne de la ligne sélectionnée (le login):
    QString selectedProfil = selectedIndex.sibling(selectedIndex.row(), 0).data().toString();
    ui->ProfilSelectedLineEdit->setText(selectedProfil);
}


void UserDialog::on_ShowBDDButton_clicked()
{
    //Creation du vecteur comprenant tous les profils de l'utilisateur connecté
    User Utilisateur = globalUserManager.searchUserByLogin(loginUser);
    vector<Profil> vecteurProfil = Utilisateur.getProfil();
    string loginProfilSelected = ui->ProfilSelectedLineEdit->text().toStdString();
    Profil profilSelected = Utilisateur.searchProfilByLogin(loginProfilSelected);


    ProfilDialog profil = new ProfilDialog(nullptr);
    profil.setProfil(loginUser ,loginProfilSelected); //on transmet le login de l'utilisateur connecté et du profil utilisé
    profil.setModal(true);
    profil.exec();
}
