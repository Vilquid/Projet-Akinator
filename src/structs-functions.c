#include "../include/structs-functions.h"


// Déclarer les fonctions après ce commentaire
/**
 * @fn creerHero
 * @brief intialize un hero avec les paramettre de la BDD.txt
 * @param age,color,equipement,humain,masque,taille,volant,nationality,sexe
 * @return
 */

File_Heros *creerHero(int sexe, char nationality[25], int age,bool equipement,int humain, bool volant, bool masque, bool taille, char color[15]) {

    // Création de la file
    Hero *hero = malloc(sizeof(Hero));

    // Si l'allocation dynamique a échouée
    if (hero == NULL) {
        printf("Erreur d'allocation memoire !\n");
        exit(EXIT_FAILURE);
    }

    // Initialiser les attributs (A CHANGER)
    hero->sexe = sexe;
    hero->nationality[25] = nationality[25];
    hero->age = age;
    hero->equipement = equipement;
    hero->humain = humain;
    hero->volant = volant;
    hero->masque = masque;
    hero->taille = taille;
    hero->color[15] = color[15];

    return hero;
}


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
 * @fn ajouter_personnage_questions_BDD
 * @brief Ajoute un personnage et une ou plusieurs questions aux bases de données
 * @param hero_de_test Structure qui est modifiée par les réponses de l'utilisateur tout au long du programme
 * @return Rien
 */

__attribute__((unused)) void ajouter_personnage_questions_BDD()
{
	FILE* fichier_personnages = NULL;
	FILE* fichier_questions = NULL;

	// string à rentrer dans la BDD
	int taille = 1;
	char* string = (char*)malloc(taille * sizeof(char));

	int choix_int = 1;
	char choix_string[256] = "";
	char caractere;

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

		do {
			printf("Son sexe : ");
			scanf("%d", &choix_int);

			if (!isdigit(choix_int))
			{
				printf("\nChoix incorrect. Veillez recommencer.\n");
			}
		} while (!isdigit(choix_int) && (choix_int < 0 || choix_int > 4));
		// potentiel problème avec la valeur de retour de isdigit()

		switch (choix_int)
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

					for (int i = 0; i < 256; i++)
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

		printf("Quel est le nationalité du héros ?\n");
		printf("  1 - Etats-Unis\n");
		printf("  2 - Russie\n");
		printf("  3 - France\n");
		printf("  4 - Autre\n");

		do {
			printf("Sa nationalité : ");
			scanf("%d", &choix_int);

			if (!isdigit(choix_int))
			{
				printf("\nChoix incorrect. Veillez recommencer.\n");
			}
		} while (!isdigit(choix_int) && (choix_int < 0 || choix_int > 4));
		// potentiel problème avec la valeur de retour de isdigit()

		switch (choix_int)
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

					for (int i = 0; i < 256; i++) {
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
		} while (!isdigit(choix_int) && (choix_int < 0 || choix_int < 2000));

		printf("Votre héros utilise-t-il plus ses pouvoirs ou son équipement du héros ?\n");
		printf("  1 - Pouvoirs\n");
		printf("  2 - Equipement\n");

		do {
			printf("Votre choix : ");
			scanf("%d", &choix_int);

			if (!isdigit(choix_int))
			{
				printf("\nChoix incorrect. Veillez recommencer.\n");
			}
		} while (!isdigit(choix_int) && (choix_int < 0 || choix_int < 2));

		printf("Quelle est l'espèce du héros ?\n");
		printf("  1 - Humain\n");
		printf("  2 - Humain altéré\n");
		printf("  3 - Mutant\n");
		printf("  4 - Extraterrestre\n");
		printf("  5 - Autre\n");
		printf("Votre choix : ");

		printf("Est-ce que le héros vole-t-il ?\n");
		printf("  1 - Oui\n");
		printf("  2 - Non\n");
		printf("Votre choix : ");

		printf("Est-ce que le héros porte-t-il un masque ?\n");
		printf("  1 - Oui\n");
		printf("  2 - Non\n");
		printf("Votre choix : ");

		printf("Est-ce que le héros a-t-il une taille d'être humain normal ?\n");
		printf("  1 - Oui\n");
		printf("  2 - Non\n");
		printf("Votre choix : ");

		printf("Quelle est la.les couleur.s caractéristique.s du héros ?\n");
		printf("Sa.es couleur.s caractéristique.s : ");
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

	// création de la.les question.s à rentrer dans la base de données Questions

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