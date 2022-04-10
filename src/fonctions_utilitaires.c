/**
 * @file fonctions_utilitaires.c
 * @brief Fonctions utiles pour ajouter un personnage et une question à la base de données
**/

#include "../include/fonctions_utilitaires.h"

/**
 * @brief Convertit tous les caractère de la string en minuscule
 * @param string String à convertir
**/
void stringToLower(char string[]) {

	for (size_t i = 0; i < strlen(string); i++) {
		string[i] = tolower(string[i]);
	}
}

/**
 * @brief Teste si la string en paramètre est seulement composée de lettres
 * @param string String à tester
 * @return bool
**/
bool isString(char string[]) {

	size_t test = 0;

	for (int i = 0; i < 256; i++) {
		if (isalpha(string[i]) == 0 && isblank(string[i]) == 0) {
			test++;
		}
	}

	if (test == strlen(string)) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief Fonction permettant de demander un entier dans un intervalle
 * @param texte Texte à afficher devant l'entrée utilisateur
 * @param borne_inf Borne inférieure (comprise)
 * @param borne_sup Borne supérieure (comprise)
 * @return int – Entier saisi par l'utilisateur
**/
int demanderIntIntervalle(char texte[], int borne_inf, int borne_sup) {

	int choix = 0;

	do {
		printf("%s", texte);
		scanf("%d", &choix);

		if (choix < borne_inf || choix > borne_sup) {
			printf("Choix incorrect. Veuillez recommencer.\n\n");
		}

	} while (choix < borne_inf || choix > borne_sup);

	return choix;
}

/**
 * @brief Fonction permettant de mettre en pause le programme
**/
void pauseProgramme() {

	// Vidange du buffer
	int c;
	do {
		c = getchar();
	} while(c != '\n' && c != EOF);

	// Attente de l'appui sur une touche
	puts("\nAppuyez sur une touche pour continuer...");
	getchar();
}

/**
 * @brief Fonction affichant le logo Marvinator et le menu principal du jeu
**/
void akinator() {

	// Nettoyage de l'écran
	#ifdef _WIN32
		system("cls");
	#endif
	#ifdef __linux__
		system("clear");
	#endif

	// Affichage du logo
	printf("___  ___                 _             _                    \n");
	printf("|  \\/  |                (_)           | |                  \n");
	printf("| .  . | __ _ _ ____   ___ _ __   __ _| |_ ___  _ __        \n");
	printf("| |\\/| |/ _` | '__\\ \\ / / | '_ \\ / _` | __/ _ \\| '__|  \n");
	printf("| |  | | (_| | |   \\ V /| | | | | (_| | || (_) | |         \n");
	printf("\\_|  |_/\\__,_|_|    \\_/ |_|_| |_|\\__,_|\\__\\___/|_|\n\n\n");

	// Affichage du menu
	printf("Que voulez-vous faire ?\n");
	printf("  1 - Jouer\n");
	printf("  2 - Connaitre les r%cgles\n", e_grave);
	printf("  3 - Gen%cse du projet\n", e_grave);
	printf("  4 - Quitter\n");

	switch (demanderIntIntervalle("Votre choix : ", 1, 4)) {

		// Jouer
		case 1:
			jeu();
		break;

		// Règles
		case 2:
			printf("\n\n");
			printf("=========================  R%cgles du jeu  ========================\n", e_grave);
			printf("= Le but du jeu est de faire deviner le nom du personnage.       =\n");
			printf("= Marvel auquel vous pensez %c Akinator. R%cpondez aux questions   =\n", a_grave, e_aigu);
			printf("= d'Akinator par Oui ou Non/je ne sais pas et Akinator trouvera  =\n");
			printf("= le nom du h%cros Marvel auquel vous pensez. Vous pouvez choisir =\n", e_aigu);
			printf("= le personnage que vous voulez.                                 =\n");
			printf("==================================================================\n");
			printf("\n\n");
			pauseProgramme();

			akinator_recursif();
		break;

		// Histoire du projet
		case 3:
			printf("\n\n");
			printf("===================================================  Histoire du projet  ==================================================\n");
			printf("= En 2007, Arnaud Megret, ing%cnieur en informatique, a l'id%ce de cr%cer Devinettor, projet pas tr%cs ambitieux, pour        =\n", e_aigu, e_aigu, e_aigu, e_grave);
			printf("= s'amuser, o%c une intelligence artificielle pose 20 questions %c un joueur pour deviner %c quel personnage il pense.       =\n", u_grave, a_grave, a_grave);
			printf("= L'ing%cnieur remplit au d%cpart la base de donn%ces avec 100 personnages et 100 questions, mais la force du jeu est de     =\n", e_aigu, e_aigu, e_aigu);
			printf("= s'enrichir au fil des parties : quand le jeu est battu par le joueur parce qu'il n'a pas su deviner le personnage,      =\n");
			printf("= Devinettor enregistre les informations de la partie. Ainsi, la base de donn%ces se diversifie au fil des parties et les  =\n", e_aigu);
			printf("= personnages pr%cc%cdemment jou%cs sont de plus en plus facilement devin%cs par l'intelligence artificielle.                 =\n", e_aigu, e_aigu, e_aigu, e_aigu);
			printf("=                                                                                                                         =\n");
			printf("= Arnaud Megret partage le jeu %c ses connaissances et peu apr%cs, Devinettor commence %c circuler sur les forums en         =\n", a_grave, e_grave, a_grave);
			printf("= ligne et atteint une relative popularit%c rapidement et le jeu est renomm%c en Akinator.                                  =\n", e_aigu, e_aigu);
			printf("===========================================================================================================================\n");
			printf("\n\n");
			pauseProgramme();

			akinator_recursif();
		break;

		// Quitter
		case 4:
			exit(EXIT_SUCCESS);
		break;
	}
}

void akinator_recursif()
{	// Affichage du menu
	printf("Que voulez-vous faire ?\n");
	printf("  1 - Jouer\n");
	printf("  2 - Connaitre les r%cgles\n", e_grave);
	printf("  3 - Gen%cse du projet\n", e_grave);
	printf("  4 - Quitter\n");

	switch (demanderIntIntervalle("Votre choix : ", 1, 4)) {

		// Jouer
		case 1:
			jeu();
			break;

			// Règles
		case 2:
			printf("\n\n");
			printf("=========================  R%cgles du jeu  ========================\n", e_grave);
			printf("= Le but du jeu est de faire deviner le nom du personnage.       =\n");
			printf("= Marvel auquel vous pensez %c Akinator. R%cpondez aux questions   =\n", a_grave, e_aigu);
			printf("= d'Akinator par Oui ou Non/je ne sais pas et Akinator trouvera  =\n");
			printf("= le nom du h%cros Marvel auquel vous pensez. Vous pouvez choisir =\n", e_aigu);
			printf("= le personnage que vous voulez.                                 =\n");
			printf("==================================================================\n");
			printf("\n\n");
			pauseProgramme();
			akinator_recursif();
			break;

			// Histoire du projet
		case 3:
			printf("\n\n");
			printf("===================================================  Histoire du projet  ==================================================\n");
			printf("= En 2007, Arnaud Megret, ing%cnieur en informatique, a l'id%ce de cr%cer Devinettor, projet pas tr%cs ambitieux, pour        =\n", e_aigu, e_aigu, e_aigu, e_grave);
			printf("= s'amuser, o%c une intelligence artificielle pose 20 questions %c un joueur pour deviner %c quel personnage il pense.       =\n", u_grave, a_grave, a_grave);
			printf("= L'ing%cnieur remplit au d%cpart la base de donn%ces avec 100 personnages et 100 questions, mais la force du jeu est de     =\n", e_aigu, e_aigu, e_aigu);
			printf("= s'enrichir au fil des parties : quand le jeu est battu par le joueur parce qu'il n'a pas su deviner le personnage,      =\n");
			printf("= Devinettor enregistre les informations de la partie. Ainsi, la base de donn%ces se diversifie au fil des parties et les  =\n", e_aigu);
			printf("= personnages pr%cc%cdemment jou%cs sont de plus en plus facilement devin%cs par l'intelligence artificielle.                 =\n", e_aigu, e_aigu, e_aigu, e_aigu);
			printf("=                                                                                                                         =\n");
			printf("= Arnaud Megret partage le jeu %c ses connaissances et peu apr%cs, Devinettor commence %c circuler sur les forums en         =\n", a_grave, e_grave, a_grave);
			printf("= ligne et atteint une relative popularit%c rapidement et le jeu est renomm%c en Akinator.                                  =\n", e_aigu, e_aigu);
			printf("===========================================================================================================================\n");
			printf("\n\n");
			pauseProgramme();
			break;

			// Quitter
		case 4:
			exit(EXIT_SUCCESS);
			break;
	}
}

