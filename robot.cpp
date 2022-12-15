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


Robot::Robot(){
    this->index = 0;
    this->posX  = 0;
    this->posY  = 0;
}

Robot::Robot(int index, int posX, int posY){
    this->index = index;
    this->posX  = posX;
    this->posY  = posY;
}

int Robot::getIndex() const{
    return this->index;
}

int Robot::getPosX()  const{
    return this->posX;
}
int Robot::getPosY()  const{
    return this->posY;
}

void Robot::setPosX(int newX){
    this->posX = newX;
}

void Robot::setPosY(int newY){
    this->posY = newY;
}

bool Robot::operator==(const Robot& robot) const{
    if(this->posX == robot.posX && this->posY == robot.posY)
        return true;
    else
        return false;
}

Robot::~Robot(){

}

bool Robot::deplacement(DIRECTIONS dir, int nbPas) {
    //if()

    return false;
}


DIRECTIONS directionAleatoire(int posX, int posY){
    return (DIRECTIONS) randomInt(0, 3); // Auto pour warning
}

