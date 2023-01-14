#ifndef LSTPRIM9_H_INCLUDED
#define LSTPRIM9_H_INCLUDED
#include "ELTPRIM9.h"
#include "LSTSDD9.h"

LISTE_DON liste9Creer(void);

void liste9Detruire(LISTE_DON);

int est9Vide(LISTE_DON);

int est9Saturee(LISTE_DON);

int liste9Taille(LISTE_DON);

ELEMENT9 recuperer9(LISTE_DON, int);

int inserer9(LISTE_DON, ELEMENT9,int);

int supprimer9(LISTE_DON, int);

void liste9Afficher(LISTE_DON);

LISTE_DON liste9Copier(LISTE_DON);

int  liste9Comparer(LISTE_DON, LISTE_DON);



#endif // LSTPRIM9_H_INCLUDED
