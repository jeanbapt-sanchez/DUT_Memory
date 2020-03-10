#AUTEUR : Jean-Baptiste Sanchez et Maxence Cramaregeas

CC=gcc
ARGS=-lgraph -g
EXEC=Memory

Memory: Main.o Affichage.o Gestion.o
		$(CC) -o Memory Main.o Affichage.o Gestion.o $(ARGS)

Gestion: Gestion.o Affichage.o Main.o
		$(CC) -o Gestion Gestion.o Affichage.o Main.o $(ARGS)

Gestion.o: Gestion.c
		$(CC) -o Gestion.o -c Gestion.c $(ARGS)

Affichage: Affichage.o Gestion .o Main.o
		$(CC) -o Affichage Affichage.o Gestion.o Main.o $(ARGS)

Affichage.o: Affichage.c
		$(CC) -o Affichage.o -c Affichage.c $(ARGS)

Main.o: Main.c Affichage.h Gestion.h
		$(CC) -o Main.o -c Main.c $(ARGS)

run :
	./$(EXEC)

./ : run
		./$(EXEC)

clean:
		rm -rf *.o

rm: clean
		rm -rf $(EXEC)
