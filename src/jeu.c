/**
 * @file jeu.c
 * @brief Fichier contenant toutes les fonctions liées au jeu
**/

#include "../include/jeu.h"


/**
 * @fn question_rejouer
 * @brief Pose la question d'un nouveau tour de boucle/jeu (et rejoue si la réponse est positive)
 * @return bool : true si le joueur veut rejouer, false sinon
 */
bool question_rejouer()
{
	int choix = 1;

	printf("Voulez-vous rejouer ?\n");
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (est_un_int_et_est_compris_entre("Votre choix : ", choix, 1, 2) == 2)
	{
		return false;
	}

	else
	{
		return true;
	}
}

/**
 * @fn question_ajouter_question_BDD
 * @brief Pose la question de l'ajout d'une question dans la base de données Questions (et l'ajoute si la réponse est positive)
 */
void question_ajouter_question_BDD()
{
	int choix = 1;

	printf("Voulez-vous ajouter une question à la base de donn%ces ?\n", e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (est_un_int_et_est_compris_entre("Votre choix : ", choix, 1, 2) == 1)
	{
		ajouter_question_BDD();
	}

	else
	{
		printf("Vous n'ajouterez pas de question.\n");
	}
}

/**
 * @fn question_ajouter_perso_BDD
 * @brief Pose la question de l'ajout d'un personnage dans la base de données Personnages (et l'ajoute si la réponse est positive)
 * @param heros Structure heros à rentrer dans la base de données Personnages
 */
void question_ajouter_perso_BDD(Heros heros)
{
	int choix = 1;
	printf("Voulez-vous ajouter un personnage %c la base de donn%ces ?\n", a_grave, e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (est_un_int_et_est_compris_entre("Votre choix : ", choix, 1, 2) == 1)
	{
		ajouter_personnage_BDD(heros);
	}

	else
	{
		printf("Vous n'ajouterez pas de personnages.\n");
	}
}

/**
 * @fn attribution_caracteristiques_heros_temporaire
 * @brief Pose la question de l'ajout d'un personnage dans la base de données (et l'ajoute si la réponse est positive)
 * @param heros_temporaire Pointeur sur le heros temporaire
 * @param liste_heros Liste des héros
 * @param liste_questions Liste des questions
 * @return heros_temporaire
 */
Heros attribution_caracteristiques_heros_temporaire(Heros heros_temporaire, Liste_Heros* liste_heros, Liste_Questions* liste_questions)
{
	// TODO : utiliser void supprimerHerosSelonCouleur(Liste_Heros *liste, char couleur[])
	int choix_int = 0;
	Elt_Heros heros_actuel;
	heros_actuel.heros = liste_heros->premier->heros;

	// Appel fonction pour choisir une question
	Question *question_actuelle = choisirQuestionAleatoire(liste_questions);

	if (strcmp(question_actuelle->question, "Est-ce que le personnage a plus de") == 0)
	{
		// Afficher la question
		printf("%s %d ans ?\n", question_actuelle->question, calculAgeMoyenHeros(liste_heros));
		printf("  1 - Oui\n");
		printf("  2 - Non - Je ne sais pas\n");

		supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage a plus de");
		supprimerHerosSelonAge(liste_heros);
	}

	else
	{
		// Afficher la question
		printf("%s\n", question_actuelle->question);
		printf("  1 - Oui\n");
		printf("  2 - Non - Je ne sais pas\n");

		choix_int = est_un_int_et_est_compris_entre("Votre choix :", choix_int, 1, 2);

		// C'est un homme
		if (strcmp(question_actuelle->question, "Est-ce que le personnage est un homme ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des hommes
			supprimerHerosSelonSexe(liste_heros, HOMME);
			heros_temporaire.sexe = HOMME;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un homme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est une femme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est ni une femme, ni un homme ?");
		}

		// C'est une femme
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est une femme ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des femmes
			supprimerHerosSelonSexe(liste_heros, FEMME);
			heros_temporaire.sexe = FEMME;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est une femme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un homme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est ni une femme, ni un homme ?");
		}

		// C'est autre chose (ni un homme, ni une femme)
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est ni une femme, ni un homme ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des hommes ou des femmes
			supprimerHerosSelonSexe(liste_heros, AUTRE);
			heros_temporaire.sexe = AUTRE;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est ni une femme, ni un homme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est une femme ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un homme ?");
		}

		// C'est un humain
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est un humain ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des humains
			supprimerHerosSelonEspece(liste_heros, HUMAIN);
			heros_temporaire.espece = HUMAIN;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un mutant ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un extraterrestre ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain altere ?");
		}

		// C'est un mutant
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est un mutant ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des mutants
			supprimerHerosSelonEspece(liste_heros, MUTANT);
			heros_temporaire.espece = MUTANT;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un mutant ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un extraterrestre");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain altere ?");
		}

		// C'est un extraterrestre
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est un extraterrestre ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des mutants
			supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
			heros_temporaire.espece = EXTRATERRESTRE;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un extraterrestre ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un mutant ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain altere ?");
		}

		// C'est un humain altéré
		else if (strcmp(question_actuelle->question, "Est-ce un humain altere ?") == 0 &&
		choix_int == 1)
		{
			// Supprimer tous les héros qui ne sont pas des mutants
			supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
			heros_temporaire.espece = HUMAIN_ALTERE;

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce un humain altere ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un humain ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un mutant ?");
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est un extraterrestre ?");
		}

		// C'est un Etats-Uniens
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage est de nationalite etats-unienne ?") == 0 && choix_int == 1)
		{
			// Supprimer tous les héros qui sont de nationalité
			supprimerHerosSelonNationalite(liste_heros, "Etats-Unis");
			strcpy(heros_temporaire.nationalite, "Etats-Unis");

			// Supprimer les questions en rapport avec l'attribut
			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage est de nationalite etats-unienne ?");
		}

		// Equipement
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage utilise plus ses pouvoirs que ses equipements ?") == 0)
		{
			if (choix_int == 1)
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

			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage utilise plus ses pouvoirs que ses equipements ?");
		}

		// Volant
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage vole ?") == 0)
		{
			if (choix_int == 1)
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

			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage vole ?");
		}

		// Masque
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage porte un masque ?") == 0)
		{
			if (choix_int == 1)
			{
				// Supprimer tous les héros qui ne volent pas
				supprimerHerosSelonMasque(liste_heros, true);
				heros_temporaire.masque = true;
			}

			else
			{
				// Supprimer tous les héros qui ne volent pas
				supprimerHerosSelonVolant(liste_heros, false);
				heros_temporaire.masque = false;
			}

			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage porte un masque ?");
		}

		// Taille normale
		else if (strcmp(question_actuelle->question, "Est-ce que le personnage a la taille d'un humain adulte ?") == 0)
		{
			if (choix_int == 1)
			{
				supprimerHerosSelonTaille(liste_heros, "taille-normale");
				heros_temporaire.taille = true;
			}

			else
			{
				supprimerHerosSelonTaille(liste_heros, "taille-anormale");
				heros_temporaire.taille = false;
			}

			supprimerQuestionSelonQuestion(liste_questions, "Est-ce que le personnage a la taille d'un humain adulte ?");
		}
	}

	return heros_temporaire;
}

/**
 * @fn boucle_jeu
 * @brief Fonction (boucle) principale du jeu
**/
void boucle_jeu()
{
	bool heros_trouve = false;
	bool rejouer = true;
	Elt_Heros heros_actuel;
	Heros heros_temporaire;
	bool sortie_boucle_question = false;

	// Création des listes de héros et de questions
	Liste_Heros* liste_heros = NULL;
	Liste_Questions* liste_questions = NULL;

	//Boucle générale du jeu
	do
	{
		// Mise à jour des listes
		liste_heros = chargerDonneesFichierPersonnages();
		liste_questions = chargerDonneesFichierQuestions();

		test_si_listes_NULL(liste_heros, liste_questions);

		// On pose les questions
		do
		{
			heros_temporaire = attribution_caracteristiques_heros_temporaire(heros_temporaire, liste_heros, liste_questions);

			// test s'il reste moins de 3 héros dans la liste
			// Poser la question si le héros 1 est celui auquel on pense
			// Si oui alors :
			sortie_boucle_question = true;
			heros_trouve = true;
			// Poser la question si le héros 2 est celui auquel on pense
			// Si oui alors :
			sortie_boucle_question = true;
			heros_trouve = true;
			// Si non alors ne rien faire
		} while (sortie_boucle_question == false);

		if (heros_trouve == false)
		{
			question_ajouter_perso_BDD(heros_temporaire);
			question_ajouter_question_BDD();
		}

		rejouer = question_rejouer();

		// Vidage des listes
		viderListeHeros(liste_heros);
		viderListeQuestions(liste_questions);

//		heros_actuel = *heros_actuel.suivant;
	} while (rejouer == true/* || (heros_trouve == false || heros_actuel.suivant == NULL)*/);
}

/**
 * @brief Fonction permettant de choisir une question aléatoire parmis la liste de questions (FONCTION TEMPORAIRE)
 * @param liste Liste des questions
 * @return Question* – Pointeur vers la question tirée au sort
**/
Question *choisirQuestionAleatoire(Liste_Questions *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("choisirQuestionAleatoire() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	int nb_aleatoire = rand() % liste->nb_questions;

	Elt_Question *elt_actuel = liste->premier;

	for (int i = 0; i < nb_aleatoire; i++) {
		elt_actuel = elt_actuel->suivant;
	}

	return elt_actuel->question;
}

/**
 * @brief Fonction permettant de choisir un suspect dans la liste des héros, s'il reste 2 héros ou moins dans la liste 
 * @param liste Liste des héros
 * @return Heros* – Pointeur vers le suspect identifié (tiré au sort si 2 restants) ou NULL s'il y a plus de 2 héros restants dans la liste
**/
Heros *choisirSuspect(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("choisirSuspect() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	// S'il reste 2 héros dans la liste
	if (liste->nb_heros == 2)
	{
		// Choisir un héros au hasard
		int nb_aleatoire = rand() % 2;

		Elt_Heros *elt_actuel = liste->premier;

		for (int i = 0; i < nb_aleatoire; i++) {
			elt_actuel = elt_actuel->suivant;
		}

		return elt_actuel->heros;
	}

	// S'il reste 1 héros dans la liste
	else if (liste->nb_heros == 1) {

		Elt_Heros *elt_actuel = liste->premier;

		return elt_actuel->heros;
	}

	return NULL;
}

/**
 * @brief Fonction permettant d'afficher les informations d'un héros
 * @param heros Héros à afficher
**/
void afficherHeros(Heros *heros) {

	if (heros != NULL) {

		// Afficher les attributs
		printf("Nom : %s\n", heros->nom);
		printf("Age : %d ans\n", heros->age);

		// Afficher le sexe en toute lettre à partir de l'énumération Sexe
		switch (heros->sexe) {
			case HOMME:
				printf("Sexe : Homme\n");
				break;
			case FEMME:
				printf("Sexe : Femme\n");
				break;
			case AUTRE:
				printf("Sexe : Autre\n");
				break;
			default:
				printf("Sexe : Inconnu\n");
				break;
		}

		printf("Nationalite : %s\n", heros->nationalite);

		// Afficher l'espèce en toute lettre à partir de l'énumération Espece
		switch (heros->espece) {
			case HUMAIN:
				printf("Espece : Humain\n");
				break;
			case EXTRATERRESTRE:
				printf("Espece : Extraterrestre\n");
				break;
			case MUTANT:
				printf("Espece : Mutant\n");
				break;
			case HUMAIN_ALTERE:
				printf("Espece : Humain Altere\n");
				break;
			default:
				printf("Espece : Inconnu\n");
				break;
		}

		printf("Equipement : %s\n", heros->equipement ? "Oui" : "Non");
		printf("Volant : %s\n", heros->volant ? "Oui" : "Non");
		printf("Masque : %s\n", heros->masque ? "Oui" : "Non");
		printf("Taille humaine : %s\n", heros->taille ? "Oui" : "Non");
		printf("Couleur associee : %s\n", heros->couleur);
		printf("\n");
	}
}

/**
 * @brief Fonction permettant de calculer l'âge moyen des héros suspects restants
 * @param liste Liste des héros
 * @return int – L'âge moyen des héros suspects restants 
**/
int calculAgeMoyenHeros(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("calculAgeMoyenHeros() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	float age_moyen = 0;

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		age_moyen += elt_actuel->heros->age;
		elt_actuel = elt_actuel->suivant;
	}

	return (int)(age_moyen / liste->nb_heros);
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ont un âge supérieur à la moyenne des héros suspects restants
 * @param liste Liste des héros
**/
void supprimerHerosSelonAge(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonAge() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;
	int age_moyen = calculAgeMoyenHeros(liste);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age > age_moyen) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas du sexe précisé
 * @param liste Liste des héros
 * @param sexe Sexe précisé par l'utilisateur
**/
void supprimerHerosSelonSexe(Liste_Heros *liste, Sexe sexe) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonSexe() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->sexe != sexe) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de la nationalité précisée
 * @param liste Liste des héros
 * @param nationalite Nationalité précisée par l'utilisateur
**/
void supprimerHerosSelonNationalite(Liste_Heros *liste, char nationalite[]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonNationalite() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->nationalite, nationalite) == 0) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de l'espèce précisée
 * @param liste Liste des héros
 * @param espece Espèce précisée par l'utilisateur
**/
void supprimerHerosSelonEspece(Liste_Heros *liste, Espece espece) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonEspece() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->espece != espece) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut équipement précisé
 * @param liste Liste des héros
 * @param equipement Attribut équipement précisé par l'utilisateur
**/
void supprimerHerosSelonEquipement(Liste_Heros *liste, bool equipement) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonEquipement() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->equipement != equipement) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut volant précisé
 * @param liste Liste des héros
 * @param volant Attribut volant précisé par l'utilisateur
**/
void supprimerHerosSelonVolant(Liste_Heros *liste, bool volant) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonVolant() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->volant != volant) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut masque précisé
 * @param liste Liste des héros
 * @param masque Attribut masque précisé par l'utilisateur
**/
void supprimerHerosSelonMasque(Liste_Heros *liste, bool masque) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonMasque() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->masque != masque) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne correspondent pas à l'attribut taille précisé
 * @param liste Liste des héros
 * @param taille Attribut taille précisé par l'utilisateur
**/
void supprimerHerosSelonTaille(Liste_Heros *liste, bool taille) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonTaille() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->taille != taille) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont pas de la couleur précisée
 * @param liste Liste des héros
 * @param couleur Attribut couleur précisé par l'utilisateur
**/
void supprimerHerosSelonCouleur(Liste_Heros *liste, char couleur[]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonCouleur() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->couleur, couleur) == 0) {
			supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer de la liste la question précisée
 * @param liste Liste des questions
 * @param question Question à supprimer
**/
void supprimerQuestionSelonQuestion(Liste_Questions *liste, char question[]) {

    // Si la liste est NULL
    if (liste == NULL) {
        printf("supprimerQuestionSelonQuestion() : La liste des questions est NULL !\n");
        exit(EXIT_FAILURE);
    }

    Elt_Question *elt_actuel = liste->premier;

    while (elt_actuel != NULL)
    {
        if (strcmp(elt_actuel->question->question, question) != 0) {
            supprimerQuestionListe(liste, elt_actuel);
        }

        elt_actuel = elt_actuel->suivant;
    }
}
