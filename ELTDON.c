#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include "ELTDON.h"
#include "ELTPRIM9.h"

ELEMENT9 element9Creer()
{
    ELEMENT9 elt=(ELEMENT9)malloc(sizeof(DON));
    /*elt->age=0;
    strcpy(elt->adr,"");
    strcpy(elt->nom,"");
    strcpy(elt->prenom,"");*/
    return (elt);

}

void element9Lire(ELEMENT9 * e)
{

    do{
     printf("Donnez la nature : tapez 0 si espece et 1 sinon ");
     scanf("%d",&((*e)->nature));
    } while(((*e)->nature!=0)&& ((*e)->nature !=1));

     if ((*e)->nature == 0)
            {
               printf("Combien : ");
                 scanf("%d",&((*e)->esp));
            }
     else {printf("quoi");
            fflush(stdin);
           gets((*e)->besoin);}

}

void element9Afficher(ELEMENT9 e)
{
     if (e->nature==0)
     {
         printf("%d",e->esp);
     }
     else printf("%s",e->besoin);
}

void element9Detruire(ELEMENT9 e)
{
   free(e);
}

void element9Affecter(ELEMENT9* e1, ELEMENT9 e2)
{
     *e1=e2;
}

void element9Copier(ELEMENT9 * e1, ELEMENT9 e2)
{

   memcpy(*e1,e2,sizeof(DON));
}

int element9Comparer(ELEMENT9 e1, ELEMENT9 e2)
{
    if ( (e1->nature == e2->nature)&&( e1->esp == e2->esp )&&( strcmp(e1->besoin , e2->besoin)==0 ) ) return 1;

     else return 0;
}
