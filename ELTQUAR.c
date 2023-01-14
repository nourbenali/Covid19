#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>

#include "ELTPRIM6.h"
#include "ELTQUAR.h"


ELEMENT6 element6Creer()
{
    ELEMENT6 elt=(ELEMENT6)malloc(sizeof(QUARANTAINE));

    elt->age=0;
    strcpy(elt->adr,"");
    strcpy(elt->nom,"");
    strcpy(elt->prenom,"");
    elt->L_MAL=liste1Creer();
    elt->L_PER=liste2Creer();

    return (elt);

}
void element6Lire(ELEMENT6 * e)
{ int nb_mal,nb_per,i;

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
     scanf("%i",&((*e)->age));
    do{
     printf("donnez la date de debut de confinement\n");
     printf("jour : ");
     scanf("%d",&((*e)->d_debut.jour));
    }while(((*e)->d_debut.jour <1)||((*e)->d_debut.jour>31));
    do{
     printf("mois : ");
     scanf("%d",&((*e)->d_debut.mois));
    }while(((*e)->d_debut.mois <1)||((*e)->d_debut.mois >12));
    do{
     printf("annee : ");
     scanf("%d",&((*e)->d_debut.annee));
    }while(((*e)->d_debut.annee <2020));
     printf("\n");
     printf("donnez la date du fin de confinement\n");
     do{
     do{
     printf("jour : ");
     scanf("%d",&((*e)->d_fin.jour));
     }while (((*e)->d_fin.jour<1)||((*e)->d_fin.jour>31));
     do{
     printf("mois : ");
     scanf("%d",&((*e)->d_fin.mois));
     }while (((*e)->d_fin.mois <1)||((*e)->d_fin.mois >12));
       }while((( (*e)->d_debut.mois==(*e)->d_fin.mois )&&(((*e)->d_fin.jour - (*e)->d_debut.jour )<14))||( ((*e)->d_debut.mois<(*e)->d_fin.mois)&&((30-(*e)->d_debut.jour + (*e)->d_fin.jour)<14) )  );
     do{
     printf("annee : ");
     scanf("%d",&((*e)->d_fin.annee));
     }while (((*e)->d_fin.annee <2020));
     printf("\n");
   do{
     printf("Donner votre code postal : ");
     scanf("%i",&((*e)->code_postal));
   }while(((*e)->code_postal <1000)|| ((*e)->code_postal >9999));
     printf("\n");
     printf("\n");
     do{
     printf("il appartient a quel gouvernorat sachant que leurs numeros sont : Ariana 12, Beja 31, Ben Arous 13, Bizert 23,Gabes 81,\nGafsa 71, Jendouba 32, Kairaouan 41, Kasserine 42, Kebili 73, Kef 33, Mahdia 53, La Manouba 14, Medenine 82,\n Monastir 52, Nabeul 21,Sfax 61, Sidi Bouzid 43, Siliana 34, Sousse 51, Tataouine 83, Tozeur 72, Tunis 11 et Zaghouan 22\n");
     scanf("%d",&((*e)->gouvernorat));
     }while( ((*e)->gouvernorat!=11)&&((*e)->gouvernorat!=12)&&((*e)->gouvernorat!=13)&&((*e)->gouvernorat!=14)&&((*e)->gouvernorat!=31)&&((*e)->gouvernorat!=23)&&((*e)->gouvernorat!=81)&&((*e)->gouvernorat!=71)&&((*e)->gouvernorat!=32)&&((*e)->gouvernorat!=41)&&((*e)->gouvernorat!=42)&&((*e)->gouvernorat!=73)&&((*e)->gouvernorat!=33)&&((*e)->gouvernorat!=53)&&((*e)->gouvernorat!=82)&&((*e)->gouvernorat!=52)&&((*e)->gouvernorat!=21)&&((*e)->gouvernorat!=61)&&((*e)->gouvernorat!=43)&&((*e)->gouvernorat!=34)&&((*e)->gouvernorat!=51)&&((*e)->gouvernorat!=83)&&((*e)->gouvernorat!=72)&&((*e)->gouvernorat!=22)  );
     do {
     printf("donner le numero de la CIN : ");
      scanf("%d",&(*e)->NCIN);
     } while (((*e)->NCIN/10000000<1)||((*e)->NCIN/10000000>9));

      do {
     printf("tapez 1 si le patient est un homme, 0 si une femme : ");
      scanf("%d",&(*e)->sexe);
     } while(((*e)->sexe !=0)&&((*e)->sexe !=1));
           do {
     printf("tapez 0 si le patient est marie, 1 s il est divorce, 2 s il est celibataire ,3 sinon : ");
      scanf("%d",&(*e)->etat_marital);
     } while(((*e)->etat_marital !=0)&&((*e)->etat_marital !=1)&&((*e)->etat_marital !=2)&&((*e)->etat_marital !=3));
       do {
     printf("donner le numero de telephone : ");
      scanf("%d",&(*e)->num_tel);
     } while (((*e)->num_tel/10000000 !=2)&&((*e)->num_tel/10000000!=5)&&((*e)->num_tel/10000000!=9));

     do {
     printf("tapez 1 si la contamination est introduite, 0 sinon : ");
      scanf("%d",&(*e)->cont_intro);
     } while(((*e)->cont_intro !=0)&&((*e)->cont_intro !=1));

     do {
     printf("tapez 1 s il arrive d un autre pays, 0 sinon : ");
      scanf("%d",&(*e)->provenance);
     } while(((*e)->provenance !=0)&&((*e)->provenance !=1));

     do {
     printf("tapez 1 si l etat normal, 0 sinon : ");
      scanf("%d",&(*e)->etat);
     } while(((*e)->etat !=0)&&((*e)->etat !=1));


  printf("donner le nombre de maladies chroniques : ");
  scanf("%d",&nb_mal);
  for(i=1;i<=nb_mal;i++)
  {   printf("Maladie %d :",i);
      ELEMENT1 e_m=element1Creer();
      element1Lire(&(e_m));
     // element1Lire(&((*e)->L_MAL->tabmaladie[i]));
      inserer1((*e)->L_MAL, e_m,  i);
      printf("\n");
  }
   printf("\n");
   printf("donner le nombre de personnes qu il etait en contact avec: ");
  scanf("%d",&nb_per);
  for(i=1;i<=nb_per;i++)
  {   printf("Personne %d :",i);
      ELEMENT2 e_p= element2Creer();
      element2Lire(&e_p);
     // element1Lire(&((*e)->L_PER->tabpersonne[i]));
      inserer2((*e)->L_PER , e_p ,i );
      printf("\n");
  }


}

void element6Afficher(ELEMENT6 e)
{ int i;
     printf("nom : %s , prenom : %s , adresse : %s , age : %d , numero CIN = %d ,\n code postal: %d, numero de telephone :%d ",e->nom,e->prenom,e->adr,e->age,e->NCIN,e->code_postal,e->num_tel);
     printf("\n");
     if (e->sexe == 1) {printf("sexe : homme . ");}
     else if (e->sexe == 0) {printf(" sexe : femme . ");}
     if (e->etat_marital == 1) {printf("statut marital : divorce. ");}
     else if (e->etat_marital == 0) {printf(" statut marital :marie . ");}
     else if (e->etat_marital == 2) {printf(" statut marital :celibataire . ");}
     else  {printf(" statut marital :voeuf(ve) . ");}
     if (e->cont_intro == 1) {printf("la contamination est introduite . ");}
     else if (e->cont_intro == 0) {printf("la contamination est locale . ");}
     if (e->provenance == 1) {printf("Il arrive d un autre pays ");}
     else if (e->provenance == 0) {printf("il est en tunisie ");}
     if (e->etat == 1) {printf("son etat est normal . ");}
     else if (e->etat == 0) {printf("son etat est critique . ");}


       printf("\n");
       printf("Date de debut de confinement : %d/%d/%d \n",e->d_debut.jour,e->d_debut.mois,e->d_debut.annee);
       printf("Date du fin de confinement : %d/%d/%d \n",e->d_fin.jour,e->d_fin.mois,e->d_fin.annee);
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
        printf("\n");
       printf("la liste des maladies qu il a : ");

   /*  for (i=1;i<=liste1Taille(e->L_MAL); i++)
     {   printf("Maladie %d : ",i);
         element1Afficher(e->L_MAL->tabmaladie[i-1]);
         printf("  ");
     }*/
     liste1Afficher(e->L_MAL);
     printf("\n");
     printf("la liste des personnes qu il etait en contact avec \n");


    /* for (i=1;i<=liste2Taille (e->L_PER); i++)
     {   printf("Personne %d : ",i);
         element2Afficher(e->L_PER->tabpersonne[i-1]);
         printf("  ");
     }*/
     liste2Afficher(e->L_PER);



}

void element6Detruire(ELEMENT6 e)
{  /*int i;
    for(i=1;i<=liste1Taille(e->L_MAL);i++)
    {element1Detruire(e->L_MAL->tabmaladie[i-1]) ;}
    for(i=1;i<=liste2Taille(e->L_PER);i++)
    {element2Detruire(e->L_PER->tabpersonne[i-1]);}*/
   free(e);
}

void element6Affecter(ELEMENT6* e1, ELEMENT6 e2)
{
     *e1=e2;
}

void element6Copier(ELEMENT6 * e1, ELEMENT6 e2)
{
    memcpy(*e1,e2,sizeof(QUARANTAINE));
}

int element6Comparer(ELEMENT6 e1, ELEMENT6 e2)
{
    if ((e1->NCIN) == (e2->NCIN)) {return 1; }
    else return 0;
}
