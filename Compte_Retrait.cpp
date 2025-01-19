#include "Compte_Retrait.h"
#include "Compte_bancaire.h"
#include "Opération.h"
using namespace std;


    //constructeur par defaut
    Compte_retrait::Compte_retrait() :limite_decouvert(0), Compte_bancaire(){}
    //constructeur par parametre
    Compte_retrait::Compte_retrait(double limite_dec, int id_c = 0, double s = 0, Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l) :
        limite_decouvert(limite_dec), Compte_bancaire(id_c, s, d, agB, cl,l) {
        Compte_bancaire::get_operations().resize(l.size());
        for (Operation* op : Compte_bancaire::get_operations()) {
            Compte_bancaire::set_operations(l);
        }
        
    }
    //destructeur
    Compte_retrait::~Compte_retrait() {
        
        cout << "objet detruit" << endl;
    }
    //methode abstraite
    void Compte_retrait::releve_bancaire() {
        cout << "-L'identifiant du compte :" << Compte_retrait::getid_compte() << endl;
        cout<< "-Date :" << Compte_retrait::getdate_creation() << endl;
        cout << "-Nom client :" << Compte_retrait::getclient() << endl;
        cout << "-Liste des opérations :" << endl;
        double mont = 0;
        for (auto op : Compte_retrait::get_operations()) {
            cout <<"-Réference operation: "<< op->Operation::getreference_operation() << endl;
            cout <<"-Data de l'operation: "<< op->Operation::getdate_operation() << endl;
            cout <<"-Type operation: "<< op->Operation::gettype_operation() << endl;
            cout <<"-Montant"<< op->Operation::getmontant() << endl;
            mont = mont + op->Operation::getmontant();
        }
        cout << "-Total des operations: " << Compte_retrait::get_operations().size() << endl;
        cout << "-Montant: " << mont << endl;

        
    }
    //getters et setters
    void Compte_retrait::settaux_limlite_decouvert(double limit_dec) {
        limite_decouvert = limit_dec;
    }
    double Compte_retrait::getlimlite_decouvert() {
        return limite_decouvert;
    }
    //surcharge

    istream& operator>>(istream& is, Compte_retrait& cr) {
        cout << "Entrez la limite de découvert du compte : ";
        is >> cr.limite_decouvert;

        return is;
    }
    
   
    
    ostream& operator<<(ostream& os, const Compte_retrait cr){
        os << "la limite decouvert du Compte_retrait est: " << cr.limite_decouvert << endl;
          
        return os;
    }

    Compte_retrait& Compte_retrait::operator=(const Compte_retrait cr) {
        this->limite_decouvert = cr.limite_decouvert;
        return (*this);

    }