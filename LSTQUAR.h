#ifndef LSTQUAR_H_INCLUDED
#define LSTQUAR_H_INCLUDED

#include "ELTPRIM6.h"
#include "ELTQUAR.h"

typedef struct structNoeud2 { ELEMENT6 info ; struct structNoeud2 * suivant ; struct structNoeud2 * precedent ;

                          }structNoeud2, *NOEUD2;

typedef struct { NOEUD2 tete; NOEUD2 queuee; int lg ; } LSTQUARANTAINE, *LISTE_QUARANTAINE;

#endif // LSTQUAR_H_INCLUDED
