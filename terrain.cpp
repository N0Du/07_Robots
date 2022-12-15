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
#include <iomanip>

using namespace std;

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

bool Terrain::positionDisponible(int posX, int posY) const {
    if(posX == 0 || posX == hauteur-1 || posY == 0 || posY == largeur -1)
        return false;

    return true;
}

void Terrain::ajouterRobot(const Robot& robot) {
    terrain.at((size_t)robot.getPosY()).at((size_t)robot.getPosX()) = char(robot.getIndex() + '0');
}

// A revoir
ostream& operator<<(ostream &os, const Terrain &terrain){
    for(const Ligne & i : terrain.terrain){
        for(char y : i){
            cout << setw(2) << y;
        }
        cout << endl;
    }
    return os;
}
