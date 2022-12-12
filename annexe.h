// Fichier     annexe.h
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

#ifndef LABO_07_ROBOTS_ANNEXE_H
#define LABO_07_ROBOTS_ANNEXE_H

#include <string>

int saisieInt(int min, int max, const std::string& msgEntree, const std::string& msgErreur);
int randomInt(int min, int max);
#endif //LABO_07_ROBOTS_ANNEXE_H
