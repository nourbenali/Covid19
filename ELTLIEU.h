#ifndef ELTLIEU_H_INCLUDED
#define ELTLIEU_H_INCLUDED

#include "LSTPERLIEU.h"
#include "LSTPRIM8.h"
#include "LSTPRIM6.h"
typedef struct
{
   char nom[100];
    char adr[100];
    int gouvernorat;
    int code_postal;
    int capacite;

    LISTE_PERLIEU per_lieu ;
}LIEU , *ELEMENT7;

#endif // ELTLIEU_H_INCLUDED
