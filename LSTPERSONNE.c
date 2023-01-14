#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM2.h"
#include "ELTPRIM2.h"


LISTE_PERSONNE liste2Creer(void)
{
    LISTE_PERSONNE L;
   L = (LISTE_PERSONNE) malloc(sizeof(LSTPER));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste2Detruire(LISTE_PERSONNE L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element2Detruire(L->tabpersonne[i]);}

    free(L);
}

int est2Vide(LISTE_PERSONNE L)
{
    return (L->lg == 0);
}

int est2Saturee(LISTE_PERSONNE L)
{
    return (L->lg == LongMax);
}

int liste2Taille(LISTE_PERSONNE L)
{
return L->lg ;
}
ELEMENT2 recuperer2(LISTE_PERSONNE L, int pos)
{
    ELEMENT2 elt= element2Creer();

	if (est2Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element2Affecter(&elt,L->tabpersonne[pos]);
			}
	return(elt);
}

int inserer2(LISTE_PERSONNE L, ELEMENT2 e ,int pos)
{
     int i;
   int succee=1;

  if (est2Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element2Affecter(&L->tabpersonne[i+1], L->tabpersonne[i]);
						element2Affecter(&L->tabpersonne[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer2(LISTE_PERSONNE L, int pos)
{
    int i;
	int succee=1;

  if (est2Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element2Detruire(L->tabpersonne[pos]);

						for(i=pos;i<=L->lg;i++)
								element2Affecter(&L->tabpersonne[i], L->tabpersonne[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste2Afficher(LISTE_PERSONNE L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i = 1;i <= L->lg; i++)
   {

        printf("Personne %d ",i);
		element2Afficher(L->tabpersonne[i]);
		printf("\n");
   }}
}

LISTE_PERSONNE liste2Copier(LISTE_PERSONNE L)
{
    LISTE_PERSONNE LR = liste2Creer();

int i;
ELEMENT2 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element2Creer();
		element2Copier(&elt, recuperer2(L,i));

		inserer2(LR,elt, i);
	}
 return LR;
}

int  liste2Comparer(LISTE_PERSONNE L1, LISTE_PERSONNE L2)
{
    int test= 1;
int i=1;

if (liste2Taille(L1) != liste2Taille(L2)) test= 0;

while ((i<=liste2Taille(L1)) && (test)) {
	   if (element2Comparer(recuperer2(L1,i),recuperer2(L2,i))==0)
		test=0;
	i++;
}

return test;
}
