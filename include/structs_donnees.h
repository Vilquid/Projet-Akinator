/**
 * @file structs_donnees.h
 * @brief Fichier contenant toutes les déclarations des structures de données
**/

#ifndef STRUCT_DONNEES_H
#define STRUCT_DONNEES_H

/*--------------------------------
   Déclaration des Enumérations
--------------------------------*/

typedef enum Sexe { HOMME, FEMME, AUTRE } Sexe;
typedef enum Espece { HUMAIN, EXTRATERRESTRE, MUTANT, HUMAIN_ALTERE } Espece;

/*------------------------------
   Déclaration des Structures
------------------------------*/

typedef struct Heros Heros;
typedef struct Question Question;
typedef struct Elt_Heros Elt_Heros;
typedef struct Elt_Question Elt_Question;
typedef struct Liste_Heros Liste_Heros;
typedef struct Liste_Questions Liste_Questions;

struct Heros {
	char nom[25];         // Nom du perso
	int age;              // Age du personnage
	Sexe sexe;            // 0 = Homme, 1 = Femme, 2 = Autre
	char nationalite[25]; // Nationalité du personnage
	Espece espece;        // 0 = Humain, 1 = Extraterrestre, 2 = Mutant, 3 = Humain altéré
	bool equipement;      // True = Oui en porte, False = Non en porte pas
	bool volant;          // True = il vole, False = ne vole pas
	bool masque;          // True = porte un masque, False = Non
	bool taille;          // True = taille normale, False = taille anormale
	char couleur[25];     // Couleur prédominante
};

struct Question {
	char question[128];        // Texte de la question
	char reponse_attendue[25]; // Réponse positive attendue
	int priorite;              // Priorité de la question
	char attribut[32];         // Attribut ciblé par la question
};

struct Elt_Heros {
	Heros *heros;
	Elt_Heros *suivant;
};

struct Elt_Question {
	Question *question;
	Elt_Question *suivant;
};

struct Liste_Heros {
	Elt_Heros *premier;
	int nb_heros;
};

struct Liste_Questions {
	Elt_Question *premier;
	int nb_questions;
};

#endif // STRUCT_DONNEES_H
