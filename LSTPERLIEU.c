#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTPRIM8.h"
#include "LSTPERLIEU.h"



LISTE_PERLIEU liste8Creer()
{
    LISTE_PERLIEU L;
   L = (LISTE_PERLIEU) malloc(sizeof(PERLIEU));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste8Detruire(LISTE_PERLIEU L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element6Detruire(L->tabperlieu[i]);}

    free(L);
}

int est8Vide(LISTE_PERLIEU L)
{
    return (L->lg == 0);
}

int est8Saturee(LISTE_PERLIEU L)
{
    return (L->lg == LongMax);
}

int liste8Taille(LISTE_PERLIEU L)
{
return L->lg ;
}

ELEMENT6 recuperer8(LISTE_PERLIEU L , int pos)
{
    ELEMENT6 elt= element6Creer();

	if (est8Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element6Affecter(&elt,L->tabperlieu[pos]);
			}
	return(elt);
}

int inserer8(LISTE_PERLIEU L, ELEMENT6 e , int pos)
{
     int i;
   int succee=1;

  if (est8Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element6Affecter(&L->tabperlieu [i+1], L->tabperlieu[i]);
						element6Affecter(&L->tabperlieu[pos], e);
						(L->lg)++ ;
					 	}
			}
	return(succee);
}

int supprimer8(LISTE_PERLIEU L, int pos)
{
    int i;
	int succee=1;

  if (est8Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element6Detruire(L->tabperlieu[pos]);

						for(i=pos;i<=L->lg;i++)
								element6Affecter(&L->tabperlieu[i], L->tabperlieu[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste8Afficher(LISTE_PERLIEU L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i =1 ;i <=L->lg ; i++)
          {

        printf("Personne %d ",i);
		element6Afficher(recuperer8(L,i));
		printf("\n");
          }
       }
}

LISTE_PERLIEU liste8Copier(LISTE_PERLIEU L)
{
    LISTE_PERLIEU LR = liste8Creer();

int i;
ELEMENT6 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element6Creer();
		element6Copier(&elt, recuperer8(L,i));

		inserer8(LR,elt, i);
	}
 return LR;
}

int  liste8Comparer(LISTE_PERLIEU L1, LISTE_PERLIEU L2)
{
    int test= 1;
int i=1;

if (liste8Taille(L1) != liste8Taille(L2)) test= 0;

while ((i<=liste8Taille(L1)) && (test)) {
	   if (element6Comparer(recuperer8(L1,i),recuperer8(L2,i))==0)
		test=0;
	i++;
}

return test;
}
