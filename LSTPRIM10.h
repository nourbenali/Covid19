#ifndef LSTPRIM10_H_INCLUDED
#define LSTPRIM10_H_INCLUDED
#include "ELTPRIM10.h"
#include "LSTSDD10.h"

LISTE_PHARMACIE liste10Creer(void);

void liste10Detruire(LISTE_PHARMACIE);

int est10Vide(LISTE_PHARMACIE);

int est10Saturee(LISTE_PHARMACIE);

int liste10Taille(LISTE_PHARMACIE);

ELEMENT10 recuperer10(LISTE_PHARMACIE, int);

int inserer10(LISTE_PHARMACIE, ELEMENT10,int);

int supprimer10(LISTE_PHARMACIE, int);

void liste10Afficher(LISTE_PHARMACIE);

LISTE_PHARMACIE liste10Copier(LISTE_PHARMACIE);

int  liste10Comparer(LISTE_PHARMACIE, LISTE_PHARMACIE);


#endif // LSTPRIM10_H_INCLUDED
