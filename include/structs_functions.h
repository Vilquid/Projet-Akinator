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

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

void convert_to_lower(char string[]);
int est_une_string(char string[]);
int est_un_int_et_est_compris_entre(char string[], int choix, int nombre_1, int nombre_2);
void ajouter_question_BDD();
void ajouter_personnage_BDD();
void akinator();

#endif // STRUCTS_FUNCTIONS_H
