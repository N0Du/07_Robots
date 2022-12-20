// Fichier     annexe.cpp
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        12.12.2022
//
// But         description détaillée du projet
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0
#include "annexe.h"
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

// Macro pour vider le buffer
#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

int saisieInt(int min, int max, const string& msgEntree, const string& msgErreur){
    const int W = 20; //

    // Déclaration de variables internes
    int saisie;
    bool erreur;

    do {
        // Message et entrée utilisateur
        cout << left << setw(W) << msgEntree << right << setw(15) << "[" << min << "-"<< max << "]: ";
        cin >> saisie;

        // Vérification de l'entrée
        erreur = cin.fail() or saisie < min or saisie > max;
        if (erreur) {
            cout << msgErreur << endl;
            cin.clear();
        }
        VIDER_BUFFER;

    } while (erreur); // Recommencer si une il y a erreur

    return saisie;
}

int randomInt(int min, int max){
    // Déclaration librairie random
    random_device                  device;
    default_random_engine          generateur(device());
    uniform_int_distribution<int>  distribution(min, max);

    // Retourne une valeur aléatoire
    return distribution(generateur);
}

vector<int> randomListInt(int nbElem){
    vector<int> temp;
    //construction du vecteur de base
    for(int i = 0; i<nbElem; ++i){
        temp.push_back(i);
    }

    vector<int> retour;

    while(!temp.empty()){
        int randomIndex = randomInt(0, (int)temp.size()-1);
        retour.push_back(temp.at((size_t)randomIndex));
        temp.erase(temp.begin()+randomIndex);
    }

    return retour;
}