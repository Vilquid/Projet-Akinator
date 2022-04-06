/**
 * @file gestion_fichiers.c
 * @brief Fichier contenant toutes les fonctions de gestion des fichiers
**/

#include "../include/gestion_fichiers.h"

// TODO : Fonction de récupération des questions
Liste_Questions *chargerFichierQuestions() {
	return NULL;
}

Liste_Heros *chargerFichierPersonnages() {

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
	Liste_Heros *file = creerListeHeros();

	// Variables à récupérer
	char nom[25];
	memset(nom, '\0', 25 * sizeof(char));
	int age = 0;
	Sexe sexe = 0;
	char nationalite[25];
	memset(nationalite, '\0', 25 * sizeof(char));
	Espece espece = 0;
	bool equipement = false;
	bool volant = false;
	bool masque = false;
	bool taille = false;
	char couleur[15];
	memset(couleur, '\0', 15 * sizeof(char));

	// Variables temporaires pour traiter et interpréter les chaînes de caractères
	char sexe_tmp[10];
	memset(sexe_tmp, '\0', 10 * sizeof(char));
	char espece_tmp[10];
	memset(espece_tmp, '\0', 10 * sizeof(char));
	char equipement_tmp[15];
	memset(equipement_tmp, '\0', 15 * sizeof(char));
	char volant_tmp[15];
	memset(volant_tmp, '\0', 15 * sizeof(char));
	char masque_tmp[15];
	memset(masque_tmp, '\0', 15 * sizeof(char));
	char taille_tmp[15];
	memset(taille_tmp, '\0', 15 * sizeof(char));

	// Tant qu'on n'est pas arrivé à la fin du fichier
	while (!feof(fichier_file)) {

		// Récupérer les données de la ligne courante du fichier texte
		fscanf(fichier_file, "%s,%s,%s,%d,%s,%s,%s,%s,%s,%s\n", nom, sexe_tmp, nationalite, age, equipement_tmp, espece_tmp, volant_tmp, masque_tmp, taille_tmp, couleur);

		// Faire correspondre la chaîne de caractères à l'énumération Sexe
		if (strcmp(sexe_tmp, "homme") == 0) {
			sexe = HOMME;
		} else if (strcmp(sexe_tmp, "femme") == 0) {
			sexe = FEMME;
		} else if (strcmp(sexe_tmp, "autre") == 0) {
			sexe = AUTRE;
		}

		// Faire correspondre la chaîne de caractères au booléen équipement
		if (strcmp(equipement_tmp, "equipement") == 0) {
			equipement = true;
		} else if (strcmp(equipement_tmp, "pouvoirs") == 0) {
			equipement = false;
		}

		// Faire correspondre la chaîne de caractères à l'énumération Espece
		if (strcmp(espece_tmp, "humain") == 0) {
			espece = HUMAIN;
		} else if (strcmp(espece_tmp, "extraterrestre") == 0) {
			espece = EXTRATERRESTRE;
		} else if (strcmp(espece_tmp, "mutant") == 0) {
			espece = MUTANT;
		} else if (strcmp(espece_tmp, "humain-altere") == 0) {
			espece = HUMAIN_ALTERE;
		}

		// Faire correspondre la chaîne de caractères au booléen volant
		if (strcmp(volant_tmp, "volant") == 0) {
			volant = true;
		} else if (strcmp(volant_tmp, "non-volant") == 0) {
			volant = false;
		}

		// Faire correspondre la chaîne de caractères au booléen masque
		if (strcmp(masque_tmp, "masque") == 0) {
			masque = true;
		} else if (strcmp(masque_tmp, "non-masque") == 0) {
			masque = false;
		}

		// Faire correspondre la chaîne de caractères au booléen taille
		if (strcmp(taille_tmp, "taille-normale") == 0) {
			taille = true;
		} else if (strcmp(taille_tmp, "taille-anormale") == 0) {
			taille = false;
		}

		// Créer et ajouter à la liste des héros un nouvel élément à partir des données récupérées
		ajouterHerosListe(file, creerEltHeros(creerHeros(nom, age, sexe, nationalite, espece, equipement, volant, masque, taille, couleur)));
	}

	// Fermeture du fichier texte
	fclose(fichier_file);

	return file;
}
