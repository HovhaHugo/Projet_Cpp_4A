#include "usermanager.h"
#include "QtCore/qfile.h"
#include "QtCore/qstring.h"
#include <iostream>
#include <json.hpp>
#include <fstream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

using namespace std;

UserManager::UserManager() {}

UserManager::~UserManager() {}

/**
 * @brief UserManager::parseFile
 * fonction qui va lire le fichier de sauvegarde json et creer la liste des Users
 * @param pathFichier
 * string comprenant le path du fichier de sauvegarde
 */
void UserManager::parseFile(string pathFichier){

    QString fichier = QString::fromStdString(pathFichier);
    QFile fichierJSON(fichier);
    if (fichierJSON.open(QFile::ReadOnly | QFile::Text))
    {
        // lecture les données du fichier JSON
        QString donnees = fichierJSON.readAll();

        // création d'un document JSON
        QJsonDocument documentJSON = QJsonDocument::fromJson(donnees.toUtf8());

        QJsonObject objetJSON = documentJSON.object();

        QStringList listeCles;
        listeCles = objetJSON.keys();

        // Les valeurs
        for(int i = 0; i <= listeCles.count()-1; i++)
        {
            QJsonValue valeur = objetJSON[listeCles.at(i)]; // un QJsonValue

            //Si c'est un Array, c'est un tableau, donc notre liste d'utilisateur.
            if(valeur.isArray())
            {

                QJsonArray tableau = valeur.toArray();

                for(int j = 0; j < tableau.size(); j++){
                    //Comme c'est un tableau d'objet il faut le transformer
                    QJsonObject user = tableau[j].toObject();


                    //qDebug() << user[listeCle.at(w)]; // un QJsonValue
                    //On récupére les informations pour l'utilisateur.
                    string login = user["login"].toString().toStdString();
                    string nom = user["nom"].toString().toStdString();
                    string prenom = user["prenom"].toString().toStdString();
                    string mdp = user["mdp"].toString().toStdString();
                    int admin = user["admin"].toInt();

                    vector<Profil> profils;

                    QJsonArray tableauProfils = user["profils"].toArray();
                    for(int prof = 0; prof < tableauProfils.size(); prof++){
                        //qDebug() << profils[prof];

                        QJsonObject objetProfils = tableauProfils[prof].toObject();

                        string login = objetProfils["login"].toString().toStdString();
                        string label = objetProfils["label"].toString().toStdString();
                        int actif = objetProfils["actif"].toInt();
                        int nbBDD = objetProfils["nbBDD"].toInt();
                        QStringList liste;
                        liste = objetProfils.keys();
                        vector<BDD> acces;
                        //Si on as plus de 0 BDD, on va donc les récupérer.
                        if(nbBDD>0){
                            //On récupére l'arrays
                            QJsonArray Bdd = objetProfils["BDD"].toArray();
                            for(int database = 0; database < Bdd.size(); database++){
                                //Comme l'array est en fait composer d'objet, on récuper l'objet
                                QJsonObject objetBDD = Bdd[database].toObject();

                                //On récuper les données et on les stocks dans l'application.
                                string label = objetBDD["label"].toString().toStdString();
                                string path = objetBDD["path"].toString().toStdString();
                                int identifiant = objetBDD["identifiant"].toInt();
                                acces.push_back(BDD(identifiant, label, path));
                            }
                        }
                        profils.push_back(Profil(login, label, actif, acces));
                    }
                    User newUser =  User(login, mdp, nom, prenom, admin, profils);
                    listeUsers.push_back(newUser);
                    cout << "Login: " << login << endl;
                    cout << "Mdp: " << mdp << endl;
                    cout << "Nom: " << nom << endl;
                    cout << "Prenom: " << prenom << endl;
                }
            }
            //Si c'est un double, c'est un chiffre, donc le nombre d'utilisateur qu'on as dans le fichier.
            else if(valeur.isDouble())
            {
                //qDebug() << QString("[valeur]");
            }
        }
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
 * -1 si il n'y a pas de correspondance, l'emplacement de l'a'utilisateur correspondant dans la liste sinon
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
 * l'objet User s'il est admin, un User vide si aucun admin n'est trouvé
 */
User UserManager::searchAdmin() {
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].isAdmin()){
            return listeUsers[i];
        }
    }
    return User();
}

/**
 * @brief UserManager::searchUserByLogin
 * Recherche un utilisateur par son login
 * @param loginTest
 * un string contenant le login que l'on recherche
 * @return
 * l'objet User recherché si il y a correspondance, un User vide sinon
 */
User UserManager::searchUserByLogin(const string loginTest){
    for(int i=0; i<int(listeUsers.size()); i++){
        if(listeUsers[i].getLogin()==loginTest){
            return listeUsers[i];
        }
    }
    return User();
}
