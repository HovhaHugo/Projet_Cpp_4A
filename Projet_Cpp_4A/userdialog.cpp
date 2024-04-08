#include "userdialog.h"
#include "profil.h"
#include "profildialog.h"
#include "ui_userdialog.h"
#include "login.h"
#include "usereditordialog.h"

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

//FONCTIONS QT

/**
 * @brief UserDialog::affichageProfilsUser
 * Permet d'ajouter des donnéer dans le tableau pour afficher les profils.
 */
void UserDialog::affichageProfilsUser(){
    modele = new QStandardItemModel(0,3);


    //Creation du vecteur comprenant tous les profils de l'utilisateur connecté
    vector<Profil> vecteurProfil = this->user.getProfil();

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

    //Affichage / Occultation de la partie administrateur
    if(this->user.isAdmin()){
        ui->AdminLabel->show();
        ui->AdminButton->show();
    }
    else{
        ui->AdminLabel->hide();
        ui->AdminButton->hide();
    }
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
    // On veut acceder a la 1ere colonne de la ligne selectionnee (le login):
    QString selectedProfil = selectedIndex.sibling(selectedIndex.row(), 0).data().toString();
    ui->ProfilSelectedLineEdit->setText(selectedProfil);
}


void UserDialog::on_ShowBDDButton_clicked()
{
    //On recherche le profil selectionne par l'utilisateur a partir de son login
    ProfilDialog profil = new ProfilDialog(nullptr);
    vector<Profil> vecteurProfil = this->user.getProfil();
    int identifiantProfil= 0;
    for(int row=0; row<int(vecteurProfil.size());row++){
        if(vecteurProfil[row].getLogin() == ui->ProfilSelectedLineEdit->text().toStdString()){
            identifiantProfil = row;
        }
    }
    profil.setIdentifiantProfil(identifiantProfil);
    profil.setProfils(this->user.getProfil()); //on transmet le login de l'utilisateur connecté et du profil utilisé
    profil.setModal(true);
    profil.exec();
}

void UserDialog::on_AdminButton_clicked(){
    UserEditorDialog userEdit = UserEditorDialog(nullptr);
    userEdit.setModal(true);
    userEdit.exec();
}
