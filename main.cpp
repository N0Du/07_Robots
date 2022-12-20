// Fichier     main.cpp
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        12.12.2022
//
// But         créer une terrain avec de robot qui s'entretue. le dernier gagne
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
    const string MSG_ERREUR = "Veuillez entrer un nombre valide."; // Message d'erreur lors d'une saisie invalide

    //==============================
    // Saisie utilisateur
    //==============================
    string msg = "Saisir la largeur";
    int largeur  = saisieInt(10, 1000, msg, MSG_ERREUR);
    msg = "Saisir la hauteur";
    int hauteur  = saisieInt(10, 1000, msg, MSG_ERREUR);
    msg = "Saisir le nombre de robot";
    int nbRobots = saisieInt(1, 9, msg, MSG_ERREUR);
    //==============================


    //==============================
    // Préparation du jeu
    //==============================
    stringstream historiqueMorts; // Flux contenant la liste des robots mort

    vector<Robot> listeRobot;

    Terrain terrain(largeur, hauteur);

    //==============================
    // Création des robots
    //==============================
    for(int i = 0; i < nbRobots; ++i){
        bool robotAparu;
        position pos;

        do{
            robotAparu = true;

            //Generation d'une position aléatoire
            pos.front() = randomInt(0, terrain.getLargeur()-1);
            pos.back()  = randomInt(0, terrain.getHauteur()-1);

            // Verifie si la position souhaitée est disponible
            if(!terrain.positionDisponible(pos)){
                robotAparu = false;
                continue;
            }

            //Création du robot
            Robot robot(i, pos);

            auto iterator = find_if(listeRobot.begin(), listeRobot.end(), EstAuMemeEndroit(robot)); // auto pour eviter warning
            if(iterator == listeRobot.end()){
                //Si la positione est dispo, insertion du robot dans la liste des robots
                listeRobot.push_back(robot);
            }
        }while(!robotAparu);
    }

    vector<int> ordreIteration;

    //==============================
    //Boucle principale du programme
    //==============================
    while (listeRobot.size() > 1) {
        // Génère une liste contenant les index de chaque élément de "listeRobot".
        // L'ordre des index est aléatoire
        ordreIteration = randomListInt((int) listeRobot.size());

        DIRECTIONS dir;
        for (size_t i = 0; i < listeRobot.size(); ++i) {
            Robot &robotActuel = listeRobot.at((size_t) ordreIteration[i]);
            bool peuxBouger = false;

            //Essaye de déplacer le robot jusqu'a qu'il trouve une position valide
            do {
                dir = directionAleatoire();
                //Vérifie si la position voulue est disponible
                if (terrain.positionDisponible(positionRelative(robotActuel.getPosition(), dir, 1))) {
                    peuxBouger = true;
                    robotActuel.deplacement(dir, 1); // Déplace le robot
                }
            } while (!peuxBouger);

            // Cherche si le robot a été déplacé sur un autre
            auto it = find_if(listeRobot.begin(), listeRobot.end(), EstAuMemeEndroit(robotActuel)); // Auto pour eviter warning

            if(it != listeRobot.end()){
                historiqueMorts << "Robot " << robotActuel << " a ete tuer par Robot " << it->getIndex() << endl;

                //Supprimer le robot actuel de la liste
                listeRobot.erase(listeRobot.begin() + ordreIteration[i]);

                //Mettre a jour les index de la liste d'itération après la suppression
                for (size_t y = 0; y < ordreIteration.size(); ++y) {
                    if (ordreIteration[y] > ordreIteration[i]) {
                        --ordreIteration[y];
                    }
                }
            }
        }

        system("clear");
        affichage(terrain, listeRobot);         // Affiche le terrain ainsi que les robots
        cout << historiqueMorts.str() << endl;  // Affiche la liste des morts

        this_thread::sleep_for(chrono::milliseconds(200)); // Pause le programme temporairement
    }

    return 0;
}
