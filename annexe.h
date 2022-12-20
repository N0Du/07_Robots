// Fichier     annexe.h
// Auteur      Noam Dugerdil & Sebastian Diaz
// Date        12.12.2022
//
// But         header pour les fonctions annexes
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0

#ifndef LABO_07_ROBOTS_ANNEXE_H
#define LABO_07_ROBOTS_ANNEXE_H

#include <string>
#include <vector>

// nom         saisieInt
// but         fonction de saisie
//             la saisie est controllée
// param       msgEntree   message d'invite
// param       msgErreur   message d'erreur
// param       min         intervalle de saisie, valeur min comprise
// param       max         intervalle de saisie, valeur max comprise
// return      valeur saisie
// exception   n/a
int saisieInt(int min, int max, const std::string& msgEntree, const std::string& msgErreur);

// nom         randomInt
// but         fonction de generation d'un entier aléatoire
//
// param       MIN         intervalle, valeur min comprise
// param       MAX         intervalle, valeur max comprise
// return      entier
// exception   n/a
int randomInt(int min, int max);

// nom         randomListInt
// but         fonction de generation d'une liste d'entier continu dans un ordre aleatoire
//             [0-nbElem]
// param       nbElem      nb maximal du la suite d'entier
// return      vecteur contenant la liste des entiers
// exception   n/a
std::vector<int> randomListInt (int nbElem);
#endif //LABO_07_ROBOTS_ANNEXE_H
