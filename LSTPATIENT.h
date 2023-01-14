#ifndef LSTPATIENT_H_INCLUDED
#define LSTPATIENT_H_INCLUDED
#include "ELTPRIM3.h"
#include "ELTPATIENT.h"

typedef struct structNoeud1 { ELEMENT3 info ; struct structNoeud1 * suivant ; struct structNoeud1 * precedent ;

                          }structNoeud1, *NOEUD1;

typedef struct { NOEUD1 tete; NOEUD1 queuee; int lg ; } LSTPAT, *LISTE_PATIENT;


#endif // LSTPATIENT_H_INCLUDED
