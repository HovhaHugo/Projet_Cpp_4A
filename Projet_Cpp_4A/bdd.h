#ifndef BDD_H
#define BDD_H
#include <string>
using namespace std;

class BDD
{
private:
    int identifiant;
    string label;
    string path;
public:
    BDD();
    BDD(int newIdentifiant, string newLabel, string newPath);

    // Getters
    int getIdentifiant() { return identifiant; }
    string getLabel() { return label; }
    string getPath() { return path; }

    // Setters
    void setIdentifiant(int newIdentifiant) { identifiant = newIdentifiant; }
    void setLabel(const string newLabel) { label = newLabel; }
    void setContenu(string newPath) { path = newPath; }
};

#endif // BDD_H
