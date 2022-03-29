#include "../include/fonctions_utilitaires.h"
#include "../include/structs_donnees.h"
#include "../include/gestion_listes.h"


int main(int argc, char const *argv[])
{
	akinator();

	bool heros_trouve = false;
	char* question; // variable à suppr car elle sera remplacée par une fonction
	Elt_Hero heros_actuel;

	// Création des listes de héros et de questions
	File_Heros* liste_heros = creerListeHeros();
	File_Questions* liste_questions = creerListeQuestions();

	if (liste_heros != NULL && liste_questions != NULL && liste_heros->premier != NULL)
	{
		for (heros_actuel.hero = liste_heros->premier->hero; !heros_trouve || heros_actuel.suivant == NULL;
		heros_actuel = *heros_actuel.suivant)
		{
			heros_trouve = !heros_trouve;

			// Choisir une question
			printf("%s", question);

			// Choisir un personnage

			// Récupérer la question et la stocker

			// Interpréter

				// Parcourir la liste Liste_Heros

				// Vérifications des attributs

				// Eliminations de certains héros

				// Vérifications des héros qui restent
		}
	}

	if (liste_heros == NULL)
	{
		printf("\nProblème détecté avec la liste des héros.\n");
	}

	if (liste_questions == NULL)
	{
		printf("\nProblème détecté avec la liste des questions.\n");
	}

	if (liste_heros->premier == NULL)
	{
		printf("\nProblème détecté avec le premier héro de la liste des héros.\n");
	}

	return EXIT_SUCCESS;
}
