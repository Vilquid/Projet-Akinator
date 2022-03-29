cmake_minimum_required(VERSION 3.21)
project(Projet_1___Akinator C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_1___Akinator src/main.c include/structs-functions.h src/structs-functions.c include/structs-functions.h src/gestion_BDD.c include/gestion_BDD.h)
