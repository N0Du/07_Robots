// Fichier     position.h
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
#ifndef LABO_07_ROBOTS_POSITION_H
#define LABO_07_ROBOTS_POSITION_H
#include <array>

enum class DIRECTIONS{
    HAUT,
    BAS,
    GAUCHE,
    DROITE
};

using position = std::array<int, 2>;

// nom         positionRelative
// but         Calcul les coordonnée apres un déplacement depuis un certain point
//
// param       pos         Position initiale
// param       dir         Direction vers laquelle se deplacer
// param       intervalle  Intervalle de déplacement dans la direction voulue (nombre de pas)
// return      entier
// exception   n/a
position positionRelative(const position& pos, DIRECTIONS dir, int intervalle);

// nom         directionAleatoire
// but         fonction pour générer une direction aléatoire
//
// return      DIRECTION
// exception   n/a
DIRECTIONS directionAleatoire();


#endif //LABO_07_ROBOTS_POSITION_H
