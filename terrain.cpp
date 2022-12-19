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

bool Terrain::positionDisponible(position pos) const {
    if(pos.front() <= 0 || pos.front() >= largeur-1 || pos.back() <= 0 || pos.back() >= hauteur -1)
        return false;

    return true;
}

ostream& operator<<(ostream &os, const Terrain &terrain){
    for(const Ligne & i : terrain.terrain){
        for(char y : i){
            cout << setw(2) << y;
        }
        cout << endl;
    }
    return os;
}

void affichage(const Terrain& terrain, const std::vector<Robot>& listeRobot){
    for(size_t i = 0; i < terrain.getTerrain().size(); ++i){
        for(size_t y = 0; y < terrain.getTerrain()[i].size(); ++y){
            bool robotAfficher = false;
            for(const Robot& robot : listeRobot){
                if(robot.getPosition().front() == (int)y && robot.getPosition().back() == (int)i){
                    robotAfficher = true;
                    cout << setw(2) << robot;
                    break;
                }
            }
            if(!robotAfficher){
                cout << setw(2) << terrain.getTerrain()[i][y];
            }
        }
        cout << endl;
    }
    cout << endl;
}
