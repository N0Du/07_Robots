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

    vector<int> winRate(nbRobots, 0);//rem
    int longestGame = 0;//rem
    int shortestGame = 0;//rem

    while(true) {//rem
    //========================
    // Préparation du jeu
    //========================
    stringstream historiqueMorts;

    vector<Robot> listeRobot;

    Terrain terrain(largeur, hauteur);

    // Création des robots
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
    int iterations = 0;

    //Boucle principale du programme
    while (listeRobot.size() > 1) {
        ordreIteration = randomListInt((int) listeRobot.size());
        DIRECTIONS dir;

        for (size_t i = 0; i < listeRobot.size(); ++i) {
            Robot &robotActuel = listeRobot.at((size_t) ordreIteration[i]);
            bool peuxBouger = false;

            do {
                dir = directionAleatoire();
                if (terrain.positionDisponible(positionRelative(robotActuel.getPosition(), dir, 1))) {
                    peuxBouger = true;
                    robotActuel.deplacement(dir, 1);
                }

            } while (!peuxBouger);

            for (const Robot &robot: listeRobot) {
                if (robotActuel.getIndex() == robot.getIndex())
                    continue;
                if (robotActuel == robot) {
                    historiqueMorts << "Robot " << robotActuel << " : est mort..." << endl;
                    //Tuer robot actuel
                    listeRobot.erase(listeRobot.begin() + ordreIteration[i]);

                    //Mettre a jour les index de la liste d'itération
                    for (size_t y = 0; y < ordreIteration.size(); ++y) {
                        if (ordreIteration[y] > ordreIteration[i]) {
                            --ordreIteration[y];
                        }
                    }
                    break;
                }
            }
        }

        system("clear");
        affichage(terrain, listeRobot); // Affiche le terrain ainsi que les robots
        cout << historiqueMorts.str() << endl;

        //this_thread::sleep_for(chrono::milliseconds(0)); // Pause le programme temporairement
        cout    << "Wins: " << endl
                << "0: " << winRate[0] << endl
                << "1: " << winRate[1] << endl
                << "2: " << winRate[2] << endl
                << "3: " << winRate[3] << endl
                << "4: " << winRate[4] << endl
                << "5: " << winRate[5] << endl
                << "6: " << winRate[6] << endl
                << "7: " << winRate[7] << endl
                << "8: " << winRate[8] << endl
                << "Current game: " << iterations << endl
                << "Shotest game: " << shortestGame << endl
                << "Longest game: " << longestGame  << endl;
        ++iterations;
    }
        if(iterations > longestGame){
            longestGame = iterations;
        }

        if(iterations < shortestGame || !shortestGame)
            shortestGame = iterations;

        ++winRate[listeRobot[0].getIndex()];
    }//
    return 0;
}
