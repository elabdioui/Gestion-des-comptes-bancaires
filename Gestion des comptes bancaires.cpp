#include <string>
#include <vector>
#include <algorithm>
#include<deque>
#include <map>
#include <iostream>
#include<list>
#include "Agence_bancaire.h"
#include "Client.h"
#include "Opération.h"
#include "Date.h"
#include "Employé.h"
#include "Compte_bancaire.h"
#include "Compte_Retrait.h"
#include "Compte_Retrait.h"
using namespace std;






//     **Fonctionnalité 1 : gestion Agence bancaire **
void fonction1() {
	//remplissage la liste des agence bancaire.
	vector<Agence_bancaire>liste_agence_bancaire;
	vector<Agence_bancaire>::iterator itab1, itab2;
	itab1 = liste_agence_bancaire.begin(); itab2 = liste_agence_bancaire.end();
	cout << "veuiller remplir le vector: " << endl;
	for (auto it=itab1;it<itab2;it++)
	{
		cin >> *it;
	}
	//Affichage
	for (auto it = itab1; it < itab2; it++)
	{
		cout << *it;
	}
	//modifier/supprimer une agence
	char trait;
	Agence_bancaire ab;
	cout << "pour supprimer une agence veuiller tapez sur s pour modifier veuiller taper sur m,entrez l'agence desireé:" << endl;
	cin >> ab;
	cout << " dans le cas de modification entrer la nouvelle agence, sinon tapez entrer" << endl;
	Agence_bancaire ab1; cin >> ab1;
	
	switch (trait)
	{
	case 's': remove(itab1, itab2, ab);break;
	case 'm': replace(itab1, itab2, ab, ab1);break;
	default: cout << "Choix invalide. Veuillez réessayer." << endl; break;

	}

}

//		**Fonctionnalité 2 : gestion Client **

// fonction qui verifient les comptes bancaires qui ont été créé il y a 5 ans et dont le solde dépasse les 50000dh
bool condition1(Compte_bancaire* cb) {
	return (cb->getdate_creation() == "28/04/2019" && cb->getsolde() > 5000);
}
void fonction2() {
	//demander à l’utilisateur de remplir les clients 
	deque<Client> GestionClient;
	deque<Client>::iterator itgc1, itgc2;
	itgc1 = GestionClient.begin(); itgc2 = GestionClient.end();
	cout << "entrer les clients: " << endl;
	for (auto it = itgc1; it < itgc2; it++) {
		cin >> *it;
	}
	//modifier/supprimer un client
	char trait;
	Client c;
	cout << "pour supprimer un client veuiller tapez sur s pour modifier veuiller taper sur m pour rien faire tapez x" << endl;
	cin >> c;

	cout << " dans le cas de modification entrer le nouveau client, sinon tapez entrer" << endl;
	Client c1; cin >> c1;

	switch (trait)
	{
	case 's': remove(itgc1, itgc2, c);
	case 'm': replace(itgc1, itgc2, c,c1);
	default: cout << "Choix invalide. Veuillez réessayer." << endl; break;
	}
	//Afficher pour chaque client, le nombre des comptes crées

	for (auto it : GestionClient) {
		cout << "le client :" << it << "ses comptes:" << it.getcompte();
	}

}


//      **Fonctionnalité 3 : gestion des Comptes bancaires ** 
void fonction3() {
	
	map< int, Compte_bancaire*> GestionCompte;
	// ajouter/ modifier/ supprimer un compte bancaire
	map< int, Compte_bancaire*>::iterator itgc1, itgc2;
	itgc1 = GestionCompte.begin(); itgc2 = GestionCompte.end();
	cout << "pour ajouter veuiller tapez sur a pour supprimer un client veuiller tapez sur s pour modifier veuiller taper sur m pour rien faire tapez x,entrez le compte desireé:" << endl;
	Compte_bancaire* cb; cin >> *cb;
	cout << " dans le cas de modification entrer le nouveau compte, sinon tapez entrer" << endl;
	Compte_bancaire *cb1; cin >> *cb1;
	
	char trait;
	switch (trait)
	{
	case 'a':fill(itgc1, itgc2, *cb); break;
	case 's':remove(itgc1, itgc2, *cb); break;
	case 'm':replace(itgc1, itgc2, *cb, *cb1); break;
	default: cout << "Choix invalide. Veuillez réessayer." << endl; break;
	

	}
	//le nombre des comptes bancaires qui ont été créé il y a 5 ans et dont le solde dépasse les 50000dh
	int i = count_if(itgc1, itgc2, condition1);
	cout << "le nom nombre des comptes bancaires qui ont été créé il y a 5 ans et dont le solde dépasse les 50000dh est :" << i;

	//le relevé bancaire de chaque compte
	cout << "Relevé bancaire de chaque compte :" << endl;
	for (auto& p :GestionCompte) {
		p.second->releve_bancaire();
	}


	

}
//	     **Fonctionnalité 4 : gestion Opération**
void fonction4() {
	fonction1(); fonction2();
	// demander à l’utilisateur de remplir la liste des opérations
	list<Operation> GestionOperation;
	list<Operation>::iterator itgo1, itgo2;
	itgo1 = GestionOperation.begin(); itgo2 = GestionOperation.end();
	for (auto it : GestionOperation)
	{
		cin >> it;
	}


	// ajouter / modifier / supprimer des opérations
	cout << "pour ajouter veuiller tapez sur a pour supprimer  veuiller tapez sur s pour modifier veuiller taper sur m ,entrez l'e compte'operation desireé:" << endl;
	Operation op;
	cin >> op;
	cout << " dans le cas de modification entrer la nouvelle operation, sinon tapez entrer" << endl;
	Operation op1; cin >> op1;
	char trait;
	switch (trait)
	{
	case 'a':fill(itgo1,itgo2,op); break;
	case 's':remove(itgo1, itgo2, op); break;	
	case 'm':replace(itgo1, itgo2, op, op1); break;
	default: cout << "Choix invalide. Veuillez réessayer." << endl; break;

	}


}








int main()
{
	// *********** MENU *************
	cout << " Dans de programme vous avez plusieurs fonctionnalité a faire voici le menu " << endl;
	cout << "Pour gérer les agences bancaire veuillez tapez le no 1" << endl;
	cout << "Pour gérer les clients veuillez tapez le no 2" << endl;
	cout << "Pour gérer les comptes bancaires veuillez tapez le no 3" << endl;
	cout << "Pour gérer les  operations veuillez tapez le no 4" << endl;
	cout << "Pour quitter veuiller taper la lettre q" << endl;

    char fonct;
	cin >> fonct;
	switch (fonct)
	{
	case '1': fonction1(); break;
	case '2': fonction2(); break;
	case '3': fonction3(); break;
	case '4': fonction4(); break;
	case 'q':	break;
	default : cout << "Choix invalide. Veuillez réessayer." << endl; break;
	}
    
    
}


