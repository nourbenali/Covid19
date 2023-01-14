#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include "ELTLIEU.h"
#include "ELTPRIM7.h"
#include "LSTPRIM8.h"
#include "LSTPERLIEU.h"


ELEMENT7 element7Creer()
{
    ELEMENT7 elt=(ELEMENT7)malloc(sizeof(LIEU));
    elt->per_lieu=liste8Creer();
/*    elt->age=0;
    strcpy(elt->adr,"");
    strcpy(elt->nom,"");
    strcpy(elt->prenom,"");*/
    return (elt);

}

void element7Lire(ELEMENT7 * e)
{    fflush(stdin);
      printf("Donner le nom : ");
     gets((*e)->nom);
     fflush(stdin);
     printf("Donner l'adresse : ");
     gets((*e)->adr);
    do{
     printf("Donner le code postal : ");
     scanf("%d",&((*e)->code_postal));
    }while(((*e)->code_postal <1000)|| ((*e)->code_postal >9999));
    do{
     printf("Donner le gouvernorat auquel appartient cet hopital sachant que : Ariana 12, Beja 31, Ben Arous 13, Bizert 23,Gabes 81,\nGafsa 71, Jendouba 32, Kairaouan 41, Kasserine 42, Kebili 73, Kef 33, Mahdia 53, La Manouba 14, Medenine 82,\n Monastir 52, Nabeul 21,Sfax 61, Sidi Bouzid 43, Siliana 34, Sousse 51, Tataouine 83, Tozeur 72, Tunis 11 et Zaghouan 22\n");

     scanf("%d",&((*e)->gouvernorat));
     }while( ((*e)->gouvernorat!=11)&&((*e)->gouvernorat!=12)&&((*e)->gouvernorat!=13)&&((*e)->gouvernorat!=14)&&((*e)->gouvernorat!=31)&&((*e)->gouvernorat!=23)&&((*e)->gouvernorat!=81)&&((*e)->gouvernorat!=71)&&((*e)->gouvernorat!=32)&&((*e)->gouvernorat!=41)&&((*e)->gouvernorat!=42)&&((*e)->gouvernorat!=73)&&((*e)->gouvernorat!=33)&&((*e)->gouvernorat!=53)&&((*e)->gouvernorat!=82)&&((*e)->gouvernorat!=52)&&((*e)->gouvernorat!=21)&&((*e)->gouvernorat!=61)&&((*e)->gouvernorat!=43)&&((*e)->gouvernorat!=34)&&((*e)->gouvernorat!=51)&&((*e)->gouvernorat!=83)&&((*e)->gouvernorat!=72)&&((*e)->gouvernorat!=22)  );

      printf("Donner la capacite du lieu : ");
     scanf("%d",&((*e)->capacite));


}

void element7Afficher(ELEMENT7 e)
{
     printf("nom : %s, adresse : %s, code postal : %d, capacite :%d  \n ",e->nom,e->adr,e->code_postal,e->capacite);
       switch(e->gouvernorat)
       {
           case 12 : printf("gouvernorat : Ariana ");
           break;
           case 31 : printf("gouvernorat : Beja ");
           break;
           case 13 : printf("gouvernorat : Ben Arous");
           break;
           case 23 : printf("gouvernorat : Bizerte ");
           break;
           case 81 : printf("gouvernorat : Gabes ");
           break;
           case 71 : printf("gouvernorat : Gafsa ");
           break;
           case 32 : printf("gouvernorat : Jendouba ");
           break;
           case 41 : printf("gouvernorat : Kairouan ");
           break;
           case 42 : printf("gouvernorat : Kasserine ");
           break;
           case 73 : printf("gouvernorat : Kebili ");
           break;
           case 33 : printf("gouvernorat : Kef ");
           break;
           case 53 : printf("gouvernorat : Mahdia ");
           break;
           case 14 : printf("gouvernorat : La Manouba ");
           break;
           case 82 : printf("gouvernorat : Medenine ");
           break;
           case 52 : printf("gouvernorat : Monastir ");
           break;
           case 21 : printf("gouvernorat : Nabeul ");
           break;
           case 61 : printf("gouvernorat : Sfax ");
           break;
           case 43 : printf("gouvernorat : Sidi Bouzid ");
           break;
           case 34 : printf("gouvernorat : Siliana ");
           break;
           case 51 : printf("gouvernorat : Sousse ");
           break;
           case 83 : printf("gouvernorat : Tataouine ");
           break;
           case 72 : printf("gouvernorat : Tozeur ");
           break;
           case 11 : printf("gouvernorat : Tunis ");
           break;
           case 22 : printf("gouvernorat : Zaghouan ");
           break;
       }
       printf("\n la liste des personnes qui y appartiennent : \n");
      liste8Afficher(e->per_lieu);
}

void element7Detruire(ELEMENT7 e)
{
   free(e);
}

void element7Affecter(ELEMENT7* e1, ELEMENT7 e2)
{
     *e1=e2;
}

void element7Copier(ELEMENT7 * e1, ELEMENT7 e2)
{
   memcpy(*e1,e2,sizeof(LIEU));
}

int element7Comparer(ELEMENT7 e1, ELEMENT7 e2)
{
    if (strcmp(e1->adr,e2->adr)==0)  return 1;
     else return 0;
}
