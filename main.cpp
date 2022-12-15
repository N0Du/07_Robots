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
#include <thread>

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
    const int LARGEUR_MUR = 1;
    string historiqueMorts = "";

    vector<Robot> listeRobot;

    Terrain terrain(largeur, hauteur);
    for(int i = 0; i < nbRobots; ++i){
        //Générer une position aléatoire (Range basé sur la hauteur-2 et la largeur-2
        // Verifier si le robot est au même endroit qu'un autre
        int posX = randomInt(0, largeur - 2 * LARGEUR_MUR);
        int posY = randomInt(0, hauteur - 2 * LARGEUR_MUR);

        if(!listeRobot.empty()){

        }

        Robot robot (i, 0, 0);

        listeRobot.push_back(robot);
    }

    vector<int> listeIteration;

    Robot robot_test(7, 5, 5);
    terrain.ajouterRobot(robot_test);

    //Boucle principale du programme
    while(listeRobot.size() > 1){
        listeIteration = randomListInt((int)listeRobot.size());
        DIRECTIONS dir;
        /*
        for(size_t i = 0; i < listeRobot.size(); ++i){
            Robot robotActuel = listeRobot.at((size_t)listeIteration[i]);
            bool peuxBouger = false;

            do {
                dir = directionAleatoire(robotActuel.getPosX(), robotActuel.getPosY());

                switch(dir){
                    case DIRECTIONS::HAUT: {
                        if(terrain.positionDisponible(robotActuel.getPosX(), robotActuel.getPosY() - 1)){
                            peuxBouger = true;
                        }
                        break;
                    }

                    case DIRECTIONS::BAS:   {
                        if(terrain.positionDisponible(robotActuel.getPosX(), robotActuel.getPosY() + 1)){
                            peuxBouger = true;
                        }
                        break;
                    }

                    case DIRECTIONS::DROITE: {
                        if(terrain.positionDisponible(robotActuel.getPosX() + 1, robotActuel.getPosY())){
                            peuxBouger = true;
                        }
                        break;
                    }

                    case DIRECTIONS::GAUCHE:  {
                        if(terrain.positionDisponible(robotActuel.getPosX() - 1, robotActuel.getPosY())){
                            peuxBouger = true;
                        }
                        break;
                    }
                }
            } while(!peuxBouger);

            robotActuel.deplacement(dir, 1);

            /*Tester si il c'est déplacer sur un autre robots

            terrain.ajouterRobot(robotActuel);
        }*/

        system("clear");
        cout << terrain;

        /* Afficher le terrain et les robots */
        this_thread::sleep_for(chrono::milliseconds(200)); // Pause le programme temporairement
    }

    return 0;
}
