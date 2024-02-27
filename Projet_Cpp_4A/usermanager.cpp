#include "usermanager.h"
#include <fstream>

UserManager::UserManager() {}

UserManager::~UserManager() {}

//fonction qui va lire le .json et creer la liste des Users
/*void UserManager::parseFile(string pathFichier){
    ifstream fichier(pathFichier);
    string user;
    string delimiter = " ";
    //on parcourt tous les Users stockes dans le fichier
    while (getline (fichier, user)) {
        //on va lire ses parametres un par un
        int count=0;
        string login;
        string mdp;
        string nom;
        string prenom;
        bool admin;
        while(!user.empty()){
            //param prend comme valeur du debut jusqu'au premier espace
            string param = user.substr(0, user.find(delimiter));
            switch(count){
            case 0:
                login = param;
                break;
            case 1:
                mdp = param;
                break;
            case 2:
                nom = param;
                break;
            case 3:
                prenom = param;
                break;
            case 4:
                if(param.compare("admin")) admin = true;
                else admin = false;
                break;
            }
            count++;
            //on supprime le paramètre du string pour passer au prochain
            user.erase(0, user.find(delimiter)+1);
        }
        listeUsers.push_back(Users(login, nom, prenom, mdp, admin));
    }
}

void UserManager::writeFile(const string pathFichier){
    ofstream fichier(pathFichier);
    for(Users i:listeUsers){
        string admin ="";
        if(i.isAdmin()) admin = " admin";
        fichier << i.getLogin() + ' ' + i.getMdp() + ' ' + i.getNom() + ' ' + i.getPrenom() + admin;
    }
}

int UserManager::searchLogin(const string loginTest, const string mdpTest) {
    int found = -1;
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].verifyLogin(loginTest,mdpTest)){
            found = i;
        }
    }
    return found;
}*/
