/*AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas*/

#include "Affichage.h"

void Menu(void)
{
  ChoisirEcran(0);
  ChargerImageFond("./IMAGE/MENU.png");
  ChoisirCouleurDessin(CouleurParNom("orange"));
}

int Selection(void)
{
  int evenement = 0;
  int difficulte;

  /*Boutons JOUER et INFO*/
  while (evenement == 0)
  {
    if (SourisCliquee())
    {
      if ((_X >= 535) && (_X <= 685) && (_Y >= 345) && (_Y <= 425))
      {
        evenement = 1;
      }

      else if ((_X >= 535) && (_X <= 685) && (_Y >= 490) && (_Y <= 570))
      {
        evenement = 2;
      }
    }
  }

  /*Affichage et gestion de la selection de la difficulte si on a appuyer sur JOUER*/
  if (evenement == 1)
  {
    evenement = 0;
    ChargerImageFond("./IMAGE/JOUER.png");

    while (evenement == 0)
    {
      if (SourisCliquee())
      {
        if ((_X >= 460) && (_X <= 725) && (_Y >= 310) && (_Y <= 345))
        {
          evenement = 1;
        }

        else if ((_X >= 460) && (_X <= 725) && (_Y >= 385) && (_Y <= 415))
        {
          evenement = 2;
        }

        else if ((_X >= 410) && (_X <= 780) && (_Y >= 460) && (_Y <= 490))
        {
          evenement = 3;
        }
      }
    }

    if (evenement == 1)
    {
      evenement = 0;
      difficulte = 1;
      return difficulte;
    }

    else if (evenement == 2)
    {
      evenement = 0;
      difficulte = 2;
      return difficulte;
    }

    else if (evenement == 3)
    {
      evenement = 0;
      difficulte = 3;
      return difficulte;
    }
  }

  /*Affichage des informations du jeu si on appuie sur INFO*/
  else if (evenement == 2)
  {
    difficulte = 0;
    ChargerImageFond("./IMAGE/INFO.png");
  }
}

int* Grid(int nbcartesX, int nbcartesY, int x, int y)
{
  int ligne,colonne;
  int x2 = x, y2 = y;
  srand(time(NULL));
  int i, j;
  int nbpaire = nbcartesX * nbcartesY, nbsprite = nbpaire / 2, MAX = nbpaire, MIN = 0;

  int* randcard;
  randcard = malloc(nbpaire * sizeof(int));

  int sprite[21] =
  {
    ChargerSprite("./IMAGE/Image1.png"),
    ChargerSprite("./IMAGE/Image2.png"),
    ChargerSprite("./IMAGE/Image3.png"),
    ChargerSprite("./IMAGE/Image4.png"),
    ChargerSprite("./IMAGE/Image5.png"),
    ChargerSprite("./IMAGE/Image6.png"),
    ChargerSprite("./IMAGE/Image7.png"),
    ChargerSprite("./IMAGE/Image8.png"),
    ChargerSprite("./IMAGE/Image9.png"),
    ChargerSprite("./IMAGE/Image10.png"),
    ChargerSprite("./IMAGE/Image11.png"),
    ChargerSprite("./IMAGE/Image12.png"),
    ChargerSprite("./IMAGE/Image13.png"),
    ChargerSprite("./IMAGE/Image14.png"),
    ChargerSprite("./IMAGE/Image15.png"),
    ChargerSprite("./IMAGE/Image16.png"),
    ChargerSprite("./IMAGE/Image17.png"),
    ChargerSprite("./IMAGE/Image18.png"),
    ChargerSprite("./IMAGE/Image19.png"),
    ChargerSprite("./IMAGE/Image20.png"),
    ChargerSprite("./IMAGE/Image21.png")
  };

  ChargerImageFond("./IMAGE/FOND.png");

  /*Melanger et affiche la grille en fonction du nombre de paire correspondant à la difficulte*/

  for(i = 0; i < nbpaire; i++)
  {
      randcard[i] = 0;
  }

  for (i = 0; i < nbsprite; i++)
  {
    int card = sprite[i];
    for(j = 0; j < 2;)
    {
      int idcard = (rand() % (MAX - MIN) + MIN);
      if(randcard[idcard] == 0)
      {
        randcard[idcard] = card;
        j++;
      }
    }
  }

  for (colonne = 0, y = y2, i = 0; colonne < nbcartesY; colonne++)
  {
    for (ligne = 0, x = x2; ligne < nbcartesX; ligne++)
    {
      /*Je place mes cartes faces cachées sur l'écran principal*/
      ChoisirEcran(0);
      DessinerRectangle(x,y,50,50);

      /*Je place mes cartes faces cachées sur un l'écran 3 afin de pouvoir remettre des cartes faces cachées si changement sur l'écran principal*/
      ChoisirEcran(3);
      DessinerRectangle(x,y,50,50);

      /*Je place mes cartes faces découvertes sur l'écran 2*/
      ChoisirEcran(2);
      AfficherSprite(randcard[i],x,y);

      x = x + 90;
      i++;
    }
    y = y + 90;
  }
  return randcard;
}
