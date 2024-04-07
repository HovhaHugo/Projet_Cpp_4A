#include "profildialog.h"
#include "ui_profildialog.h"
#include "sqlitewindow.h"


//CONSTRUCTEURS
ProfilDialog::ProfilDialog() {}

ProfilDialog::ProfilDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfilDialog)
{
    ui->setupUi(this);
    affichageBDDProfil();
}

//DESTRUCTEUR
ProfilDialog::~ProfilDialog() {}


//FONCTIONS QT

void ProfilDialog::affichageBDDProfil(){
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

void ProfilDialog::on_ShowSQLiteButton_clicked()
{
    SQLiteWindow sql = new SQLiteWindow(nullptr);
    sql.setModal(true);
    sql.exec();
}
