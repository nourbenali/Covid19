#ifndef ELTPRIM9_H_INCLUDED
#define ELTPRIM9_H_INCLUDED
#include "ELTSDD9.h"

ELEMENT9 element9Creer() ;
void element9Lire(ELEMENT9*);
void element9Detruire (ELEMENT9);
void element9Afficher(ELEMENT9);
void element9Affecter(ELEMENT9*, ELEMENT9);
void element9Copier(ELEMENT9*, ELEMENT9) ;
int element9Comparer(ELEMENT9, ELEMENT9);



#endif // ELTPRIM9_H_INCLUDED
