#include "../include/fonctions_utilitaires.h"
#include "../include/structs_donnees.h"
#include "../include/gestion_listes.h"
#include "../include/gestion_fichiers.h"
#include "../include/jeu.h"


int main(/*int argc, char const *argv[]*/)
{
	akinator();

	bool heros_trouve = false;
	bool rejouer = true;
	char* question = (char*) malloc(1 * sizeof(char)); // variable à suppr car elle sera remplacée par une fonction
	Elt_Heros heros_actuel;
	Heros heros_recherche;
	int choix_int = 0;
	char* string_age;

	// Création des listes de héros et de questions
	Liste_Heros* liste_heros = NULL;
	Liste_Questions* liste_questions = NULL;

	do // Boucle testant tous les héros pour chaque question
	{
		// Vider les listes ici

		// Mise à jour des listes
		liste_heros = chargerFichierPersonnages();
		liste_questions = chargerFichierQuestions();

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
			printf("\nProbl%cme d%ctect%c avec le premier h%cro de la liste des h%cros.\n", e_grave, e_aigu, e_aigu, e_aigu, e_aigu);
		}

		heros_actuel.heros = liste_heros->premier->heros;

		// Appel fonction pour choisir une question
		Question question_actuelle = (Question) NULL;
//		Question *question_actuelle = choisirQuestionAleatoire(liste_questions);

		if (strcmp(question_actuelle.question, "Est-ce que le personnage a plus de") == 1)
		{
			itoa(calculAgeMoyenHerosSuspects(liste_heros), string_age, 4);

			strcat(question_actuelle.question, " ");
			strcat(question_actuelle.question, string_age);
			strcat(question_actuelle.question, " ans ?\n");

			// Afficher la question
			printf("%s", question_actuelle.question);
			printf("  1 - Oui\n");
			printf("  2 - Non - Je ne sais pas\n");

			// Supprimer les hérosqui ont un age supérieur à la moyenne
			supprimerHerosSuspectsSelonAge(liste_heros);
		}

		else
		{
			// Afficher la question
			printf("%s", question_actuelle.question);
			printf("  1 - Oui\n");
			printf("  2 - Non - Je ne sais pas\n");

			// Comparer le choix de l'utilisateur avec la réponse attendue à la question en fonction de l'attribut de la question
			// C'est un homme
			if (strcmp(question_actuelle.question, "Est-ce un homme ?") == 0
				&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des hommes
			}

			// C'est une femme
			else if (strcmp(question_actuelle.question, "Est-ce un femme ?") == 0
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est autre chose (ni un homme, ni un femme)
			else if (strcmp(question_actuelle.question, "Est-ce autre chose ?") == 0
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est un humain
			else if (strcmp(question_actuelle.question, "Est-ce un humain ?") == 0
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un mutant ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est un humain altéré
			else if (strcmp(question_actuelle.question, "Est-ce un humain alterne ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est un Etats-Uniens
			else if (strcmp(question_actuelle.question, "Est-ce que le personnage est de nationalite etats-unienne ?")== 1 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// Le personnage utilise plus ses pouvoirs que ses equipements
			else if (strcmp(question_actuelle.question, "Est-ce que le personnage utilise plus ses pouvoirs que ses equipements ?") == 1
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// Le personnage utilise moins ses pouvoirs que ses equipements
			else if (strcmp(question_actuelle.question, "Est-ce que le personnage utilise plus ses pouvoirs que ses equipements ?") == 1
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 2)
			{

			}

			// Le personnage vole
			else if (strcmp(question_actuelle.question, "Est-ce que le personnage vole ?") == 1
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

			// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}

				// C'est un extraterrestre
			else if (strcmp(question_actuelle.question, "Est-ce un extraterrestre ?") == 1
					 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1) {

			}
		}

		// Eliminer les héros qui ne possèdent pas cet attribut
//		eliminerHeros(liste_heros, question_actuelle.attribut);
		// help

		if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2) == 1) // Oui
		{

		}
		else // Non - Je ne sais pas
		{}
		// Récupérer la question et la stocker

		// Interpréter

			// Parcourir la liste Liste_Heros

			// Vérifications des attributs

			// Eliminations de certains héros

			// Vérifications des héros qui restent


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

		heros_actuel = *heros_actuel.suivant;heros_trouve = !heros_trouve;
	} while (rejouer && (heros_trouve == false || heros_actuel.suivant == NULL));

	return EXIT_SUCCESS;
}
