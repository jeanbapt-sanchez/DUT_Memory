/*AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "Affichage.h"
#include "Gestion.h"

#define TX 1200
#define TY 800
#define DELTA 1000000L

const int MARGINX[3]={400, 350, 300};
const int MARGINY[3]={275, 225, 175};

int main (void)
{
  int evenement = 0;
  unsigned int nbcartesX,nbcartesY,x,y,difficulte;
  int* randcard;
  int clique = 0;
  int cliqueposx = 0;
  int cliqueposy = 0;
  int score = 0;

  int seconde = 0;
  char time[100];
  unsigned long suivant = Microsecondes() + DELTA;

  /*Ouvre un graphique puis une fenetre avec son positionnement et ses dimensions en parametres*/
  InitialiserGraphique();
  CreerFenetre(350,350,TX,TY);

  /*Charge sur les écrans le fond à calquer pour que les copies de zones affichent correctement les modifications avec le fond d'écran général*/
  /*Ecran du timer*/
  ChoisirEcran(1);
  ChargerImageFond("./IMAGE/FOND.png");
  /*Ecran cartes faces decouvertes*/
  ChoisirEcran(2);
  ChargerImageFond("./IMAGE/FOND.png");
  /*Ecran cartes faces cachees*/
  ChoisirEcran(3);
  ChargerImageFond("./IMAGE/FOND.png");
  /*Texte pour cheatmode*/
  ChoisirEcran(4);
  ChargerImageFond("./IMAGE/CHEATMODE.png");

  /*Affichage du Menu*/
  Menu();
  /*Affichage des sous menu et renvoie une valeur de choix de diffculté*/
  difficulte = Selection();

  /*En fonction de la difficulte on donne des positions différentes à la grille et des marges différentes*/
  if (difficulte == 0)
  {
    evenement = 1;
  }

  if (difficulte == 1)
  {
    nbcartesX = 5;
    nbcartesY = 4;
    x = MARGINX[0];
    y = MARGINY[0];
    randcard = Grid(nbcartesX,nbcartesY,x,y);
  }

  if (difficulte == 2)
  {
    nbcartesX = 6;
    nbcartesY = 5;
    x = MARGINX[1];
    y = MARGINY[1];
    randcard = Grid(nbcartesX,nbcartesY,x,y);
  }

  if (difficulte == 3)
  {
    nbcartesX = 7;
    nbcartesY = 6;
    x = MARGINX[2];
    y = MARGINY[2];
    randcard = Grid(nbcartesX,nbcartesY,x,y);
  }

  /*Début d'une nouvelle partie*/
  while (evenement == 0)
  {
    Cheatmode(nbcartesX,nbcartesY,x,y);
    Updatecard(nbcartesX,nbcartesY,x,y,randcard, &clique, &cliqueposx, &cliqueposy, &score);

    if (Microsecondes() > suivant)
    {
      CopierZone(1,0,0,0,1200,70,0,0);
      ChoisirEcran(0);
      snprintf(time,100,"TIME : %5d",seconde);
      EcrireTexte(70,70,time,1);
      seconde++;
      suivant = Microsecondes() + DELTA;
    }

    if(score == (nbcartesX * nbcartesY) / 2 )
    {
    	ChargerImageFond("./IMAGE/FINAL.png");
    	evenement = 1;
    }
  }

  free(randcard);
  Touche();
  FermerGraphique();

  return EXIT_SUCCESS;
}
