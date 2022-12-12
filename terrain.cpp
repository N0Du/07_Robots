// Fichier     terrain.cpp
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
#include "terrain.h"

Terrain::Terrain(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur){
    for(int i = 0; i < hauteur; ++i){
        if(!i || i == hauteur-1 ){
            terrain.push_back(Ligne((size_t)this->largeur, '_'));
        }else{
            terrain.push_back(Ligne((size_t)this->hauteur, ' '));
            terrain.back().front() = '|';
            terrain.back().back()  = '|';
        }
    }
}

int Terrain::getLargeur () const{
    return this->largeur;
}

int Terrain::getHauteur () const{
    return this->hauteur;
}

Matrice Terrain::getTerrain() const{
    return this->terrain;
}