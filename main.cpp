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

#include "position.h"
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
    string historiqueMorts;

    vector<Robot> listeRobot;

    Terrain terrain(largeur, hauteur);
    for(int i = 0; i < nbRobots; ++i){
        bool robotAparu;
        position pos;

        do{
            robotAparu = true;
            pos.front() = randomInt(0, terrain.getLargeur()-1);
            pos.back()  = randomInt(0, terrain.getHauteur()-1);

            if(!terrain.positionDisponible(pos)){
                robotAparu = false;
                continue;
            }

            if(!listeRobot.empty()){
                //Tester si robot poser sur un autre
                for(const Robot& robot : listeRobot){
                    if(pos == robot.getPosition()){
                        robotAparu = false;
                        break;
                    }
                }
            }
        }while(!robotAparu);

        Robot robot(i, pos);

        listeRobot.push_back(robot);
    }

    vector<int> ordreIteration;

    //Boucle principale du programme
    while(listeRobot.size() > 1){
        ordreIteration = randomListInt((int)listeRobot.size());
        DIRECTIONS dir;

        for(size_t i = 0; i < listeRobot.size(); ++i){
            Robot robotActuel = listeRobot.at((size_t)ordreIteration[i]);
            bool peuxBouger = false;

            do {
                dir = directionAleatoire();
                if(terrain.positionDisponible(positionRelative(robotActuel.getPosition(), dir, 1))){
                    peuxBouger = true;
                    listeRobot.at((size_t)ordreIteration[i]).deplacement(dir, 1);
                }

            } while(!peuxBouger);

            for(const Robot& robot : listeRobot){
                if(robotActuel.getIndex() == robot.getIndex())
                    continue;
                if(robotActuel == robot){
                    /*  FONCTIONNE PAS
                    // Ajouter le message de mort
                    string mort = "Robot " + robotActuel.getIndex(); // Utiler streamoperator
                    mort +=  ": est mort... \n";

                    historiqueMorts += mort;
                    */

                    //Tuer robot actuel
                    listeRobot.erase(listeRobot.begin() + ordreIteration[i]);

                    //Mettre a jour les index de la liste d'itération
                    for(size_t y = 0; y < ordreIteration.size(); ++y){
                        if(ordreIteration[y] > ordreIteration[i]){
                            --ordreIteration[y];
                        }
                    }


                    break;
                }
            }
        }

        system("clear");
        affichage(terrain, listeRobot);
        cout << historiqueMorts;

        /* Afficher le terrain et les robots */
        this_thread::sleep_for(chrono::milliseconds(200)); // Pause le programme temporairement
    }

    return 0;
}
