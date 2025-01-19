#include "Compte_bancaire.h"
#include "Date.h"
#include "Opération.h"
#include <iostream>
#include <string>
using namespace std;

    //constructeur par defaut 
    Compte_bancaire::Compte_bancaire() :id_compte(0), solde(0), agenceB(nullptr), client(nullptr) { date_creation.Ndate(); }
    //constructeur par parametre	
    Compte_bancaire::Compte_bancaire(int id_c , double s, Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l) :
        id_compte(id_c), solde(s), agenceB(agB), client(cl) {
        Compte_bancaire::get_operations().resize(l.size());
        for (Operation* op : Compte_bancaire::get_operations()) {
            Compte_bancaire::set_operations(l);
        }
    }
    
    //destructeur
    Compte_bancaire::~Compte_bancaire() {
       
        cout << "objet detruit" << endl;
    }
    //setters
    void Compte_bancaire::setid_compte(int id_c) {
        id_compte = id_c;
    }
    void Compte_bancaire::setsolde(double s) {
        solde = s;
    }
    void Compte_bancaire::setdate_creation(Date d) {
        date_creation.Adate(d);
    }
    void Compte_bancaire::setagence(Agence_bancaire* agB) {
        agenceB = agB;
    }
    void Compte_bancaire::setclient(Client* cl) {
        client = cl;
    }
    void Compte_bancaire::set_operations(vector<Operation*> l) {
        liste.clear();
        liste.resize(l.size());
        for (Operation* op : liste) {
            liste = l;
        }
    }
    //getters  
    int Compte_bancaire::getid_compte() {
        return id_compte;
    }
    double Compte_bancaire::getsolde() {
        return solde;
    }
    string Compte_bancaire::getdate_creation() {
        return date_creation.Rdate();
    }
    Agence_bancaire* Compte_bancaire::getagence() {
        return agenceB;
    }
    Client* Compte_bancaire::getclient() {
        return client;
    }
    
    vector<Operation*> Compte_bancaire::get_operations() {
        return liste;
    }
    //surcharge
    istream& operator>>(istream& is, Compte_bancaire& cb) {
        cout << "entrer id du compte,le solde , date de sa creation son agence, son client et ses operations :" << endl;
        is >> cb.id_compte>>cb.solde>>cb.date_creation.Udate() >> *(cb.agenceB) >> *(cb.client);
        for (int i = 0; i < cb.liste.size(); ++i) {
            Operation* new_operation = new Operation(); // Créer une nouvelle opération
            is >> *new_operation; // Saisir les informations pour cette opération
            cb.liste.push_back(new_operation); 
        }
        
        return is;
    }
    ostream& operator<<(ostream& os,const Compte_bancaire *cb) {
        os << "l' id du Compte_bancaire est: " << cb->id_compte <<
            "le solde du Compte_bancaire est: " << cb->solde <<
            "la date de creation du Compte_bancaire est: " << cb->date_creation.jour << "/" <<cb->date_creation.annee<< "/" << cb->date_creation.annee<<
            "l'agence est: " << cb->agenceB <<
            "le client est: " << cb->client << endl;
        os << "liste des operations" << endl;
            for (auto op : cb->liste) {
                os << *op << endl;
            }
  
        return os;
    }
    Compte_bancaire& Compte_bancaire::operator=(const Compte_bancaire *cb) {
        this->id_compte = cb->id_compte;
        this->solde = cb->solde;
        this->date_creation.Adate(cb->date_creation);
        this->agenceB = cb->agenceB;
        this->client = cb->client;
        this->liste.empty();
        for (int i = 0;i<cb->liste.size();i++) {

            this->liste[i] = cb->liste[i];
        }
        return (*this);
    }

        
    
 