// Fichier     terrain.cpp
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        12.12.2022
//
// But         permet de créer un terrain de jeu pour les robots.
//             vérifi aussi si la positions sont disponible.
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
            terrain.push_back(Ligne((size_t)this->largeur, ' '));
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

// Retourne si une position donnée est disponible ou non
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

//Affiche le terrain avec les robots dedans
void affichage(const Terrain& terrain, const std::vector<Robot>& listeRobot){
    for(size_t i = 0; i < terrain.getTerrain().size(); ++i){
        for(size_t y = 0; y < terrain.getTerrain()[i].size(); ++y){
            //Affiche un robot si il y en a un present sur la position, affiche le terrain autrement
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
