#include <iostream>
#include <vector>
/*#include "Agence_bancaire.h"
#include "Client.h"
#include "Operation.h"*/
#include "Date.h"


class Agence_bancaire;
class Client;
class Operation;

using namespace std;



class Compte_bancaire {
private:
    int id_compte;
    double solde;
    Date date_creation;
    Agence_bancaire* agenceB;
    Client* client;
    vector<Operation*> liste;
public:
    //constructeur par defaut
    Compte_bancaire();
    //constructeur  et parametre	
    Compte_bancaire(int id_c, double s, Date d, Agence_bancaire* agB, Client* cl, vector<Operation*> l);
    //methode abstraite
    virtual void releve_bancaire() = 0;
    //destructeur
    virtual ~Compte_bancaire();
    //setters
    void setid_compte(int id_c);
    void setsolde(double s);
    void setdate_creation(Date d);
    void setagence(Agence_bancaire* agB);
    void setclient(Client* cl);
    void set_operations(vector<Operation*> ops);
    //getters  
    int getid_compte();
    double getsolde();
    string getdate_creation();
    Agence_bancaire* getagence();
    Client* getclient();
    vector<Operation*> get_operations();
    friend  istream& operator>>(istream& is, Compte_bancaire& cb);
    friend ostream& operator<<(ostream& os, const  Compte_bancaire *cb);
    Compte_bancaire& operator=(const Compte_bancaire *cb);

};



