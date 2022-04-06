/**
 * @file gestion_questions.h
 * @brief Fichier contenant les fichiers header utilisés par gestion_questions.c ainsi que la déclaration des fonctions de gestion_questions.c
**/

#ifndef GESTION_QUESTIONS_H
#define GESTION_QUESTIONS_H

/*---------------------
   Appel des Headers
---------------------*/

#include "librairies.h"
#include "structs_donnees.h"
#include "gestion_listes.h"
#include <sys/stat.h>

/*-----------------------------
   Déclaration des Fonctions
-----------------------------*/

Liste_Questions *initQuestions();
char recupQuestion(Liste_Questions *liste);

#endif // GESTION_QUESTIONS_H
