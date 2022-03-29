//#include "structs-functions.h"
#include "../include/librairies.h"
#include "../include/structs_donnees.h"
#include <sys/stat.h>

const char* filename = "questions.txt";

char recupQuestion(File_Questions* fileQuestion);
File_Questions* initQuestions();

File_Questions* initQuestions(){
    FILE* fichier_questions = NULL;
	File_Questions* fileQuestion = creerListeQuestions();

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
    char attribute[32];
    char reponse[32];

	while (fscanf(fichier_questions, "%s/%s : %[^\n] ", attribute, reponse, file_contents) != EOF){
		printf("> %s : %s/%s\n", file_contents, attribute, reponse);
	}
	
	fclose(fichier_questions);
    return fileQuestion;
}

char recupQuestion(File_Questions* fileQuestion){
    char strQuestion[128];

	

    return strQuestion;
}