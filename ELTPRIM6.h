#ifndef ELTPRIM6_H_INCLUDED
#define ELTPRIM6_H_INCLUDED
#include "ELTSDD6.h"

ELEMENT6 element6Creer() ;
void element6Lire(ELEMENT6*);
void element6Detruire (ELEMENT6);
void element6Afficher(ELEMENT6);
void element6Affecter(ELEMENT6*, ELEMENT6);
void element6Copier(ELEMENT6 *, ELEMENT6) ;
int element6Comparer(ELEMENT6, ELEMENT6);



#endif // ELTPRIM6_H_INCLUDED
