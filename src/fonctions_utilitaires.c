/**
 * @file fonctions_utilitaires.c
 * @brief Fonctions utiles pour ajouter un personnage et une question à la base de données
**/

#include "../include/fonctions_utilitaires.h"

/**
 * @fn convert_to_lower
 * @brief Convertit tous les caractère de la string en minuscule
 * @param string String à convertir
**/
void convert_to_lower(char string[])
{
	for (size_t i = 0; i < strlen(string); i++)
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
	size_t test = 0;

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
 * @param borne_inf Borne inférieure pour le test
 * @param borne_sup Borne supérieure pour le test
 * @return Choix correct
**/
int est_un_int_et_est_compris_entre(char string[], int choix, int borne_inf, int borne_sup)
{
	do {
		printf("%s", string);
		scanf("%d", &choix);

		if (!isdigit(choix) && (choix < borne_inf || choix > borne_sup))
		{
			printf("Choix incorrect. Veuillez recommencer.\n\n");
		}
	} while (!isdigit(choix) && (choix < borne_inf || choix > borne_sup));
	// potentiel problème avec la valeur de retour d'isdigit()
	
	return choix;
}


/**
 * @fn akinator
 * @brief Affiche le nom du programme et demande à l'utilisateur s'il veut connaitre les règles ou la genèse d'Akinator
**/
void akinator() // ne pas toucher même si c'est moche, car ça rend bien
{
	printf("___  ___                 _             _                    \n");
	printf("|  \\/  |                (_)           | |                  \n");
	printf("| .  . | __ _ _ ____   ___ _ __   __ _| |_ ___  _ __        \n");
	printf("| |\\/| |/ _` | '__\\ \\ / / | '_ \\ / _` | __/ _ \\| '__|  \n");
	printf("| |  | | (_| | |   \\ V /| | | | | (_| | || (_) | |         \n");
	printf("\\_|  |_/\\__,_|_|    \\_/ |_|_| |_|\\__,_|\\__\\___/|_|\n\n\n");

//	printf("Que voulez-vous faire ?\n");
//	printf("  1 - Jouer\n");
//	printf("  2 - Connaitre les r%cgles\n", e_grave);
//	printf("  3 - Gen%cse du projet\n", e_grave);
//	printf("  4 - Quitter\n");
//
//	int choix = 0;
//
//	switch (est_un_int_et_est_compris_entre("Votre choix :", choix, 1, 4))
//	{
//		case 1: // jeu
//		{
//			break;
//		}
//		case 2: // règles akinator
//		{
//			printf("\n\n");
//			printf("=========================  R%cgles du jeu  ========================\n", e_grave);
//			printf("= Le but du jeu est de faire deviner le nom du personnage.       =\n");
//			printf("= Marvel auquel vous pensez %c Akinator. R%cpondez aux questions   =\n", a_grave, e_aigu);
//			printf("= d'Akinator par Oui ou Non/je ne sais pas et Akinator trouvera  =\n");
//			printf("= le nom du h%cros Marvel auquel vous pensez. Vous pouvez choisir =\n", e_aigu);
//			printf("= le personnage que vous voulez.                                 =\n");
//			printf("==================================================================\n");
//			printf("\n\n");
//
//			break;
//		}
//		case 3: // histoire du projet
//		{
//			printf("\n\n");
//			printf("===================================================  Histoire du projet  ==================================================\n");
//			printf("= En 2007, Arnaud Megret, ing%cnieur en informatique, a l'id%ce de cr%cer Devinettor, projet pas tr%cs ambitieux, pour        =\n", e_aigu, e_aigu, e_aigu, e_grave);
//			printf("= s'amuser, o%c une intelligence artificielle pose 20 questions %c un joueur pour deviner %c quel personnage il pense.       =\n", u_grave, a_grave, a_grave);
//			printf("= L'ing%cnieur remplit au d%cpart la base de donn%ces avec 100 personnages et 100 questions, mais la force du jeu est de     =\n", e_aigu, e_aigu, e_aigu);
//			printf("= s'enrichir au fil des parties : quand le jeu est battu par le joueur parce qu'il n'a pas su deviner le personnage,      =\n");
//			printf("= Devinettor enregistre les informations de la partie. Ainsi, la base de donn%ces se diversifie au fil des parties et les  =\n", e_aigu);
//			printf("= personnages pr%cc%cdemment jou%cs sont de plus en plus facilement devin%cs par l'intelligence artificielle.                 =\n", e_aigu, e_aigu, e_aigu, e_aigu);
//			printf("=                                                                                                                         =\n");
//			printf("= Arnaud Megret partage le jeu %c ses connaissances et peu apr%cs, Devinettor commence %c circuler sur les forums en         =\n", a_grave, e_grave, a_grave);
//			printf("= ligne et atteint une relative popularit%c rapidement et le jeu est renomm%c en Akinator.                                  =\n", e_aigu, e_aigu);
//			printf("===========================================================================================================================\n");
//			printf("\n\n");
//
//			break;
//		}
//		case 4:
//		{
//			exit(EXIT_SUCCESS);
//			break;
//		}
//		default:
//			break;
//	}
}
