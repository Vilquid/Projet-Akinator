/**
 * @file gestion_fichiers.c
 * @brief Fichier contenant toutes les fonctions de gestion des fichiers
**/

#include "../include/gestion_fichiers.h"

Liste_Heros *chargerFichierPersonnage() {

	// Création du pointeur vers le fichier texte
	FILE *fichier_file = NULL;

	// Ouverture du fichier texte en lecture
	fichier_file = fopen("../db/personnages.txt", "r");

	// Si le fichier texte n'a pas pu être ouvert
	if (fichier_file == NULL) {
		printf("Erreur d'ouverture du fichier texte !\n");
		exit(EXIT_FAILURE);
	}

	// Création du pointeur de la pile
	Liste_Heros *file = creerListeHeros();

	// Variables à récupérer
	char nom[25];
	memset(nom, '\0', 25 * sizeof(char));
	int sexe = 0;
	char nationalite[25];
	memset(nationalite, '\0', 25 * sizeof(char));
	int age = 0;
	bool equipement = false;
	int humain = 0;
	bool volant = false;
	bool masque = false;
	bool taille = false;
	char color[15];
	memset(color, '\0', 15 * sizeof(char));

    char sexe_tmp[5];
    memset(nom, '\0', 5 * sizeof(char));
    char humain_tmp[10];
    memset(nom, '\0', 10 * sizeof(char));
    char volant_tmp[15];
    memset(nom, '\0', 15 * sizeof(char));
    char masque_tmp[15];
    memset(nom, '\0', 15 * sizeof(char));
    char taille_tmp[15];
    memset(nom, '\0', 15 * sizeof(char));
    char equipement_tmp[15];
    memset(nom, '\0', 15 * sizeof(char));
    char age_tmp[4];
    memset(nom, '\0', 4 * sizeof(char));



	// Tant qu'on n'est pas arrivé à la fin du fichier
	while (!feof(fichier_file)) {

		// Récupérer les données de la ligne
		// TODO : Modifier les types de données et déduire infos des chaines de caractères BDD
		fscanf(fichier_file, "%s,%s,%s,%d,%s,%s,%s,%s,%s,%s\n", nom, sexe_tmp, nationalite, age_tmp, equipement_tmp, humain_tmp, volant_tmp, masque_tmp, taille_tmp, color);

		// Créer et empiler un nouvel élément à partir des données récupérées
		// TODO : Changer la création du Héro pour du Elt_Hero
        age = charToInt(age_tmp);
        sexe = charToIntSexe(sexe_tmp);
        humain = charToIntEspece(humain_tmp);
        volant = charToBool(volant_tmp, "volant");
        masque = charToBool(masque_tmp, "masque");
        taille = charToBool(taille_tmp, "taille-normale");
        equipement = charToBool(equipement_tmp, "equipement"); //true -> equipement, false -> pouvoirs

		creerHeros(nom, sexe, nationalite, age, equipement, humain, volant, masque, taille, color);
		//ajouterHeroListe(file, );
	}

	// Fermeture du fichier texte
	fclose(fichier_file);

	return file;
}

// TODO : sexe char -> int / equipement char -> bool / espece char -> int / volant char -> bool / masque char -> bool / taille char -> bool
/**
 * @fn charToInt
 * @param c
 * @return int
 */
int charToInt(char c){
    int num = 0;
    num = c - '0';
    return num;
}


/**
 * @fn charToIntSexe
 * @brief prend un char en param et retourne un entier/ 1>Homme, 2>Femme, 0>Autre
 * @param type
 * @return int num
 */
int charToIntSexe(char type){
    if (strcmp(type, 'homme') == true){
        return 1;
    } else if (strcmp(type, 'femme') == true){
        return 2;
    } else if (strcmp(type, 'autre') == true){
        return 0;
    } else{
        return 0;
    }
}

/**
 * @fn CharToIntEspece
 * @brief 0 => Humain / 1 => Extraterrestre / 2 => Mutant / 3 => Humain-altere
 * @param type
 * @return
 */
int charToIntEspece(char type){
    if (strcmp(type, 'humain') == true){
        return 0;
    } else if (strcmp(type, 'extraterrestre') == true){
        return 1;
    } else if (strcmp(type, 'mutant') == true){
        return 2;
    } else if (strcmp(type, 'humain-altere') == true){
        return 3;
    } else{
        return 0;
    }
}


/**
 * @fn charToBool
 * @brief mettre le type attendu pour avoir true
 * @param typeAttendu, valeur
 * @param valeur
 * @return
 */
bool charToBool(char typeAttendu, char valeur){
    if (strcmp(typeAttendu, valeur) == true){
        return true;
    } else{
        return false;
    }
}

