// Fichier     terrain.h
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

#ifndef LABO_07_ROBOTS_TERRAIN_H
#define LABO_07_ROBOTS_TERRAIN_H

#include <vector>
#include <iostream>

#include "robot.h"


using Data = char;
using Ligne = std::vector<Data>;
using Matrice = std::vector<Ligne>;


class Terrain {
private:
    const int largeur;
    const int hauteur;

    Matrice terrain;
public:
    Terrain(int largeur, int hauteur);

    int getLargeur () const;
    int getHauteur () const;

    Matrice getTerrain() const;

    bool positionDisponible(position pos) const;

    friend std::ostream& operator<< (std::ostream& os, const Terrain& terrain);

};

void affichage(const Terrain& terrain, const std::vector<Robot>& listeRobot);



#endif //LABO_07_ROBOTS_TERRAIN_H
