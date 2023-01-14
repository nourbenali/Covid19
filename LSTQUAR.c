#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include "LSTPRIM6.h"
#include "ELTPRIM6.h"
#include"ELTPRIM1.h"
#include"ELTPRIM2.h"
#include"LSTPRIM1.h"
#include"LSTPRIM2.h"

NOEUD2 noeud2Creer(ELEMENT6 e){

NOEUD2 n;

n =(NOEUD2)malloc(sizeof(structNoeud2));
if(!n)
	printf ("\nPlus d'espace");
else
	{
	element6Affecter(&n->info, e);
	n->suivant = NULL;
     n->precedent = NULL;
	}
return n;
}

void noeud2Detruire(NOEUD2 n){
element6Detruire(n->info);
free(n);
}

LISTE_QUARANTAINE liste6Creer(void)  {
	LISTE_QUARANTAINE L;
   L = (LISTE_QUARANTAINE) malloc(sizeof(LSTQUARANTAINE));
   if(!L) {
		printf("\nProbl%cme de m%cmoire",138,130) ;
		exit(0) ;
	}
   L->lg = 0;
   return(L);
}

void liste6Detruire(LISTE_QUARANTAINE L)
{   NOEUD2 p,q;
    p=L->tete ;
    for (int i=1 ; i<=L->lg; i++)
    {
        q=p;
        p=p->suivant;
         noeud2Detruire(q);
    }

    free(L);

}

int est6Vide(LISTE_QUARANTAINE L) {
	return (L->lg == 0);
}


int est6Saturee(LISTE_QUARANTAINE L)
{
    NOEUD2 temp;
int saturee = 1; /* on suppose mémoire saturée */
temp = (NOEUD2) malloc ( sizeof ( structNoeud2 ) );
if(temp != NULL) {
saturee = 0; /* mémoire non saturée */
free(temp);
}
return saturee;
}


int liste6Taille(LISTE_QUARANTAINE L) {
   return (L->lg);
}


void inserer6 (LISTE_QUARANTAINE L, ELEMENT6 e, int pos)
{
int succee=1;
int i;
NOEUD2 n, p, q;
if (est6Saturee(L))
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
	      n=noeud2Creer(e); /*on est sûr que la réservation va se faire car la mémoire n'est pas saturée*/

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

int supprimer6 (LISTE_QUARANTAINE L, int pos ){
	int i;
	int succee=1;
	NOEUD2  p,  q;

  if (est6Vide(L))
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
  noeud2Detruire(q);
  (L->lg)--;
  }
 }
return succee;
}

ELEMENT6 recuperer6(LISTE_QUARANTAINE L, int pos) {

	/*  s'il ya une erreur on affiche un message et on retourne un element vide */

	ELEMENT6 elt= element6Creer();
	int i;
	NOEUD2 p;

	if (est6Vide(L))
		printf ("\nListe vide");
	else	{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");
		else	{
			  p= L->tete;
			for (i=1; i<pos; i++)
				 {p = p->suivant;}
			 element6Affecter(&elt,p->info);
			}
		}
	return(elt);
}

void liste6Afficher(LISTE_QUARANTAINE L)
{
   int i=1;
   NOEUD2 p;
   p=L->tete;

   for(i = 1;i <= L->lg; i++) {
        printf("Personne %d \n",i);
		element6Afficher(p->info);

		printf("\n");
		p= p->suivant;
	}

}


LISTE_QUARANTAINE liste6Copier(LISTE_QUARANTAINE L){

LISTE_QUARANTAINE LR = liste6Creer();

int i;
ELEMENT6 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element6Creer();
		element6Copier(&elt, recuperer6(L,i));

		inserer3(LR,elt, i);
	}
 return LR;
}


int  liste6Comparer (LISTE_QUARANTAINE L1,LISTE_QUARANTAINE L2 )
{
int test= 1;
int i=1;

if (liste6Taille(L1) != liste6Taille(L2)) test= 0;

while ((i<=liste6Taille(L1)) && (test)) {
	   if (element6Comparer(recuperer6(L1,i),recuperer6(L2,i))!=0)
		test=0;
	i++;
}

return test;
}
