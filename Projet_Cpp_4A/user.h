#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include "QStandardItemModel"
#include "profil.h"

using namespace std;


namespace Ui {
class User;
}

class User :public QDialog
{
    Q_OBJECT

private:
        Ui::User *ui;
        QStandardItemModel *modele;

        string login;
        string mdp;
        string nom;
        string prenom;
        bool admin;
        vector<Profil> profils;

private slots:
    void affichageProfilsUser();

    void on_DisconnectButton_clicked();
    void on_testButton_clicked();

public:
    User();
    User(QWidget *parent = nullptr);
    User(const User &user);
    User(const string login, const string mdp, const string nom, const string prenom, const bool admin, const vector<Profil> profils);
    ~User();

    // Getters
    string getLogin() { return login; }
    string getMdp() { return mdp; }
    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    bool isAdmin() { return admin; }
    vector<Profil> getProfil() { return profils; }

    // Setters
    void setLogin(const string newLogin) { login = newLogin; }
    void setMdp(const string newMdp) { mdp = newMdp; }
    void setNom(const string newNom) { nom = newNom; }
    void setPrenom(const string newPrenom) { prenom = newPrenom; }
    void setAdmin(bool isAdmin) { admin = isAdmin; }
    void setProfil(vector<Profil> newProfils) { profils = newProfils;}
    void addProfil(Profil newProfil) { profils.push_back(newProfil); }
    void delProfil(Profil supProfil);

    void setUser(string login, string nom, string prenom);
    bool verifyLogin(const string loginTest, const string mdpTest);


};

#endif // M_USERS_H
