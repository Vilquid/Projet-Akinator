/**
 * @file jeu.c
 * @brief Fichier contenant toutes les fonctions liées au jeu
**/

#include "../include/jeu.h"

/**
 * @brief Fonction permettant de choisir une question aléatoire parmis la liste de questions (FONCTION TEMPORAIRE)
 * @param liste Liste des questions
 * @return Question* – Pointeur vers la question tirée au sort
**/
Question *choisirQuestionAleatoire(Liste_Questions *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("choisirQuestionAleatoire() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// Initialiser l'aléatoire
	srand(time(NULL));

	int nb_aleatoire = rand() % liste->nb_questions;

	Elt_Question *elt_actuel = liste->premier;

	for (int i = 0; i < nb_aleatoire; i++) {
		elt_actuel = elt_actuel->suivant;
	}

	return elt_actuel->question;
}

/**
 * @brief Fonction permettant de choisir un suspect dans la liste des héros, s'il reste 2 héros ou moins dans la liste 
 * @param liste Liste des héros
 * @return Heros* – Pointeur vers le suspect identifié (tiré au sort si 2 restants) ou NULL s'il y a plus de 2 héros restants dans la liste
**/
Heros *choisirSuspect(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("choisirSuspect() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// S'il reste 2 héros dans la liste
	if (liste->nb_heros == 2) {

		// Initialiser l'aléatoire
		srand(time(NULL));

		// Choisir un héros au hasard
		int nb_aleatoire = rand() % 2;

		Elt_Heros *elt_actuel = liste->premier;

		for (int i = 0; i < nb_aleatoire; i++) {
			elt_actuel = elt_actuel->suivant;
		}

		return elt_actuel->heros;
	}

	// S'il reste 1 héros dans la liste
	else if (liste->nb_heros == 1) {

		Elt_Heros *elt_actuel = liste->premier;

		return elt_actuel->heros;
	}

	return NULL;
}

/**
 * @brief Fonction permettant d'afficher les informations d'un héros
 * @param heros Héros à afficher
**/
void afficherHeros(Heros *heros) {

	if (heros != NULL) {
		// Afficher les attributs
		printf("Nom : %s\n", heros->nom);
		printf("Age : %d ans\n", heros->age);
		printf("Sexe : %s\n", heros->sexe);
		printf("Nationalité : %s\n", heros->nationalite);
		printf("Espece : %s\n", heros->espece);
		printf("Equipement : %s\n", heros->equipement ? "Oui" : "Non");
		printf("Volant : %s\n", heros->volant ? "Oui" : "Non");
		printf("Masque : %s\n", heros->masque ? "Oui" : "Non");
		printf("Taille Humaine : %s\n", heros->taille ? "Oui" : "Non");
		printf("Couleur associee : %s\n", heros->couleur);
		printf("\n");
	}
}

/**
 * @brief Fonction permettant de calculer l'âge moyen des héros suspects restants
 * @param liste Liste des héros
 * @return int – L'âge moyen des héros suspects restants 
**/
int calculAgeMoyenHeros(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("calculAgeMoyenHeros() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	float age_moyen = 0;

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		age_moyen += elt_actuel->heros->age;
		elt_actuel = elt_actuel->suivant;
	}

	return (int)(age_moyen / liste->nb_heros);
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ont un âge supérieur à la moyenne des héros suspects restants
 * @param liste Liste des héros
**/
void supprimerHerosSelonAge(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonAge() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;
	int age_moyen = calculAgeMoyenHeros(liste);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age > age_moyen) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas du sexe précisé
 * @param liste Liste des héros
 * @param sexe Sexe précisé par l'utilisateur
**/
void supprimerHerosSelonSexe(Liste_Heros *liste, Sexe sexe) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonSexe() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->sexe != sexe) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de la nationalité précisée
 * @param liste Liste des héros
 * @param nationalite Nationalité précisée par l'utilisateur
**/
void supprimerHerosSelonNationalite(Liste_Heros *liste, char nationalite[25]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonNationalite() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->nationalite, nationalite) != 0) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de l'espèce précisée
 * @param liste Liste des héros
 * @param espece Espèce précisée par l'utilisateur
**/
void supprimerHerosSelonEspece(Liste_Heros *liste, Espece espece) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonEspece() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->espece != espece) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut équipement précisé
 * @param liste Liste des héros
 * @param equipement Attribut équipement précisé par l'utilisateur
**/
void supprimerHerosSelonEquipement(Liste_Heros *liste, bool equipement) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonEquipement() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->equipement != equipement) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut volant précisé
 * @param liste Liste des héros
 * @param volant Attribut volant précisé par l'utilisateur
**/
void supprimerHerosSelonVolant(Liste_Heros *liste, bool volant) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonVolant() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->volant != volant) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut masque précisé
 * @param liste Liste des héros
 * @param masque Attribut masque précisé par l'utilisateur
**/
void supprimerHerosSelonMasque(Liste_Heros *liste, bool masque) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonMasque() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->masque != masque) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut taille précisé
 * @param liste Liste des héros
 * @param taille Attribut taille précisé par l'utilisateur
**/
void supprimerHerosSelonTaille(Liste_Heros *liste, bool taille) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonTaille() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->taille != taille) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de la couleur précisée
 * @param liste Liste des héros
 * @param couleur Attribut couleur précisé par l'utilisateur
**/
void supprimerHerosSelonCouleur(Liste_Heros *liste, char couleur[25]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonCouleur() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->couleur, couleur) != 0) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}
