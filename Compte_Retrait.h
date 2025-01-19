#include <string>
#include "Compte_bancaire.h"

using namespace std;


class Compte_retrait : public Compte_bancaire
{
private:
    double limite_decouvert;
public:
    //constructeur par defaut
    Compte_retrait();
    //constructeur par parametre
    Compte_retrait(double limite_dec, int id_c , double s , Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l);
    //destructeur
    ~Compte_retrait();
    //methode abstraite
    virtual void releve_bancaire();
    //getters et setters
    void settaux_limlite_decouvert(double limit_dec);
    double getlimlite_decouvert();
    friend  istream& operator>>(istream& is, Compte_retrait& cr);
    friend ostream& operator<<(ostream& os, const Compte_retrait cr);
    Compte_retrait& operator=(const Compte_retrait cr);
};

