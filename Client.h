#include "Compte_bancaire.h"
#include<string>
#include<iostream>

using namespace std;



class Client {
private:
    int id_client;
    string nom;
    string contact;
    Compte_bancaire* moncompte;

public:
    // constructeur par defaut
    Client();
    //constructeur par parametre	
    Client(int id_cl , string ncl , string ct , Compte_bancaire* cb);
    //constructeur par copie
    Client(Client const& cl);
    //destructeur
    ~Client();
    //setters
    void setid_client(int id_cl);
    void setnom(string ncl);
    void setcontact(string ct);
    void setcompte(Compte_bancaire* cb);
    //getters  
    int getid_client();
    string getnom();
    string getcontact();
    Compte_bancaire* getcompte();
    friend  istream& operator>>(istream& is, Client& cl);
    friend ostream& operator<<(ostream& os, const  Client cl);
    Client& operator=(const Client c);
    
};

