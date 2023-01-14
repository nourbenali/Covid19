#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include "LSTPRIM3.h"
#include "ELTPRIM3.h"
#include"ELTPRIM1.h"
#include"ELTPRIM2.h"
#include"LSTPRIM1.h"
#include"LSTPRIM2.h"
NOEUD1 noeud1Creer(ELEMENT3 e){

NOEUD1 n;

n =(NOEUD1)malloc(sizeof(structNoeud1));
if(!n)
	printf ("\nPlus d'espace");
else
	{
	element3Affecter(&n->info, e);
	n->suivant = NULL;
     n->precedent = NULL;
	}
return n;
}

void noeud1Detruire(NOEUD1 n){
element3Detruire(n->info);
free(n);
}

LISTE_PATIENT liste3Creer(void)  {
	LISTE_PATIENT L;
   L = (LISTE_PATIENT) malloc(sizeof(LSTPAT));
   if(!L) {
		printf("\nProbl%cme de m%cmoire",138,130) ;
		exit(0) ;
	}
   L->lg = 0;
   return(L);
}

void liste3Detruire(LISTE_PATIENT L)
{   NOEUD1 p,q;
    p=L->tete ;
    for (int i=1 ; i<=L->lg; i++)
    {
        q=p;
        p=p->suivant;
         noeud1Detruire(q);
    }

    free(L);

}

int est3Vide(LISTE_PATIENT L) {
	return (L->lg == 0);
}


int est3Saturee(LISTE_PATIENT L)
{
    NOEUD1 temp;
int saturee = 1; /* on suppose mémoire saturée */
temp = (NOEUD1) malloc ( sizeof ( structNoeud1 ) );
if(temp != NULL) {
saturee = 0; /* mémoire non saturée */
free(temp);
}
return saturee;
}


int liste3Taille(LISTE_PATIENT L) {
   return (L->lg);
}


void inserer3 (LISTE_PATIENT L, ELEMENT3 e, int pos)
{
int succee=1;
int i;
NOEUD1 n, p, q;
if (est3Saturee(L))
{
     printf ("\nListe saturée");
     succee=0;
}
else  {if  ((pos < 1) || (pos > L->lg + 1))
          {
	      printf ("\nPosition invalide");
	      succee=0;
          }
        else
	    {
	      n=noeud1Creer (e); /*on est sûr que la réservation va se faire car la mémoire n'est pas saturée*/

	      if (L->lg == 0) /* la liste est vide */
          {
           L->tete = n;
           L->queuee = n;
          }
          else {if (pos == 1)  /*insertion en tête de liste*/
            {
              L->tete->precedent = n;
              n->suivant=L->tete;
              L->tete = n;
            }
            else { if (pos == (L->lg) +1) /*  ajout à la fin */
              {
                  L->queuee->suivant = n;
               n->precedent = L->queuee;
               L->queuee = n;
  	          }
              else
              {
               q= L->tete;
               for (i=1; i<pos; i++)
               {
                 p = q;
                 q = q->suivant;
                }
                /* q désigne l’élément de rang pos et p son prédécesseur*/
                p->suivant=n;
                n->precedent=p;
                n->suivant=q;
                q->precedent=n;
               }
            }
               }
               L->lg++;
	    }
}


}

int supprimer3 (LISTE_PATIENT L, int pos ){
	int i;
	int succee=1;
	NOEUD1  p,  q;

  if (est3Vide(L))
{
    printf ("\nListe vide");
    succee=0;}
   else{
	if   ((pos < 1) || (pos > L->lg))
	    {
                   printf ("\nPosition invalide");
	       succee=0;
                 }
           else
                {
                     if (L->lg ==1) /* un seul element donc pos == 1*/
		{
		   q=L->tete;
		   L->tete = NULL;
		   L->queuee = NULL;
		}
else
   {
       if (pos == 1)  /*suppression en tête de liste*/
	{
                  q=L->tete;
                  L->tete=L->tete->suivant;
                  L->tete->precedent = NULL;
              }
        else
              {
                 if (pos == L->lg)
                     {
                        q=L->queuee;
	          L->queuee = L->queuee->precedent;
                         L->queuee->suivant = NULL;
	       }
else
      {
         q= L->tete;
         for (i=1; i<pos; i++)
            {  p = q;
            q = q->suivant;
            }
       /*q désigne l’élément de rang pos et p son prédécesseur*/
            q->suivant->precedent = p;
            p->suivant=q->suivant;
      }
    }
  }
  noeud1Detruire(q);
  (L->lg)--;
  }
 }
return succee;
}

ELEMENT3 recuperer3(LISTE_PATIENT L, int pos) {

	/*  s'il ya une erreur on affiche un message et on retourne un element vide */

	ELEMENT3 elt= element3Creer();
	int i;
	NOEUD1 p;

	if (est3Vide(L))
		printf ("\nListe vide");
	else	{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");
		else	{
			  p= L->tete;
			for (i=1; i<pos; i++)
				 {p = p->suivant;}
			 element3Affecter(&elt,p->info);
			}
		}
	return(elt);
}

void liste3Afficher(LISTE_PATIENT L)
{
   int i=1;
   NOEUD1 p;
   p=L->tete;

   for(i = 1;i <= L->lg; i++) {
        printf("Patient %d",i);
		element3Afficher(p->info);

		printf("\n");
		p= p->suivant;
	}

}


LISTE_PATIENT liste3Copier(LISTE_PATIENT L){

LISTE_PATIENT LR = liste3Creer();

int i;
ELEMENT3 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element3Creer();
		element3Copier(&elt, recuperer3(L,i));

		inserer3(LR,elt, i);
	}
 return LR;
}


int  liste3Comparer (LISTE_PATIENT L1,LISTE_PATIENT L2 )
{
int test= 1;
int i=1;

if (liste3Taille(L1) != liste3Taille(L2)) test= 0;

while ((i<=liste3Taille(L1)) && (test)) {
	   if (element3Comparer(recuperer3(L1,i),recuperer3(L2,i))!=0)
		test=0;
	i++;
}

return test;
}
