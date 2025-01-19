#include "Opération.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;



    // constructeur par defaut
	Operation::Operation() :reference_operation(0), type_operation(""), montant(0), moncompte(nullptr) { date_operation.Ndate(); }
	//constructeur par defaut et parametre	
	Operation::Operation(int ref , Date d, string tyop, double mt , Compte_bancaire* cb) :
		reference_operation(ref), type_operation(tyop), montant(mt), moncompte(cb) {
		date_operation.Adate(d);
	}
	//constructeur par copie
	Operation::Operation(Operation const& op) :
			reference_operation(op.reference_operation), type_operation(op.type_operation),
			montant(op.montant),moncompte(op.moncompte) {
		date_operation.Adate(op.date_operation);
	}
	//destructeur 
	Operation::~Operation() {
		cout << "objet detruit" << endl;
	}
	//setters
	void Operation::setreference_operation(int ref) {
		reference_operation = ref;
	}
	void Operation::setdate_operation(Date d) {
		date_operation.Adate(d);
	}
	void Operation::settype_operation(string typ_op) {
		type_operation = typ_op;
	}
	void Operation::getmontant(double m) {
		montant = m;
	}
	void Operation::setcompte(Compte_bancaire* cb) {
		moncompte = cb;
	}
	//getters  
	int Operation::getreference_operation() {
		return reference_operation;
	}
	string Operation::getdate_operation() {
		return date_operation.Rdate();
	}
	string Operation::gettype_operation() {
		return type_operation;
	}
	double Operation::getmontant() {
		return montant;
	}
	Compte_bancaire* Operation::getcompte() {
		return moncompte;
	}
	//surcharge
	
	istream& operator>>(istream& is, Operation& op) {
		cout << "entrer la reference de l'operation, la date,le type,le montant et le compte :" << endl;
		is >> op.reference_operation >> op.date_operation.Udate() >> op.type_operation >> op.montant >> op.moncompte;
	
		return is;
	}
	ostream& operator<<(ostream& os, const  Operation op) {

		os << "la reference de l'operation est: " << op.reference_operation <<
			"la date de l'operation est: " << op.date_operation.jour << "/" << op.date_operation.mois << "/" << op.date_operation.annee <<
			"le type de l'operation est: " << op.type_operation <<
			"le montant de l'operation est: " << op.montant <<
			"le compte de l'operation est: " << op.moncompte->getid_compte() <<
			"sa date de creation est" << op.moncompte->getdate_creation() <<
			"son solde est: " << op.moncompte->getsolde() <<
			"son client est: " << op.moncompte->getclient() << endl;
			
		
		return os;
	}
	Operation& Operation::operator=(const Operation op) {
		this->reference_operation = op.reference_operation;
		this->date_operation.Adate(op.date_operation);
		this->montant = op.montant;
		this->type_operation = op.type_operation;
		this->moncompte = op.moncompte;
		return (*this);

	}


