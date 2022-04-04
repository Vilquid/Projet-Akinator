/**
 * @file jeu.c
 * @brief Fichier contenant toutes les fonctions liées au jeu
**/

#include "../include/jeu.h"

/**
 * @brief Fonction permettant de calculer l'âge moyen des héros suspects restants
 * @param liste_heros Liste des héros
 * @return int – L'âge moyen des héros suspects restants 
**/
int calculAgeMoyenHerosSuspects(Liste_Heros *liste_heros) {

	float age_moyen = 0;
	int nb_heros = 0;

	Elt_Heros *elt_actuel = liste_heros->premier;

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
 * @param liste_heros Liste des héros
**/
void supprimerHerosSuspectsSelonAge(Liste_Heros *liste_heros) {

	Elt_Heros *elt_actuel = liste_heros->premier;
	int age_moyen = calculAgeMoyenHerosSuspects(liste_heros);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age > age_moyen) {
			elt_actuel->suspect = false;
		}

		elt_actuel = elt_actuel->suivant;
	}
}
