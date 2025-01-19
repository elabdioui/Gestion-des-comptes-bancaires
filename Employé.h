#include<string>
#include "Compte_bancaire.h"

using namespace std;


//classe d'employe
class Employe {
private:
    int id_employe;
    string nom;
    string poste;
    Compte_bancaire* moncompte;
public:
    // constructeur par defaut 
    Employe();
    //constructeur par parametre
    Employe(int id_e, string n, string p,Compte_bancaire * cb);
    //constructeur par copie
    Employe(const Employe& e);
    //destructeur
    ~Employe();
    // setters
    void setid_employe(int id_e);
    void setnom(string n);
    void setposte(string p);
    void setcompte(Compte_bancaire* cb);
    //getters 
    int getid_employe();
    string getnom();
    string getposte();
    Compte_bancaire* getcompte();
    friend  istream& operator>>(istream& is, Employe& e);
    friend ostream& operator<<(ostream& os, const  Employe e);
    Employe& operator=(const Employe e);
};

