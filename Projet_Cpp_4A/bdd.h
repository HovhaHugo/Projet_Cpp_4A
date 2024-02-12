#ifndef BDD_H
#define BDD_H
#include <string>
using namespace std;

class BDD
{
private:
    int identifiant;
    string label;
public:
    BDD();

    // Getters
    int getIdentifiant() { return identifiant; }
    string getLabel() { return label; }

    // Setters
    void setIdentifiant(int newIdentifiant) { identifiant = newIdentifiant; }
    void setLabel(const string newLabel) { label = newLabel; }
};

#endif // BDD_H
