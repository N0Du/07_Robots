// Fichier     position.h
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        19.12.2022
//
// But         description détaillée du projet
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0
#ifndef LABO_07_ROBOTS_POSITION_H
#define LABO_07_ROBOTS_POSITION_H
#include <array>
#include <iostream>

enum class DIRECTIONS{
    HAUT,
    BAS,
    GAUCHE,
    DROITE
};

using position = std::array<int, 2>;

position positionRelative(const position& pos, DIRECTIONS dir, int intervalle);

DIRECTIONS directionAleatoire();


#endif //LABO_07_ROBOTS_POSITION_H
