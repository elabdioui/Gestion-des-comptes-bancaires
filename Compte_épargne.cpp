#include "Compte_épargne.h"
#include "Opération.h"
#include "Compte_bancaire.h"



//constructeur par defaut
Compte_epargne::Compte_epargne() :taux_intere(0.0) {}
//constructeur par defaut et parametre
Compte_epargne::Compte_epargne(int tx, int id_c , double s , Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l) :
    taux_intere(tx), Compte_bancaire::Compte_bancaire(id_c, s, d, agB, cl,l) {}

//methode virtual
 void Compte_epargne::releve_bancaire() {
    cout << "-L'identifiant du compte :" << Compte_epargne::getid_compte() << endl;
    cout << "-Date :" << Compte_epargne::getdate_creation() << endl;
    cout << "-Nom client :" << Compte_epargne::getclient() << endl;
    cout << "-Liste des opérations :" << endl;
    double mont = 0;
    for (auto op : Compte_epargne::get_operations()) {
        cout << "-Réference operation: " << op->Operation::getreference_operation() << endl;
        cout << "-Data de l'operation: " << op->Operation::getdate_operation() << endl;
        cout << "-Type operation: " << op->Operation::gettype_operation() << endl;
        cout << "-Montant" << op->Operation::getmontant() << endl;
        mont = mont + op->Operation::getmontant();
    }
    cout << "-Total des operations: " << Compte_epargne::get_operations().size() << endl;
    cout << "-Montant: " << mont << endl;


}
    


//destructeur
Compte_epargne::~Compte_epargne() {
    
    cout << "objet detruit" << endl;
};
//getters et setters
void Compte_epargne::settaux_interer(int tx) {
    taux_intere = tx;
};
int Compte_epargne::gettaux_interer() {
    return taux_intere;
};

//surcharge
//surcharge

istream& operator>>(istream& is, Compte_epargne& ce) {
    cout << "entrez le taux d'interet et les autres information du compte:" << endl;
    is >> ce.taux_intere ;
        
    return is;
}
ostream& operator<<(ostream& os, const Compte_epargne ce) {
    os << "la taux d'interet du Compte epargne est: " << ce.taux_intere;
        
 
    return os;
}
Compte_epargne& Compte_epargne::operator=(const Compte_epargne ce) {
    this->taux_intere = ce.taux_intere;
    return (*this);

}