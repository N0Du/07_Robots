// Fichier     main.cpp
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
#include <iostream>
#include <iomanip>

#include "annexe.h"
#include "robot.h"
#include "terrain.h"

using namespace std;

int main() {
    const string MSG_ERREUR = "Veuillez entrer un nombre valide.";

    //=======================
    // Saisie utilisateur
    //=======================
    string msg = "Saisir la largeur";
    int largeur  = saisieInt(10, 1000, msg, MSG_ERREUR);
    msg = "Saisir la hauteur";
    int hauteur  = saisieInt(10, 1000, msg, MSG_ERREUR);
    msg = "Saisir le nombre de robot";
    int nbRobots = saisieInt(1, 9, msg, MSG_ERREUR);
    //========================


    //========================
    // Préparation du jeu
    //========================
    string historiqueMorts = "";

    vector<Robot> listeRobot;

    Terrain terrain(largeur, hauteur);
    for(int i = 0; i < nbRobots; ++i){
        Robot robot;
        //Générer une position aléatoire (Range basé sur la hauteur-2 et la largeur-2
        // Verifier si le robot est au même endroit qu'un autre

        listeRobot.push_back(robot);
    }
    return 0;
}
