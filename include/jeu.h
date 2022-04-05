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

Question *choisirQuestionAleatoire(Liste_Questions *liste);
void afficherHeros(Heros *heros);

int calculAgeMoyenHeros(Liste_Heros *liste);

void supprimerHerosSelonAge(Liste_Heros *liste);
void supprimerHerosSelonSexe(Liste_Heros *liste, Sexe sexe);
void supprimerHerosSelonNationalite(Liste_Heros *liste, char nationalite[25]);
void supprimerHerosSelonEspece(Liste_Heros *liste, Espece espece);
void supprimerHerosSelonEquipement(Liste_Heros *liste, bool equipement);
void supprimerHerosSelonVolant(Liste_Heros *liste, bool volant);
void supprimerHerosSelonMasque(Liste_Heros *liste, bool masque);
void supprimerHerosSelonTaille(Liste_Heros *liste, bool taille);
void supprimerHerosSelonCouleur(Liste_Heros *liste, char couleur[25]);

#endif // JEU_H
