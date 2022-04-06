/**
 * @file gestion_fichiers.h
 * @brief Fichier contenant les fichiers header utilisés par gestion_fichiers.c ainsi que la déclaration des fonctions de gestion_fichiers.c
**/

#ifndef GESTION_FICHIERS_H
#define GESTION_FICHIERS_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "structs_donnees.h"
#include "gestion_listes.h"

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

Liste_Heros *chargerFichierPersonnages();
Liste_Questions *chargerFichierQuestions();

#endif // GESTION_FICHIERS_H
