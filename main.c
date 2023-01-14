#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ELTPRIM1.h"
#include "ELTPRIM2.h"
#include "ELTPRIM3.h"
#include "ELTPRIM4.h"
#include "ELTPRIM6.h"
#include "ELTPRIM7.h"
#include "ELTPRIM9.h"
#include "ELTPRIM10.h"
#include "LSTPRIM1.h"
#include "LSTPRIM2.h"
#include "LSTPRIM3.h"
#include "LSTPRIM4.h"
#include "LSTPRIM5.h"
#include "LSTPRIM6.h"
#include "LSTPRIM7.h"
#include "LSTPRIM8.h"
#include "LSTPRIM9.h"
#include "LSTPRIM10.h"
#include "LSTMALADIE.h"
#include "LSTPERSONNE.h"
#include "LSTPATIENT.h"
#include "LSTHOPITAL.h"
#include "LSTPATHOP.h"
#include "LSTPERLIEU.h"
#include "LSTLIEU.h"
#include "LSTQUAR.h"
#include "LSTDON.h"
#include "LSTPHARM.h"



void ajout_patient(LISTE_PATIENT L ,int nb)
{
    int i,contamine=1025;
    for (i=1; i<=nb ; i++)
    {
    printf("Patient %d \n :",i);
    ELEMENT3 pat=element3Creer();
    element3Lire(&pat);
    inserer3(L,pat,liste3Taille(L)+1);
    contamine++;
    }
    printf("\n L'ajout a ete effectue avec succes\n");

    printf("\n le nombre de cas contamines est : %d \n",contamine);

}

void ajout_hopital(LISTE_HOPITAL L ,int nb)
{
    int i;
    for (i=1; i<=nb ; i++)
    { printf("hopital %d \n :",i);
    ELEMENT4 hop=element4Creer();
    element4Lire(&hop);
    hop->id= L->lg + 1 ;
    inserer4(L,hop,liste4Taille(L)+1);
    }
    printf("\n L'ajout a ete effectue avec succes\n");

}

void ajout_lieu(LISTE_LIEU L ,int nb)
{
    int i;
    for (i=1; i<=nb ; i++)
    { printf("Lieu %d \n :",i);
    ELEMENT7 lieu=element7Creer();
    element7Lire(&lieu);
    inserer7(L,lieu,liste7Taille(L)+1);
    }
    printf("\n L'ajout a ete effectue avec succes\n");

}
void modifEtat ( LISTE_PATIENT L_PAT, int a)
   {
        NOEUD1 p,q;int test=0,i=1;
      p=L_PAT->tete;
      while((i<=liste3Taille(L_PAT))&&(test==0))
      {
          if (p->info->NCIN==a) { test=1; q=p;}
          else { p=p->suivant; i++; }
      }
    if ( q->info->etat==0){  q->info->etat=1; /*inserer3(L_PAT,q->info,i);*/ }
    else {  q->info->etat=0;/* inserer3(L_PAT,q->info,i); */}

 printf("La modification a ete effectuee avec succes");

}

void ajout_quarantaine(LISTE_QUARANTAINE L ,int nb)
{
    int i;
    for (i=1; i<=nb ; i++)
    {
    printf("Personne %d \n :",i);
    ELEMENT6 per=element6Creer();
    element6Lire(&per);
    inserer6(L,per,(L->lg)+1);
    }
    printf("\n L'ajout a ete effectue avec succes\n");

}
void ajout_don ( LISTE_HOPITAL L )
{ int i,num,trouve=0,j=1,k,nb_don;
  for ( i=1 ; i<=L->lg ; i++)
  {
      ELEMENT4 h =element4Creer();
      element4Affecter(&h, recuperer4(L,i));
      printf("HOPITAL %d : %s  ",i,h->nom);
  }
  printf("D apres ces hopitaux donner le numero de l hopital concerne : ");
 do{
  scanf("%d",&num);
 } while ((num<1 )||(num>L->lg));

 while ( (j<=L->lg)&&(!trouve))
 {
     if ( recuperer4(L,j)->id ==num )
     {
         trouve=1;
           printf("combien de dons voulez-vous ajouter? ");
  scanf("%d",&nb_don);
  for(k=1;k<=nb_don;k++)
  {   printf("Don %d :",k);
      ELEMENT9 e_d= element9Creer();
      element9Lire(&e_d);
     // element1Lire(&((*e)->L_PER->tabpersonne[i]));
      inserer9(recuperer4(L,j)->dons, e_d , liste9Taille(recuperer4(L,j)->dons)+1 ) ;
      printf("\n");
  }
     }
     j++;
 }
 printf("\n L'ajout a ete effectue avec succes\n");
}
void supp_don( LISTE_HOPITAL L)
{
    int i,num,trouve=0,j=1,k,nb_don,numsupp;
  for ( i=1 ; i<=L->lg ; i++)
  {
      ELEMENT4 h =element4Creer();
      element4Affecter(&h, recuperer4(L,i));
      printf("HOPITAL %d : %s  ",i,h->nom);
  }
  printf("D apres ces hopitaux donner le numero de l hopital concerne : ");
 do{
  scanf("%d",&num);
 } while ((num<1 )||(num>L->lg));

 while ( (j<=L->lg)&&(!trouve))
 {
     if ( recuperer4(L,j)->id ==num )
     {
         trouve=1;
         do{
         printf("Combien de don voulez-vous supprimer?  ");
  scanf("%d",&nb_don);
         }while(nb_don>liste9Taille(recuperer4(L,j)->dons));


  for(k=1;k<=nb_don;k++)
  { liste9Afficher(recuperer4(L,j)->dons);

    printf(" veuillez saisir le numero a supprimer :");
    scanf("%d",&numsupp);
    supprimer9(recuperer4(L,j)->dons , numsupp);

      printf("\n");
  }
     }
     j++;
 }
  printf("La suppression a ete effectuee avec succes");


}

void affichage_patient(LISTE_PATIENT L)
{
     int k;
  for(k=1;k<=liste3Taille(L);k++)
    {
        printf("patient %d : \n",k);
        printf("\n");
       element3Afficher(recuperer3(L,k));
       printf("\n");
    }
}
int rech_hop ( LISTE_HOPITAL LH, int a )
{
    int i=1;
    int trouve=0;
    while((i<=liste4Taille(LH))&&(trouve==0))
    {
        if ((recuperer4(LH,i)->gouvernorat==a)&&(recuperer4(LH,i)->nb_lits_rea>0)&&(recuperer4(LH,i)->nb_lits_ailleurs>0))
        {
            trouve=i;
        }
        else i++;
    }
    return trouve ;
}

void hoppat(LISTE_PATIENT LP, LISTE_HOPITAL LH)
{
    int i,trouve,proche,j,min,k,nb,w;
    NOEUD1 p=LP->tete;
    while(p!=NULL)

              { k=0;
                nb=0;
                w=0;

                min = 2000;

        for(i=1;i<=liste4Taille(LH);i++)
        { int  a;


        if ((p->info->gouvernorat==recuperer4(LH,i)->gouvernorat)&&(recuperer4(LH,i)->nb_lits_ailleurs>0)&&(recuperer4(LH,i)->nb_lits_rea>0))
            {    nb++; w=i;
                a = abs(p->info->code_postal - recuperer4(LH,i)->code_postal) ;
                if (a<min){min=a;k=i;}
            }
        }
         if(nb!=0)
        { if(k!=0){

        inserer5(recuperer4(LH,k)->pat_hop,p->info,liste5Taille(recuperer4(LH,k)->pat_hop)+1);
        if ( p->info->etat==0  ) { recuperer4(LH,k)->nb_lits_rea--; }
                else if  ( p->info->etat==1 ) { recuperer4(LH,k)->nb_lits_ailleurs--; }}
        else if(k==0)
        {
            inserer5(recuperer4(LH,w)->pat_hop,p->info,liste5Taille(recuperer4(LH,w)->pat_hop)+1);
            if ( p->info->etat==0  ) { recuperer4(LH,w)->nb_lits_rea--; }
                else if  ( p->info->etat==1 ) { recuperer4(LH,w)->nb_lits_ailleurs--; }
        }

        }

        else if (nb==0)
        {
            switch(p->info->gouvernorat)
            {
                case 11 :   if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,13)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,13))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,13))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,12)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,12))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,12))->pat_hop)+1);

                              }

                case 12 : if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,13)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,13))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,13))->pat_hop)+1);

                              }
                              break;

                case 13 : if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                               }
                              else if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,12)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,12))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,12))->pat_hop)+1);

                              }
                              break;

                case 14 : if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,12)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,12))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,12))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,13)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,13))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,13))->pat_hop)+1);

                              }
                              break;

                 case 21 : if (rech_hop(LH,13)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,13))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,13))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                 case 22 : if (rech_hop(LH,13)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,13))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,13))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);    }
                              break;

                case 23 : if (rech_hop(LH,12)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,12))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,12))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,11)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,14)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,14))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,14))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                case 31 : if (rech_hop(LH,32)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,32))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,32))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,34)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,34))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,34))->pat_hop)+1);

                            }
                              else if (rech_hop(LH,33)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,33))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,33))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                case 32 : if (rech_hop(LH,31)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,31))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,31))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,33)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,33))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,33))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,34)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,34))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,34))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); }
                              break;

                case 33 : if (rech_hop(LH,32)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,32))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,32))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,34)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,34))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,34))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,31)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,31))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,31))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);}
                              break;

                case 34 : if (rech_hop(LH,33)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,33))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,33))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,31)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,31))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,31))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,32)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,32))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,32))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                 case 41 : if (rech_hop(LH,51)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,51))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,51))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,34)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,34))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,34))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,53)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,53))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,53))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                 case 42 : if (rech_hop(LH,43)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,43))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,43))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,71)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,71))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,71))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,33)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,33))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,33))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                   case 43: if (rech_hop(LH,42)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,42))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,42))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,71)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,71))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,71))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,41)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,41))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,41))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;

                   case 51 : if (rech_hop(LH,52)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,52))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,52))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,41)!=0)
                              {
                                inserer5(recuperer4(LH,rech_hop(LH,41))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,41))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,22)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,22))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,22))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }
                              break;


                  case 52 : if (rech_hop(LH,51)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,51))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,51))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,53)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,53))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,53))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,41)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,41))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,41))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);}
                              break;

                 case 53 : if (rech_hop(LH,52)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,52))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,52))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,51)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,51))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,51))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,41)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,41))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,41))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); break; }

                 case 61 : if (rech_hop(LH,53)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,53))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,53))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,43)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,43))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,43))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,41)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,41))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,41))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); }
                              break;

                case 71 : if (rech_hop(LH,72)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,72))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,72))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,43)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,43))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,43))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,42)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,42))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,42))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); }
                              break;

                  case 72 : if (rech_hop(LH,71)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,71))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,71))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,73)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,73))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,73))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,43)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,43))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,43))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); }
                                break;

                 case 73 : {if (rech_hop(LH,72)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,72))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,72))->pat_hop)+1);

                              }
                             else if (rech_hop(LH,71)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,71))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,71))->pat_hop)+1);

                              }
                             else if (rech_hop(LH,81)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,81))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,81))->pat_hop)+1);

                              }
                             else
                                {
                                     inserer5(recuperer4(LH,rech_hop(LH,12))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,12))->pat_hop)+1);

                                }
                                break;
                 }
                case 81 : if (rech_hop(LH,82)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,82))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,82))->pat_hop)+1);

                               }
                              else if (rech_hop(LH,73)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,73))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,73))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,61)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,61))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,61))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); }
                              break;

                 case 82 : if (rech_hop(LH,83)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,83))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,83))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,81)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,81))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,81))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,73)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,73))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,73))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1); break; }


                 case 83 :  if (rech_hop(LH,82)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,82))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,82))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,81)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,81))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,81))->pat_hop)+1);

                              }
                              else if (rech_hop(LH,73)!=0)
                              {
                                  inserer5(recuperer4(LH,rech_hop(LH,73))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,73))->pat_hop)+1);

                              }
                              else { inserer5(recuperer4(LH,rech_hop(LH,11))->pat_hop,p->info,liste5Taille(recuperer4(LH,rech_hop(LH,11))->pat_hop)+1);  }

                              break;

            }

        }


           p=p->suivant;
    }
}



/*int rech_lieu ( LISTE_LIEU LH, int a )
{
    int i=1;
    int trouve=0;
    while((i<=liste7Taille(LH))&&(!trouve))
    {
        if ((recuperer7(LH,i)->gouvernorat==a)&&(recuperer7(LH,i)->capacite>0))
        {
            trouve=1;
        }
        else i++;
    }
    return (trouve+i);
}*/
void lieuper(LISTE_QUARANTAINE LQ, LISTE_LIEU LL)
{
    int i,min,k,w;
    NOEUD2 p=LQ->tete;
        while(p!=NULL)

    { min = 2000;
        k=0;

        w=0;
        for(i=1;i<=liste7Taille(LL);i++)
        { int  a;
            if ((p->info->gouvernorat==recuperer7(LL,i)->gouvernorat)&&(recuperer7(LL,i)->capacite>0))
            {    w=i;
                a = abs(p->info->code_postal - recuperer7(LL,i)->code_postal) ;
                if (a<min){min=a;k=i;}
            }

        }
        if(k!=0){
         inserer8(recuperer7(LL,k)->per_lieu,p->info,liste8Taille(recuperer7(LL,k)->per_lieu)+1);
               recuperer7(LL,k)->capacite--;}
               else if (k==0)
               {
                inserer8(recuperer7(LL,w)->per_lieu,p->info,liste8Taille(recuperer7(LL,w)->per_lieu)+1);
               recuperer7(LL,w)->capacite--;}


               p=p->suivant;
        }
}

void supp_patient(LISTE_PATIENT L,int a)
{   int cas_gueris=591;
    int deces=43;
    int choix;
    printf("tapez 0 si le patient a supprimer est gueri,1 s'il est mort : ");
    do
    {
        scanf("%d",&choix);
    }
    while((choix<0)||(choix>1));

      trier(L);
    NOEUD1 p,q;
    p=L->tete;
    int trouve=0,i=1;
    while((p!=NULL)&&(!trouve))
    {
        if (p->info->NCIN==a){ q=p; trouve=1;}
        else {p=p->suivant;  i++;}
    }
    supprimer3(L,i);
    printf("\n La suppression a été effectuee avec succes \n");

    if (choix==0)
    {cas_gueris++;
    printf("\n le nombre de cas gueris est %d \n",cas_gueris);
    }
    else if (choix==1)
    {
        deces++;
        printf("\n le nombre des patients morts est %d \n",deces);
    }

}

void trier (LISTE_PATIENT L)
{
    NOEUD1 p,q;
    p=L->tete;
    q=p->suivant;
    while(q!=NULL)
    {
        if ((p->info->age) > (q->info->age))
        {   ELEMENT3 e =element3Creer();
            element3Affecter(&e,p->info);
            element3Affecter(&(p->info),q->info);
            element3Affecter(&(q->info),e);}


        p=p->suivant;
        q=q->suivant;
    }
}
void recherche_patient (LISTE_PATIENT L)
{ int choix1,choix2,choix3,choix3_1,choix4,CIN,age,sexe,gouv,trouve=0;
  char nomf[20];
  NOEUD1 p=L->tete;
  do {
    printf("Tapez 0 si la recherche est selon 1 seul patient, 1 sinon : ");
    scanf("%d",&choix1);
  } while( (choix1<0)||(choix1>1));
    if (choix1==0)
    {
        do {
        printf("Donner son numero CIN");
        scanf("%d",&CIN);
           }  while ((CIN/10000000<1)||(CIN/10000000>9));


        while((p!=NULL)&&(!trouve))
        {
            if (p->info->NCIN == CIN) { element3Afficher(p->info);trouve=1; }
            p=p->suivant;
        }
        if (trouve==0){printf("Desole, le patient cherche n existe pas");}


    }
  else
    {  do{
        printf("Tapez 0 si vous recherchez selon 1 seul critere, 1 sinon");
        scanf("%d",&choix2);
    } while ((choix2<0)||(choix2>1));
       if (choix2==0)
       {
       printf("Tapez 0 si vous recherchez selon l age \n Tapez 1 si vous recherchez selon l adresse \n Tapez 2 si vous recherchez selon le genre\n Tapez 3 si vous recherchez selon le nom de famille \n");
       do{
       scanf("%d",&choix3);
    }  while( (choix3<0)||(choix3>3));

          if (choix3==0)
          {  // trier(L);
               NOEUD1 p=L->tete;
              for(int i=1;i<=liste3Taille(L)/2;i++)
              {
                  p=p->suivant;
              }
              do {
              printf("Tapez 0 si le patient bebe , 1 si enfant, 2 si adolescent, 3 si adulte , 4 si vieux ");
              scanf("%d",&choix3_1);
              } while( (choix3_1<0)||(choix3_1>4));
              if (choix3_1==0)
              {
                  if (4<= p->info->age)
                  {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L)/2; i++)
				             {  if (4>=q->info->age) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }
                  }

			  else {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L); i++)
				             {  if (4>=q->info->age) { element3Afficher(q->info); }

				                 q= q->suivant;
				             }

                  }

			}
			else if (choix3_1==1)
              {
                  if (p->info->age>=16)
                  {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L)/2; i++)
				             {  if ((q->info->age<=16)&& (q->info->age>=5)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }
                  }

			  else if (p->info->age<=5) {  NOEUD1 q=L->queuee;
                       for ( int i=liste3Taille(L); i>=liste3Taille(L)/2; i--)
				             {  if ((q->info->age<=16)&& (q->info->age>=5)) { element3Afficher(q->info); }

				                 q = q->precedent;
				             }

                  }
                  else {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L); i++)
				             {  if ((q->info->age<=16)&& (q->info->age>=5)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }

                  }

			}
			else if (choix3_1==2)
              {
                  if (p->info->age>=30)
                  {  NOEUD1 q =L->tete;
                       for ( int i=1; i<=liste3Taille(L)/2; i++)
				             {  if ((q->info->age<=30)&& (q->info->age>=17)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }
                  }

			  else if (p->info->age<=17) {  NOEUD1 q=L->queuee;
                       for ( int i=liste3Taille(L); i>=liste3Taille(L)/2; i--)
				             {  if ((q->info->age<=30)&& (q->info->age>=17)) { element3Afficher(q->info); }

				                 q = q->precedent;
				             }

                  }
                  else {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L); i++)
				             {  if ((q->info->age<=30)&& (q->info->age>=17)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }

                  }
              }
			else if (choix3_1==3)
              {
                 if (p->info->age>=55)
                  {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L)/2; i++)
				             {  if ((q->info->age<=55)&& (q->info->age>=31)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }
                  }

			  else if (p->info->age<=31) {  NOEUD1 q=L->queuee;
                       for ( int i=liste3Taille(L); i>=liste3Taille(L)/2; i--)
				             {  if ((q->info->age<=55)&& (q->info->age>=31)) { element3Afficher(q->info); }

				                 q = q->precedent;
				             }

                  }
                  else {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L); i++)
				             {  if ((q->info->age<=55)&& (q->info->age>=31)) { element3Afficher(q->info); }

				                 q = q->suivant;
				             }

                  }
			  }
			else
              {
                  if (p->info->age<=56)
                  {  NOEUD1 q=L->queuee;
                       for ( int i=liste3Taille(L); i<=liste3Taille(L)/2; i--)
				             {  if (q->info->age>=56) { element3Afficher(q->info); }

				                 q = q->precedent;
				             }
                  }

			  else {  NOEUD1 q=L->tete;
                       for ( int i=1; i<=liste3Taille(L); i++)
				             {  if (4>=q->info->age) { element3Afficher(q->info); }

				                 q= q->suivant;
				             }

                  }
              }
          }
          else if (choix3==1)
          {  char adr [20];
              int i=1;
              printf("Donner l adresse ");
             scanf("%s",&adr);
              NOEUD1 q=L->tete;
              while(q!=NULL)
              {
                  if (strcmp(q->info->adr,adr)==0){printf("Patient %d \n",i); element3Afficher(q->info);i++;  }
                      q=q->suivant;
              }

          }
          else if (choix3==2)
          {
              int genre,i=1;
              printf("Tapez 1 si les patients a chercher sont des hommes , 0 sinon ");
             scanf("%d",&genre);
              NOEUD1 q=L->tete;
              while(q!=NULL)
              {
                  if (q->info->sexe==genre){ printf("Patient %d \n",i);element3Afficher(q->info);i++;  }
                      q=q->suivant;
              }

          }
          else
          {
              char nom [20];
              int i=1;
              printf("Donner le nom de famille ");
             scanf("%s",&nom);
              NOEUD1 q=L->tete;
              while(q!=NULL)
              {
                  if (strcmp(q->info->nom,nom)==0){printf("Patient %d \n",i); element3Afficher(q->info);i++;  }
                      q=q->suivant;
              }
          }

              }
              else if (choix2==1)
              {
                  printf("Tapez 0 si vous cherchez selon :age & sexe , 1 si vous cherchez selon : gouvernorat & nom de famille  ");

                   do{
                      scanf("%d",&choix4);
                     }  while( (choix4<0)||(choix4>1));
                     if  (choix4==0)
                     {
                         printf("donner l age ");
                         scanf("%d",&age);
                         printf("Tapez 0 si le sexe est feminin, 1 sinon");
                         do{
                                scanf("%d",&sexe);
                         }while( (sexe<0)||(sexe>1) );

                         NOEUD1 q = L->tete;
                         while(q!=NULL)
                         {  int j=0;
                             if ((q->info->age==age)&&(q->info->sexe == sexe))
                             {  j++;
                                 printf("Patient : %d",j);
                                 element3Afficher(q->info);
                                 printf("\n");
                             }
                             q=q->suivant;
                         }


                     }
                     else if (choix4==1)
                     {
                         printf("Donner le numero du gouvernorat : ");
                         scanf("%d",&gouv);
                         printf("Donner le nom de famille : ");
                         fflush(stdin);
                         gets(nomf);


                         NOEUD1 q = L->tete;
                         while(q!=NULL)
                         { int i=0;
                             if ((q->info->gouvernorat==gouv)&&( strcmp(q->info->nom,nomf)==0))
                             { i++;
                                   printf("Patient %d",i);
                                 element3Afficher(q->info);
                                 printf("\n");
                             }
                             q=q->suivant;
                         }
                     }

              }


          }
    }

void ajout_per_pat(LISTE_PATIENT LP, LISTE_QUARANTAINE LQ)
{ char nom[10],prenom[10];
  int trouve=0;
   NOEUD1 p=LP->tete;
   int i,j,k,nb_mal,nb_per;
    printf("Donner le nom du patient qu'il y a eu un contact avec : ");
    scanf("%s",&nom);
    printf("Donner le prenom du patient qu'il y a eu un contact avec : ");
    scanf("%s",&prenom);


    while((p!=NULL)&&(!trouve))
    {
        if (( strcmp(p->info->nom,nom)==0)&&(strcmp(p->info->prenom,prenom)==0))
        {

            for (i=1;i<=liste2Taille(p->info->L_PER);i++)
       {
           ELEMENT2 ep=element2Creer();
           ELEMENT6 eq=element6Creer();
           element2Affecter(&ep,recuperer2(p->info->L_PER,i));
           strcpy(eq->nom,ep->nom);
           strcpy(eq->prenom,ep->prenom);
           strcpy(eq->adr,ep->adr);
           eq->age=ep->age;

     printf("%s %s \n",eq->nom ,eq->prenom);
     printf("Donnez la date de debut de confinement\n");
     do{
     printf("jour : ");
     scanf("%d",&((eq)->d_debut.jour));
     }while(((eq)->d_debut.jour<1)||(((eq)->d_debut.jour >31)));
    do{
     printf("mois : ");
     scanf("%d",&((eq)->d_debut.mois));
    }while(((eq)->d_debut.mois <1)||((eq)->d_debut.mois>12));
    do{
     printf("annee : ");
     scanf("%d",&((eq)->d_debut.annee));
    }while ((eq)->d_debut.annee <2020);
     printf("\n");
     printf("Donnez la date de fin de confinement\n");
     do{
     do{
     printf("jour : ");
     scanf("%d",&((eq)->d_fin.jour));
     }while (((eq)->d_fin.jour<1)||(((eq)->d_fin.jour >31)));
     do{
     printf("mois : ");

     scanf("%d",&((eq)->d_fin.mois));
     }while(((eq)->d_fin.mois <1)||((eq)->d_fin.mois>12));
     }while((( eq->d_debut.mois==eq->d_fin.mois )&&((eq->d_fin.jour - eq->d_debut.jour )<14))||( (eq->d_debut.mois<eq->d_fin.mois)&&((30-eq->d_debut.jour + eq->d_fin.jour)<14) )  );
    do{
     printf("annee : ");
     scanf("%d",&((eq)->d_fin.annee));
    }while((eq)->d_fin.annee <2020);
    do{
     printf("Donner le code postal : ");
     scanf("%i",&(eq->code_postal));
    }while ((eq->code_postal <1000)|| (eq->code_postal >9999));

     printf("\n");

     do{
     printf("Il appartient a quel gouvernorat sachant que leurs numeros sont : Ariana 12, Beja 31, Ben Arous 13, Bizert 23,Gabes 81,\nGafsa 71, Jendouba 32, Kairaouan 41, Kasserine 42, Kebili 73, Kef 33, Mahdia 53, La Manouba 14, Medenine 82,\n Monastir 52, Nabeul 21,Sfax 61, Sidi Bouzid 43, Siliana 34, Sousse 51, Tataouine 83, Tozeur 72, Tunis 11 et Zaghouan 22\n");
     scanf("%d",&(eq->gouvernorat));
     }while( ((eq)->gouvernorat!=11)&&((eq)->gouvernorat!=12)&&((eq)->gouvernorat!=13)&&((eq)->gouvernorat!=14)&&((eq)->gouvernorat!=31)&&((eq)->gouvernorat!=23)&&((eq)->gouvernorat!=81)&&((eq)->gouvernorat!=71)&&((eq)->gouvernorat!=32)&&((eq)->gouvernorat!=41)&&((eq)->gouvernorat!=42)&&((eq)->gouvernorat!=73)&&((eq)->gouvernorat!=33)&&((eq)->gouvernorat!=53)&&((eq)->gouvernorat!=82)&&((eq)->gouvernorat!=52)&&((eq)->gouvernorat!=21)&&((eq)->gouvernorat!=61)&&((eq)->gouvernorat!=43)&&((eq)->gouvernorat!=34)&&((eq)->gouvernorat!=51)&&((eq)->gouvernorat!=83)&&((eq)->gouvernorat!=72)&&((eq)->gouvernorat!=22)  );
     do {
     printf("Donner le numero de CIN : ");
      scanf("%d",&(eq->NCIN));
     } while ((eq->NCIN/10000000<1)||(eq->NCIN/10000000>9));

      do {
     printf("Tapez 1 si le patient est un homme, 0 si une femme : ");
      scanf("%d",&(eq->sexe));
     } while((eq->sexe !=0)&&(eq->sexe !=1));
           do {
     printf("Tapez 0 si le patient est marie, 1 s il est divorce, 2 s il est celibataire ,3 sinon : ");
      scanf("%d",&(eq->etat_marital));
     } while((eq->etat_marital !=0)&&(eq->etat_marital !=1)&&(eq->etat_marital !=2)&&(eq->etat_marital !=3));
       do {
     printf("Donner le numero de telephone : ");
      scanf("%d",&(eq->num_tel));
     }while (((eq)->num_tel/10000000 !=2)&&((eq)->num_tel/10000000!=5)&&((eq)->num_tel/10000000!=9));

     do {
     printf("Tapez 1 si la contamination est introduite, 0 sinon : ");
      scanf("%d",&(eq->cont_intro));
     } while((eq->cont_intro !=0)&&(eq->cont_intro !=1));
     do {
     printf("Tapez 1 si l etat normal, 0 sinon : ");
      scanf("%d",&(eq->etat));
     } while((eq->etat !=0)&&(eq->etat !=1));
  printf("Donner le nombre de maladies chroniques : ");
  scanf("%d",&nb_mal);
  for(j=1;j<=nb_mal;j++)
  {   printf("Maladie %d :",j);
      ELEMENT1 e_m=element1Creer();
      element1Lire(&(e_m));
     // element1Lire(&((*e)->L_MAL->tabmaladie[i]));
      inserer1(eq->L_MAL, e_m,  j);
      printf("\n");
  }
   printf("\n");
   printf("Donner le nombre de personnes qu il etait en contact avec: ");
  scanf("%d",&nb_per);
  for(k=1;k<=nb_per;k++)
  {   printf("Personne %d :",k);
      ELEMENT2 e_p= element2Creer();
      element2Lire(&e_p);
     // element1Lire(&((*e)->L_PER->tabpersonne[i]));
      inserer2(eq->L_PER , e_p ,k );
      printf("\n");
  }

  inserer6(LQ,eq,(LQ->lg)+1);


       }
       trouve=1;
        }



 else p=p->suivant;
    }
    printf("\n L'ajout a ete effectue avec succes\n");

}
void ajout_pharma(LISTE_PHARMACIE L, int nb)
{ int i;
    for(i=1;i<=nb;i++)

      {
          printf("PHARMACIE %d",i);
          ELEMENT10 e=element10Creer();
          element10Lire(&e);
          inserer10(L,e,i);
      }
      printf("\n L'ajout a ete effectue avec succes\n");
}
void vente_med(ELEMENT10 e)
{ int nb_chlor,nb_bav,nb_gel,nb_par,nb_gants,nb_ther,choix1,choix2,choix3,choix4,choix5,choix6;
printf("chloroquine \n");
if(e->chlor>0)
{printf("Voulez vous acheter du chloroquine : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix1);}while ((choix1<0)||(choix1>1));
    if (choix1==1)
    {
        do{ printf("Combien de paquets coulez-vous acheter : ");
         scanf("%d",&nb_chlor);
        }while(nb_chlor>e->chlor);
        e->chlor=e->chlor-nb_chlor;
        printf("Commande a ete effectuee avec succes");
       }

    }
    else printf("Chloroquine indisponible");
printf("\n gel \n");
if(e->gel>0)
{
    printf("Voulez vous acheter du gel : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix2);}while ((choix2<0)||(choix2>1));
    if (choix2==1)
    { do{
        printf("Combien de flacon coulez-vous acheter : ");
         scanf("%d",&nb_gel);
    }while(nb_gel>e->gel);
        e->gel=e->gel-nb_gel;
        printf("Commande a ete effectuee avec succes");
    }
}
else printf("gel indisponible");
printf("\n bavettes \n");
if(e->bav>0)
{printf("Voulez vous acheter des bavettes  : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix3);}while ((choix3<0)||(choix3>1));
    if (choix3==1)
    {
        do{ printf("combien de piece voulez-vous : ");
         scanf("%d",&nb_bav);
        }while(nb_chlor>e->bav);
        e->bav=e->bav-nb_bav;
        printf("commande a ete effectuee avec succes");
       }

    }
    else printf("bavette indisponible");
printf("\n gants \n");
if(e->gants>0)
{
    printf("Voulez vous acheter des gants : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix4);}while ((choix4<0)||(choix4>1));
    if (choix4==1)
    { do{
        printf("combien de paires voulez-vous : ");
         scanf("%d",&nb_gants);
    }while(nb_gants>e->gants);
        e->gants=e->gants-nb_gants;
        printf("commande a ete effectuee avec succes");
    }
}
else printf("gants indisponibles");
printf("\n Paracetamol \n");
if(e->par>0)
{printf("Voulez vous acheter du paracetamol : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix5);}while ((choix5<0)||(choix5>1));
    if (choix5==1)
    {
        do{ printf("combien de paquets voulez-vous : ");
         scanf("%d",&nb_par);
        }while(nb_par>e->par);
        e->par=e->par-nb_par;
        printf("commande a ete effectuee avec succes");
       }

    }
    else printf("Paracetamol indisponible");
printf("\n Thermometres \n");
if(e->ther>0)
{
    printf("Voulez vous acheter des thermometres : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix6);}while ((choix6<0)||(choix6>1));
    if (choix6==1)
    { do{
        printf("combien de piece voulez-vous : ");
         scanf("%d",&nb_ther);
    }while(nb_ther>e->ther);
        e->ther=e->ther-nb_ther;
        printf("commande a ete effectuee avec succes");
    }
}
else printf("Thermometres indisponibles");
}
void passer_commande(ELEMENT10 e)
{
    int j,m,a,nb_chlor,nb_bav,nb_gel,nb_par,nb_gants,nb_ther,choix1,choix2,choix3,choix4,choix5,choix6;
printf("Voulez vous passer une commande pour le chloroquine: tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix1);}while ((choix1<0)||(choix1>1));
    if (choix1==1)
    {
    printf("donner la date de la commande \n ");
    do{
    printf("jour : ");
    scanf("%d",&j);
    }while((j<1)||(j>31));
    printf("\n");
    do{
    printf("mois : ");
    scanf("%d",&m);
    }while((m<1)||(m>12));
    printf("\n");
    do{
    printf("annee : ");
    scanf("%d",&a);
    }while(a!=2020);
    if (m>3)
    {
        printf("impossible");
    }
    else
    { if ((j<27)&&(a==2020))
       {printf("combien de paquets voulez-vous : ");
         scanf("%d",&nb_chlor);
        e->chlor=e->chlor+nb_chlor;
        printf("commande a ete effectuee avec succes");
       }
       else printf("impossible");
    }
    }
    printf("voulez vous passer une commande pour le gel : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix2);}while ((choix2<0)||(choix2>1));
    if (choix2==1)
    { printf("combien de flacon voulez-vous : ");
         scanf("%d",&nb_gel);
        e->gel=e->gel+nb_gel;
        printf("commande a ete effectuee avec succes");
    }

     printf("voulez vous passer une commande pour les bavettes : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix3);}while ((choix3<0)||(choix3>1));
    if (choix3==1)
    { printf("combien de piece voulez-vous  ");
         scanf("%d",&nb_bav);
        e->bav=e->bav+nb_bav;
        printf("commande a ete effectuee avec succes");
    }

     printf("voulez vous passer une commande pour le paracetamol : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix4);}while ((choix4<0)||(choix4>1));
    if (choix4==1)
    { printf("combien de paquet voulez vous : ");
         scanf("%d",&nb_par);
        e->par=e->par+nb_par;
        printf("commande a ete effectuee avec succes");
    }

     printf("voulez vous passer une commande pour le thermometre : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix5);}while ((choix5<0)||(choix5>1));
    if (choix5==1)
    { printf("combien de piece voulez-vous : ");
         scanf("%d",&nb_ther);
        e->ther=e->ther+nb_ther;
        printf("commande a ete effectuee avec succes");
    }

     printf("voulez vous passer une commande pour les gants : tapez 1 si oui et 0 sinon  ");
do{scanf("%d",&choix6);}while ((choix6<0)||(choix6>1));
    if (choix6==1)
    { printf("combien de paires voulez-vous : ");
         scanf("%d",&nb_gants);
        e->gants=e->gants+nb_gants;
        printf("commande a ete effectuee avec succes");
    }
}
int rech_nb_pat(LISTE_PATIENT L, int nb)
{
    int i=1,res=0;
    while(i<=liste3Taille(L))
    {
        if (recuperer3(L,i)->gouvernorat ==nb)
        {
            res++;
        }
        i++;
    }
    return res;

}


void graphique (LISTE_PATIENT L)
 {
  int ariana=rech_nb_pat(L,12);
  int beja=rech_nb_pat(L,31);
  int bizert=rech_nb_pat(L,23);
  int gabes=rech_nb_pat(L,81);
  int gafsa=rech_nb_pat(L,71);
  int jendouba=rech_nb_pat(L,32);
  int kairaouan=rech_nb_pat(L,41);
  int kasserine=rech_nb_pat(L,42);
  int kebili=rech_nb_pat(L,73);
  int kef=rech_nb_pat(L,33);
  int mahdia=rech_nb_pat(L,53);
  int manouba=rech_nb_pat(L,14);
  int medenine=rech_nb_pat(L,82);
  int monastir=rech_nb_pat(L,52);
  int nabeul=rech_nb_pat(L,21);
  int sfax=rech_nb_pat(L,61);
  int sidibouzid=rech_nb_pat(L,43);
  int siliana=rech_nb_pat(L,34);
  int sousse=rech_nb_pat(L,51);
  int tataouin=rech_nb_pat(L,83);
  int tozeur=rech_nb_pat(L,72);
  int tunis=rech_nb_pat(L,11);
  int ben_arous=rech_nb_pat(L,13);
  int zaghouan=rech_nb_pat(L,22);

 printf("                                                          %d*                        ",ben_arous);
 printf("\n");
 printf("                                                           *%d*                       ",nabeul);
 printf("\n");
 printf("                                               * * * %d   *   *                      ",bizert);
 printf("\n");
 printf("                                            %d*%d    *%d   *   *                       ",jendouba,beja,ariana);
 printf("\n");
 printf("                                             *  %d  *%d  *   *                        ",manouba,tunis);
 printf("\n");
 printf("                                            *       %d      *                        ",zaghouan);
 printf("\n");
 printf("                                        %d  *     %d         %d*                      ",kef,siliana,sousse);
 printf("\n");
 printf("                                            *     %d           %d*                   ",kairaouan,monastir);
 printf("\n");
 printf("                                             *%d                 %d*                ",kasserine,mahdia);
 printf("\n");
 printf("                                             *        %d            *                ",sidibouzid);
 printf("\n");
 printf("                                             *                     *                 ");
 printf("\n");
 printf("                                             *                 %d *                   ",sfax);
 printf("\n");
 printf("                                             *  %d              *                    ",gafsa);
 printf("\n");
 printf("                                            *                 *                      ");
 printf("\n");
 printf("                                            *                *                      ");
 printf("\n");
 printf("                                         %d *               %d *                         ",tozeur,gabes);
 printf("\n");
 printf("                                         *         %d         *                      ",kebili);
 printf("\n");
 printf("                                        *                       *                    ");
 printf("\n");
 printf("                                       *                        %d*                  ",medenine);
 printf("\n");
 printf("                                        *                           *                ");
 printf("\n");
 printf("                                          *                          *               ");
 printf("\n");
 printf("                                            *                         *              ");
 printf("\n");
 printf("                                              *                       *              ");
 printf("\n");
 printf("                                               *               %d    *               ",tataouin);
 printf("\n");
 printf("                                             *                     *                 ");
 printf("\n");
 printf("                                           *                     *                   ");
 printf("\n");
 printf("                                             *                   *                   ");
 printf("\n");
 printf("                                              *                  *                   ");
 printf("\n");
 printf("                                               *                 *                   ");
 printf("\n");
 printf("                                                *                *                   ");
 printf("\n");
 printf("                                                *                *                   ");
 printf("\n");
 printf("                                                *               *                    ");
 printf("\n");
 printf("                                                *              *                     ");
 printf("\n");
 printf("                                                 *            *                      ");
 printf("\n");
 printf("                                                   *         *                       ");
 printf("\n");
 printf("                                                     *     *                         ");
 printf("\n");
 printf("                                                      *   *                          ");
 printf("\n");
 printf("                                                      *     *                        ");
 printf("\n");
 printf("                                                      *     *                        ");
 printf("\n");
 printf("                                                      *   *                          ");
 printf("\n");
 printf("                                                      *  *                           ");
 printf("\n");
 printf("                                                       *                             ");
}

void reseau (LISTE_PATIENT L)
{  int i=1;
    NOEUD1 p=L->tete;
    while(p!=NULL)
    {int j;
      int nb_tn=0,nb_fr=0,nb_it=0,nb_esp=0,nb_eg=0;
        for(j=1;j<=liste2Taille(p->info->L_PER);j++)
        {
            switch (recuperer2(p->info->L_PER,j)->code_pays)
                {
                    case 1 : nb_tn++; break;
                    case 2 : nb_fr++;break;
                    case 3 : nb_it++;break;
                    case 4 : nb_esp++;break;
                    case 5 : nb_eg++;break;
                }
        }
        if (nb_fr!=0) {printf("                    FR: %d\n",nb_fr);}
        if (nb_it!=0) {printf("                    IT: %d\n",nb_it);}
        if (nb_esp!=0){printf("         ESP: %d",nb_esp);}
                       printf("                    **P%d** ",i);
        if (nb_eg!=0) {printf("  EGY: %d\n",nb_eg);}


        if (nb_tn!=0) {printf("   TN: %d\n",nb_tn);}
        i++;
        p=p->suivant;
        printf("\n");
        printf("\n");
    }
}





void main()
{ int choix1,choix11,choix111,choix1111,choix1112,choix1113,choix1114,choix1115,choix112,choix1121,choix1122,choix1123,choix131,choix132,choix142,choix143,choix144,choix145;
int choix12,choix121,choix122,choix123,choix124,choix125,choix13,choix151,choix161,nb_pat,choix14,choix141,nb_pharm,nb_lieu,nb_hop,nb_per, CIN;
  LISTE_PATIENT LPAT= liste3Creer();
  LISTE_HOPITAL LHOP= liste4Creer();
  LISTE_QUARANTAINE LQUAR= liste6Creer();
  LISTE_LIEU LLIEU= liste7Creer();
  LISTE_PHARMACIE LPHARM= liste10Creer();

  //Initialisation des patiens
  ELEMENT3 pat1=element3Creer();
  strcpy(pat1->nom,"ben ali");
  strcpy(pat1->prenom,"mohamed");
  strcpy(pat1->adr,"16 Rue Ibn El Jazzar Skanes");
  pat1->age=64;
  pat1->code_postal=5000;
  pat1->cont_intro=1;
  pat1->etat=1;
  pat1->NCIN=11254697;
  pat1->sexe=1;
  pat1->etat_marital=2;
  pat1->num_tel=25471236;
  pat1->gouvernorat=53;

  ELEMENT2 per11=element2Creer();
  ELEMENT2 per12=element2Creer();
  strcpy(per11->nom,"ammar");
  strcpy( per11->prenom,"Paul");
  strcpy(per11->adr,"marseille");
  per11->age=55;
  per11->code_pays=2;
  inserer2(pat1->L_PER,per11,1);


  strcpy(per12->nom,"ben mohamed");
  strcpy(per12->prenom,"salah");
  strcpy(per12->adr,"le vieux Caire, Cairo Governorate, Egypte");
  per12->age=43;
  per12->code_pays=5;
   inserer2(pat1->L_PER,per12,2);

ELEMENT1 mal11 =element1Creer();
strcpy(mal11->mal,"diabete");
inserer1(pat1->L_MAL,mal11,1);

inserer3(LPAT,pat1,1);

  ELEMENT3 pat2=element3Creer();
  strcpy(pat2->nom,"hechmi");
  strcpy(pat2->prenom,"helmi");
  strcpy(pat2->adr,"Route Tatouine Immeuble Boussaid,");
  pat2->age=27;
  pat2->code_postal=4100;
  pat2->cont_intro=0;
  pat2->etat=1;
  pat2->NCIN=11789523;
  pat2->sexe=1;
  pat2->etat_marital=0;
  pat2->num_tel=25471236;
  pat2->gouvernorat=82;

  ELEMENT2 per21=element2Creer();
  ELEMENT2 per22=element2Creer();
  strcpy(per21->nom,"mellouli");
  strcpy( per21->prenom,"adem");
  strcpy(per21->adr,"houmet souk 7510");
  per21->age=32;
  per21->code_pays=1;
  inserer2(pat2->L_PER,per21,1);


  strcpy(per22->nom,"ben mohamed");
  strcpy(per22->prenom,"selim");
  strcpy(per22->adr,"nahj ljazira 1416");
  per22->age=29;
  per22->code_pays=1;
   inserer2(pat2->L_PER,per22,2);

ELEMENT1 mal21 =element1Creer();
strcpy(mal21->mal,"hypertension arterielle");
inserer1(pat2->L_MAL,mal21,1);

inserer3(LPAT,pat2,2);

ELEMENT3 pat3=element3Creer();
  strcpy(pat3->nom,"louati");
  strcpy(pat3->prenom,"salma");
  strcpy(pat3->adr,"11 2045 rue mesk Elllil");
  pat3->age=51;
  pat3->code_postal=2090;
  pat3->cont_intro=1;
  pat3->etat=0;
  pat3->NCIN=17551423;
  pat3->sexe=0;
  pat3->etat_marital=2;
  pat3->num_tel=25471236;
  pat3->gouvernorat=12;


ELEMENT1 mal31 =element1Creer();
strcpy(mal31->mal,"asthme");
inserer1(pat3->L_MAL,mal31,1);

inserer3(LPAT,pat3,3);

ELEMENT3 pat4=element3Creer();
  strcpy(pat4->nom,"bellil");
  strcpy(pat4->prenom,"Mohssen");
  strcpy(pat4->adr,"Rue Mohamed Ali, Bizerte 7080");
  pat4->age=83;
  pat4->code_postal=5100;
  pat4->cont_intro=1;
  pat4->etat=1;
  pat4->NCIN=11546331;
  pat4->sexe=1;
  pat4->etat_marital=3;
  pat4->num_tel=25471236;
  pat4->gouvernorat=23;

 // printf("Patient 1 :\n");
  printf("\n");
  ELEMENT2 per41=element2Creer();
  strcpy(per41->nom,"trabelsi");
  strcpy(per41->prenom,"hssan");
  strcpy(per41->adr,"Ave Bourguiba, Ghar El Melh 2140");
  per41->age=77;
  per41->code_pays=1;
   inserer2(pat4->L_PER,per41,1);


ELEMENT1 mal41 =element1Creer();
strcpy(mal41->mal,"cancer du pancréas");
inserer1(pat4->L_MAL,mal41,1);

inserer3(LPAT,pat4,4);

ELEMENT3 pat5=element3Creer();
  strcpy(pat5->nom,"chaari");
  strcpy(pat5->prenom,"hasna");
  strcpy(pat5->adr,"Avenue Hedi Nouira, Hammamet 8050");
  pat5->age=18;
  pat5->code_postal=8050;
  pat5->cont_intro=1;
  pat5->etat=1;
  pat5->NCIN=11114789;
  pat5->sexe=0;
  pat5->etat_marital=3;
  pat5->num_tel=25471236;
  pat5->gouvernorat=21;

  ELEMENT2 per51=element2Creer();
  ELEMENT2 per52=element2Creer();
  ELEMENT2 per53=element2Creer();
  strcpy(per51->nom,"ferjani");
  strcpy( per51->prenom,"melik");
  strcpy(per51->adr,"Avenue Habib Bourguiba, Marsa 2080");
  per51->age=19;
  per51->code_pays=2;
  inserer2(pat5->L_PER,per51,1);


  strcpy(per52->nom,"kochlev");
  strcpy(per52->prenom,"mayssa");
  strcpy(per52->adr,"Boumhel El Bassatine 2097");
  per52->age=21;
  per52->code_pays=4;
   inserer2(pat5->L_PER,per52,2);

   strcpy(per53->nom,"ben sassi");
  strcpy(per53->prenom,"leila");
  strcpy(per53->adr,"16 rue hedi mansouri, cite ibn khaldoun,tunis 1070");
  per53->age=20;
  per53->code_pays=1;
   inserer2(pat5->L_PER,per53,3);

inserer3(LPAT,pat5,5);


 ELEMENT6 p1=element6Creer();
           strcpy(p1->nom,per11->nom);
           strcpy(p1->prenom,per11->prenom);
           strcpy(p1->adr,per11->adr);
           p1->age=per11->age;
            p1->code_postal=2080;

  p1->cont_intro=0;
  p1->etat=1;
  p1->NCIN=55555555;
  p1->sexe=1;
  p1->provenance=1;
  p1->etat_marital=3;
  p1->num_tel=22414565;
  p1->gouvernorat=12;
  p1->d_debut.jour=2;
  p1->d_debut.mois=3;
  p1->d_debut.annee=2020;
  p1->d_fin.jour=18;
  p1->d_fin.mois=3;
  p1->d_fin.annee=2020;
  inserer6(LQUAR,p1,1);

   ELEMENT6 p2=element6Creer();
           strcpy(p2->nom,per12->nom);
           strcpy(p2->prenom,per12->prenom);
           strcpy(p2->adr,per12->adr);
           p2->age=per12->age;

  p2->code_postal=2070;
  p2->cont_intro=1;
  p2->etat=0;
  p2->NCIN=11555555;
  p2->sexe=0;
  p2->provenance=0;
  p2->etat_marital=1;
  p2->num_tel=22414445;
  p2->gouvernorat=11;
  p2->d_debut.jour=5;
  p2->d_debut.mois=3;
  p2->d_debut.annee=2020;
  p2->d_fin.jour=29;
  p2->d_fin.mois=3;
  p2->d_fin.annee=2020;
  inserer6(LQUAR,p2,2);



  // initialisation des hopitaux
  ELEMENT4 hop1=element4Creer();
      strcpy(hop1->adr,"Route de Bizerte Ariana 2080");
     strcpy(hop1->nom,"Hopital de Pneumo Phtisiologie");

  hop1->id=1;
  hop1->code_postal=2080;
  hop1->gouvernorat=12;
  hop1->nb_lits_ailleurs=70;
  hop1->nb_lits_rea=15;
  hop1->nb_med_corona=10;
  hop1->nb_paramedicaux=50;
   hop1->tel=71713645;
  hop1->fax=71713645;
  hop1->urg=71821188;

  inserer4(LHOP,hop1,1);

  ELEMENT4 hop2=element4Creer();
  hop2->tel=78457322;
  hop2->fax=71713645;
  hop2->urg=71821188;
  hop2->gouvernorat=31;
  hop2->code_postal=9000;
  hop2->nb_lits_ailleurs=35;
  hop2->nb_lits_rea=10;
  hop2->nb_med_corona=6;
  hop2->nb_paramedicaux=20;
  strcpy(hop2->nom,"Hopital regional de beja");
  strcpy(hop2->adr,"Avenue Habib BOURGUIBA 9000 BEJA");
  hop2->id=2;
  inserer4(LHOP,hop2,2);

  ELEMENT4 hop3=element4Creer();
  hop3->id=3;
  hop3->tel=71262740;
  hop3->fax=71262740;
  hop3->urg=71578007;
  hop3->code_postal=1006;
  hop3->gouvernorat=11;
  hop3->nb_lits_ailleurs=100;
  hop3->nb_lits_rea=20;
  hop3->nb_med_corona=12;
  hop3->nb_paramedicaux=60;
  strcpy(hop3->nom,"Charles Nicolle");
  strcpy(hop3->adr,"Boulevard 9 Avril 1938, Tunis-1006,");
  inserer4(LHOP,hop3,3);


  ELEMENT4 hop4=element4Creer();
  hop4->id=4;
  hop4->tel=71764325;
  hop4->fax=71765118;
  hop4->urg=71764845;
  hop4->code_postal=2070;
  hop4->gouvernorat=11;
  hop4->nb_lits_ailleurs=40;
  hop4->nb_lits_rea=15;
  hop4->nb_med_corona=9;
  hop4->nb_paramedicaux=30;
  strcpy(hop4->nom,"Hopital Mongi Slim");
  strcpy(hop4->adr,"Sidi Daoud, la Marsa, 2070");
  inserer4(LHOP,hop4,4);


  ELEMENT4 hop5=element4Creer();
  hop5->id=5;
  hop5->tel=71263980;
  hop5->fax=71263980;
  hop5->urg=71800114;
  hop5->code_postal=1006;
  hop5->gouvernorat=11;
  hop5->nb_lits_ailleurs=35;
  hop5->nb_lits_rea=11;
  hop5->nb_med_corona=6;
  hop5->nb_paramedicaux=25;
  strcpy(hop5->nom,"Institut Salah Azaiez");
  strcpy(hop5->adr,"Bab Saadoun, Tunis-1006");
  inserer4(LHOP,hop5,5);

  ELEMENT4 hop6=element4Creer();
  hop6->id=6;
  hop6->tel=74242181;
  hop6->fax=74242181;
  hop6->urg=74244422;
  hop6->code_postal=3020;
  hop6->gouvernorat=61;
  hop6->nb_lits_ailleurs=80;
  hop6->nb_lits_rea=50;
  hop6->nb_med_corona=20;
  hop6->nb_paramedicaux=80;
  strcpy(hop6->nom,"Hopital Hedi Chaker");
  strcpy(hop6->adr,"Route El Ain Km 0,5-Sfax");
  inserer4(LHOP,hop6,6);

   ELEMENT4 hop7=element4Creer();
   hop7->id=7;
  hop7->tel=73222293;
  hop7->fax=73222293;
  hop7->urg=73223311;
  hop7->code_postal=4000;
  hop7->gouvernorat=51;
  hop7->nb_lits_ailleurs=150;
  hop7->nb_lits_rea=35;
  hop7->nb_med_corona=25;
  hop7->nb_paramedicaux=80;
  strcpy(hop7->nom,"Hopital Farhat Hached");
  strcpy(hop7->adr," Avenue Ibn El Jazzar-Sousse- 4000");
  inserer4(LHOP,hop7,7);

  ELEMENT4 hop8=element4Creer();
  hop8->id=8;
  hop8->tel=73222293;
  hop8->fax=73222293;
  hop8->urg=73223311;
  hop8->code_postal=2010;
  hop8->gouvernorat=14;
  hop8->nb_lits_ailleurs=55;
  hop8->nb_lits_rea=12;
  hop8->nb_med_corona=10;
  hop8->nb_paramedicaux=55;
  strcpy(hop8->nom,"Institut Mohamed Kassab d'Orthopédie");
  strcpy(hop8->adr," Ksar Saïd - 2010");
  inserer4(LHOP,hop8,8);

  ELEMENT4 hop9=element4Creer();
  hop9->id=9;
  hop9->tel=72640477;
  hop9->fax=72640016;
  hop9->urg=72640140 ;
  hop9->code_postal=1111;
  hop9->gouvernorat=22;
  hop9->nb_lits_ailleurs=40;
  hop9->nb_lits_rea=8;
  hop9->nb_med_corona=10;
  hop9->nb_paramedicaux=25;
  strcpy(hop9->nom,"Complexe sanitaire Djebel Ouest");
  strcpy(hop9->adr," Route Zaghouane-1111");
  inserer4(LHOP,hop9,9);

  //INITIALISATION DES LIEUX
  ELEMENT7 lieu1=element7Creer();
  strcpy(lieu1->nom,"Hopital Charles Nicolle");
  strcpy(lieu1->adr,"Boulevard 9 Avril 1938 Tunis-1006");
  lieu1->capacite=250;
  lieu1->code_postal=2070;
  lieu1->gouvernorat=11;
  inserer7(LLIEU,lieu1,1);

  ELEMENT7 lieu2=element7Creer();
  strcpy(lieu2->nom,"Foyer Universitaire Ariana Thameur ");
  strcpy(lieu2->adr,"Avenue Habib Thameur, Ariana");
  lieu2->capacite=150;
  lieu2->code_postal=2000;
  lieu2->gouvernorat=12;
  inserer7(LLIEU,lieu2,2);


  ELEMENT7 lieu3=element7Creer();
  strcpy(lieu3->nom," foyer unitaire kasserine");
  strcpy(lieu3->adr," P 17, Kasserine");
  lieu3->capacite=120;
  lieu3->code_postal=1200;
  lieu3->gouvernorat=42;
  inserer7(LLIEU,lieu3,3);

  ELEMENT7 lieu4=element7Creer();
  strcpy(lieu4->nom," Hotel phenix");
  strcpy(lieu4->adr," Avenue de la republique,beja");
  lieu4->capacite=230;
  lieu4->code_postal=9000;
  lieu4->gouvernorat=31;
  inserer7(LLIEU,lieu4,4);

  ELEMENT7 lieu5=element7Creer();
  strcpy(lieu5->nom," Foyer universitaire Ben Arous");
  strcpy(lieu5->adr," Rue 20 mars,Ben Arous");
  lieu5->capacite=210;
  lieu5->code_postal=2013;
  lieu5->gouvernorat=42;
  inserer7(LLIEU,lieu5,5);

  ELEMENT7 lieu6=element7Creer();
  strcpy(lieu6->nom,"Hotel nour");
  strcpy(lieu6->adr," Zone touristique sidi salem,bizerte");
  lieu6->capacite=300;
  lieu6->code_postal=7100;
  lieu6->gouvernorat=23;
  inserer7(LLIEU,lieu6,6);

    ELEMENT7 lieu7=element7Creer();
  strcpy(lieu7->nom," Hopital regional de gabes mohamed ben sassi");
  strcpy(lieu7->adr,"Mtorrech, rue ibn khaldoun");
  lieu7->capacite=80;
  lieu7->code_postal=6500;
  lieu7->gouvernorat=81;
  inserer7(LLIEU,lieu7,7);

  ELEMENT7 lieu8=element7Creer();
  strcpy(lieu8->nom," Foyer jihene");
  strcpy(lieu8->adr,"Sidi ahmed zarroug,Gafsa");
  lieu8->capacite=105;
  lieu8->code_postal=2120;
  lieu8->gouvernorat=71;
  inserer7(LLIEU,lieu8,8);

  ELEMENT7 lieu9=element7Creer();
  strcpy(lieu9->nom," Hotel royal rihana");
  strcpy(lieu9->adr," P17,ayn drahim");
  lieu9->capacite=140;
  lieu9->code_postal=8130;
  lieu9->gouvernorat=32;
  inserer7(LLIEU,lieu9,9);

  ELEMENT7 lieu10=element7Creer();
  strcpy(lieu10->nom," Hopital ibn el jazzar");
  strcpy(lieu10->adr,"Rue ibn el jazzar,kairouan");
  lieu10->capacite=350;
  lieu10->code_postal=3100;
  lieu10->gouvernorat=41;
  inserer7(LLIEU,lieu10,10);

  ELEMENT7 lieu11=element7Creer();
  strcpy(lieu11->nom," Foyer prive roma");
  strcpy(lieu11->adr,"Avenue habib bourguiba,le kef");
  lieu11->capacite=550;
  lieu11->code_postal=7100;
  lieu11->gouvernorat=33;
  inserer7(LLIEU,lieu11,11);

  ELEMENT7 lieu12=element7Creer();
  strcpy(lieu12->nom," Yadis oasis kebili");
  strcpy(lieu12->adr,"Route touristique kebili");
  lieu12->capacite=70;
  lieu12->code_postal=4200;
  lieu12->gouvernorat=73;
  inserer7(LLIEU,lieu12,12);

  ELEMENT7 lieu13=element7Creer();
  strcpy(lieu13->nom," Hotel houria house sable d'or");
  strcpy(lieu13->adr," Avenue tahar sfar la corniche,mahdia");
  lieu13->capacite=340;
  lieu13->code_postal=5100;
  lieu13->gouvernorat=53;
  inserer7(LLIEU,lieu13,13);

  ELEMENT7 lieu14=element7Creer();
  strcpy(lieu14->nom," Foyer universitaire ibn zohr");
  strcpy(lieu14->adr," Rue ibn zohr");
  lieu14->capacite=220;
  lieu14->code_postal=1120;
  lieu14->gouvernorat=14;
  inserer7(LLIEU,lieu14,14);

  ELEMENT7 lieu15=element7Creer();
  strcpy(lieu15->nom," Hopital regional habib bourguiba");
  strcpy(lieu15->adr,"Medenine");
  lieu15->capacite=50;
  lieu15->code_postal=4100;
  lieu15->gouvernorat=82;
  inserer7(LLIEU,lieu15,15);

  ELEMENT7 lieu16=element7Creer();
  strcpy(lieu16->nom,"Clinique debbabi");
  strcpy(lieu16->adr," Avenue avicenne,monastir");
  lieu16->capacite=200;
  lieu16->code_postal=5000;
  lieu16->gouvernorat=52;
  inserer7(LLIEU,lieu16,16);

  ELEMENT7 lieu17=element7Creer();
  strcpy(lieu17->nom," Hopital regional mohamed tahar el maamouri");
  strcpy(lieu17->adr,"Mrazka hammamet nabeul");
  lieu17->capacite=305;
  lieu17->code_postal=8000;
  lieu17->gouvernorat=21;
  inserer7(LLIEU,lieu17,17);

  ELEMENT7 lieu18=element7Creer();
  strcpy(lieu18->nom," Foyer universitaire sfax al jadida");
  strcpy(lieu18->adr,"Sfax");
  lieu18->capacite=500;
  lieu18->code_postal=3000;
  lieu18->gouvernorat=61;
  inserer7(LLIEU,lieu18,18);

  ELEMENT7 lieu19=element7Creer();
  strcpy(lieu19->nom,"Hopital regional de sidi bouzid");
  strcpy(lieu19->adr,"Cite yassminet");
  lieu19->capacite=140;
  lieu19->code_postal=9100;
  lieu19->gouvernorat=43;
  inserer7(LLIEU,lieu19,19);

  ELEMENT7 lieu20=element7Creer();
  strcpy(lieu20->nom," Hotel zama");
  strcpy(lieu20->adr,"C73,siliana");
  lieu20->capacite=240;
  lieu20->code_postal=6100;
  lieu20->gouvernorat=34;
  inserer7(LLIEU,lieu20,20);

  ELEMENT7 lieu21=element7Creer();
  strcpy(lieu21->nom," Foyer carthago");
  strcpy(lieu21->adr,"Carthago,sousse");
  lieu21->capacite=360;
  lieu21->code_postal=4023;
  lieu21->gouvernorat=51;
  inserer7(LLIEU,lieu21,21);

  ELEMENT7 lieu22=element7Creer();
  strcpy(lieu22->nom,"Sangho privilege tataouine");
  strcpy(lieu22->adr,"Route de chenini el farch");
  lieu22->capacite=140;
  lieu22->code_postal=3200;
  lieu22->gouvernorat=83;
  inserer7(LLIEU,lieu22,22);

  ELEMENT7 lieu23=element7Creer();
  strcpy(lieu23->nom,"Hotel la palmeraie");
  strcpy(lieu23->adr,"Zone touristique, tozeur");
  lieu23->capacite=220;
  lieu23->code_postal=2200;
  lieu23->gouvernorat=72;
  inserer7(LLIEU,lieu23,23);

  ELEMENT7 lieu24=element7Creer();
  strcpy(lieu24->nom,"Dar zaghouan");
  strcpy(lieu24->adr,"Zaghouan");
  lieu24->capacite=190;
  lieu24->code_postal=1100;
  lieu24->gouvernorat=22;
  inserer7(LLIEU,lieu24,24);






  // initialisation des pharmacies
  ELEMENT10 phar1=element10Creer();
  strcpy(phar1->nom,"abdelkader Chaouch");
  strcpy(phar1->adr,"79 Avenue Hédi Chaker, Tunis");
  phar1->bav=200;
  phar1->gel=250;
  phar1->gants=250;
  phar1->chlor=20;
  phar1->par=30;
  phar1->ther=300;
  phar1->gouvernorat=11;
  phar1->tel= 71289806;
  inserer10(LPHARM,phar1,1);



    MenuPrincipal :
    printf("                                    C O R O N A    V I R U S \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                    ------------1.Gestion des patients et hopitaux ---------------\n");
    printf("                    ------------2.Gestion des personnes en quarantaine------------\n");
    printf("                    ------------3.Gestion des dons/besoins------------------------\n");
    printf("                    ------------4.Gestion des pharmacies--------------------------\n");
    printf("                    ------------5.Rrepartition geographique des cas---------------\n");
    printf("                    ------------6.Reseau de propagation---------------------------\n");
    printf("                    ------------7.QUITTER-----------------------------------------\n");
    printf("              .Bienvenue cher utilisateur, veuillez choisir l'une de ces suggestions ci dessus : \n");

    do{
    scanf("%d",&choix1);
      }
      while ((choix1<1)||(choix1>7)) ;

    if (choix1==1)
    { system("cls");
        Menu_1 :

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                    ------------------1.Gestion des patients-----------------\n");
    printf("                    ------------------2.Gestion des hopitaux-----------------\n");
    printf("                    ------------------3.Retour au menu principal-------------\n");

    printf("\n");
    printf("                     .Veuillez choisir une des propositions ci dessus :\n");

    do{
    scanf("%d",&choix11);
      }
      while ((choix11<1)||(choix11>3)) ;
      if (choix11==1)
      { system("cls");
          Menu_1_1 :

    printf("\n");
    printf("\n");

    printf("\n");
    printf("                    ------------------1.Ajouter un patient---------------\n");
    printf("                    ------------------2.Afficher tous les patients-------\n");
    printf("                    ------------------3.Modifier l etat d un patient-----\n");
    printf("                    ------------------4.Recherche d un patient-----------\n");
    printf("                    ------------------5.Suppression d un patient---------\n");
    printf("                     .Veuillez choisir une des propositions ci dessus:\n");

    do{
    scanf("%d",&choix111);
      }
      while ((choix111<1)||(choix111>5)) ;
      if (choix111==1)
      {
      printf("Combien de patient a ajouter : ");
      scanf("%d",&nb_pat);
      ajout_patient(LPAT,nb_pat);
       do {
         printf("\n Tapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1111);
       } while((choix1111<1)||(choix1111>3));
       switch(choix1111)
       {
           case 1 : system("cls");goto Menu_1 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
      }

       if (choix111==2)
      { trier(LPAT);
    affichage_patient(LPAT);
     do {
         printf("\n Tapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1112);
       } while((choix1112<1)||(choix1112>3));
       switch(choix1112)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }
      }
        if (choix111==3)
       {
          // modifEtat(L_PAT);
      printf("Donner son numero de CIN");
      scanf("%d",&CIN);
      modifEtat(LPAT,CIN);
      do {
         printf("\n Tapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1113);
       } while((choix1113<1)||(choix1113>3));
       switch(choix1113)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }

       }
       if (choix111==4)
       {
           recherche_patient(LPAT);
           do {
         printf("\n Tapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1114);
       } while((choix1114<1)||(choix1114>3));
       switch(choix1114)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }
       }
       if (choix111==5)
        {
            printf("Donner le numero cin du patient a supprimer");
            scanf("%d",&CIN);
            supp_patient(LPAT,CIN);
             do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1115);
       } while((choix1115<1)||(choix1115>3));
       switch(choix1115)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }
        }
              }
              else if (choix11==2)
              {
                  system("cls");
                  Menu_1_2 :
                      printf("\n");
    printf("\n");

    printf("\n");
    printf("                    ---------------1.Ajouter un hopital---------------\n");
    printf("                    ---------------2.Affecter les patients------------\n");
    printf("                    ---------------3.Afficher tous les hopitaux-------\n");
    printf("\n");
    printf("                     .Veuillez choisir une des propositions ci dessus : \n");

                     do{
                          scanf("%d",&choix112);
                       }
                   while ((choix112<1)||(choix112>3)) ;

        if (choix112==1)
            {
            printf("combien d hopital vous allez ajouter : ");
              scanf("%d",&nb_hop);
              ajout_hopital(LHOP,nb_hop);

           do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1121);
       } while((choix1121<1)||(choix1121>3));
       switch(choix1121)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }
        }
        else if (choix112==2)
        {
            hoppat(LPAT,LHOP);
            printf("Affectation a ete effectuee avec succes ");

            do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1123);
       } while((choix1123<1)||(choix1123>3));
       switch(choix1123)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }

        }
        else if (choix112==3)
        {
            liste4Afficher(LHOP);

            do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix1122);
       } while((choix1122<1)||(choix1122>3));
       switch(choix1122)
       {
           case 1 :  system("cls");goto Menu_1 ; break;
           case 2 :  system("cls"); goto MenuPrincipal; break;
           default : exit(0);
       }
        }




              }
              else { system("cls");goto MenuPrincipal;}

    }
    else if (choix1==2)
    {
        system("cls");
        Menu_2 :

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                        ------------------1.Gestion de nouvelles personnes----------------\n");
    printf("                        ------------------2.Gestion des anciennes personnes---------------\n");
    printf("                        ------------------3.Afficher toutes les personnes-----------------\n");
    printf("                        ------------------4.Gestion des lieux-----------------------------\n");
    printf("                        ------------------5.Afficher les lieux----------------------------\n");
    printf("                        ------------------6.Retour au menu principal----------------------\n");

    printf("\n");
    printf("                          .Veuillez choisir une des propositions ci dessus : \n");
    do
    {
        scanf("%d",&choix12);
    }
    while((choix12<1)||(choix12>6));

       if (choix12==1)
    {
         printf("Combien de personne a ajouter : ");
      scanf("%d",&nb_per);
      ajout_quarantaine(LQUAR,nb_per);
       do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix121);
       } while((choix121<1)||(choix121>3));
       switch(choix121)
       {
           case 1 : system("cls");goto Menu_2 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix12==2)
    {
          ajout_per_pat(LPAT,LQUAR);
          do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix122);
       } while((choix122<1)||(choix122>3));
       switch(choix122)
       {
           case 1 : system("cls");goto Menu_2 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix12==3)
    {
        liste6Afficher(LQUAR);
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix123);
       } while((choix123<1)||(choix123>3));
       switch(choix123)
       {
           case 1 : system("cls");goto Menu_2 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
     else if (choix12==4)
    {   printf("combien de lieu a ajouter : ");
         scanf("%d",&nb_lieu);

        ajout_lieu(LLIEU,nb_lieu);

        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix124);
       } while((choix124<1)||(choix124>3));
       switch(choix124)
       {
           case 1 : system("cls");goto Menu_2 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix12==5)
    {
         lieuper(LQUAR,LLIEU);
         liste7Afficher(LLIEU);

         do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix125);
       } while((choix125<1)||(choix125>3));
       switch(choix125)
       {
           case 1 : system("cls");goto Menu_2 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if(choix12==6){ system("cls"); goto MenuPrincipal; }

    }


    else if (choix1==3)
    {
        system("cls");
        Menu_3 :

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                        ------------------1.Ajout d un don-----------------\n");
    printf("                        ------------------2.Suppression d un don-----------\n");
    printf("                        ------------------3.Retour au menu principal-------\n");

    printf("\n");
    printf("                          .Veuillez choisir une des propositions ci dessus : \n");
    do
    {
        scanf("%d",&choix13);
    }
    while((choix13<1)||(choix13>3));
    if(choix13==1)
    {
        ajout_don(LHOP);

         do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix131);
       } while((choix131<1)||(choix131>3));
       switch(choix131)
       {
           case 1 : system("cls");goto Menu_3 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix13==2)
    {
        supp_don(LHOP);
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix132);
       } while((choix132<1)||(choix132>3));
       switch(choix132)
       {
           case 1 : system("cls");goto Menu_3 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix13==3)
    {  system("cls");
        goto MenuPrincipal;
    }

    }
    else if (choix1==4)
    {
        system("cls");
        Menu_4 :

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                        ------------------1.Gestion des pharmacies-----------------\n");
    printf("                        ------------------2.Retour au menu principal---------------\n");
    printf("\n");
    printf("                              .Veuillez choisir l une de ces propositions :\n");
    do
    {
        scanf("%d",&choix14);
    }
    while((choix14<1)||(choix14>2));
    if (choix14==1)
    {
        system("cls");
        Menu_41 :

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                        ------------------1.ajout d une pharmacie-----------------\n");
    printf("                        ------------------2.Gestion du stock----------------------\n");
    printf("                        ------------------3.passer une commande-------------------\n");
    printf("                        ------------------4.afficher les pharmacies---------------\n");

    printf("\n");
    printf("               .Veuillez choisir une des propositions ci dessus : \n");
    do
    {
        scanf("%d",&choix141);
    }
    while((choix141<1)||(choix141>4));

    if (choix141==1)
    {  printf("Combien de pharmacie a ajouter");
       scanf("%d",&nb_pharm);
        ajout_pharma(LPHARM,nb_pharm);
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix142);
       } while((choix142<1)||(choix142>3));
       switch(choix142)
       {
           case 1 : system("cls");goto Menu_4 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix141==2)
    {
        char nom[20];int i=1, trouve=0;
        printf("Donner le nom de la pharmacie ");
        fflush(stdin);
        gets(nom);
        while ((i<=liste10Taille(LPHARM))&&(!trouve))
        {
            if (strcmp(nom,recuperer10(LPHARM,i))==0)
            {
                passer_commande(recuperer10(LPHARM,i));
                trouve=1;
            }
            i++;
        }
        if(trouve==0) printf("Pharmacie introuvable. \n");

        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix143);
       } while((choix143<1)||(choix143>3));
       switch(choix143)
       {
           case 1 : system("cls");goto Menu_4 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }

    }
    else if (choix141==3)
    {
        char nom[20];int i=1, trouve=0;
        printf("donner le nom de la pharmacie ");
        fflush(stdin);
        gets(nom);
        while ((i<=liste10Taille(LPHARM))&&(!trouve))
        {
            if (strcmp(nom,recuperer10(LPHARM,i))==0)
            {
                vente_med(recuperer10(LPHARM,i));
                trouve=1;
            }
            i++;
        }
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix144);
       } while((choix144<1)||(choix144>3));
       switch(choix144)
       {
           case 1 : system("cls");goto Menu_4 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    else if (choix141==4)
    {
        liste10Afficher(LPHARM);
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si voulez retournez au menu principal , 3 si vous voulez quitter");
         scanf("%d",&choix145);
       } while((choix145<1)||(choix145>3));
       switch(choix145)
       {
           case 1 : system("cls");goto Menu_4 ; break;
           case 2 : system("cls"); goto MenuPrincipal; break;
           default :exit(0);
       }
    }
    }
    else if (choix14==2)
    { system("cls");
        goto MenuPrincipal ;
    }

    }
    else if (choix1==5)
    {   system("cls");
        graphique(LPAT);
        do {
         printf("\nTapez 1 si vous voulez retourner au menu precedent, 2 si vous voulez quitter");
         scanf("%d",&choix151);
       } while((choix151<1)||(choix151>2));
       switch(choix151)
       {
           case 1 : system("cls");goto MenuPrincipal ; break;
           case 2 : system("cls"); exit(0); break;

       }

    }
    else if (choix1==6)
    {   system("cls");
       reseau(LPAT);
        do {
         printf("`\nTapez 1 si vous voulez retourner au menu precedent, 2 si vous voulez quitter");
         scanf("%d",&choix161);
       } while((choix161<1)||(choix161>2));
       switch(choix161)
       {
           case 1 : system("cls");goto MenuPrincipal ; break;
           case 2 : system("cls"); exit(0); break;

       }

    }


    else if (choix1==7){exit(0);}



}
