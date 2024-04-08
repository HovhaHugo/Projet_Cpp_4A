#include "globals.h"

#include "usereditordialog.h"
#include "ui_usereditordialog.h"

UserEditorDialog::UserEditorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserEditorDialog)
{
    ui->setupUi(this);
    affichageProfilsUser();
}

UserEditorDialog::~UserEditorDialog()
{
    delete ui;
}

void UserEditorDialog::affichageProfilsUser(){
    modele = new QStandardItemModel(0,4);

    //Creation du vecteur comprenant tous les profils de l'utilisateur connecté
    vector<User> vecteurUsers = globalUserManager.getListeUsers();

    for(int row=0; row<int(vecteurUsers.size());row++){
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(vecteurUsers[row].getLogin())));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurUsers[row].getNom())));
        modele->setItem(row,2, new QStandardItem(QString::fromStdString(vecteurUsers[row].getPrenom())));
        if(vecteurUsers[row].isAdmin() == 1){
            modele->setItem(row,3, new QStandardItem("Admin"));
        }else{
            modele->setItem(row,3, new QStandardItem("User"));
        }
    }

    //Labels des colonnes
    modele->setHeaderData(0,Qt::Horizontal,"Login");
    modele->setHeaderData(1,Qt::Horizontal,"Nom");
    modele->setHeaderData(2,Qt::Horizontal,"Prenom");
    modele->setHeaderData(2,Qt::Horizontal,"Droits");

    ui->tableView->setModel(modele);
}

void UserEditorDialog::on_tableView_clicked(){
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    // On veut acceder a la 1ere colonne de la ligne selectionnee (le login):
    QString selectedProfil = selectedIndex.sibling(selectedIndex.row(), 0).data().toString();
    ui->LoginUserLineEdit->setText(selectedProfil);
}

void UserEditorDialog::on_AddUserButton_clicked(){

}

void UserEditorDialog::on_EditUserButton_clicked(){

}

void UserEditorDialog::on_DeleteUserButton_clicked(){

}
