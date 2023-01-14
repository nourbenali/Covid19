#ifndef ELTPRIM3_H_INCLUDED
#define ELTPRIM3_H_INCLUDED
#include "ELTSDD3.h"

ELEMENT3 element3Creer() ;
void element3Lire(ELEMENT3*);
void element3Detruire (ELEMENT3);
void element3Afficher(ELEMENT3);
void element3Affecter(ELEMENT3*, ELEMENT3);
void element3Copier(ELEMENT3 *, ELEMENT3) ;
int element3Comparer(ELEMENT3, ELEMENT3);


#endif // ELTPRIM3_H_INCLUDED
