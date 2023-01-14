#ifndef LSTPRIM2_H_INCLUDED
#define LSTPRIM2_H_INCLUDED
#include "ELTPRIM2.h"
#include "LSTSDD2.h"

LISTE_PERSONNE liste2Creer(void);

void liste2Detruire(LISTE_PERSONNE);

int est2Vide(LISTE_PERSONNE);

int est2Saturee(LISTE_PERSONNE);

int liste2Taille(LISTE_PERSONNE);

ELEMENT2 recuperer2(LISTE_PERSONNE, int);

int inserer2(LISTE_PERSONNE, ELEMENT2,int);

int supprimer2(LISTE_PERSONNE, int);

void liste2Afficher(LISTE_PERSONNE);

LISTE_PERSONNE liste2Copier(LISTE_PERSONNE);

int  liste2Comparer(LISTE_PERSONNE, LISTE_PERSONNE);


#endif // LSTPRIM2_H_INCLUDED
