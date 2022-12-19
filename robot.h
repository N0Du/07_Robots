// Fichier     robot.h
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

#ifndef LABO_07_ROBOTS_ROBOT_H
#define LABO_07_ROBOTS_ROBOT_H

#include "position.h"

class Robot {
private:
    int index;
    position positionR;

public:
    Robot();
    Robot(int index, position pos);

    int getIndex() const;
    position getPosition()  const;

    void deplacement(DIRECTIONS dir, int nbPas);

    bool operator==(const Robot& robot) const;

    friend std::ostream& operator<< (std::ostream& os, const Robot& robot);
};

DIRECTIONS directionAleatoire();

#endif //LABO_07_ROBOTS_ROBOT_H
