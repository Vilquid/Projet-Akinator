/**
 * @file main.c
 * @brief Fichier contenant la fonction principale du programme
**/

#include "../include/main.h"

int main()
{
	// Initialiser l'aléatoire
	srand(time(NULL));

	akinator();
	boucle_jeu();

	return EXIT_SUCCESS;
}
