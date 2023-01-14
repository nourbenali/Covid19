#ifndef LSTPRIM7_H_INCLUDED
#define LSTPRIM7_H_INCLUDED
#include "LSTSDD7.h"

LISTE_LIEU liste7Creer(void);

void liste7Detruire(LISTE_LIEU);

int est7Vide(LISTE_LIEU);

int est7Saturee(LISTE_LIEU);

int liste7Taille(LISTE_LIEU);

ELEMENT7 recuperer7(LISTE_LIEU, int);

int inserer7(LISTE_LIEU, ELEMENT7,int);

int supprimer7(LISTE_LIEU, int);

void liste7Afficher(LISTE_LIEU);

LISTE_LIEU liste7Copier(LISTE_LIEU);

int  liste7Comparer(LISTE_LIEU, LISTE_LIEU);



#endif // LSTPRIM7_H_INCLUDED
