/*AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <unistd.h>

#define DELTA 1000000L

void Updatecard(int nbcartesX, int nbcartesY, int x, int y, int* randcard, int* clique, int* cliqueposx, int* cliqueposy, int* score); /*Retourne une carte de sa face cachée à sa face découverte*/
void Cheatmode(int nbcartesX, int nbcartesY, int x, int y); /*Active le cheatmode*/
