// Fichier     robot.h
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        12.12.2022
//
// But         Permet de créer et déplacer des robots relativement a leur position
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0

#ifndef LABO_07_ROBOTS_ROBOT_H
#define LABO_07_ROBOTS_ROBOT_H

#include "position.h"
#include <iostream>

class Robot {
private:
    int index;              // Numéro du robot
    position positionR;     // Position du Robot

public:
    Robot();
    Robot(int index, position pos);

    int getIndex() const;
    position getPosition()  const;

    void deplacement(DIRECTIONS dir, int nbPas);

    bool operator==(const Robot& robot) const;

    friend std::ostream& operator<< (std::ostream& os, const Robot& robot);
};

// nom         EstAuMemeEndroit
// but         foncteur
class EstAuMemeEndroit{
private:
    Robot    robot;
public:
    explicit EstAuMemeEndroit(Robot robot)   : robot(robot){};
    bool operator() (Robot r);
};

#endif //LABO_07_ROBOTS_ROBOT_H
