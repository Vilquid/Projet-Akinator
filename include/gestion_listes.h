/**
 * @file gestion_listes.h
 * @brief Fichier contenant les fichiers header utilisés par gestion_listes.c ainsi que la déclaration des fonctions de gestion_listes.c
**/

#ifndef GESTION_LISTES_H
#define GESTION_LISTES_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "structs_donnees.h"

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

Hero *creerHero(char nom[25], int sexe, char nationalite[25], int age, bool equipement, int humain, bool volant, bool masque, bool taille, char color[15]);
File_Heros *creerListeHeros();
File_Questions *creerListeQuestions();
int ajouterHeroListe(File_Heros *liste_heros, Elt_Hero *hero);

#endif // GESTION_LISTES_H
