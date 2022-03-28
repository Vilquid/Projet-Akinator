#ifndef PROJET_1___AKINATOR_STRUCTS_FUNCTIONS_H
#define PROJET_1___AKINATOR_STRUCTS_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Placer les déclarations des structures après ce commentaire
typedef struct Hero Hero;
struct Hero{
    bool sexe; //True => feminin, False => Masculin
    char nationality[25]; //nationalité du personnage
    int age; //Age du personnage
    bool equipement; //True => Oui en porte, False => Non en porte pas
    bool humain; //True => humain, False => ExtreTerrestre
    bool volant; //True => il vole, False => ne vole pas
    bool masque; //True => porte un masque, False => Non
    bool taille; //True => taille normal, False => taille anormal
    char color[15]; //Couleur prédominante
};
// Placer les déclarations des structures avant ce commentaire

// Placer les prototypes des fonctions après ce commentaire
void akinator();
void ajouter_personnage_questions_BDD(Hero);
int est_une_string(char string[]);
void convert_to_lower(char string[]);
// Placer les prototypes des fonctions avant ce commentaire

#endif //PROJET_1___AKINATOR_STRUCTS_FUNCTIONS_H
