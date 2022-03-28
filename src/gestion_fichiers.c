/**
 * @file gestion_fichiers.c
 * @brief Fichier contenant toutes les fonctions de gestion des fichiers
**/

#include "../include/gestion_fichiers.h"

File_Heros *chargerFichierPersonnage() {

	// Création du pointeur vers le fichier texte
	FILE *fichier_file = NULL;

	// Ouverture du fichier texte en lecture
	fichier_file = fopen("../db/personnages.txt", "r");

	// Si le fichier texte n'a pas pu être ouvert
	if (fichier_file == NULL) {
		printf("Erreur d'ouverture du fichier texte !\n");
		exit(EXIT_FAILURE);
	}

	// Création du pointeur de la pile
	File_Heros *file = creerListeHeros();

	// Variables à récupérer
	char nom[25];
	memset(nom, '\0', 25 * sizeof(char));
	int sexe = 0;
	char nationalite[25];
	memset(nationalite, '\0', 25 * sizeof(char));
	int age = 0;
	bool equipement = false;
	int humain = 0;
	bool volant = false;
	bool masque = false;
	bool taille = false;
	char color[15];
	memset(color, '\0', 15 * sizeof(char));

	// Tant qu'on n'est pas arrivé à la fin du fichier
	while (!feof(fichier_file)) {

		// Récupérer les données de la ligne
		// TODO : Modifier les types de données et déduire infos des chaines de caractères BDD
		fscanf(fichier_file, "%s,%s,%s,%d,%s,%s,%s,%s,%s,%s\n", nom, sexe, nationalite, age, equipement, humain, volant, masque, taille, color);

		// Créer et empiler un nouvel élément à partir des données récupérées
		// TODO : Changer la création du Héro pour du Elt_Hero
		creerHero(nom, sexe, nationalite, age, equipement, humain, volant, masque, taille, color);
		//ajouterHeroListe(file, );
	}

	// Fermeture du fichier texte
	fclose(fichier_file);

	return file;
}
