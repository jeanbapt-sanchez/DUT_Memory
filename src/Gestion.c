/*AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas*/

#include "Gestion.h"

void Updatecard(int nbcartesX, int nbcartesY, int x, int y, int* randcard, int* clique, int* cliqueposx, int* cliqueposy, int* score)
{
    int ligne, colonne;
    int x2 = x, y2 = y;
    int i = 0;

    if (SourisCliquee())
    {
        for (colonne = 0, y = y2; colonne < nbcartesY; colonne++)
        {
            for (ligne = 0, x = x2; ligne < nbcartesX; ligne++, i++)
            {
                if ((_X >= x) && (_X <= x + 50) && (_Y >= y ) && (_Y <= y + 50))
                {
                    CopierZone(2,0,x,y,60,60,x,y);

                    /*Premier clic*/
                    if(*clique == 0)
                    {
                      printf("clique = %d\n",*clique);
                      printf("\ncarte n°= %d\n",randcard[i]);
                      *clique = randcard[i];
                      *cliqueposx = x;
                      *cliqueposy = y;
                      printf("\nclique = %d\n",*clique);
                    }
                    /*Deuxieme clic*/
                    else if (*cliqueposx != x || *cliqueposy != y)
                    {
                      if (*clique == randcard[i])
                      {
                        *score = *score + 1;
                        printf("Bien Joué : score + 1 = %d \n", *score);
                        *clique = 0;
                      }

                      else
                      {
                        sleep(1);
                        *clique = 0;
                        CopierZone(3,0,x,y,60,60,*cliqueposx,*cliqueposy);
                        CopierZone(3,0,x,y,60,60,x,y);
                      }
                    }
                }
                x = x + 90;
            }
            y = y + 90;
        }
    }
}


void Cheatmode(int nbcartesX, int nbcartesY, int x, int y)
{
  int cheat = 0;
  int ligne, colonne;
  int x2 = x, y2 = y;

  if (ToucheEnAttente() && Touche() == XK_t && cheat == 0)
  {
      CopierZone(0,3,0,0,1200,800,0,0);
      CopierZone(4,0,205,116,1200,800,205,116);
      for (colonne = 0, y = y2; colonne < nbcartesY; colonne++)
      {
          for (ligne = 0, x = x2; ligne < nbcartesX; ligne++)
          {
              CopierZone(2,0,x,y,60,60,x,y);
              x = x + 90;
          }
          y = y + 90;
      }

      if (Touche() == XK_t)
      {
        CopierZone(3,0,0,0,1200,800,0,0);
        cheat = 1;
      }
  }
}
