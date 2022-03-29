cmake_minimum_required(VERSION 3.21)
project(Projet_1___Akinator C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_1___Akinator src/main.c include/fonctions_utilitaires.h src/fonctions_utilitaires.c src/gestion_BDD.c include/gestion_BDD.h src/gestion_fichiers.c include/gestion_fichiers.h src/gestion_listes.c include/gestion_listes.h include/librairies.h include/structs_donnees.h)
