#include "usermanager.h"
#include <fstream>

UserManager::UserManager() {}

UserManager::~UserManager() {}

/**
 * @brief UserManager::parseFile
 * fonction qui va lire le fichier de sauvegarde (txt, json...) et creer la liste des Users
 * @param pathFichier
 * string comprenant le path du fichier de sauvegarde
 */
void UserManager::parseFile(string pathFichier){
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
        listeUsers.push_back(User(login, nom, prenom, mdp, admin));
    }
}

/**
 * @brief UserManager::writeFile
 * ecrit dans le fichier de sauvegarde (txt, json...) les parametres des differents user
 * @param pathFichier
 * string comprenant le path du fichier de sauvegarde
 */
void UserManager::writeFile(const string pathFichier){
    ofstream fichier(pathFichier);
    for(User i:listeUsers){
        string admin ="";
        if(i.isAdmin()) admin = " admin";
        fichier << i.getLogin() + ' ' + i.getMdp() + ' ' + i.getNom() + ' ' + i.getPrenom() + admin;
    }
}

/**
 * @brief UserManager::searchLogin
 * recherche à partir d'un login et d'un mot de passe si un user correspond
 * @param loginTest
 * string comprenant le login a tester
 * @param mdpTest
 * string comprenant le mot de passe a tester
 * @return
 * -1 si il n'y a pas de correspondance, l'emplacement de la correspondance dans la liste sinon
 */
int UserManager::searchLogin(const string loginTest, const string mdpTest) {
    int found = -1;
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].verifyLogin(loginTest,mdpTest)){
            found = i;
        }
    }
    return found;
}

User UserManager::searchAdmin() {
    User user = NULL;
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].isAdmin()){
            User user = new User(listeUsers[i].getLogin(), listeUsers[i].getNom(),listeUsers[i].getPrenom(), listeUsers[i].getMdp(), 1);
        }
    }
    return user;
}
