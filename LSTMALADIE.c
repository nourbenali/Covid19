#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM1.h"
#include "ELTPRIM1.h"


LISTE_MALADIE liste1Creer(void)
{
    LISTE_MALADIE L;
   L = (LISTE_MALADIE) malloc(sizeof(MALADIE));
   if(!L) {
		printf("\nProbleme de mecmoire") ;
		exit(0) ;
	}
   L->lg = 0;
   return(L);
}

void liste1Detruire(LISTE_MALADIE L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element1Detruire(L->tabmaladie[i]);}

    free(L);
}

int est1Vide(LISTE_MALADIE L)
{
    return (L->lg == 0);
}

int est1Saturee(LISTE_MALADIE L)
{
    return (L->lg == LongMax);
}

int liste1Taille(LISTE_MALADIE L)
{
return L->lg ;
}
ELEMENT1 recuperer1(LISTE_MALADIE L, int pos)
{
    ELEMENT1 elt= element1Creer();

	if (est1Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element1Affecter(&elt,L->tabmaladie[pos]);
			}
	return(elt);
}

int inserer1(LISTE_MALADIE L, ELEMENT1 e ,int pos)
{
     int i;
   int succee=1;

  if (est1Saturee(L)){
		printf ("\nListe satur%ce",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								{element1Affecter(&L->tabmaladie[i+1], L->tabmaladie[i]);}
						element1Affecter(&L->tabmaladie[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer1(LISTE_MALADIE L, int pos)
{
    int i;
	int succee=1;

  if (est1Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element1Detruire(L->tabmaladie[pos]);

						for(i=pos;i<=L->lg;i++)
								element1Affecter(&L->tabmaladie[i], L->tabmaladie[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste1Afficher(LISTE_MALADIE L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else{ for(i = 1;i <= L->lg; i++)
   { printf("maladie %d :",i);
		element1Afficher(recuperer1(L,i));}}
}

LISTE_MALADIE liste1Copier(LISTE_MALADIE L)
{
    LISTE_MALADIE LR = liste1Creer();

int i;
ELEMENT1 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element1Creer();
		element1Copier(&elt, recuperer1(L,i));

		inserer1(LR,elt, i);
	}
 return LR;
}

int  liste1Comparer(LISTE_MALADIE L1, LISTE_MALADIE L2)
{
    int test= 1;
int i=1;

if (liste1Taille(L1) != liste1Taille(L2)) test= 0;

while ((i<=liste1Taille(L1)) && (test)) {
	   if (element1Comparer(recuperer1(L1,i),recuperer1(L2,i))==0)
		test=0;
	i++;
}

return test;
}
