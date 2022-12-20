// Fichier     position.cpp
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        19.12.2022
//
// But         Met a disposition des type et des fonction permettant de traiter des positions sur un plan en 2D
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0
#include "position.h"
#include "annexe.h"

using namespace std;

position positionRelative(const position& pos, DIRECTIONS dir, int intervalle){
    position retour = pos;
    switch(dir){
        case DIRECTIONS::HAUT: {
            retour.back() -= intervalle;
            break;
        }

        case DIRECTIONS::BAS:  {
            retour.back() += intervalle;
            break;
        }

        case DIRECTIONS::DROITE: {
            retour.front() += intervalle;
            break;
        }

        case DIRECTIONS::GAUCHE:  {
            retour.front() -= intervalle;
            break;
        }
    }
    return retour;
}

DIRECTIONS directionAleatoire(){
    return (DIRECTIONS) randomInt(0, 3); // Auto pour warning
}