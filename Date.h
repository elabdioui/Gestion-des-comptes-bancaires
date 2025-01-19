#pragma once
#include<string>
//la structure de date
struct Date {
    int jour;
    int mois;
    int annee;
    // fonction pour retourner une date 
    string Rdate() {

        return to_string(jour) + "/" + to_string(mois) + "/" + to_string(annee);
    }
    // fonction pour remplire une date
    void Adate(Date d) {
        jour = d.jour;
        mois = d.mois;
        annee = d.annee;
    }
    //fonction pour faire une date a null
    void Ndate() {
        jour = 0;
        mois = 0;
        annee = 0;

    }
    //fonction qui permet a l utilisateur d'entrer une date en ligne
    string Udate() {
        int j, m, a;
        cin >> j >> m >> a;
        return to_string(j) + "/" + to_string(m) + "/" + to_string(a);

    }
    
    
    //surcharge
    istream& operator>>(istream& is) {
        cout << "entrer jour , mois et annee" << endl;
        is >> jour >> mois >> annee;
        return is;
    }
    ostream& operator<<(ostream& os) {
        os << "la date est: " << jour << "/" << mois << "/" << annee << endl;
        return os;
    }
       
}; typename Date date;