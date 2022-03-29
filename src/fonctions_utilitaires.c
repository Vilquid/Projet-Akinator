/**
 * @file structs_functions.c
 * @brief 
**/

#include "../include/fonctions_utilitaires.h"

/**
 * @fn convert_to_lower
 * @brief Convertit tous les caractère de la string en minuscule
 * @param string String à convertir
 * @return
**/
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
**/
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
 * @return Choix correct
**/
int est_un_int_et_est_compris_entre(char string[], int choix, int nombre_1, int nombre_2)
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
 * @fn akinator
 * @brief Affiche le nom du programme
**/
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
