#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include "ELTPERSONNE.h"
#include "ELTPRIM2.h"

ELEMENT2 element2Creer()
{
    ELEMENT2 elt=(ELEMENT2)malloc(sizeof(PERSONNE));
    /*elt->age=0;
    strcpy(elt->adr,"");
    strcpy(elt->nom,"");
    strcpy(elt->prenom,"");*/
    return (elt);

}

void element2Lire(ELEMENT2 * e)
{
     fflush(stdin);
     printf("Donnez le nom : ");
     gets((*e)->nom);
     fflush(stdin);
     printf("Donner le prenom : ");
     gets((*e)->prenom);
     fflush(stdin);
     printf("Donner l'adresse : ");
     gets((*e)->adr);
     printf("Donner l'age : ");
     scanf("%d",&((*e)->age));
     printf("A quel pays elle appartient ? Tapez 1 si la tunisie, 2 si la france,3 si italie, 4 si espagne et 5 si egypte ");
     do{
     scanf("%d",&((*e)->code_pays));
     } while(((*e)->code_pays<1)||((*e)->code_pays>5));

}

void element2Afficher(ELEMENT2 e)
{
     printf("nom : %s, prenom : %s, adresse : %s, age : %d  ",e->nom,e->prenom,e->adr,e->age);
     switch (e->code_pays)
     {
         case 1 : printf("il vient de la tunisie");
                  break;
         case 2 : printf("il vient de la france");
                  break;
         case 3 : printf("il vient de l italie");
                  break;
         case 4 : printf("il vient de l espagne");
                  break;
         case 5 : printf("il vient de l egypte ");
                  break;

     }
     printf("\n");
}

void element2Detruire(ELEMENT2 e)
{
   free(e);
}

void element2Affecter(ELEMENT2* e1, ELEMENT2 e2)
{
     *e1=e2;
}

void element2Copier(ELEMENT2 * e1, ELEMENT2 e2)
{

    strcpy((*e1)->nom, e2->nom);
    strcpy((*e1)->prenom,e2->prenom);
    strcpy((*e1)->adr,e2->adr);
    (*e1)->age=e2->age;
}

int element2Comparer(ELEMENT2 e1, ELEMENT2 e2)
{
    if ((strcmp(e1->nom,e2->nom)==0)&& (strcmp(e1->prenom,e2->prenom)==0)&& (strcmp(e1->adr,e2->adr)==0)&& (e1->age == e2->age))  return 1;
     else return 0;
}
