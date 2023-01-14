#ifndef LSTPRIM6_H_INCLUDED
#define LSTPRIM6_H_INCLUDED
#include "LSTSDD6.h"
NOEUD2 noeud2Creer(ELEMENT6 );
void noeud2Detruire(NOEUD2 );
LISTE_QUARANTAINE liste6Creer(void);
void liste6Detruire(LISTE_QUARANTAINE);
void liste6Afficher(LISTE_QUARANTAINE );
int est6Vide(LISTE_QUARANTAINE );
int est6Saturee(LISTE_QUARANTAINE );
int liste6Taille(LISTE_QUARANTAINE );
void inserer6 (LISTE_QUARANTAINE , ELEMENT6 , int );
int supprimer6 (LISTE_QUARANTAINE , int );
ELEMENT6 recuperer6(LISTE_QUARANTAINE , int );
LISTE_QUARANTAINE liste6Copier(LISTE_QUARANTAINE );
int  liste6Comparer (LISTE_QUARANTAINE ,LISTE_QUARANTAINE );



#endif // LSTPRIM6_H_INCLUDED
