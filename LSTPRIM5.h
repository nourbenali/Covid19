#ifndef LSTPRIM5_H_INCLUDED
#define LSTPRIM5_H_INCLUDED
#include "LSTSDD5.h"

LISTE_PATHOP liste5Creer(void);

void liste5Detruire(LISTE_PATHOP);

int est5Vide(LISTE_PATHOP);

int est5Saturee(LISTE_PATHOP);

int liste5Taille(LISTE_PATHOP);

ELEMENT3 recuperer5(LISTE_PATHOP, int);

int inserer5(LISTE_PATHOP, ELEMENT3,int);

int supprimer5(LISTE_PATHOP, int);

void liste5Afficher(LISTE_PATHOP);

LISTE_PATHOP liste5Copier(LISTE_PATHOP);

int  liste5Comparer(LISTE_PATHOP, LISTE_PATHOP);


#endif // LSTPRIM5_H_INCLUDED
