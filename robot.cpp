// Fichier     robot.cpp
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

#include "robot.h"
#include "annexe.h"
#include <iostream>
using namespace std;

Robot::Robot(){
    this->index = 0;
    this->positionR = {0, 0};
}

Robot::Robot(int index, position pos){
    this->index = index;
    this->positionR = pos;
}

int Robot::getIndex() const{
    return this->index;
}

position Robot::getPosition()  const{
    return positionR;
}

bool Robot::operator==(const Robot& robot) const{
    if(this->positionR.front() == robot.positionR.front() && this->positionR.back() == robot.positionR.back())
        return true;
    else
        return false;
}

ostream& operator<<(ostream &os, const Robot &robot){
    os << robot.getIndex();
    return os;
}

void Robot::deplacement(DIRECTIONS dir, int nbPas) {
    this->positionR = positionRelative(this->positionR, dir, nbPas);

}