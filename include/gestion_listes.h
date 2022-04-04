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

Heros *creerHeros(char nom[25], Sexe, char nationalite[25], int, bool, Espece, bool, bool, bool, char couleur[15]);
Question *creerQuestion(char question[128], char reponse_attendue[64], int, char attribut[32]);

Elt_Heros *creerEltHeros(Heros *heros);
Elt_Question *creerEltQuestion(Question *question);

Liste_Heros *creerListeHeros();
Liste_Questions *creerListeQuestions();

void ajouterHerosListe(Liste_Heros *liste, Elt_Heros *elt_heros);
void ajouterQuestionListe(Liste_Questions *liste, Elt_Question *elt_question);

void viderListeHeros(Liste_Heros *liste);
void viderListeQuestions(Liste_Questions *liste);

#endif // GESTION_LISTES_H
