/**
 * @file structs_functions.h
 * @brief Fichier contenant les fichiers header utilisés par structs_functions.c ainsi que la déclaration des fonctions de structs_functions.c
**/

#ifndef STRUCTS_FUNCTIONS_H
#define STRUCTS_FUNCTIONS_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "jeu.h"

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

void stringToLower(char string[]);
bool isString(char string[]);
int demanderIntIntervalle(char texte[], int borne_inf, int borne_sup);
void pauseProgramme();
void akinator();
void akinator_recursif();

#endif // STRUCTS_FUNCTIONS_H
