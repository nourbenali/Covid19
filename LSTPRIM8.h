#ifndef LSTPRIM8_H_INCLUDED
#define LSTPRIM8_H_INCLUDED
#include "LSTSDD8.h"

LISTE_PERLIEU liste8Creer(void);

void liste8Detruire(LISTE_PERLIEU);

int est8Vide(LISTE_PERLIEU);

int est8Saturee(LISTE_PERLIEU);

int liste8Taille(LISTE_PERLIEU);

ELEMENT6 recuperer8(LISTE_PERLIEU, int);

int inserer8(LISTE_PERLIEU, ELEMENT6,int);

int supprimer8(LISTE_PERLIEU, int);

void liste8Afficher(LISTE_PERLIEU);

LISTE_PERLIEU liste8Copier(LISTE_PERLIEU);

int  liste8Comparer(LISTE_PERLIEU, LISTE_PERLIEU);


#endif // LSTPRIM8_H_INCLUDED
