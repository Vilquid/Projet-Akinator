//#include "structs-functions.h"
#include "../include/librairies.h"
#include "../include/structs_donnees.h"
#include <sys/stat.h>

const char* filename = "questions.txt";

char recupQuestion(Liste_Questions* fileQuestion);
Liste_Questions* initQuestions();

Liste_Questions* initQuestions(){
    FILE* fichier_questions = NULL;
	Liste_Questions* fileQuestion = creerListeQuestions();

    fichier_questions = fopen(filename, "r");

	if(!fichier_questions){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	
	struct stat sb;
	if (stat(filename, &sb) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

	char *file_contents = malloc(sb.st_size);
    int priority;
    char attribute[32];
    char reponse[32];

	while (fscanf(fichier_questions, "%d/%s/%s : %[^\n] ", priority, attribute, reponse, file_contents) != EOF){
		printf("> %s : %d/%s/%s\n", file_contents, priority, attribute, reponse);
	}
	
	fclose(fichier_questions);
    return fileQuestion;
}

char recupQuestion(Liste_Questions* fileQuestion){
    char strQuestion[128];

	

    return strQuestion;
}