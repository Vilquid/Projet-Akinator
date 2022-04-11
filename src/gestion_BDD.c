/**
 * @file gestion_BDD.C
 * @brief Fichier contenant toutes les fonctions pour ajouter un personnage et une question aux bases de données
 */

#include "../include/gestion_BDD.h"

/**
 * @brief Fonction permettant d'ajouter une question à la base de données questions
**/
void ajouterQuestionBDD() {

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
 * @brief Fonction permettant d'ajouter un personnage à la base de données personnages
 * @param heros Héros à ajouter
**/
void ajouterPersonnageBDD(Heros *heros) {

	// Chaîne de caractères à écrire dans la BDD
	char string_bdd[256];
	memset(string_bdd, '\0', 256 * sizeof(char));

	// Demande du nom
	printf("Saisissez le nom du personnage que vous voulez ajouter.\n");
	printf("Son nom : ");
	scanf("%s", heros->nom);

	// Demande de l'âge
	printf("\nSaisissez l'%cge du personnage que vous voulez ajouter.\n", a_circonflexe);
	printf("Son age : ");
	scanf("%d", &heros->age);

	// Demande de la nationalité
	printf("\nSaisissez la nationalit%c du personnage que vous voulez ajouter.\n", e_aigu);
	printf("Sa nationalite : ");
	scanf("%s", heros->nationalite);

	// Demande de l'équipement
	printf("\nVotre personnage utilise-t-il plus ses %cquipements que ses pouvoirs ?\n", e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");
	switch (demanderIntIntervalle("Votre choix : ", 1, 2)) {
		case 1:
			heros->equipement = true;
		break;
		case 2:
			heros->equipement = false;
		break;
	}

	// Demande de volant
	printf("Votre personnage peut-il voler ?\n");
	printf("  1 - Oui\n");
	printf("  2 - Non\n");
	switch (demanderIntIntervalle("Votre choix : ", 1, 2)) {
		case 1:
			heros->volant = true;
		break;
		case 2:
			heros->volant = false;
		break;
	}

	// Demande de masque
	printf("Votre personnage est-il masqu%c ?\n", e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");
	switch (demanderIntIntervalle("Votre choix : ", 1, 2)) {
		case 1:
			heros->masque = true;
		break;
		case 2:
			heros->masque = false;
		break;
	}

	// Demande de la taille
	printf("Votre personnage a-t-il la taille d'un humain adulte ?\n");
	printf("  1 - Oui\n");
	printf("  2 - Non\n");
	switch (demanderIntIntervalle("Votre choix : ", 1, 2)) {
		case 1:
			heros->taille = true;
		break;
		case 2:
			heros->taille = false;
		break;
	}

	// Demande de la couleur
	printf("Saisissez la couleur pr%cdominante du personnage que vous voulez ajouter.\n", e_aigu);
	printf("Sa couleur : ");
	scanf("%s", heros->couleur);

	// Variables de conversion
	char sexe[10];
	char espece[25];
	char equipement[25];
	char volant[25];
	char masque[25];
	char taille[25];
	memset(sexe, '\0', 10 * sizeof(char));
	memset(espece, '\0', 25 * sizeof(char));
	memset(equipement, '\0', 25 * sizeof(char));
	memset(volant, '\0', 25 * sizeof(char));
	memset(masque, '\0', 25 * sizeof(char));
	memset(taille, '\0', 25 * sizeof(char));

	// Conversion de l'attribut sexe
	switch (heros->sexe) {
		case HOMME:
			strcpy(sexe, "homme");
		break;
		case FEMME:
			strcpy(sexe, "femme");
		break;
		case AUTRE:
			strcpy(sexe, "autre");
		break;
	}

	// Conversion de l'attribut espèce
	switch (heros->espece) {
		case HUMAIN:
			strcpy(espece, "humain");
		break;
		case EXTRATERRESTRE:
			strcpy(espece, "extraterrestre");
		break;
		case MUTANT:
			strcpy(espece, "mutant");
		break;
		case HUMAIN_ALTERE:
			strcpy(espece, "humain-altere");
		break;
	}

	// Conversion de l'attribut équipement
	switch (heros->equipement) {
		case true:
			strcpy(equipement, "equipement");
		break;
		case false:
			strcpy(equipement, "pouvoirs");
		break;
	}

	// Conversion de l'attribut volant
	switch (heros->volant) {
		case true:
			strcpy(volant, "volant");
		break;
		case false:
			strcpy(volant, "non-volant");
		break;
	}

	// Conversion de l'attribut masque
	switch (heros->masque) {
		case true:
			strcpy(masque, "masque");
		break;
		case false:
			strcpy(masque, "non-masque");
		break;
	}

	// Conversion de l'attribut taille
	switch (heros->taille) {
		case true:
			strcpy(taille, "taille-normale");
		break;
		case false:
			strcpy(taille, "taille-anormale");
		break;
	}

	// Création du pointeur vers le fichier texte
	FILE *fichier_persos = NULL;

	// Ouverture du fichier texte en lecture
	fichier_persos = fopen("../db/personnages.txt", "a");

	// Si le fichier texte n'a pas pu être ouvert
	if (fichier_persos == NULL) {
		printf("ajouterPersonnageBDD() : Erreur d'ouverture du fichier texte !\n");
		exit(EXIT_FAILURE);
	}

	// Création de la chaîne de caractères à écrire dans la BDD
	sprintf(string_bdd, "\n%s %s %s %d %s %s %s %s %s %s", heros->nom, sexe, heros->nationalite, heros->age, equipement, espece, volant, masque, taille, heros->couleur);

	// Récapitulatif
	printf("\nLe personnage suivant va %ctre ajout%c %c la BDD :\n", e_circonflexe, e_aigu, a_grave);
	printf("\nString : %s\n", string_bdd);
	afficherHeros(heros);

	// Demande si les infos sont correctes
	printf("Voulez-vous vraiment ajouter ce personnage dans la BDD ?\n");
	printf("  1 - Oui\n");
	printf("  2 - Non\n");
	switch (demanderIntIntervalle("Votre choix : ", 1, 2)) {
		case 1:
			// Ecriture dans le fichier texte
			fputs(string_bdd, fichier_persos);
			printf("Le personnage a bien %ct%c ajout%c dans la BDD !\n\n", e_aigu, e_aigu, e_aigu);
		break;
		case 2:
			printf("Vous avez annul%c l'ajout du personnage\n\n", e_aigu);
		break;
	}

	fclose(fichier_persos);
}
