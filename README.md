# Memory
- **Auteurs :** *Jean-Baptiste Sanchez*, *Maxence Cramaregeas*
- **Licence :** *MIT Licence*

Ce projet est le résultat d'un travail en binôme réalisé en 2018 par Jean-Baptiste Sanchez et Maxence Cramaregeas.
Le sujet a été donné en tant que Projet Tutoré de semestre 1 dans la matière APL (Algorithmie Programmation et Langage) dans le cadre de la formation du DUT Informatique.

## Table des matières
- Lancement du Memory
- Détails du projet
  - Qu'est-ce que le jeu du Memory ?
  - Fonctionnalités demandées
- Bibliothèque Graphique
  - Présentation
  - Installation
  - Utilisation

## Lancement du Memory
> **Important:** Pour lancer le Memory il faut installer la bibliothèque graphique. Si cela n'a pas été fait il faut alors suivre les instructions du manuel dans la partie *Bibliothèque Graphique*

Téléchargez le dépôt puis dans un terminal depuis le dépôt Git allez dans `./src/` pour accéder aux fichiers sources du jeu. Vous y retrouverez un fichier `Makefile`. Il a été écrit pour permettre de compiler, de lancer l'application ainsi que de nettoyer les fichiers du jeu.

>**Commandes à inscrire au terminal pour utiliser le projet :**
- `make` permet de compiler les fichiers du jeu
- `make run` permet de lancer le jeu compilé
- `make clean` permet de supprimer tous les fichiers intermédiaires du jeu compilé
- `make rm` permet de supprimer tous les fichiers qui peuvent être régénérés afin de reconstruire le projet

## Détails du projet
### Qu'est-ce que le jeu du Memory ?
C'est un jeu de cartes se jouant généralement seul. Parmi un lot de cartes disposé sur le terrain face cachée, le but est de trouver les paires d'images. Le joueur doit donc choisir deux cartes voir si ce sont les mêmes et les remettre face cachée en cas d'erreur. C'est un jeu de mémorisation.

### Fonctionnalités demandées
- makefile
- jeu fonctionnel respectant les règles du jeu
- plusieurs difficulté de grille
- terrain bien distribué aléatoirement
- un menu
- un cheatmode permettant de dévoiler les cartes suite à une pression de la touche t
- un timer correspondant au score du joueur


## Bibliothèque Graphique
### Présentation
Cette bibliothèque, écrite en C, est construite directement sur la couche XLib. Elle fournit des primitives de dessins très rudimentaires. Son seul intérêt est de pouvoir écrire des applications graphiques sans avoir à connaître le fonctionnement et l'API de la couche X11. Elle est évidemment (très) perfectible.

Afin d'uniformiser le nom des fonctions et de rendre plus facile l'écriture de programmes, la bibliothèque adopte la convention suivante pour le nommage des fonctions :

- La première lettre est une majuscule.
- Si le nom de la fonction est composé de plusieurs mots, chaque mot commence lui-même par une majuscule.

Par exemple :
> DessinerSegment

### Installation

Récupérez l'archive. Après avoir désarchiver, lancer le script configure pour préparer la compilation et l'installation :

`./configure --prefix=/usr --disable-exemples`

`--prefix` permet de choisir le répertoire d'installation. `--enable/--disable-exemples` permet de construire ou non la librairie avec des exemples. (ExempleMandelbrot,ExempleSouris, ExempleGraphique, ExempleSprite). `--enable/--disable-xpm` permet ou non le support des images de format xpm.
Faire configure `--help` pour avoir la liste de toutes les options.

> **Important :** La librairie dépend de la librairie X11 qui doit être installée préalablement et optionnellement de la librairie XPM.

1. Lancez la commande `make` pour la compilation et `make install` pour l'installation.
2. Lancez `make uninstall` pour la désinstallation.


### Utilisation

- Le seul header à include dans votre programme est
`graph.h`
- A la compilation, rajouter `-lgraph`.
Voici un exemple :

```
#include<stdlib.h>
#include<graph.h>

int main()
{
    InitialiserGraphique();
    CreerFenetre(10,10,500,500);
    EcrireTexte(10,100,"Hello World !",2);
    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}
```

`gcc -o hello_world hello_world.c -lgraph`

> **Remarque :** Si le répertoire d'installation n'est pas standard, il faudra rajouter à la ligne de compilation les répertoires pour le header et la bibliothèque :

`gcc -o hello_world hello_world.c -lgraph -I/repertoire/vers/include -L/repertoire/vers/lib`
