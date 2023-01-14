#ifndef ELTPRIM2_H_INCLUDED
#define ELTPRIM2_H_INCLUDED
#include "ELTSDD2.h"

ELEMENT2 element2Creer() ;
void element2Lire(ELEMENT2*);
void element2Detruire (ELEMENT2);
void element2Afficher(ELEMENT2);
void element2Affecter(ELEMENT2*, ELEMENT2);
void element2Copier(ELEMENT2 *, ELEMENT2) ;
int element2Comparer(ELEMENT2, ELEMENT2);



#endif // ELTPRIM2_H_INCLUDED
