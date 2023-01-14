#ifndef LSTPRIM1_H_INCLUDED
#define LSTPRIM1_H_INCLUDED

#include "ELTPRIM1.h"
#include "LSTSDD1.h"

LISTE_MALADIE liste1Creer(void);

void liste1Detruire(LISTE_MALADIE);

int est1Vide(LISTE_MALADIE);

int est1Saturee(LISTE_MALADIE);

int liste1Taille(LISTE_MALADIE);

ELEMENT1 recuperer1(LISTE_MALADIE, int);

int inserer1(LISTE_MALADIE, ELEMENT1,int);

int supprimer1(LISTE_MALADIE, int);

void liste1Afficher(LISTE_MALADIE);

LISTE_MALADIE liste1Copier(LISTE_MALADIE);

int  liste1Comparer(LISTE_MALADIE, LISTE_MALADIE);

#endif // LSTPRIM1_H_INCLUDED
