#ifndef ELTPRIM7_H_INCLUDED
#define ELTPRIM7_H_INCLUDED
#include "ELTSDD7.h"

ELEMENT7 element7Creer() ;
void element7Lire(ELEMENT7*);
void element7Detruire (ELEMENT7);
void element7Afficher(ELEMENT7);
void element7Affecter(ELEMENT7*, ELEMENT7);
void element7Copier(ELEMENT7*, ELEMENT7) ;
int element7Comparer(ELEMENT7, ELEMENT7);


#endif // ELTPRIM7_H_INCLUDED
