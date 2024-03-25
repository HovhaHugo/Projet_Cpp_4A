#ifndef PROFIL_H
#define PROFIL_H

#include <QDialog>
#include "QStandardItemModel"
#include "bdd.h"

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
    vector<BDD> acces;
    bool actif;

private slots:

public:
    Profil();
    Profil(const Profil &profil);
    Profil(QWidget *parent = nullptr);
    Profil(const string newLogin,const string newLabel,const bool newStatus);
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
    void setAcces(vector<BDD> newAcces) { acces = newAcces; /*mieux gérer le pointeur*/}
    void setActif(const bool newStatus) { actif = newStatus; }

    void setProfil(string login, string label);
};

#endif // PROFIL_H
