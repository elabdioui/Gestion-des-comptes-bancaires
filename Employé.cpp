#include "Employé.h"
#include <iostream>
#include <string>
using namespace std;



    // constructeur par defaut
    Employe::Employe():id_employe(0),nom(""),poste(""), moncompte(nullptr) {}
    //constructeur par defaut et parametre
    Employe::Employe(int id_e , string n , string p , Compte_bancaire* cb) :id_employe(id_e), nom(n), poste(p), moncompte(cb) {}
    //constructeur par copie
    Employe::Employe(const Employe& em) :id_employe(em.id_employe), nom(em.nom), poste(em.poste),moncompte(em.moncompte) {}
    //destructeur
    Employe::~Employe() {
       
        cout << "objet detruit" << endl;
    }
    //setters
    void Employe::setid_employe(int id_e) {
        id_employe = id_e;
    }
    void Employe::setnom(string n) {
        nom = n;
    }
    void Employe::setposte(string p) {
        poste = p;
    }
    void Employe::setcompte(Compte_bancaire* cb) {
        moncompte = cb;
    }
    //getters 
    int Employe::getid_employe() {
        return id_employe;
    }
    string Employe::getnom() {
        return nom;
    }
    string Employe::getposte() {
        return poste;
    }
    Compte_bancaire* Employe::getcompte() {
        return moncompte;
    }
    //surcharge
    istream& operator>>(istream& is, Employe& e) {
        cout << "entrer l'id de l'Employe , son nom ,son poste et son compte" << endl;
        is >> e.id_employe>>e.nom>>e.poste>>*(e.moncompte);
 
        return is;
    }

    
    ostream& operator<<(ostream& os, const  Employe e) {
        os << "l' id de l'employe est: " << e.id_employe <<
            "le nom de l'employe est: " << e.nom <<
            "le poste de l'employe est: " << e.poste <<
            "le compte de l'employe est: " << e.moncompte->getid_compte() <<
            "sa date de creation est" << e.moncompte->getdate_creation() <<
            "son solde est: " << e.moncompte->getsolde() <<
            "son client est: " << e.moncompte->getclient() << endl;
            os << "liste des operations" << endl;
        for (auto op : e.moncompte->get_operations()) {
            os << op << endl;
        }
        return os;
    }
    Employe& Employe::operator=(const Employe e) {
        this->id_employe = e.id_employe;
        this->nom = e.nom;
        this->poste = e.poste;
        this->moncompte = e.moncompte;
        return (*this);
    }
