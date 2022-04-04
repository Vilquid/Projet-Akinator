/**
 * @file jeu.h
 * @brief Fichier contenant les fichiers header utilisés par jeu.c ainsi que la déclaration des fonctions de jeu.c
**/

#ifndef JEU_H
#define JEU_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "structs_donnees.h"
#include <time.h>

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

int calculAgeMoyenHerosSuspects(Liste_Heros *liste);
void supprimerHerosSuspectsSelonAge(Liste_Heros *liste);
Question *choisirQuestionAleatoire(Liste_Questions *liste);

#endif // JEU_H
