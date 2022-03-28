#include "../include/structs-functions.h"


// Déclarer les fonctions après ce commentaire

/**
 * @fn convert_to_lower
 * @brief Convertit tous les caractère de la string en minuscule
 * @param string String à convertir
 * @return
 */

void convert_to_lower(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		string[i] = tolower(string[i]);
	}
}

/**
 * @fn est_une_string
 * @brief Teste si la string en paramètre est seulement composée de lettres
 * @param string String à tester
 * @return 1 si le test est valide
 * @return 0 si le test n'est pas valide
 */

int est_une_string(char string[])
{
	int test = 0;

	for (int i = 0; i < 256; i++)
	{
		if (isalpha(string[i]) == 0 && isblank(string[i]) == 0)
		{
			test++;
		}
	}

	if (test == strlen(string))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/**
 * @fn est_un_int_et_est_compris_entre
 * @brief Vérifie si le int passé en paramètre est bien un int et s'il est bien compris entre nombre_1 et nombre_2
 * @param string Chaine qui sera répétée si le choix n'est pas bon
 * @param choix Nombre à tester
 * @param nombre_1 Borne inférieure pour le test
 * @param nombre_2 Borne supérieure pour le test
 * @return Choix correcte
 */

__attribute__((unused)) int est_un_int_et_est_compris_entre(char string[], int choix, int nombre_1, int nombre_2)
{
	do {
		printf("%s", string);
		scanf("%d", &choix);

		if (!isdigit(choix))
		{
			printf("\nChoix incorrect. Veillez recommencer.\n");
		}
	} while (!isdigit(choix) && (choix < nombre_1 || choix > nombre_2));
	// potentiel problème avec la valeur de retour de isdigit()
	
	return choix;
}

/**
 * @fn ajouter_question_BDD
 * @brief Ajoute une ou plusieurs questions à la base de données questions
 * @return Rien
 */

__attribute__((unused)) void ajouter_question_BDD()
{
	FILE* fichier_questions = NULL;

	// string à rentrer dans la BDD
	int taille = 1;
	char* string = (char*) malloc(taille * sizeof(char));

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
		printf("\nProblème d'ouverture de la base de données Questions\n");
	}

	fclose(fichier_questions);

	if (fclose(fichier_questions) != 0)
	{
		printf("\nProblème d'ouverture de la base de données Questions\n");
	}
}

/**
 * @fn ajouter_personnage_questions_BDD
 * @brief Ajoute un personnage à la base de données personnages
 */
	
__attribute__((unused)) void ajouter_personnage_BDD()
{
	FILE* fichier_personnages = NULL;

	// string à rentrer dans la BDD
	int taille = 1;
	char* string = (char*)malloc(taille * sizeof(char));

	int choix_int = 1;
	char choix_string[256] = "";

	if (string != NULL) // ajouter les caractéristiques d'un personnage à la string
	{
		printf("Quel est le nom du héros ?\n");
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

		printf("Quel est le sexe du héros ?\n");
		printf("  1 - Homme\n");
		printf("  2 - Femme\n");
		printf("  3 - Autre\n");

		printf("Son sexe : ");

		switch (est_un_int_et_est_compris_entre("", choix_int, 0, 4))
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
					printf("Son sexe personnalisé : ");
					scanf("%s", choix_string);
					printf("\n");

				} while (est_une_string(string) != 1);

				convert_to_lower(choix_string);

				strcat(choix_string, ",");
				strcat(string, choix_string);
				break;
			}
		}

		printf("Quel est le nationalité du héros ?\n");
		printf("  1 - Etats-Unis\n");
		printf("  2 - Russie\n");
		printf("  3 - France\n");
		printf("  4 - Autre\n");

		switch (est_un_int_et_est_compris_entre("Sa nationalité : ", choix_int, 0, 4))
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
					printf("Son sexe personnalisé : ");
					scanf("%s", choix_string);
					printf("\n");

					for (int i = 0; i < strlen(choix_string); i++)
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

		printf("Quel est l'age du héros ?\n");
		do {
			printf("Son age : ");
			scanf("%d", &choix_int);

			if (!isdigit(choix_int))
			{
				printf("\nChoix incorrect. Veillez recommencer.\n");
			}
		} while (!isdigit(choix_int) && (choix_int < 0 || choix_int > 2000));

		printf("Votre héros utilise-t-il plus ses pouvoirs ou son équipement du héros ?\n");
		printf("  1 - Pouvoirs\n");
		printf("  2 - Equipement\n");

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
		
		printf("Quelle est l'espèce du héros ?\n");
		printf("  1 - Humain\n");
		printf("  2 - Humain altéré\n");
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
					printf("Son espèce : ");
					scanf("%s", choix_string);
					printf("\n");
				} while (est_une_string(choix_string) != 1);

				convert_to_lower(choix_string);

				strcat(choix_string, ",");
				strcat(string, choix_string);
				break;
			}
		}

		printf("Est-ce que le héros vole-t-il ?\n");
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

		printf("Est-ce que le héros porte-t-il un masque ?\n");
		printf("  1 - Oui\n");
		printf("  2 - Non\n");

		if (choix_int == est_un_int_et_est_compris_entre("Votre choix : ", choix_int, 1, 2))
		{
			strcpy(choix_string, "masque,");
			strcat(string, choix_string);
		}

		else
		{
			strcpy(choix_string, "non-masque,");
			strcat(string, choix_string);
		}

		printf("Est-ce que le héros a-t-il une taille d'être humain normal ?\n");
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

		printf("Quelle est la.les couleur.s caractéristique.s du héros ?\n");
		printf("Sa.es couleur.s caractéristique.s : ");
		
		do {
			printf("Sa.es couleur.s caractéristique.s : ");
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

	else
	{
		printf("\nProblème dans la création de la string  \n");
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
		printf("\nProblème d'ouverture de la base de données Personnages\n");
	}

	fclose(fichier_personnages);

	if (fclose(fichier_personnages) != 0)
	{
		printf("\nProblème d'ouverture de la base de données Personnages\n");
	}
}

/**
 * @fn akinator
 * @brief Affiche le nom du programme
 */

void akinator() // ne pas toucher même si c'est moche car ça rend bien
{
	printf("  .--.  .-. .-..-..-. .-.  .--.  .---.  .----. .----.    \n");
	printf(" / {} \\ | |/ / | ||  `| | / {} \\{_   _}/  {}  \\| {}  }\n");
	printf("/  /\\  \\| |\\ \\ | || |\\  |/  /\\  \\ | |  \\      /| .-. \\\n");
	printf("`-'  `-'`-' `-'`-'`-' `-'`-'  `-' `-'   `----' `-' `-'       \n\n");

	printf(".-.   .-.  .--.  .----. .-. .-..-..-. .-.  .--.  .---.  .----. .----.    \n");
	printf("|  `.'  | / {} \\ | {}  }| | | || ||  `| | / {} \\{_   _}/  {}  \\| {}  }\n");
	printf("| |\\ /| |/  /\\  \\| .-. \\\\ \\_/ /| || |\\  |/  /\\  \\ | |  \\      /| .-. \\\n");
	printf("`-' ` `-'`-'  `-'`-' `-' `---' `-'`-' `-'`-'  `-' `-'   `----' `-' `-' \n\n");

	printf("___  ___                 _             _                  \n");
	printf("|  \\/  |                (_)           | |                \n");
	printf("| .  . | __ _ _ ____   ___ _ __   __ _| |_ ___  _ __      \n");
	printf("| |\\/| |/ _` | '__\\ \\ / / | '_ \\ / _` | __/ _ \\| '__|\n");
	printf("| |  | | (_| | |   \\ V /| | | | | (_| | || (_) | |       \n");
	printf("\\_|  |_/\\__,_|_|    \\_/ |_|_| |_|\\__,_|\\__\\___/|_|\n\n");
}