#include "Agence_bancaire.h"
#include<iostream>
#include<string>
using namespace std;

//classe agence bancaire
    
// constructeur par defaut
    Agence_bancaire::Agence_bancaire():id_agence(0),adresse(""), moncompte(nullptr), employe(nullptr) {}
    //constructeur par defaut et parametre
    Agence_bancaire::Agence_bancaire(int id_ag, string ad, Compte_bancaire* cb, Employe* e) :id_agence(id_ag), adresse(ad), moncompte(cb), employe(e) {}
    
    //constructeur par copie
    Agence_bancaire::Agence_bancaire(const Agence_bancaire& ab) :id_agence(ab.id_agence), adresse(ab.adresse),moncompte(ab.moncompte),employe(ab.employe) {}
    //destructeur
    Agence_bancaire::~Agence_bancaire() {
        delete moncompte;
        delete employe;
        cout << "objet detruit" << endl;
    }
    //setters  
    void Agence_bancaire::setid_agence(int id_ag) {
        id_agence = id_ag;
    }
    void Agence_bancaire::setadresse(string ad) {
        adresse = ad;
    }
    void Agence_bancaire::setcompte(Compte_bancaire* compte) {
        moncompte = compte;
    }

    void Agence_bancaire::setemploye(Employe* emp) {
        employe = emp;
    }
    //getters 
    int Agence_bancaire::getid_agence() {
        return id_agence;
    }
    string Agence_bancaire::getadresse() {
        return adresse;
    }
    Compte_bancaire* Agence_bancaire::getcompte()  {
        return moncompte;
    }

    Employe* Agence_bancaire::getemploye() {
        return employe;
    }

    //surcharge
    istream& operator>>(istream& is, Agence_bancaire& ab) {
        cout << "entrer l'id de l'agence ,son adresse, son compte et son employe"<<endl;
        is >> ab.id_agence >> ab.adresse >> *(ab.moncompte) >> *(ab.employe);

        return is;
    }

    ostream& operator<<(ostream& os, const  Agence_bancaire ab) {
        os << "le id de l'agence est: " << ab.id_agence <<
            "l'adresse de l'agence est : " << ab.adresse <<
            "le compte de l'agence est: " << ab.moncompte->getid_compte() <<
            "sa date de creation est"<<ab.moncompte->getdate_creation()<<
            "son solde est: "<<ab.moncompte->getsolde()<<
            "son client est: "<<ab.moncompte->getclient()<<
            "l'employe de l agence est: " << ab.employe->getid_employe() <<
            "son nom est :" << ab.employe->getnom() <<
            "son poste est: " << ab.employe->getposte() <<
            "son compte est:" << ab.employe->getcompte() << endl;
        os << "liste des operations" << endl;
        for (auto op : ab.moncompte->get_operations()) {
            os << op << endl;
        }

        return os;
    }
    Agence_bancaire& Agence_bancaire::operator=(const Agence_bancaire& ab) {
        this->id_agence = ab.id_agence;
        this->adresse = ab.adresse;
        this->moncompte = ab.moncompte;
        this->employe = ab.employe;
        return (*this);

    }