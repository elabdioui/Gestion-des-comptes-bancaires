#include<string>
#include "Compte_bancaire.h"

using namespace std;


class Compte_epargne :public Compte_bancaire
{
private:
    int taux_intere;
public:
    // constructeur par defaut
    Compte_epargne();
    //constructeur par defaut et parametre
    Compte_epargne(int tx, int id_c , double s , Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l);
    //destructeur
    ~Compte_epargne();
    //methode virtual
    virtual void releve_bancaire();
    //getters setters
    void settaux_interer(int tx);
    int gettaux_interer();
    friend  istream& operator>>(istream& is, Compte_epargne& ce);
    friend ostream& operator<<(ostream& os, const  Compte_epargne ce);
    Compte_epargne& operator=(const Compte_epargne ce);
};
