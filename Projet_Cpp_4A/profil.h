#ifndef PROFIL_H
#define PROFIL_H

#include <QDialog>
#include "QStandardItemModel"
#include "bdd.h"
#include "sqlitewindow.h"

namespace Ui {
class Profil;
}

class Profil :public QDialog
{
    Q_OBJECT

private:
    Ui::Profil *ui;
    QStandardItemModel *modele;

    string login;
    string label;
    bool actif;
    vector<BDD> acces;

private slots:
    void affichageBDDProfil();

    void on_ShowSQLiteButton_clicked();

    void on_pushButton_clicked();

public:
    Profil();
    Profil(const Profil &profil);
    Profil(QWidget *parent = nullptr);
    Profil(const string newLogin,const string newLabel,const bool newStatus, const vector<BDD> newAcces);
    ~Profil();

    //Operators
    Profil operator=(const Profil& profil);

    // Getters
    string getLogin() { return login; }
    string getLabel() { return label; }
    vector<BDD> getAcces() { return acces; }
    bool getActif(){return actif;}

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setActif(const bool newStatus) { actif = newStatus; }
    void setAcces(vector<BDD> newAcces) { acces = newAcces;}
    void addBDD(BDD newBDD) { acces.push_back(newBDD);}
    void delBDD(BDD delBDD);

    void setProfil(string login, string label);
};

#endif // PROFIL_H
