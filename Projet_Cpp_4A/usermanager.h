#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "users.h"
#include <vector>

class UserManager
{
private:
    vector<Users> listeUsers;
public:
    UserManager();
    ~UserManager();

    //Lire et Ecrire dans le fichier
    void parseFile(const string pathFichier);
    void writeFile(const string pathFichier);

    // Getter & Setter
    vector<Users> getListeUsers() { return listeUsers;}
    void setListeUsers(const vector<Users> newListeUsers) {listeUsers = newListeUsers;}

    int searchLogin(const string loginTest, const string mdpTest);
};

#endif // USERMANAGER_H
