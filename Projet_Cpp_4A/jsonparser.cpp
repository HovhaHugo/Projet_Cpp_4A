#include "jsonparser.h"
#include <json.hpp>
#include <fstream>
#include <iostream>

JsonParser::JsonParser() {}

string JsonParser::JsonGetUser(){
    using json = nlohmann::json;
    ifstream f("/Users/hugohovhannessian/Hugo/Etude_Sup/Polytech/DI4/S8/PlatLog_Cpp/test.json");
    json data = json::parse(f);
    // Access the values existing in JSON data
    json users = data.at("users");
    for(int i =0; i<data.value("nombre",0);i++){
        string login = users.at(i).at("login");
        string nom = users.at(i).at("nom");
        string prenom = users.at(i).at("prenom");
        // Print the value
        cout << "Login: " << login << endl;
        cout << "Nom: " << nom << endl;
        cout << "Prenom: " << prenom << endl;
    }
    return "yes";
}


bool JsonParser::JsonGetAdmin(){
    using json = nlohmann::json;
    bool HaveAdmin = false;
    ifstream f("/Users/hugohovhannessian/Hugo/Etude_Sup/Polytech/DI4/S8/PlatLog_Cpp/test.json");
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
