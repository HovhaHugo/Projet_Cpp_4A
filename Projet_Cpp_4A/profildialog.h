#ifndef PROFILDIALOG_H
#define PROFILDIALOG_H

#include <QDialog>
#include "QStandardItemModel"
#include "profil.h"

namespace Ui {
class ProfilDialog;
}

class ProfilDialog :public QDialog
{
    Q_OBJECT

private:
    Ui::ProfilDialog *ui;
    QStandardItemModel *modele;

    vector<Profil> profils;
    int idProfil;

private slots:
    void affichageBDDProfil();

    void on_tableView_clicked();
    void on_ShowSQLiteButton_clicked();

    void on_pushButton_clicked();

public:
    ProfilDialog();
    ProfilDialog(QWidget *parent = nullptr);
    ~ProfilDialog();

    void setProfils(vector<Profil> newProfil){ this->profils = newProfil; affichageBDDProfil();};
    void setIdentifiantProfil(const int newIdentifiant){this->idProfil = newIdentifiant;}
};

#endif // PROFILDIALOG_H
