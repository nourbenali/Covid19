#ifndef ELTPRIM4_H_INCLUDED
#define ELTPRIM4_H_INCLUDED
#include "ELTSDD4.h"


ELEMENT4 element4Creer() ;
void element4Lire(ELEMENT4*);
void element4Detruire (ELEMENT4);
void element4Afficher(ELEMENT4);
void element4Affecter(ELEMENT4*, ELEMENT4);
void element4Copier(ELEMENT4 *, ELEMENT4) ;
int element4Comparer(ELEMENT4, ELEMENT4);



#endif // ELTPRIM4_H_INCLUDED
