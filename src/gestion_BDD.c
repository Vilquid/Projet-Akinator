/**
 * @file gestion_BDD.C
 * @brief Fichier contenant toutes les fonctions pour ajouter un personnage et une question aux bases de données
 */

#include "../include/gestion_BDD.h"


/**
 * @fn ajouter_question_BDD
 * @brief Ajoute une ou plusieurs questions à la base de données questions
**/
void ajouter_question_BDD()
{
	FILE* fichier_questions = NULL;

	// string à rentrer dans la BDD
	char* string = (char*) malloc(1 * sizeof(char));

	// création de la.les question.s à rentrer dans la base de données Questions
	if (string != NULL) // ajouter les caractéristiques d'un personnage à la string
	{
		printf("Saisissez la question que vous voulez ajouter.\n");

		printf("Son nom : ");
		scanf("%s", string);
		printf("\n");
	}

	// rentrer la question dans la BDD
	fichier_questions = fopen("questions.txt", "r+");

	if (fichier_questions != NULL)
	{
		fseek(fichier_questions, 0, SEEK_END);
		fputs(string, fichier_questions);
	}

	else
	{
		printf("\nProbl%cme d'ouverture de la base de donn%ces Questions\n", e_grave, e_aigu);
	}

	fclose(fichier_questions);

	if (fclose(fichier_questions) != 0)
	{
		printf("\nProbl%cme d'ouverture de la base de donn%ces Questions\n", e_grave, e_aigu);
	}
}

/**
 * @fn ajouter_personnage_questions_BDD
 * @brief Ajoute un personnage à la base de données personnages
**/
void ajouter_personnage_BDD(Heros heros)
{
	FILE* fichier_personnages = NULL;

	// string à rentrer dans la BDD
	char string[256];
	memset(string, '\0', 256 * sizeof(char));

	int choix_int = 1;
	char choix_string[256] = "";

	if (string != NULL) // ajouter les caractéristiques d'un personnage à la string
	{
		printf("De quelle manière vous voulez ajouter un personnage à la base de donn%ces ?\n", e_aigu);
		printf("  1 - De mani%cre automatique ?\n", e_grave);
		printf("  2 - De mani%cre manuelle ?\n", e_grave);

		if (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 0, 3) == 1)
		{
			strcat(string, heros.nom);
			strcat(string, ",");

			switch (heros.sexe)
			{
				case HOMME:
					strcat(string, "homme,");
					break;
				case FEMME:
					strcat(string, "femme,");
					break;
				case AUTRE:
					strcat(string, "autre,");
					break;
				default:
					strcat(string, "autre,");
					break;
			}

			printf("Quel est le nationalit%c du h%cros ?\n", e_aigu, e_aigu);
			printf("  1 - Etats-Unis\n");
			printf("  2 - Russie\n");
			printf("  3 - France\n");
			printf("  4 - Autre\n");

			switch (est_un_int_et_est_compris_entre("Sa nationalite : ", choix_int, 0, 4))
			{
				case 1:
				{
					strcpy(choix_string, "Etats-Unis,");
					strcat(string, choix_string);
					break;
				}
				case 2:
				{
					strcpy(choix_string, "Russie,");
					strcat(string, choix_string);
					break;
				}
				default:
				{
					do {
						printf("Son sexe personnalis%c : ", e_aigu);
						scanf("%s", choix_string);
						printf("\n");

						for (size_t i = 0; i < strlen(choix_string); i++)
						{
							if (isalpha(choix_string[i]) == 0 && isblank(choix_string[i]) == 0)
							{
								printf("\nSaisie incorrecte. Veillez recommencer.\n");
							}
						}
					} while (est_une_string(string) != 1);

					convert_to_lower(choix_string);
					strcat(string, choix_string);
					strcat(string, ",");

					break;
				}
			}

			printf("Quel est l'age du h%cros ?\n", e_aigu);
			do {
				printf("Son %cge : ", a_circonflexe);
				scanf("%d", &choix_int);

				if (!isdigit(choix_int))
				{
					printf("\nChoix incorrect. Veillez recommencer.\n");
				}
			} while (!isdigit(choix_int) && (choix_int < 0 || choix_int > 2000));

			sprintf(choix_string, "%d", choix_int);
			strcat(string, choix_string);
			strcat(string, ",");

			if (heros.equipement)
			{
				strcat(string, "equipement,");
			}

			else
			{
				strcat(string, "pouvoirs,");
			}

			switch (heros.espece)
			{
				case HUMAIN:
				{
					strcat(string, "humain,");
					break;
				}
				case HUMAIN_ALTERE:
				{
					strcat(string, "humain-altere,");
					break;
				}
				case MUTANT:
				{
					strcat(string, "mutant,");
					break;
				}
				default:
				{
					strcat(string, "extraterrestre,");
					break;
				}
			}

			if (heros.volant)
			{
				strcat(string, "volant,");
			}

			else
			{
				strcat(string, "non-volant,");
			}

			if (heros.masque)
			{
				strcat(string, "masque,");
			}

			else
			{
				strcat(string, "non-masque,");
			}

			if (heros.taille)
			{
				strcat(string, "taille-normale,");
			}

			else
			{
				strcat(string, "taille-anormale,");
			}

			printf("Quelle est la.les couleur.s caract%cristique.s du h%cros ?\n", e_aigu, e_aigu);

			do {
				printf("Sa.es couleur.s caract%cristique.s : ", e_aigu);
				scanf("%s", choix_string);
				printf("\n");

				if (est_une_string(choix_string) != 1)
				{
					printf("\nSaisie incorrecte. Veillez recommencer.\n");
				}
			} while (est_une_string(choix_string) != 1);

			strcat(string, choix_string);
			strcpy(string, ",");
		}

		else
		{
			printf("Quel est le nom du h%cros ?\n", e_aigu);
			do {
				printf("Son nom : ");
				scanf("%s", choix_string);
				printf("\n");

				if (est_une_string(choix_string) != 1)
				{
					printf("\nSaisie incorrecte. Veillez recommencer.\n");
				}
			} while (est_une_string(choix_string) != 1);

			convert_to_lower(choix_string);

			strcat(choix_string, ",");
			strcat(string, choix_string);

			printf("Quel est le sexe du h%cros ?\n", e_aigu);
			printf("  1 - Homme\n");
			printf("  2 - Femme\n");
			printf("  3 - Autre\n");

			switch (est_un_int_et_est_compris_entre("Son sexe : ", choix_int, 0, 4))
			{
				case 1:
				{
					strcpy(choix_string, "homme,");
					strcat(string, choix_string);
					break;
				}
				case 2:
				{
					strcpy(choix_string, "femme,");
					strcat(string, choix_string);
					break;
				}
				default:
				{
					do {
						printf("Son sexe personnalis%c : ", e_aigu);
						scanf("%s", choix_string);
						printf("\n");

					} while (est_une_string(string) != 1);

					convert_to_lower(choix_string);

					strcat(choix_string, ",");
					strcat(string, choix_string);
					break;
				}
			}

			printf("Quel est le nationalit%c du h%cros ?\n", e_aigu, e_aigu);
			printf("  1 - Etats-Unis\n");
			printf("  2 - Russie\n");
			printf("  3 - France\n");
			printf("  4 - Autre\n");

			switch (est_un_int_et_est_compris_entre("Sa nationalit%c : ", choix_int, 0, 4))
			{
				case 1:
				{
					strcpy(choix_string, "Etats-Unis,");
					strcat(string, choix_string);
					break;
				}
				case 2:
				{
					strcpy(choix_string, "Russie,");
					strcat(string, choix_string);
					break;
				}
				default:
				{
					do {
						printf("Son sexe personnalis%c : ", e_aigu);
						scanf("%s", choix_string);
						printf("\n");

						for (size_t i = 0; i < strlen(choix_string); i++)
						{
							if (isalpha(choix_string[i]) == 0 && isblank(choix_string[i]) == 0)
							{
								printf("\nSaisie incorrecte. Veillez recommencer.\n");
							}
						}
					} while (est_une_string(string) != 1);

					convert_to_lower(choix_string);

					strcat(choix_string, ",");
					strcat(string, choix_string);
					break;
				}
			}

			printf("Quel est l'age du h%cros ?\n", e_aigu);
			do {
				printf("Son %cge : ", a_circonflexe);
				scanf("%d", &choix_int);

				if (!isdigit(choix_int))
				{
					printf("\nChoix incorrect. Veillez recommencer.\n");
				}
			} while (!isdigit(choix_int) && (choix_int < 0 || choix_int > 2000));

			printf("Votre h%cros utilise-t-il plus ses pouvoirs ou son %cquipement du h%cros ?\n", e_aigu, e_aigu, e_aigu);
			printf("  1 - Pouvoirs\n");
			printf("  2 - %cquipement\n", E_aigu);

			if (choix_int == est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2))
			{
				strcpy(choix_string, "pouvoirs,");
				strcat(string, choix_string);
			}

			else
			{
				strcpy(choix_string, "equipement,");
				strcat(string, choix_string);
			}

			printf("Quelle est l'esp%cce du h%cros ?\n", e_grave, e_aigu);
			printf("  1 - Humain\n");
			printf("  2 - Humain alt%cr%c\n", e_aigu, e_aigu);
			printf("  3 - Mutant\n");
			printf("  4 - Extraterrestre\n");
			printf("  5 - Autre\n");

			switch (est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 0, 5))
			{
				case 1:
				{
					strcpy(choix_string, "humain,");
					strcat(string, choix_string);
					break;
				}
				case 2:
				{
					strcpy(choix_string, "humain-altere,");
					strcat(string, choix_string);
					break;
				}
				case 3:
				{
					strcpy(choix_string, "mutant,");
					strcat(string, choix_string);
					break;
				}
				case 4:
				{
					strcat(string, "extraterrestre,");
					break;
				}
				default:
				{
					do {
						printf("Son esp%cce : ", e_grave);
						scanf("%s", choix_string);
						printf("\n");
					} while (est_une_string(choix_string) != 1);

					convert_to_lower(choix_string);

					strcat(choix_string, ",");
					strcat(string, choix_string);
					break;
				}
			}

			printf("Est-ce que le h%cros vole-t-il ?\n", e_aigu);
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (choix_int == est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2))
			{
				strcpy(choix_string, "volant,");
				strcat(string, choix_string);
			}

			else
			{
				strcpy(choix_string, "non-volant,");
				strcat(string, choix_string);
			}

			printf("Est-ce que le h%cros porte-t-il un masque ?\n", e_aigu);
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (choix_int == est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2))
			{
				strcat(string, "masque,");
			}

			else
			{
				strcat(string, "non-masque,");
			}

			printf("Est-ce que le h%cros a-t-il une taille d'%ctre humain normal ?\n", e_aigu, e_circonflexe);
			printf("  1 - Oui\n");
			printf("  2 - Non\n");

			if (choix_int == est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 0, 5))
			{
				strcpy(choix_string, "taille-normale,");
				strcat(string, choix_string);
			}

			else
			{
				strcpy(choix_string, "taille-anormale,");
				strcat(string, choix_string);
			}

			printf("Quelle est la.les couleur.s caract%cristique.s du h%cros ?\n", e_aigu, e_aigu);

			do {
				printf("Sa.es couleur.s caract%cristique.s : ", e_aigu);
				scanf("%s", choix_string);
				printf("\n");

				if (est_une_string(choix_string) != 1)
				{
					printf("\nSaisie incorrecte. Veillez recommencer.\n");
				}
			} while (est_une_string(choix_string) != 1);

			strcpy(choix_string, ",");
			strcat(string, choix_string);
		}
	}

	else
	{
		printf("\nProbl%cme dans la cr%cation de la string\n", e_grave, e_aigu);
	}

	// rentrer le personnage dans la BDD
	fichier_personnages = fopen("personnages.txt", "r+");

	if (fichier_personnages != NULL)
	{
		fseek(fichier_personnages, 0, SEEK_END);
		fputs(string, fichier_personnages);
	}

	else
	{
		printf("\nProbl%cme d'ouverture de la base de donn%ces Personnages\n", e_grave, e_aigu);
	}

	fclose(fichier_personnages);

	if (fclose(fichier_personnages) != 0)
	{
		printf("\nProbl%cme d'ouverture de la base de donn%ces Personnages\n", e_grave, e_aigu);
	}
}
