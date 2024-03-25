#ifndef BDD_H
#define BDD_H
#include <string>
#include <vector>
using namespace std;

class BDD
{
private:
    int identifiant;
    string label;
    vector<vector<string>> contenu;
public:
    BDD();

    // Getters
    int getIdentifiant() { return identifiant; }
    string getLabel() { return label; }
    vector<vector<string>> getContenu() { return contenu; }

    // Setters
    void setIdentifiant(int newIdentifiant) { identifiant = newIdentifiant; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setContenu(vector<vector<string>> newContenu) { contenu = newContenu; }
};

#endif // BDD_H
