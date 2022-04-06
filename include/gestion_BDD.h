/**
 * @file gestion_BDD.h
 * @brief Fichier contenant les fichiers header utilisés par gestion_BDD.c ainsi que la déclaration des fonctions de gestion_BDD.c
**/

#ifndef GESTION_BDD_H
#define GESTION_BDD_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "fonctions_utilitaires.h"
#include "structs_donnees.h"

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

void ajouter_question_BDD();
void ajouter_personnage_BDD(Heros heros);

#endif // GESTION_BDD_H
