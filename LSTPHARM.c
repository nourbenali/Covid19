#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM10.h"
#include "ELTPRIM10.h"


LISTE_PHARMACIE liste10Creer(void)
{
    LISTE_PHARMACIE L;
   L = (LISTE_PHARMACIE) malloc(sizeof(LSTPHAR));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste10Detruire(LISTE_PHARMACIE L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element10Detruire(L->tabpharm[i]);}

    free(L);
}

int est10Vide(LISTE_PHARMACIE L)
{
    return (L->lg == 0);
}

int est10Saturee(LISTE_PHARMACIE L)
{
    return (L->lg == LongMax);
}

int liste10Taille(LISTE_PHARMACIE L)
{
return L->lg ;
}
ELEMENT10 recuperer10(LISTE_PHARMACIE L, int pos)
{
    ELEMENT10 elt= element10Creer();

	if (est10Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element10Affecter(&elt,L->tabpharm[pos]);
			}
	return(elt);
}

int inserer10(LISTE_PHARMACIE L, ELEMENT10 e ,int pos)
{
     int i;
   int succee=1;

  if (est10Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element10Affecter(&L->tabpharm[i+1], L->tabpharm[i]);
						element10Affecter(&L->tabpharm[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer10(LISTE_PHARMACIE L, int pos)
{
    int i;
	int succee=1;

  if (est10Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element10Detruire(L->tabpharm[pos]);

						for(i=pos;i<=L->lg;i++)
								element10Affecter(&L->tabpharm[i], L->tabpharm[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste10Afficher(LISTE_PHARMACIE L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i = 1;i <= L->lg; i++)
   {

        printf("PHARMACIE %d ",i);
		element10Afficher(L->tabpharm[i]);
		printf("\n");
   }}
}

LISTE_PHARMACIE liste10Copier(LISTE_PHARMACIE L)
{
    LISTE_PHARMACIE LR = liste10Creer();

int i;
ELEMENT10 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element10Creer();
		element10Copier(&elt, recuperer10(L,i));

		inserer10(LR,elt, i);
	}
 return LR;
}

int  liste10Comparer(LISTE_PHARMACIE L1, LISTE_PHARMACIE L2)
{
    int test= 1;
int i=1;

if (liste10Taille(L1) != liste10Taille(L2)) test= 0;

while ((i<=liste10Taille(L1)) && (test)) {
	   if (element10Comparer(recuperer10(L1,i),recuperer10(L2,i))==0)
		test=0;
	i++;
}

return test;
}
