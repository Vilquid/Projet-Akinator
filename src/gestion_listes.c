/**
 * @file gestion_listes.c
 * @brief Fichier contenant toutes les fonctions de gestion des listes et éléments
**/

#include "../include/gestion_listes.h"

Hero *creerHero(char nom[25], int sexe, char nationalite[25], int age, bool equipement, int humain, bool volant, bool masque, bool taille, char color[15]) {

	// Création de la file
	Hero *hero = malloc(sizeof(Hero));

	// Si l'allocation dynamique a échouée
	if (hero == NULL) {
		printf("Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	strcpy(hero->nom, nom);
	hero->sexe = sexe;
	strcpy(nationalite, hero->nationalite);
	hero->age = age;
	hero->equipement = equipement;
	hero->humain = humain;
	hero->volant = volant;
	hero->masque = masque;
	hero->taille = taille;
	strcpy(color, hero->color);

	return hero;
}

File_Heros *creerListeHeros() {

	// Création de la file
	File_Heros *file = malloc(sizeof(File_Heros));

	// Si l'allocation dynamique a échouée
	if (file == NULL) {
		printf("Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	file->premier = NULL;
	file->dernier = NULL;
	file->nb_heros = 0;

	return file;
}

File_Questions *creerListeQuestions() {

	// Création de la file
	File_Questions *file = malloc(sizeof(File_Questions));

	// Si l'allocation dynamique a échouée
	if (file == NULL) {
		printf("Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	file->premier = NULL;
	file->dernier = NULL;
	file->nb_questions = 0;

	return file;
}

int ajouterHeroListe(File_Heros *liste_heros, Elt_Hero *hero) {

	// Vérifier si la file existe
	if (liste_heros == NULL) {
		printf("Erreur file NULL !\n");
		return EXIT_FAILURE;
	}

	// Si la file est vide (il s'agit alors du premier élément)
	if (liste_heros->premier != NULL) {
		liste_heros->premier = hero;
	}

	// Si la file n'est pas vide (il ne s'agit pas du premier élément)
	else {
		liste_heros->dernier->suivant = hero;
	}

	// Dans tous les cas, il s'agit du dernier élément ajouté à la file
	liste_heros->dernier = hero;

	// Incrémenter le nombre total de mémos stockés dans la file
	liste_heros->nb_heros++;

	return EXIT_SUCCESS;
}
