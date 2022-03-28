/**
 * @file structs_donnees.h
 * @brief Fichier contenant toutes les déclarations des structures de données
**/

#ifndef STRUCT_DONNEES_H
#define STRUCT_DONNEES_H

/*------------------------------
   Déclaration des Structures
------------------------------*/

typedef struct Hero Hero;
typedef struct File_Heros File_Heros;
typedef struct File_Questions File_Questions;
typedef struct Elt_Hero Elt_Hero;
typedef struct Elt_Question Elt_Question;

struct Hero {
	char nom[25];         // Nom du perso
	int sexe;             // 2 => Féminin, 1 => Masculin, 0 => Autre
	char nationalite[25]; // Nationalité du personnage
	int age;              // Age du personnage
	bool equipement;      // True => Oui en porte, False => Non en porte pas
	int humain;           // 0 => Humain / 1 => Extraterrestre / 2 => Mutant / 3 => Humain-altere
	bool volant;          // True => il vole, False => ne vole pas
	bool masque;          // True => porte un masque, False => Non
	bool taille;          // True => taille normal, False => taille anormal
	char color[15];       // Couleur prédominante
};

struct Elt_Hero {
	Hero *hero;
	bool suspect;
	Elt_Hero *suivant;
};

struct Elt_Question {
	char question[256];
	Elt_Question *suivant;
};

struct File_Heros {
	Elt_Hero *premier;
	Elt_Hero *dernier;
	int nb_heros;
};

struct File_Questions {
	Elt_Question *premier;
	Elt_Question *dernier;
	int nb_questions;
};

#endif // STRUCT_DONNEES_H
