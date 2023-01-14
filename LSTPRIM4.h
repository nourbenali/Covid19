#ifndef LSTPRIM4_H_INCLUDED
#define LSTPRIM4_H_INCLUDED
#include "LSTSDD4.h"

LISTE_HOPITAL liste4Creer(void);

void liste4Detruire(LISTE_HOPITAL);

int est4Vide(LISTE_HOPITAL);

int est4Saturee(LISTE_HOPITAL);

int liste4Taille(LISTE_HOPITAL);

ELEMENT4 recuperer4(LISTE_HOPITAL, int);

int inserer4(LISTE_HOPITAL, ELEMENT4,int);

int supprimer4(LISTE_HOPITAL, int);

void liste4Afficher(LISTE_HOPITAL);

LISTE_HOPITAL liste4Copier(LISTE_HOPITAL);

int  liste4Comparer(LISTE_HOPITAL, LISTE_HOPITAL);


#endif // LSTPRIM4_H_INCLUDED
