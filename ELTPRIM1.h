#ifndef ELTPRIM1_H_INCLUDED
#define ELTPRIM1_H_INCLUDED
#include "ELTSDD1.h"

ELEMENT1 element1Creer() ;
void element1Lire(ELEMENT1*);
void element1Detruire (ELEMENT1);
void element1Afficher(ELEMENT1);
void element1Affecter(ELEMENT1*, ELEMENT1);
void element1Copier(ELEMENT1 *, ELEMENT1) ;
int element1Comparer(ELEMENT1, ELEMENT1);



#endif // ELTPRIM1_H_INCLUDED
