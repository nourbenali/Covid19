#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include "ELTHOPITAL.h"
#include "ELTPRIM4.h"
#include"LSTPATHOP.h"
#include"LSTDON.h"
#include"LSTPRIM5.h"
#include"LSTPRIM9.h"


ELEMENT4 element4Creer()
{
    ELEMENT4 elt=(ELEMENT4)malloc(sizeof(HOPITAL));
    elt->pat_hop=liste5Creer();
    elt->dons =liste9Creer();
    /*elt->age=0;
    strcpy(elt->adr,"");
    strcpy(elt->nom,"");
    strcpy(elt->prenom,"");*/
    return (elt);

}

void element4Lire(ELEMENT4 * e)
{ int nb_don,i;
     fflush(stdin);
     printf("Donnez le nom : ");
     gets((*e)->nom);
     fflush(stdin);
     printf("Donner l'adresse : ");
     gets((*e)->adr);
     fflush(stdin);
   do{
     printf("Donner le code postal : ");
     scanf("%d",&((*e)->code_postal));
   }while(((*e)->code_postal <1000)|| ((*e)->code_postal >9999));
    do{
     printf("Donner le gouvernorat auquel appartient cet hopital sachant que : Ariana 12, Beja 31, Ben Arous 13, Bizert 23,Gabes 81,\nGafsa 71, Jendouba 32, Kairaouan 41, Kasserine 42, Kebili 73, Kef 33, Mahdia 53, La Manouba 14, Medenine 82,\n Monastir 52, Nabeul 21,Sfax 61, Sidi Bouzid 43, Siliana 34, Sousse 51, Tataouine 83, Tozeur 72, Tunis 11 et Zaghouan 22\n");
     scanf("%d",&((*e)->gouvernorat));
    }while( ((*e)->gouvernorat!=11)&&((*e)->gouvernorat!=12)&&((*e)->gouvernorat!=13)&&((*e)->gouvernorat!=14)&&((*e)->gouvernorat!=31)&&((*e)->gouvernorat!=23)&&((*e)->gouvernorat!=81)&&((*e)->gouvernorat!=71)&&((*e)->gouvernorat!=32)&&((*e)->gouvernorat!=41)&&((*e)->gouvernorat!=42)&&((*e)->gouvernorat!=73)&&((*e)->gouvernorat!=33)&&((*e)->gouvernorat!=53)&&((*e)->gouvernorat!=82)&&((*e)->gouvernorat!=52)&&((*e)->gouvernorat!=21)&&((*e)->gouvernorat!=61)&&((*e)->gouvernorat!=43)&&((*e)->gouvernorat!=34)&&((*e)->gouvernorat!=51)&&((*e)->gouvernorat!=83)&&((*e)->gouvernorat!=72)&&((*e)->gouvernorat!=22)  );
    do{
     printf("Donner le numero tel : ");
     scanf("%d",&((*e)->tel));
    }while  (((*e)->tel/10000000 !=2)&&((*e)->tel/10000000!=5)&&((*e)->tel/10000000!=9)&&((*e)->tel/10000000!=7));
    do{
     printf("Donner le numero fax: ");
     scanf("%d",&((*e)->fax));
   }  while (((*e)->fax/10000000 !=2)&&((*e)->fax/10000000!=5)&&((*e)->fax/10000000!=9)&&((*e)->fax/10000000!=7));
   do{
     printf("Donner le numero d urgence: ");
     scanf("%d",&((*e)->urg));
   }    while (((*e)->urg/10000000 !=2)&&((*e)->urg/10000000!=5)&&((*e)->urg/10000000!=9)&&((*e)->urg/10000000!=7));
     printf("donner le nombre de lits disponibles en rea");
     scanf("%d",&((*e)->nb_lits_rea));
     printf("donner le nombre de lits disponibles ailleurs");
     scanf("%d",&((*e)->nb_lits_ailleurs));
     printf("donner le nombre de medecins specialistes en corona");
     scanf("%d",&((*e)->nb_med_corona));
     printf("donner le nombre de paramédicaux");
     scanf("%d",&((*e)->nb_paramedicaux));

     printf("\n");


      printf("Combien de don voulez-vous : ");
        scanf("%d",&nb_don);
         for(i=1;i<=nb_don;i++)
  {   printf("Don %d :",i);
      ELEMENT9 e_d= element9Creer();
      element9Lire(&e_d);
     // element1Lire(&((*e)->L_PER->tabpersonne[i]));
      inserer9((*e)->dons, e_d ,i ) ;
      printf("\n");
  }

}

void element4Afficher(ELEMENT4 e)
{
     printf("nom : %s, adresse : %s, code postal : %d, \n num (tel) : %d , num (fax) : %d ,num urgence : %d ,\n nombre de lits en rea %d, nombre de lits ailleurs %d,\n nombre de medecins specialistes en corona : %d, nombre du staff medical : %d ",e->nom,e->adr,e->code_postal,e->tel,e->fax,e->urg,e->nb_lits_rea,e->nb_lits_ailleurs,e->nb_med_corona,e->nb_paramedicaux);
      printf("\n");
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
       printf("\n la liste des patients qui y appartiennent : \n");
        liste5Afficher(e->pat_hop);
        printf("\n la liste des dons : \n");
        liste9Afficher(e->dons);
        printf("\n");
}

void element4Detruire(ELEMENT4 e)
{
   free(e);
}

void element4Affecter(ELEMENT4* e1, ELEMENT4 e2)
{
     *e1=e2;
}

void element4Copier(ELEMENT4 * e1, ELEMENT4 e2)
{
   memcpy(*e1,e2,sizeof(HOPITAL));
}

int element4Comparer(ELEMENT4 e1, ELEMENT4 e2)
{
    if (strcmp(e1->nom,e2->nom)==0)  return 1;
     else return 0;
}
