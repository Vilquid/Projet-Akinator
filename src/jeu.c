/**
 * @file jeu.c
 * @brief Fichier contenant toutes les fonctions liées au jeu
**/

#include "../include/jeu.h"

/**
 * @brief Fonction principale du jeu
**/
void jeu() {

	bool rejouer = false;

	// Boucle rejouer
	do {

		// Variables de jeu
		bool heros_trouve = false;
		Liste_Heros *liste_heros = NULL;
		Liste_Questions *liste_questions = NULL;
		Heros *heros_test = NULL;

		// Charger les données des personnages et des questions
		liste_heros = chargerDonneesFichierPersonnages();
		liste_questions = chargerDonneesFichierQuestions();

		// Initialisation du héros pour faire nos tests
		heros_test = creerHeros("", 0, HOMME, "", HUMAIN, false, false, false, false, "");

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

		// Boucle de jeu
		do {
			// Poser la question suivante de la liste

			// S'il n'y a plus de questions à poser
			if (liste_questions->nb_questions == 0) {

				printf("Je ne sais plus quoi vous demander.\n");
				printf("Fin du jeu !\n\n");
				heros_trouve = true;
			}

			// Cas particulier pour l'âge
			if (strcmp(liste_questions->premier->question->attribut, "age") == 0)
			{
				printf("%s %d ans ?\n", liste_questions->premier->question->question, calculAgeMoyenHerosRestants(liste_heros));
			}
			else {
				printf("%s\n", liste_questions->premier->question->question);
			}

			printf("  1 - Oui\n");
			printf("  2 - Non\n");
			int choix = demanderIntIntervalle("Votre choix : ", 1, 2);

			// Si l'utilisateur a répondu "Oui"
			if (choix == 1) {

				// Si l'attribut de la question était "age"
				if (strcmp(liste_questions->premier->question->attribut, "age") == 0)
				{
					supprimerHerosSelonAgeInferieur(liste_heros);
				}

				// Si l'attribut de la question était "sexe"
				else if (strcmp(liste_questions->premier->question->attribut, "sexe") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					if (strcmp(liste_questions->premier->question->reponse_attendue, "homme") == 0) {
						heros_test->sexe = HOMME;
						supprimerHerosSelonSexe(liste_heros, FEMME);
						supprimerHerosSelonSexe(liste_heros, AUTRE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "femme") == 0) {
						heros_test->sexe = FEMME;
						supprimerHerosSelonSexe(liste_heros, HOMME);
						supprimerHerosSelonSexe(liste_heros, AUTRE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "autre") == 0) {
						heros_test->sexe = AUTRE;
						supprimerHerosSelonSexe(liste_heros, HOMME);
						supprimerHerosSelonSexe(liste_heros, FEMME);
					}
				}

				// Si l'attribut de la question était "nationalite"
				else if (strcmp(liste_questions->premier->question->attribut, "nationalite") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					strcpy(heros_test->nationalite, liste_questions->premier->question->reponse_attendue);
					supprimerHerosSelonNationaliteDifferente(liste_heros, liste_questions->premier->question->reponse_attendue);
				}

				// Si l'attribut de la question était "espece"
				else if (strcmp(liste_questions->premier->question->attribut, "espece") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					if (strcmp(liste_questions->premier->question->reponse_attendue, "humain") == 0) {
						heros_test->espece = HUMAIN;
						supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
						supprimerHerosSelonEspece(liste_heros, MUTANT);
						supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "extraterrestre") == 0) {
						heros_test->espece = EXTRATERRESTRE;
						supprimerHerosSelonEspece(liste_heros, HUMAIN);
						supprimerHerosSelonEspece(liste_heros, MUTANT);
						supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "mutant") == 0) {
						heros_test->espece = MUTANT;
						supprimerHerosSelonEspece(liste_heros, HUMAIN);
						supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
						supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "humain-altere") == 0) {
						heros_test->espece = HUMAIN_ALTERE;
						supprimerHerosSelonEspece(liste_heros, HUMAIN);
						supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
						supprimerHerosSelonEspece(liste_heros, MUTANT);
					}
				}

				// Si l'attribut de la question était "equipement"
				else if (strcmp(liste_questions->premier->question->attribut, "equipement") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					heros_test->equipement = true;
					supprimerHerosSelonEquipement(liste_heros, false);
				}

				// Si l'attribut de la question était "volant"
				else if (strcmp(liste_questions->premier->question->attribut, "volant") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					heros_test->volant = true;
					supprimerHerosSelonVolant(liste_heros, false);
				}

				// Si l'attribut de la question était "masque"
				else if (strcmp(liste_questions->premier->question->attribut, "masque") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					heros_test->masque = true;
					supprimerHerosSelonMasque(liste_heros, false);
				}

				// Si l'attribut de la question était "taille"
				else if (strcmp(liste_questions->premier->question->attribut, "taille") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					heros_test->taille = true;
					supprimerHerosSelonTaille(liste_heros, false);
				}

				// Si l'attribut de la question était "couleur"
				else if (strcmp(liste_questions->premier->question->attribut, "couleur") == 0)
				{
					// Stocker l'attribut dans heros_test et supprimer les personnages qui ne répondent PAS à l'attribut
					strcpy(heros_test->couleur, liste_questions->premier->question->reponse_attendue);
					supprimerHerosSelonCouleurDifferente(liste_heros, liste_questions->premier->question->reponse_attendue);
				}

				// Supprimer toutes les questions qui répondent au même attribut
				supprimerQuestionsSelonAttribut(liste_questions, liste_questions->premier->question->attribut);
			}

			// Si l'utilisateur a répondu "Non"
			else if (choix == 2) {

				// Si l'attribut de la question était "age"
				if (strcmp(liste_questions->premier->question->attribut, "age") == 0)
				{
					supprimerHerosSelonAgeSuperieur(liste_heros);
				}

				// Si l'attribut de la question était "sexe"
				else if (strcmp(liste_questions->premier->question->attribut, "sexe") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					if (strcmp(liste_questions->premier->question->reponse_attendue, "homme") == 0) {
						supprimerHerosSelonSexe(liste_heros, HOMME);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "femme") == 0) {
						supprimerHerosSelonSexe(liste_heros, FEMME);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "autre") == 0) {
						supprimerHerosSelonSexe(liste_heros, AUTRE);
					}
				}

				// Si l'attribut de la question était "nationalite"
				else if (strcmp(liste_questions->premier->question->attribut, "nationalite") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonNationalite(liste_heros, liste_questions->premier->question->reponse_attendue);
				}

				// Si l'attribut de la question était "espece"
				else if (strcmp(liste_questions->premier->question->attribut, "espece") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					if (strcmp(liste_questions->premier->question->reponse_attendue, "humain") == 0) {
						supprimerHerosSelonEspece(liste_heros, HUMAIN);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "extraterrestre") == 0) {
						supprimerHerosSelonEspece(liste_heros, EXTRATERRESTRE);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "mutant") == 0) {
						supprimerHerosSelonEspece(liste_heros, MUTANT);
					}
					else if (strcmp(liste_questions->premier->question->reponse_attendue, "humain-altere") == 0) {
						supprimerHerosSelonEspece(liste_heros, HUMAIN_ALTERE);
					}
				}

				// Si l'attribut de la question était "equipement"
				else if (strcmp(liste_questions->premier->question->attribut, "equipement") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonEquipement(liste_heros, true);
				}

				// Si l'attribut de la question était "volant"
				else if (strcmp(liste_questions->premier->question->attribut, "volant") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonVolant(liste_heros, true);
				}

				// Si l'attribut de la question était "masque"
				else if (strcmp(liste_questions->premier->question->attribut, "masque") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonMasque(liste_heros, true);
				}

				// Si l'attribut de la question était "taille"
				else if (strcmp(liste_questions->premier->question->attribut, "taille") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonTaille(liste_heros, true);
				}

				// Si l'attribut de la question était "couleur"
				else if (strcmp(liste_questions->premier->question->attribut, "couleur") == 0)
				{
					// Supprimer les personnages qui correspondent à l'attribut
					supprimerHerosSelonCouleur(liste_heros, liste_questions->premier->question->reponse_attendue);
				}

				// Supprimer la question que l'ont vient de poser
				supprimerQuestionListe(liste_questions, liste_questions->premier);
			}

			// S'il n'y a plus aucun héros
			if (liste_heros->nb_heros == 0) {

				printf("Oh non... Je ne connais pas votre personnage\n\n");
				heros_trouve = true;

				questionAjouterPersoBDD(heros_test);
			}

			// S'il reste moins de 3 héros
			else if (liste_heros->nb_heros < 3) {

				// Tenter le premier choix de personnage
				printf("Est-ce que le personnage est %s ?\n", liste_heros->premier->heros->nom);
				printf("  1 - Oui\n");
				printf("  2 - Non\n");
				choix = demanderIntIntervalle("Votre choix : ", 1, 2);

				// Si c'était le bon personnage
				if (choix == 1) {
					printf("Incroyable ! Je suis trop fort :)\n\n");
					heros_trouve = true;
				}

				// Si ce n'était pas le bon personnage
				else if (choix == 2) {

					// Supprimer le personnage de la liste
					liste_heros->premier = supprimerHerosListe(liste_heros, liste_heros->premier);

					if (liste_heros->premier == NULL) {

						printf("Oh non... Je ne connais pas votre personnage\n\n");
						heros_trouve = true;

						questionAjouterPersoBDD(heros_test);
					}

					else {
						// Tenter le deuxième choix de personnage
						printf("Zut ! Est-ce que le personnage est %s ?\n", liste_heros->premier->heros->nom);
						printf("  1 - Oui\n");
						printf("  2 - Non\n");
						choix = demanderIntIntervalle("Votre choix : ", 1, 2);

						// Si c'était le bon personnage
						if (choix == 1) {
							printf("Excellent ! Je ne suis pas trop mauvais\n\n");
							heros_trouve = true;
						}

						// Si ce n'était toujours pas le bon personnage
						else if (choix == 2) {
							printf("Oh non... Je ne connais donc pas votre personnage\n\n");
							heros_trouve = true;

							questionAjouterPersoBDD(heros_test);
						}
					}
				}
			}

		} while (!heros_trouve);

		rejouer = questionRejouer();

		if (rejouer) {
			// Vidage des listes
			viderListeHeros(liste_heros);
			viderListeQuestions(liste_questions);
		}

	} while (rejouer);

}

/**
 * @brief Fonction permettant de demander à l'utilisateur s'il souhaite rejouer
 * @return bool – True si le joueur veut rejouer, False sinon
**/
bool questionRejouer() {

	printf("Voulez-vous rejouer ?\n");
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (demanderIntIntervalle("Votre choix : ", 1, 2) == 2) {
		return false;
	}
	else {
		return true;
	}
}

/**
 * @brief Fonction permettant de demander à l'utilisateur s'il souhaite ajouter une question dans la base de données
**/
void questionAjouterQuestionBDD() {

	printf("Voulez-vous ajouter une question à la base de donn%ces ?\n", e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (demanderIntIntervalle("Votre choix : ", 1, 2) == 1) {
		ajouterQuestionBDD();
	}
	else {
		printf("Vous n'ajoutez pas de question\n\n");
	}
}

/**
 * @brief Fonction permettant de demander à l'utilisateur s'il souhaite ajouter un personnage dans la base de données
 * @param heros Héros à ajouter
**/
void questionAjouterPersoBDD(Heros *heros) {

	printf("Voulez-vous ajouter un personnage %c la base de donn%ces ?\n", a_grave, e_aigu);
	printf("  1 - Oui\n");
	printf("  2 - Non\n");

	if (demanderIntIntervalle("Votre choix : ", 1, 2) == 1) {
		ajouterPersonnageBDD(heros);
	}
	else {
		printf("Vous n'ajoutez pas de personnage\n\n");
	}
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

		// Afficher le sexe en toute lettre à partir de l'énumération
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

		// Afficher l'espèce en toute lettre à partir de l'énumération
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
 * @return int – Age moyen des héros suspects restants
**/
int calculAgeMoyenHerosRestants(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("calculAgeMoyenHerosRestants() : La liste des héros est NULL !\n");
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
void supprimerHerosSelonAgeSuperieur(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonAgeSuperieur() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;
	int age_moyen = calculAgeMoyenHerosRestants(liste);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age > age_moyen) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ont un âge inférieur à la moyenne des héros suspects restants
 * @param liste Liste des héros
**/
void supprimerHerosSelonAgeInferieur(Liste_Heros *liste) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonAgeInferieur() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;
	int age_moyen = calculAgeMoyenHerosRestants(liste);

	while (elt_actuel != NULL)
	{
		if (elt_actuel->heros->age < age_moyen) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}

		elt_actuel = elt_actuel->suivant;
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros sont du sexe précisé
 * @param liste Liste des héros
 * @param sexe Sexe à supprimer
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
		if (elt_actuel->heros->sexe == sexe) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui sont de la nationalité précisée
 * @param liste Liste des héros
 * @param nationalite Nationalité à supprimer
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
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont PAS de la nationalité précisée
 * @param liste Liste des héros
 * @param nationalite Nationalité à ne PAS supprimer
**/
void supprimerHerosSelonNationaliteDifferente(Liste_Heros *liste, char nationalite[]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonNationaliteDifferente() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->nationalite, nationalite) != 0) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui sont de l'espèce précisée
 * @param liste Liste des héros
 * @param espece Espèce à supprimer
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
		if (elt_actuel->heros->espece == espece) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui correspondent à l'attribut équipement précisé
 * @param liste Liste des héros
 * @param equipement Attribut équipement à supprimer
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
		if (elt_actuel->heros->equipement == equipement) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui correspondent à l'attribut volant précisé
 * @param liste Liste des héros
 * @param volant Attribut volant à supprimer
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
		if (elt_actuel->heros->volant == volant) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui correspondent à l'attribut masque précisé
 * @param liste Liste des héros
 * @param masque Attribut masque à supprimer
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
		if (elt_actuel->heros->masque == masque) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui correspondent à l'attribut taille précisé
 * @param liste Liste des héros
 * @param taille Attribut taille à supprimer
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
		if (elt_actuel->heros->taille == taille) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui sont de la couleur précisée
 * @param liste Liste des héros
 * @param couleur Attribut couleur à supprimer
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
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer des suspects les héros qui ne sont PAS de la couleur précisée
 * @param liste Liste des héros
 * @param couleur Attribut couleur à ne PAS supprimer
**/
void supprimerHerosSelonCouleurDifferente(Liste_Heros *liste, char couleur[]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerHerosSelonCouleur() : La liste des héros est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Heros *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->heros->couleur, couleur) != 0) {
			elt_actuel = supprimerHerosListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}

/**
 * @brief Fonction permettant de supprimer de la liste toutes les questions qui correspondent à l'attribut précisé
 * @param liste Liste des questions
 * @param attribut Attribut ciblé par la question
**/
void supprimerQuestionsSelonAttribut(Liste_Questions *liste, char attribut[]) {

	// Si la liste est NULL
	if (liste == NULL) {
		printf("supprimerQuestionsSelonAttribut() : La liste des questions est NULL !\n");
		exit(EXIT_FAILURE);
	}

	Elt_Question *elt_actuel = liste->premier;

	while (elt_actuel != NULL)
	{
		if (strcmp(elt_actuel->question->attribut, attribut) == 0) {
			elt_actuel = supprimerQuestionListe(liste, elt_actuel);
		}
		else {
			elt_actuel = elt_actuel->suivant;
		}
	}
}
