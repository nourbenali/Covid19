#ifndef ELTPRIM10_H_INCLUDED
#define ELTPRIM10_H_INCLUDED

#include "ELTSDD10.h"

ELEMENT10 element10Creer() ;
void element10Lire(ELEMENT10*);
void element10Detruire (ELEMENT10);
void element10Afficher(ELEMENT10);
void element10Affecter(ELEMENT10*, ELEMENT10);
void element10Copier(ELEMENT10 *, ELEMENT10) ;
int element10Comparer(ELEMENT10, ELEMENT10);

#endif // ELTPRIM10_H_INCLUDED
