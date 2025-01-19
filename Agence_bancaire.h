#include<iostream>
#include<string>
#include "Compte_bancaire.h"
#include "Employé.h"
using namespace std;




class Agence_bancaire {
private:
    int id_agence;
    string adresse;
    Compte_bancaire* moncompte;
    Employe* employe;
    
public:
    // constructeur par defaut
    Agence_bancaire();
    //constructeur par parametre
    Agence_bancaire(int id_ag , string ad , Compte_bancaire* cb, Employe* e);
    //constructeur par copie
    Agence_bancaire(const Agence_bancaire& ab);
    //destructeur
    ~Agence_bancaire();
    //setters  
    void setid_agence(int id_ag);
    void setadresse(string ad);
    void setcompte(Compte_bancaire* compte);
    void setemploye(Employe* employe);
    //getters 
    int getid_agence();
    string getadresse();
    Compte_bancaire* getcompte(); 
    Employe* getemploye(); 
    // surcharge de sortie et entree
    friend  istream& operator>>(istream& is, Agence_bancaire& ab);
    friend ostream& operator<<(ostream& os, const  Agence_bancaire ab);
    Agence_bancaire& operator=(const Agence_bancaire& ab);



};
