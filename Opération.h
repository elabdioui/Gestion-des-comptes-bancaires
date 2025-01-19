#pragma once
#include<string>
#include "Date.h"
#include "Compte_bancaire.h"
using namespace std;



//classe de l'operation
class Operation {
private:
    int reference_operation;
    Date date_operation;
    string type_operation;
    double montant;
    Compte_bancaire* moncompte;

public:
    //constructeur par defaut
    Operation();
    //constructeur par parametre	
    Operation(int ref , Date d, string tyop , double mt ,Compte_bancaire * cb);
    //constructeur par copie
    Operation(Operation const& op);
    //destructeur 
    ~Operation();
    //setters
    void setreference_operation(int ref);
    void setdate_operation(Date d );
    void settype_operation(string typ_op);
    void getmontant(double m);
    void setcompte(Compte_bancaire* cb);
    //getters  
    int getreference_operation();
    string getdate_operation();
    string gettype_operation();
    double getmontant();
    Compte_bancaire* getcompte();
    //surcharge
    friend  istream& operator>>(istream& is, Operation& op);
    friend ostream& operator<<(ostream& os, const  Operation op);
    Operation& operator=(const Operation op);
};

