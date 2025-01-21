#include "Client.h"
#include <iostream>
#include <string>
using namespace std;


    // constructeur par defaut
    Client::Client():id_client(0),nom(""),contact("0000"), moncompte(nullptr){}
    //constructeur par defaut et parametre	
    Client::Client(int id_cl, string ncl , string ct , Compte_bancaire* cb) :id_client(id_cl), nom(ncl), contact(ct) ,moncompte(cb){}
    //constructeur par copie
    Client::Client(Client const& cl) :id_client(cl.id_client), nom(cl.nom), contact(cl.contact),moncompte(cl.moncompte) {}
    //destructeur
    Client::~Client() {
        delete moncompte;
        cout << "objet detruit" << endl;
    }
    //setters
    void Client::setid_client(int id_cl) {
        id_client = id_cl;
    }
    void Client::setnom(string ncl) {
        nom = ncl;
    }
    void Client::setcontact(string ct) {
        contact = ct;
    }
    void Client::setcompte(Compte_bancaire* cb) {
        moncompte = cb;
    }
    //getters  
    int Client::getid_client() {
        return id_client;
    }
    string Client::getnom() {
        return nom;
    }
    string Client::getcontact() {
        return contact;
    }
    Compte_bancaire* Client::getcompte() {
        return moncompte;
    }
    //surcharge
    
    ostream& operator<<(ostream& os, const  Client cl) {
        os << "l' id du client est: " << cl.id_client <<
            "le nom du client est: " << cl.nom <<
            "le contact du client est: " << cl.contact <<
            "le compte de l'agence est: " << cl.moncompte->getid_compte() <<
            "sa date de creation est" << cl.moncompte->getdate_creation() <<
            "son solde est: " << cl.moncompte->getsolde() <<
            "son client est: " << cl.moncompte->getclient() << endl;
            os << "liste des operations" << endl;
        for (auto op : cl.moncompte->get_operations()) {
            os << op << endl;
        }
        return os;
    }
    istream& operator>>(istream& is, Client& cl) {
        cout << "entrer id du colient,le nom et son contact :" << endl;
        is >> cl.id_client >> cl.nom >> cl.contact >> *(cl.moncompte);
       
        return is;
    }
    Client& Client::operator=(const Client c) {
        this->id_client = c.id_client;
        this->nom = c.nom;
        this->contact = c.contact;
        this->moncompte = c.moncompte;
        return (*this);
    }


//comment de commit




