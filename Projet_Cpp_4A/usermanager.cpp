#include "usermanager.h"
#include <json.hpp>
#include <fstream>
#include <iostream>


UserManager::UserManager() {}

UserManager::~UserManager() {}

/**
 * @brief UserManager::parseFile
 * fonction qui va lire le fichier de sauvegarde json et creer la liste des Users
 * @param pathFichier
 * string comprenant le path du fichier de sauvegarde
 */
void UserManager::parseFile(string pathFichier){
    using json = nlohmann::json;
    ifstream fichier(pathFichier);
    json data = json::parse(fichier);
    // Access the values existing in JSON data
    json users = data.at("users");

    for(int ItUser = 0; ItUser<data.value("nombre",0);ItUser++){

        // Collect the values

        //Tous les Users:
        string login = users.at(ItUser).at("login");
        string mdp = users.at(ItUser).at("mdp");
        string nom = users.at(ItUser).at("nom");
        string prenom = users.at(ItUser).at("prenom");
        bool admin = false;
        if(users.at(ItUser).at("admin") == 1) admin = true;
        vector<Profil> profils;

        json Jprofils = users.at(ItUser).at("profils");
        //Tous les Profils du User
        for(int ItProfil = 0; ItProfil<users.at(ItUser).value("nbprofils",0);ItProfil++){
            string login = Jprofils.at(ItProfil).at("login");
            string label = Jprofils.at(ItProfil).at("label");
            bool actif = false;
            if(Jprofils.at(ItProfil).at("actif") == 1) actif = true;
            vector<BDD> acces;

            json Jbdd = Jprofils.at(ItProfil).at("BDD");
            //Toutes les BDD du Profil
            for(int ItBDD = 0; ItBDD<Jprofils.at(ItProfil).value("nbBDD",0);ItBDD++){
                int identifiant = Jbdd.at(ItBDD).at("identifiant");
                string label = Jbdd.at(ItBDD).at("label");
                string path = Jbdd.at(ItBDD).at("path");
                //insertion de la BDD dans la liste du Profil en cours
                acces.push_back(BDD(identifiant, label, path));
            }
            //insertion du Profil dans la liste du User en cours
            profils.push_back(Profil(login, label, actif, acces));
        }
        //insertion du User dans listeUsers pour les stocker
        listeUsers.push_back(new User(login, mdp, nom, prenom, admin, profils));

        // Print the values

        cout << "Login: " << login << endl;
        cout << "Mdp: " << mdp << endl;
        cout << "Nom: " << nom << endl;
        cout << "Prenom: " << prenom << endl;
    }
}

/**
 * @brief UserManager::JsonHaveAdmin
 * Recherche s'il existe un utilisateur admin dans un fichier json
 * @param pathFichier
 * Le path vers le fichier json
 * @return
 * Un booleen True s'il trouve un admin, false sinon
 */
bool UserManager::JsonHaveAdmin(string pathFichier){
    using json = nlohmann::json;
    bool HaveAdmin = false;
    ifstream f(pathFichier);
    json data = json::parse(f);
    json users = data.at("users");
    for(int i =0; i<data.value("nombre",0);i++){
        int admin = users.at(i).at("admin");
        if(admin == 1){
            HaveAdmin = true;
        }
    }
    return HaveAdmin;
}

/**
 * @brief UserManager::writeFile
 * ecrit dans le fichier de sauvegarde json les parametres des differents user
 * @param pathFichier
 * string comprenant le path du fichier de sauvegarde
 */
void UserManager::writeFile(const string pathFichier){
    ofstream fichier(pathFichier);
    /*for(User i:listeUsers){
        string admin ="";
        if(i.isAdmin()) admin = " admin";
        fichier << i.getLogin() + ' ' + i.getMdp() + ' ' + i.getNom() + ' ' + i.getPrenom() + admin;
    }*/
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

/**
 * @brief UserManager::searchAdmin
 * Recherche s'il existe un User possédant le droit d'admin
 * @return
 * l'objet User s'il est admin, NULL si aucun admin n'est trouvé
 */
User UserManager::searchAdmin() {
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].isAdmin()){
            return listeUsers[i];
        }
    }
    return NULL;
}
