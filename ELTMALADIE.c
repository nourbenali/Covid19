#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include"ELTMALADIE.h"
#include "ELTPRIM1.h"

ELEMENT1 element1Creer()
{
   ELEMENT1 e=(ELEMENT1)malloc(sizeof(malade));
  // if (!e){ printf("memoire insuffisante"); }
 //  strcpy(e->mal,"");
   return e;
}

void element1Lire(ELEMENT1 * e)
{

         fflush(stdin);
         gets((*e)->mal);

}

void element1Afficher(ELEMENT1 e)
{
     printf("%s",e->mal);
}

void element1Detruire(ELEMENT1 e)
{
    free(e);
}

void element1Affecter(ELEMENT1* e1, ELEMENT1 e2)
{
     *e1=e2;
}

void element1Copier(ELEMENT1 * e1, ELEMENT1 e2)
{
   memcpy(*e1,e2,sizeof(malade));
}

int element1Comparer(ELEMENT1 e1, ELEMENT1 e2)
{
    if (strcmp(e1->mal,e2->mal)==0) return 1;
     else return 0;
}
