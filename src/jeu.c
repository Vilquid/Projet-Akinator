/**
 * @file jeu.c
 * @brief Fichier contenant toutes les fonctions liées au jeu
**/

#include "../include/jeu.h"

/**
 * @brief Fonction permettant de calculer l'âge moyen des héros suspects restants
 * @param liste Liste des héros
 * @return int – L'âge moyen des héros suspects restants 
**/
int calculAgeMoyenHerosSuspects(Liste_Heros *liste) {

	float age_moyen = 0;
	int nb_heros = 0;

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->suspect == true) {
			age_moyen += elt_actuel->heros->age;
			nb_heros++;
		}

		elt_actuel = elt_actuel->suivant;
	}

	return (int)(age_moyen / nb_heros);
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ont un âge supérieur à la moyenne des héros suspects restants
 * @param liste Liste des héros
**/
void supprimerHerosSuspectsSelonAge(Liste_Heros *liste) {

	Elt_Heros *elt_actuel = liste->premier;
	int age_moyen = calculAgeMoyenHerosSuspects(liste);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age > age_moyen) {
			elt_actuel->suspect = false;
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de choisir une question aléatoire parmis la liste de questions (FONCTION TEMPORAIRE)
 * @param liste Liste des questions
 * @return Question* – Pointeur vers la question tirée au sort
**/
Question *choisirQuestionAleatoire(Liste_Questions *liste) {

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
 * @brief Fonction permettant d'afficher les informations d'un héros
 * @param heros Héros à afficher
**/
void afficherHeros(Heros *heros) {

	// Afficher les attributs
	printf("Nom : %s\n", heros->nom);
	printf("Age : %d ans\n", heros->age);
	printf("Sexe : %s\n", heros->sexe);
	printf("Nationalité : %s\n", heros->nationalite);
	printf("Equipement : %s\n", heros->equipement ? "Oui" : "Non");
	printf("Espece : %s\n", heros->espece);
	printf("Volant : %s\n", heros->volant ? "Oui" : "Non");
	printf("Masque : %s\n", heros->masque ? "Oui" : "Non");
	printf("Taille Humaine : %s\n", heros->taille ? "Oui" : "Non");
	printf("Couleur associee : %s\n", heros->couleur);
	printf("\n");
}
