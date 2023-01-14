#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>

#include "ELTPRIM10.h"
#include "ELTPHARM.h"


ELEMENT10 element10Creer()
{
    ELEMENT10 elt=(ELEMENT10)malloc(sizeof(PHARMACIE));


    strcpy(elt->adr,"");
    strcpy(elt->nom,"");


    return (elt);

}
void element10Lire(ELEMENT10 * e)
{ int nb_mal,nb_per,i,j;

     fflush(stdin);
    printf("Donnez le nom : ");
    gets((*e)->nom);
     fflush(stdin);
     printf("Donner l'adresse : ");
     gets((*e)->adr);
     printf("Donner la quantité du gel  : ");
     scanf("%i",&((*e)->gel));
     printf("Donner la quantité des bavettes : ");
     scanf("%i",&((*e)->bav));
     printf("Donner la quantité des gants : ");
     scanf("%i",&((*e)->gants));
     printf("Donner la quantité du paracetamol : ");
     scanf("%i",&((*e)->par));
     printf("Donner la quantité du chloroquine : ");
     scanf("%i",&((*e)->chlor));
     printf("Donner la quantité des thermometres : ");
     scanf("%i",&((*e)->ther));


     do{
     printf("il appartient a quel gouvernorat sachant que leurs numeros sont : Ariana 12, Beja 31, Ben Arous 13, Bizert 23,Gabes 81,\nGafsa 71, Jendouba 32, Kairaouan 41, Kasserine 42, Kebili 73, Kef 33, Mahdia 53, La Manouba 14, Medenine 82,\n Monastir 52, Nabeul 21,Sfax 61, Sidi Bouzid 43, Siliana 34, Sousse 51, Tataouine 83, Tozeur 72, Tunis 11 et Zaghouan 22\n");
     scanf("%d",&((*e)->gouvernorat));
     }while( ((*e)->gouvernorat!=11)&&((*e)->gouvernorat!=12)&&((*e)->gouvernorat!=13)&&((*e)->gouvernorat!=14)&&((*e)->gouvernorat!=31)&&((*e)->gouvernorat!=23)&&((*e)->gouvernorat!=81)&&((*e)->gouvernorat!=71)&&((*e)->gouvernorat!=32)&&((*e)->gouvernorat!=41)&&((*e)->gouvernorat!=42)&&((*e)->gouvernorat!=73)&&((*e)->gouvernorat!=33)&&((*e)->gouvernorat!=53)&&((*e)->gouvernorat!=82)&&((*e)->gouvernorat!=52)&&((*e)->gouvernorat!=21)&&((*e)->gouvernorat!=61)&&((*e)->gouvernorat!=43)&&((*e)->gouvernorat!=34)&&((*e)->gouvernorat!=51)&&((*e)->gouvernorat!=83)&&((*e)->gouvernorat!=72)&&((*e)->gouvernorat!=22)  );
    do{
     printf("donner le numero de telephone ");
     scanf("%d",&((*e)->tel));
    }while (((*e)->tel/10000000 !=2)&&((*e)->tel/10000000!=5)&&((*e)->tel/10000000!=9)&&((*e)->tel/10000000!=7));


}

void element10Afficher(ELEMENT10 e)
{ int i;
     printf("nom : %s , adresse : %s \n  quantité du gel  : %d ,quantité des bavettes : %d, quantité des gants: %d \n quantité du paracetamol :%d, quantité du chloronique :%d, quantité des thermometres :%d ",e->nom,e->adr,e->gel,e->bav,e->gants,e->par,e->chlor,e->ther);
     printf("\n");
     printf("num tel : %d \n",e->tel);
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
}

void element10Detruire(ELEMENT10 e)
{
   free(e);
}

void element10Affecter(ELEMENT10* e1, ELEMENT10 e2)
{
     *e1=e2;
}

void element10Copier(ELEMENT10 * e1, ELEMENT10 e2)
{
    memcpy(*e1,e2,sizeof(PHARMACIE));
}

int element10Comparer(ELEMENT10 e1, ELEMENT10 e2)
{
    if (e1->tel == e2->tel  ) {return 1; }
    else return 0;
}
