#include "../include/fonctions_utilitaires.h"
#include "../include/structs_donnees.h"
#include "../include/gestion_listes.h"
#include "../include/gestion_fichiers.h"
#include "../include/jeu.h"
#include "../include/gestion_BDD.h"


int main(/*int argc, char const *argv[]*/)
{
	akinator();

	bool heros_trouve = false;
	bool rejouer = true;
	Elt_Heros heros_actuel;
	Heros heros_temporaire;
	int choix_int = 0;

	// Création des listes de héros et de questions
	Liste_Heros* liste_heros = NULL;
	Liste_Questions* liste_questions = NULL;

	do // Boucle testant tous les héros pour chaque question
	{
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
		Question *question_actuelle = choisirQuestionAleatoire(liste_questions);

		if (strcmp(question_actuelle->question, "Est-ce que le personnage a plus de") == 1)
		{
			// Afficher la question
			printf("%s %d ans ?\n", question_actuelle->question, calculAgeMoyenHeros(liste_heros));
			printf("  1 - Oui\n");
			printf("  2 - Non - Je ne sais pas\n");

			// Supprimer les hérosqui ont un age supérieur à la moyenne
			supprimerHerosSelonAge(liste_heros);
		}

		else
		{
			// Afficher la question
			printf("%s", question_actuelle->question);
			printf("  1 - Oui\n");
			printf("  2 - Non - Je ne sais pas\n");

			// Comparer le choix de l'utilisateur avec la réponse attendue à la question en fonction de l'attribut de la question
			// C'est un homme
			if (strcmp(question_actuelle->question, "Est-ce un homme ?") == 0
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des hommes
				supprimerHerosSelonSexe(liste_heros, HOMME);
				heros_temporaire.sexe = HOMME;
			}

			// C'est une femme
			else if (strcmp(question_actuelle->question, "Est-ce un femme ?") == 0
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des femmes
				supprimerHerosSelonSexe(liste_heros, FEMME);
				heros_temporaire.sexe = FEMME;
			}

			// C'est autre chose (ni un homme, ni un femme)
			else if (strcmp(question_actuelle->question, "Est-ce autre chose ?") == 0
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des hommes ou des femmes
				supprimerHerosSelonSexe(liste_heros, AUTRE);
				heros_temporaire.sexe = AUTRE;
			}

			// C'est un humain
			else if (strcmp(question_actuelle->question, "Est-ce un humain ?") == 0
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des humains
				supprimerHerosSelonEspece(liste_heros, HUMAIN);
				heros_temporaire.espece = HUMAIN;

			}

			// C'est un extraterrestre
			else if (strcmp(question_actuelle->question, "Est-ce un mutant ?") == 1
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des mutants
				supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
				heros_temporaire.espece = MUTANT;
			}

			// C'est un humain altéré
			else if (strcmp(question_actuelle->question, "Est-ce un humain alterne ?") == 1
			&& est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui ne sont pas des mutants
				supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
				heros_temporaire.espece = HUMAIN_ALTERE;
			}

			// C'est un Etats-Uniens
			else if (strcmp(question_actuelle->question, "Est-ce que le personnage est de nationalite etats-unienne ?")== 1 && est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
			{
				// Supprimer tous les héros qui sont de nationalité
				supprimerHerosSelonNationalite(liste_heros, "Etats-Unis");
				strcpy(heros_temporaire.nationalite, "Etats-Unis");
			}

			// Equipement
			else if (strcmp(question_actuelle->question, "Est-ce que le personnage utilise plus ses pouvoirs que ses equipements ?") == 1)
			{
				if (est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
				{
					// Supprimer tous les héros qui n'utilisent pas pluis leurs pouvoirs que leur équipement
					supprimerHerosSelonEquipement(liste_heros, false);
					heros_temporaire.equipement = false;
				}

				else
				{
					// Supprimer tous les héros qui n'utilisent pas plus leurs pouvoirs que leur équipement
					supprimerHerosSelonEquipement(liste_heros, true);
					heros_temporaire.equipement = true;
				}
			}

			// Volant
			else if (strcmp(question_actuelle->question, "Est-ce que le personnage vole ?") == 1)
			{
				if (est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
				{
					// Supprimer tous les héros qui ne volent pas
					supprimerHerosSelonVolant(liste_heros, "volant");
					heros_temporaire.volant = true;
				}

				else
				{
					// Supprimer tous les héros qui ne volent pas
					supprimerHerosSelonVolant(liste_heros, "non-volant");
					heros_temporaire.volant = false;
				}
			}

			// Taille normale
			else if (strcmp(question_actuelle->question, "Est-ce que le personnage a la taille d'un humain adulte ?")== 1)
			{
				if (est_un_int_et_est_compris_entre("Votre choix", choix_int, 1, 2) == 1)
				{
					supprimerHerosSelonTaille(liste_heros, "taille-normale");
					heros_temporaire.taille = true;
				}

				else
				{
					supprimerHerosSelonTaille(liste_heros, "taille-anormale");
					heros_temporaire.taille = false;
				}
			}
		}

		// Ajouter un personnage à la base de données
		printf("Voulez-vous ajouter un personnage à la base de donn%ces ?\n", e_aigu);
		printf("  1 - Oui\n");
		printf("  2 - Non\n");

		if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2) == 1)
		{
			ajouter_personnage_BDD(heros_temporaire);
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

		// Vidage des listes
		viderListeHeros(liste_heros);
		viderListeQuestions(liste_questions);

		heros_actuel = *heros_actuel.suivant;
	} while (rejouer && (heros_trouve == false || heros_actuel.suivant == NULL));

	return EXIT_SUCCESS;
}
