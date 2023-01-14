#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM9.h"
#include "LSTDON.h"
#include "ELTPRIM9.h"


LISTE_DON liste9Creer(void)
{
    LISTE_DON L;
   L = (LISTE_DON) malloc(sizeof(LSTDON));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste9Detruire(LISTE_DON L)
{
    int i;
   for(i = 0;i < L->lg; i++)
		{element9Detruire(L->tabdon[i]);}

    free(L);
}

int est9Vide(LISTE_DON L)
{
    return (L->lg == 0);
}

int est9Saturee(LISTE_DON L)
{
    return (L->lg == LongMax);
}

int liste9Taille(LISTE_DON L)
{
return L->lg ;
}
ELEMENT9 recuperer9(LISTE_DON L, int pos)
{
    ELEMENT9 elt= element9Creer();

	if (est9Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element9Affecter(&elt,L->tabdon[pos]);
			}
	return(elt);
}

int inserer9(LISTE_DON L, ELEMENT9 e ,int pos)
{
     int i;
   int succee=1;

  if (est9Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element9Affecter(&L->tabdon[i+1], L->tabdon[i]);
						element9Affecter(&L->tabdon[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer9(LISTE_DON L, int pos)
{
    int i;
	int succee=1;

  if (est9Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element9Detruire(L->tabdon[pos]);

						for(i=pos;i<=L->lg;i++)
								element9Affecter(&L->tabdon[i], L->tabdon[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste9Afficher(LISTE_DON L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i = 1;i <= L->lg; i++)
   {

        printf("Don %d ",i);
		element9Afficher(L->tabdon[i]);
		printf("\n");
   }}
}

LISTE_DON liste9Copier(LISTE_DON L)
{
    LISTE_DON LR = liste9Creer();

int i;
ELEMENT9 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element9Creer();
		element9Copier(&elt, recuperer9(L,i));

		inserer9(LR,elt, i);
	}
 return LR;
}

int  liste9Comparer(LISTE_DON L1, LISTE_DON L2)
{
    int test= 1;
int i=1;

if (liste9Taille(L1) != liste9Taille(L2)) test= 0;

while ((i<=liste9Taille(L1)) && (test)) {
	   if (element9Comparer(recuperer9(L1,i),recuperer9(L2,i))==0)
		test=0;
	i++;
}

return test;
}
