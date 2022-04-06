#include "../include/librairies.h"
#include "../include/structs_donnees.h"
#include "../include/gestion_listes.h"
#include <sys/stat.h>

const char *filename = "questions.txt";

char recupQuestion(Liste_Questions *file_questions);
Liste_Questions *initQuestions();

Liste_Questions *initQuestions() {

	FILE *fichier_questions = NULL;
	Liste_Questions *file_questions = creerListeQuestions();

	fichier_questions = fopen(filename, "r");

	if (!fichier_questions) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	struct stat sb;
	if (stat(filename, &sb) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

	char *file_contents = malloc(sb.st_size);
	int priority = 0;
	char attribute[32];
	char reponse[32];

	while (fscanf(fichier_questions, "%d/%s/%s : %[^\n] ", priority, attribute, reponse, file_contents) != EOF) {
		printf("> %s : %d/%s/%s\n", file_contents, priority, attribute, reponse);
	}

	fclose(fichier_questions);

	return file_questions;
}

char recupQuestion(Liste_Questions *file_questions) {

	char str_question[128];

	return str_question;
}
