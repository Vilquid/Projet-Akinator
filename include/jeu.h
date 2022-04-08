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
#include "gestion_listes.h"
#include "gestion_fichiers.h"
#include "gestion_BDD.h"
#include <time.h>

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

Question *choisirQuestionAleatoire(Liste_Questions *liste);
Heros *choisirSuspect(Liste_Heros *liste);
void afficherHeros(Heros *heros);
int calculAgeMoyenHeros(Liste_Heros *liste);

void supprimerHerosSelonAge(Liste_Heros *liste);
void supprimerHerosSelonSexe(Liste_Heros *liste, Sexe sexe);
void supprimerHerosSelonNationalite(Liste_Heros *liste, char nationalite[]);
void supprimerHerosSelonEspece(Liste_Heros *liste, Espece espece);
void supprimerHerosSelonEquipement(Liste_Heros *liste, bool equipement);
void supprimerHerosSelonVolant(Liste_Heros *liste, bool volant);
void supprimerHerosSelonMasque(Liste_Heros *liste, bool masque);
void supprimerHerosSelonTaille(Liste_Heros *liste, bool taille);
void supprimerHerosSelonCouleur(Liste_Heros *liste, char couleur[]);
void supprimerQuestionSelonQuestion(Liste_Questions *liste, char question[128]);

void boucle_jeu();
void question_ajouter_perso_BDD(Heros);
void question_ajouter_question_BDD();
bool question_rejouer();
Heros attribution_caracteristiques_heros_temporaire(Heros, Liste_Heros*, Liste_Questions*);

#endif // JEU_H
