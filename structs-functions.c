#include "structs-functions.h"


// Déclarer les fonctions après ce commentaire

void ajouter_personnage-questions_BDD(Hero hero_de_test)
{
	// string à rentrer dans la BDD
	int taille = 1;
	char* string = (char*)malloc(taille * sizeof(char));

	int choix_int = 1;
	char choix_string[256] = "";

	if (string != NULL)
	{
		// ajouter les caractéristiques d'un personnage à la string

		printf("Quel est le nom du héros ?\n");
		printf("Son nom : ");
		scanf("%s", choix_string);
		printf("\n");

		strcat(string, choix_string);

		printf("Quel est le sexe du héros ?\n");
		printf("  1 - Homme\n");
		printf("  2 - Femme\n");
		printf("  3 - Autre\n");
		printf("Son sexe : ");

		printf("Quel est le nationalité du héros ?\n");
		printf("  1 - Etats-Unis\n");
		printf("  2 - Russie\n");
		printf("  3 - France\n");
		printf("  4 - Autre\n");
		printf("Sa nationalité : ");

		printf("Quel est l'age du héros ?\n");
		printf("Son age : ");

		printf("Votre héros utilise-t-il plus ses pouvoirs ou son équipement du héros ?\n");
		printf("  1 - Pouvoirs\n");
		printf("  2 - Equipement\n");
		printf("Votre choix : ");

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

	// rentrer la string dans la BDD

	//
}

void akinator() // ne pas toucher même si c'est moche car ça rend bien
{
	printf("  .--.  .-. .-..-..-. .-.  .--.  .---.  .----. .----.\n");
	printf(" / {} \\ | |/ / | ||  `| | / {} \\{_   _}/  {}  \\| {}  }\n");
	printf("/  /\\  \\| |\\ \\ | || |\\  |/  /\\  \\ | |  \\      /| .-. \\\n");
	printf("`-'  `-'`-' `-'`-'`-' `-'`-'  `-' `-'   `----' `-' `-'");
}