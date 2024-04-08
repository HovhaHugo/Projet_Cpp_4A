#include "profildialog.h"
#include "ui_profildialog.h"
#include "bdddialog.h"
#include <QFileDialog>
#include <iostream>


//CONSTRUCTEURS
ProfilDialog::ProfilDialog() {}

ProfilDialog::ProfilDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfilDialog)
{
    ui->setupUi(this);
}

//DESTRUCTEUR
ProfilDialog::~ProfilDialog() {}

void ProfilDialog::affichageBDDProfil(){
    modele = new QStandardItemModel(0,2);

    //creation du vecteur comprenant toutes les BDD
    vector<BDD> vecteurBDD = this->profils[this->idProfil].getAcces();

    for(int row=0; row<int(vecteurBDD.size());row++){
        string id = to_string(vecteurBDD[row].getIdentifiant());
        modele->setItem(row,0, new QStandardItem(QString::fromStdString(id)));
        modele->setItem(row,1, new QStandardItem(QString::fromStdString(vecteurBDD[row].getLabel())));
        modele->setItem(row,2, new QStandardItem(QString::fromStdString(vecteurBDD[row].getPath())));
    }

    //Labels des colonnes
    modele->setHeaderData(0,Qt::Horizontal,"Identifiant");
    modele->setHeaderData(1,Qt::Horizontal,"Label");

    ui->tableView->setModel(modele);
}

void ProfilDialog::on_tableView_clicked(){
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    // On veut accéder à la 3eme colonne de la ligne selectionnee (le path vers la BDD):
    QString selectedProfil = selectedIndex.sibling(selectedIndex.row(), 2).data().toString();
    ui->BDDSelectedLineEdit->setText(selectedProfil);
}

void ProfilDialog::on_ShowSQLiteButton_clicked()
{
    string pathBDDSelected = ui->BDDSelectedLineEdit->text().toStdString();
    BDDDialog sql = new BDDDialog(nullptr);
    sql.setPath(pathBDDSelected);
    sql.setModal(true);
    sql.exec();
}

void ProfilDialog::on_pushButton_clicked()
{
    //Permet de créer un QFileDialog qui va récupérer le fichier séléctionner par l'utilisateur.
    QString name = QFileDialog::getOpenFileName(this,"Open a file",QDir::homePath(),tr("Base de données (*.db *.SQLite)"));

    QFileInfo fileInfo(name);
    QString fileName = fileInfo.fileName();

    BDD *newAccess = new BDD(1,fileName.toStdString(),name.toStdString());
    this->profils[this->idProfil].addBDD(*newAccess);

    affichageBDDProfil();
}

