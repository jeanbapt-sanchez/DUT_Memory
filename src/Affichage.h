/*AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

void Menu(void);  /*Affiche le Menu Principal*/
int Selection(void);  /*Permet de gérer la selection des boutons de difficultés*/
int* Grid(int nbcartesX, int nbcartesY, int x, int y); /*Affiche une grille de jeu de nbcartesX * nbcartesY*/
