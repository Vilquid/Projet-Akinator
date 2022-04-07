cmake_minimum_required(VERSION 3.21)
project(Akinator)

set(CMAKE_C_STANDARD 23)

add_executable(Akinator include/main.h src/main.c include/fonctions_utilitaires.h src/fonctions_utilitaires.c src/gestion_BDD.c include/gestion_BDD.h src/gestion_fichiers.c include/gestion_fichiers.h src/gestion_listes.c include/gestion_listes.h src/jeu.c include/jeu.h include/librairies.h include/structs_donnees.h)
