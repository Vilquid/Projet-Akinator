/**
 * @file gestion_listes.c
 * @brief Fichier contenant toutes les fonctions de gestion des listes et éléments
**/

#include "../include/gestion_listes.h"

/**
 * @brief Fonction permettant de créer un héros
 * @param nom Nom du personnage
 * @param sexe Sexe du personnage
 * @param nationalite Nationalité du personnage
 * @param age Age du personnage
 * @param equipement Si le personnage porte un équipement
 * @param espece Espèce du personnage
 * @param volant Si le personnage peut voler nativement (sans équipement)
 * @param masque Si le personnage porte un masque
 * @param taille Si le personnage est de taille normale ou non
 * @param couleur Couleur prédominante du personnage
 * @return Heros* – Pointeur vers le héros créé
**/
Heros *creerHeros(char nom[25], Sexe sexe, char nationalite[25], int age, bool equipement, Espece espece, bool volant, bool masque, bool taille, char couleur[15]) {

	// Création de la liste
	Heros *heros = malloc(sizeof(Heros));

	// Si l'allocation dynamique a échouée
	if (heros == NULL) {
		printf("creerHeros() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	strcpy(heros->nom, nom);
	heros->sexe = sexe;
	strcpy(nationalite, heros->nationalite);
	heros->age = age;
	heros->equipement = equipement;
	heros->espece = espece;
	heros->volant = volant;
	heros->masque = masque;
	heros->taille = taille;
	strcpy(couleur, heros->couleur);

	return heros;
}

/**
 * @brief Fonction permettant de créer une question
 * @param question Question à poser
 * @param reponse_attendue Réponse attendue
 * @param priorite Priorité de la question
 * @param attribut Attribut ciblé par la question
 * @return Question* – Pointeur vers la question créée
**/
Question *creerQuestion(char question[128], char reponse_attendue[64], int priorite, char attribut[32]) {

	// Création de la liste
	Question *quest = malloc(sizeof(Question));

	// Si l'allocation dynamique a échouée
	if (quest == NULL) {
		printf("creerQuestion() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	strcpy(quest->question, question);
	strcpy(quest->reponse_attendue, reponse_attendue);
	quest->priorite = priorite;
	strcpy(quest->attribut, attribut);

	return quest;
}

/**
 * @brief Fonction permettant de créer un élément de la liste héros
 * @param heros Héros à ajouter à la liste
 * @return Elt_Heros* – Pointeur vers l'élément de la liste créée
**/
Elt_Heros *creerEltHeros(Heros *heros) {

	// Si le héros est NULL
	if (heros == NULL) {
		printf("creerEltHeros() : Le héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Création de la liste
	Elt_Heros *elt_heros = malloc(sizeof(Elt_Heros));

	// Si l'allocation dynamique a échouée
	if (elt_heros == NULL) {
		printf("creerEltHeros() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	elt_heros->heros = heros;
	elt_heros->suivant = NULL;

	return elt_heros;
}

/**
 * @brief Fonction permettant de créer un élément de la liste question
 * @param question Question à ajouter à la liste
 * @return Elt_Question* – Pointeur vers l'élément de la liste créée
**/
Elt_Question *creerEltQuestion(Question *question) {

	// Si la question est NULL
	if (question == NULL) {
		printf("creerEltQuestion() : La question est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Création de l'élément
	Elt_Question *elt_question = malloc(sizeof(Elt_Question));

	// Si l'allocation dynamique a échouée
	if (elt_question == NULL) {
		printf("creerEltQuestion() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	elt_question->question = question;
	elt_question->suivant = NULL;

	return elt_question;
}

/**
 * @brief Fonction permettant de créer et d'initialiser la liste des héros
 * @return Liste_Heros* – Pointeur vers la liste de héros créée
**/
Liste_Heros *creerListeHeros() {

	// Création de la liste
	Liste_Heros *liste = malloc(sizeof(Liste_Heros));

	// Si l'allocation dynamique a échouée
	if (liste == NULL) {
		printf("creerListeHeros() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	liste->premier = NULL;
	liste->nb_heros = 0;

	return liste;
}

/**
 * @brief Fonction permettant de créer et d'initialiser la liste des questions
 * @return Liste_Questions* – Pointeur vers la liste de questions créée
**/
Liste_Questions *creerListeQuestions() {

	// Création de la liste
	Liste_Questions *liste = malloc(sizeof(Liste_Questions));

	// Si l'allocation dynamique a échouée
	if (liste == NULL) {
		printf("creerListeQuestions() : Erreur d'allocation memoire !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser les attributs
	liste->premier = NULL;
	liste->nb_questions = 0;

	return liste;
}

/**
 * @brief Fonction permettant d'ajouter un héros à la liste des héros
 * @param liste Liste des héros
 * @param elt_heros Héros à ajouter à la liste
**/
void ajouterHerosListe(Liste_Heros *liste, Elt_Heros *elt_heros) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("ajouterHerosListe() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si l'élément est NULL
	if (elt_heros == NULL) {
		printf("ajouterHerosListe() : L'élément à ajouter est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		liste->premier = elt_heros;
	}

	else {
		Elt_Heros *tmp = liste->premier;

		while (tmp->suivant != NULL) {
			tmp = tmp->suivant;
		}

		tmp->suivant = elt_heros;
	}

	liste->nb_heros++;
}

/**
 * @brief Fonction permettant d'ajouter une question à la liste des questions
 * @param liste Liste des questions
 * @param elt_question Question à ajouter à la liste
**/
void ajouterQuestionListe(Liste_Questions *liste, Elt_Question *elt_question) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("ajouterQuestionListe() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si l'élément est NULL
	if (elt_question == NULL) {
		printf("ajouterQuestionListe() : L'élément à ajouter est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		liste->premier = elt_question;
	}

	else {
		Elt_Question *tmp = liste->premier;

		while (tmp->suivant != NULL) {
			tmp = tmp->suivant;
		}

		tmp->suivant = elt_question;
	}

	liste->nb_questions++;
}

/**
 * @brief Fonction permettant de supprimer un héros de la liste de héros
 * @param liste Liste des héros
 * @param elt_heros Héros à supprimer de la liste
**/
void supprimerHerosListe(Liste_Heros *liste, Elt_Heros *elt_heros) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosListe() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si l'élément est NULL
	if (elt_heros == NULL) {
		printf("supprimerHerosListe() : L'élément à supprimer est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		printf("supprimerHerosListe() : La liste des héros est vide !\n");
		return;
	}

	// Si la liste contient un seul élément
	if (liste->premier->suivant == NULL) {
		free(liste->premier);
		liste->premier = NULL;
	}

	else {
		Elt_Heros *tmp = liste->premier;

		while (tmp->suivant != elt_heros) {
			tmp = tmp->suivant;
		}

		tmp->suivant = elt_heros->suivant;
		free(elt_heros);
	}

	liste->nb_heros--;
}

/**
 * @brief Fonction permettant de supprimer une question de la liste des questions
 * @param liste Liste des questions
 * @param elt_question Question à supprimer de la liste
**/
void supprimerQuestionListe(Liste_Questions *liste, Elt_Question *elt_question) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerQuestionListe() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si l'élément est NULL
	if (elt_question == NULL) {
		printf("supprimerQuestionListe() : L'élément à supprimer est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		printf("supprimerQuestionListe() : La liste des questions est vide !\n");
		return;
	}

	// Si la liste contient un seul élément
	if (liste->premier->suivant == NULL) {
		free(liste->premier);
		liste->premier = NULL;
	}

	else {
		Elt_Question *tmp = liste->premier;

		while (tmp->suivant != elt_question) {
			tmp = tmp->suivant;
		}

		tmp->suivant = elt_question->suivant;
		free(elt_question);
	}

	liste->nb_questions--;
}

/**
 * @brief Fonction permettant de vider la liste des héros
 * @param liste Liste à vider
**/
void viderListeHeros(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("viderListeHeros() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		printf("viderListeHeros() : La liste des héros est vide !\n");
		return;
	}

	// Si la liste contient un seul élément
	if (liste->premier->suivant == NULL) {
		free(liste->premier);
		liste->premier = NULL;
	}

	else {
		Elt_Heros *tmp = liste->premier;

		while (tmp->suivant != NULL) {
			Elt_Heros *tmp2 = tmp->suivant;
			free(tmp);
			tmp = tmp2;
		}

		free(tmp);
		liste->premier = NULL;
	}

	liste->nb_heros = 0;
}

/**
 * @brief Fonction permettant de vider la liste de questions
 * @param liste Liste à vider
**/
void viderListeQuestions(Liste_Questions *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("viderListeQuestions() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Si la liste est vide
	if (liste->premier == NULL) {
		printf("viderListeQuestions() : La liste des questions est vide !\n");
		return;
	}

	// Si la liste contient un seul élément
	if (liste->premier->suivant == NULL) {
		free(liste->premier);
		liste->premier = NULL;
	}

	else {
		Elt_Question *tmp = liste->premier;

		while (tmp->suivant != NULL) {
			Elt_Question *tmp2 = tmp->suivant;
			free(tmp);
			tmp = tmp2;
		}

		free(tmp);
		liste->premier = NULL;
	}

	liste->nb_questions = 0;
}
