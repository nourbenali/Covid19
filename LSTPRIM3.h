#ifndef LSTPRIM3_H_INCLUDED
#define LSTPRIM3_H_INCLUDED
#include "LSTSDD3.h"
NOEUD1 noeud1Creer(ELEMENT3 );
void noeud1Detruire(NOEUD1 );
LISTE_PATIENT liste3Creer(void);
void liste3Detruire(LISTE_PATIENT );
void liste3Afficher(LISTE_PATIENT );
int est3Vide(LISTE_PATIENT );
int est3Saturee(LISTE_PATIENT );
int liste3Taille(LISTE_PATIENT );
void inserer3 (LISTE_PATIENT , ELEMENT3 , int );
int supprimer3 (LISTE_PATIENT , int );
ELEMENT3 recuperer3(LISTE_PATIENT , int );
LISTE_PATIENT liste3Copier(LISTE_PATIENT );
int  liste3Comparer (LISTE_PATIENT ,LISTE_PATIENT );



#endif // LSTPRIM3_H_INCLUDED
