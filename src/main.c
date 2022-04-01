#include "../include/fonctions_utilitaires.h"
#include "../include/structs_donnees.h"
#include "../include/gestion_listes.h"


int main(int argc, char const *argv[])
{
	akinator();

	bool heros_trouve = false;
	bool rejouer = true;
	char* question = (char*) malloc(1 * sizeof(char)); // variable à suppr car elle sera remplacée par une fonction
	Elt_Heros heros_actuel;
	int choix_int = 0;

	// Création des listes de héros et de questions
	Liste_Heros* liste_heros = creerListeHeros();
	Liste_Questions* liste_questions = creerListeQuestions();

	do
	{
		if (liste_heros != NULL && liste_questions != NULL && liste_heros->premier != NULL)
		{
			// Boucle testant tous les héros pour chaque question
			for (heros_actuel.heros = liste_heros->premier->heros; heros_trouve == false || heros_actuel.suivant == NULL;
				 heros_actuel = *heros_actuel.suivant) // je ne suis pas du tout sûr de cette ligne
			{
				heros_trouve = !heros_trouve;

				// Choisir une question
				question;

				// Afficher la question
				printf("%s", question);

				// Choisir un personnage

				// Récupérer la question et la stocker

				// Interpréter

					// Parcourir la liste Liste_Heros

					// Vérifications des attributs

					// Eliminations de certains héros

					// Vérifications des héros qui restent
			}

			// Ajouter un personnage à la base de données
			printf("Voulez-vous ajouter un personnage à la base de donn%ces ?\n", e_aigu);
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2) == 1)
			{
				ajouter_personnage_BDD();
			}

			else
			{
				printf("Vous n'ajouterez pas de personnages.\n");
			}

			// Ajouter une question à la base de données
			printf("Voulez-vous ajouter une question à la base de donn%ces ?\n", e_aigu);
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2) == 1)
			{
				ajouter_question_BDD();
			}

			else
			{
				printf("Vous n'ajouterez pas de question.\n");
			}

			printf("Voulez-vous rejouer ?");
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2) == 2)
			{

				rejouer = false;
			}

			// Mise à jour des listes
			liste_heros = creerListeHeros();
			liste_questions = creerListeQuestions();
		}
	} while (rejouer);

	if (liste_heros == NULL)
	{
		printf("\nProbl%cme d%ctect%c avec la liste des h%cros.\n", e_grave, e_aigu, e_aigu, e_aigu);
	}

	if (liste_questions == NULL)
	{
		printf("\nProbl%cme d%ctect%c avec la liste des questions.\n", e_grave, e_aigu, e_aigu);
	}

	if (liste_heros->premier == NULL)
	{
		printf("\nProbl%cme d%ctect%c avec le premier h%cro de la liste des h%cros.\n", e_grave, e_aigu, e_aigu, e_aigu);
	}

	return EXIT_SUCCESS;
}