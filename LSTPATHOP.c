#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM5.h"
#include "LSTPATHOP.h"


LISTE_PATHOP liste5Creer(void)
{
    LISTE_PATHOP L;
   L = (LISTE_PATHOP) malloc(sizeof(PATHOP));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste5Detruire(LISTE_PATHOP L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element3Detruire(L->tabpathop[i]);}

    free(L);
}

int est5Vide(LISTE_PATHOP L)
{
    return (L->lg == 0);
}

int est5Saturee(LISTE_PATHOP L)
{
    return (L->lg == LongMax);
}

int liste5Taille(LISTE_PATHOP L)
{
return L->lg ;
}
ELEMENT3 recuperer5(LISTE_PATHOP L, int pos)
{
    ELEMENT3 elt= element3Creer();

	if (est5Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element3Affecter(&elt,L->tabpathop[pos]);
			}
	return(elt);
}

int inserer5(LISTE_PATHOP L, ELEMENT3 e ,int pos)
{
     int i;
   int succee=1;

  if (est5Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element3Affecter(&L->tabpathop [i+1], L->tabpathop[i]);
						element3Affecter(&L->tabpathop[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer5(LISTE_PATHOP L, int pos)
{
    int i;
	int succee=1;

  if (est5Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element3Detruire(L->tabpathop[pos]);

						for(i=pos;i<=L->lg;i++)
								element3Affecter(&L->tabpathop[i], L->tabpathop[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste5Afficher(LISTE_PATHOP L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i =0;i < L->lg; i++)
   {

        printf("Patient %d ",i+1);
		element3Afficher(recuperer5(L,i+1));
		printf("\n");
   }}
}

LISTE_PATHOP liste5Copier(LISTE_PATHOP L)
{
    LISTE_PATHOP LR = liste5Creer();

int i;
ELEMENT3 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element3Creer();
		element3Copier(&elt, recuperer5(L,i));

		inserer5(LR,elt, i);
	}
 return LR;
}

int  liste5Comparer(LISTE_PATHOP L1, LISTE_PATHOP L2)
{
    int test= 1;
int i=1;

if (liste5Taille(L1) != liste5Taille(L2)) test= 0;

while ((i<=liste5Taille(L1)) && (test)) {
	   if (element3Comparer(recuperer5(L1,i),recuperer5(L2,i))==0)
		test=0;
	i++;
}

return test;
}
