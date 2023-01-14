#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTHOPITAL.h"
#include "LSTPRIM4.h"


LISTE_HOPITAL liste4Creer(void)
{
    LISTE_HOPITAL L;
   L = (LISTE_HOPITAL) malloc(sizeof(LSTHOP));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste4Detruire(LISTE_HOPITAL L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element4Detruire(L->tabhopital[i]);}

    free(L);
}

int est4Vide(LISTE_HOPITAL L)
{
    return (L->lg == 0);
}

int est4Saturee(LISTE_HOPITAL L)
{
    return (L->lg == LongMax);
}

int liste4Taille(LISTE_HOPITAL L)
{
return L->lg ;
}
ELEMENT4 recuperer4(LISTE_HOPITAL L, int pos)
{
    ELEMENT4 elt= element4Creer();

	if (est4Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element4Affecter(&elt,L->tabhopital[pos]);
			}
	return(elt);
}

int inserer4(LISTE_HOPITAL L, ELEMENT4 e ,int pos)
{
     int i;
   int succee=1;

  if (est4Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element4Affecter(&L->tabhopital[i+1], L->tabhopital[i]);
						element4Affecter(&L->tabhopital[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer4(LISTE_HOPITAL L, int pos)
{
    int i;
	int succee=1;

  if (est4Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element4Detruire(L->tabhopital[pos]);

						for(i=pos;i<=L->lg;i++)
								element4Affecter(&L->tabhopital[i], L->tabhopital[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste4Afficher(LISTE_HOPITAL L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i = 1;i <= L->lg; i++)
   {
        printf("Hopital %d :\n",i);
		element4Afficher(recuperer4(L,i));
		printf("\n");
   }}
}

LISTE_HOPITAL liste4Copier(LISTE_HOPITAL L)
{
    LISTE_HOPITAL LR = liste4Creer();

int i;
ELEMENT4 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element4Creer();
		element4Copier(&elt, recuperer4(L,i));

		inserer4(LR,elt, i);
	}
 return LR;
}

int  liste4Comparer(LISTE_HOPITAL L1, LISTE_HOPITAL L2)
{
    int test= 1;
int i=1;

if (liste4Taille(L1) != liste4Taille(L2)) {test= 0;}

while ((i<=liste4Taille(L1)) && (test)) {
	   if (element4Comparer(recuperer4(L1,i),recuperer4(L2,i))==0)
		test=0;
	i++;
}

return test;
}
