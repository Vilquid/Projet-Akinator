/**
 * @file gestion_fichiers.c
 * @brief Fichier contenant toutes les fonctions de gestion des fichiers
**/

#include "../include/gestion_fichiers.h"

/**
 * @brief Fonction permettant de lire le fichier des personnages, créer les héros trouvés, et les ajouter à la liste des héros
 * @return Liste_Heros* – Pointeur vers la liste de héros créée
**/
Liste_Heros *chargerDonneesFichierPersonnages() {

	// Création du pointeur vers le fichier texte
	FILE *fichier_persos = NULL;

	// Ouverture du fichier texte en lecture
	fichier_persos = fopen("../db/personnages.txt", "r");

	// Si le fichier texte n'a pas pu être ouvert
	if (fichier_persos == NULL) {
		printf("chargerDonneesFichierPersonnages() : Erreur d'ouverture du fichier texte !\n");
		exit(EXIT_FAILURE);
	}

	// Création du pointeur de la liste
	Liste_Heros *liste_heros = creerListeHeros();

	// Variables à récupérer
	char nom[25];
	int age = 0;
	Sexe sexe = 0;
	char nationalite[25];
	Espece espece = 0;
	bool equipement = false;
	bool volant = false;
	bool masque = false;
	bool taille = false;
	char couleur[25];

	// Variables temporaires pour traiter et interpréter les chaînes de caractères
	char sexe_tmp[10];
	char espece_tmp[25];
	char equipement_tmp[25];
	char volant_tmp[25];
	char masque_tmp[25];
	char taille_tmp[25];

	// Tant qu'on n'est pas arrivé à la fin du fichier
	while (!feof(fichier_persos)) {

		// Réinitialiser les chaînes de caractères
		memset(nom, '\0', 25 * sizeof(char));
		memset(nationalite, '\0', 25 * sizeof(char));
		memset(couleur, '\0', 25 * sizeof(char));
		memset(sexe_tmp, '\0', 10 * sizeof(char));
		memset(espece_tmp, '\0', 25 * sizeof(char));
		memset(equipement_tmp, '\0', 25 * sizeof(char));
		memset(volant_tmp, '\0', 25 * sizeof(char));
		memset(masque_tmp, '\0', 25 * sizeof(char));
		memset(taille_tmp, '\0', 25 * sizeof(char));

		// Récupérer les données de la ligne courante du fichier texte
		fscanf(fichier_persos, "%s %s %s %d %s %s %s %s %s %s\n", nom, sexe_tmp, nationalite, &age, equipement_tmp, espece_tmp, volant_tmp, masque_tmp, taille_tmp, couleur);

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

		// Afficher tous les attributs récupérés
		printf("===============================\n");
		printf("Nom : %s\n", nom);
		printf("Sexe : %s\n", sexe_tmp);
		printf("Nationalite : %s\n", nationalite);
		printf("Age : %d\n", age);
		printf("Equipement : %s\n", equipement_tmp);
		printf("Espece : %s\n", espece_tmp);
		printf("Volant : %s\n", volant_tmp);
		printf("Masque : %s\n", masque_tmp);
		printf("Taille : %s\n", taille_tmp);
		printf("Couleur : %s\n", couleur);
		printf("===============================\n");

		// Créer et ajouter à la liste des héros un nouvel élément à partir des données récupérées
		ajouterHerosListe(liste_heros, creerEltHeros(creerHeros(nom, age, sexe, nationalite, espece, equipement, volant, masque, taille, couleur)));
	}

	// Fermeture du fichier texte
	fclose(fichier_persos);

	return liste_heros;
}

/**
 * @brief Fonction permettant de lire le fichier des questions, créer les questions trouvées, et les ajouter à la liste des questions
 * @return Liste_Questions* – Pointeur vers la liste de questions créée
**/
Liste_Questions *chargerDonneesFichierQuestions() {

	// Création du pointeur vers le fichier texte
	FILE *fichier_questions = NULL;

	// Ouverture du fichier texte en lecture
	fichier_questions = fopen("../db/questions.txt", "r");

	// Si le fichier texte n'a pas pu être ouvert
	if (fichier_questions == NULL) {
		printf("chargerDonneesFichierQuestions() : Erreur d'ouverture du fichier texte !\n");
		exit(EXIT_FAILURE);
	}

	// Création du pointeur de la liste
	Liste_Questions *liste_questions = creerListeQuestions();

	// Variables à récupérer
	char question[128];
	char reponse_attendue[64];
	int priorite = 0;
	char attribut[32];

	// Tant qu'on n'est pas arrivé à la fin du fichier
	while (!feof(fichier_questions)) {

		// Réinitialiser les chaînes de caractères
		memset(question, '\0', 128 * sizeof(char));
		memset(reponse_attendue, '\0', 64 * sizeof(char));
		memset(attribut, '\0', 32 * sizeof(char));

		// Récupérer les données de la ligne courante du fichier texte
		// TODO : Récupération et traitement des données récupérées du fichier texte
		fscanf(fichier_questions, "%d/%s/%s : %[^\n] ", &priorite, attribut, reponse_attendue, question);

		// Créer et ajouter à la liste des questions un nouvel élément à partir des données récupérées
		ajouterQuestionListe(liste_questions, creerEltQuestion(creerQuestion(question, reponse_attendue, priorite, attribut)));
	}

	// Fermer le fichier texte
	fclose(fichier_questions);

	// Retourner la liste des questions
	return liste_questions;
}
