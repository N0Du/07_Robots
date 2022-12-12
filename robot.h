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


class Robot {
private:
    int index;
    int posX;
    int posY;

public:
    Robot();
    Robot(int index, int posX, int posY);

    int getIndex() const;
    int getPosX()  const;
    int getPosY()  const;

    void setPosX(int newX);
    void setPosY(int newY);

    bool operator==(const Robot& robot) const;

    ~Robot();
};


#endif //LABO_07_ROBOTS_ROBOT_H
