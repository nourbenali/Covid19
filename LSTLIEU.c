#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSTLIEU.h"
#include "LSTPRIM7.h"


LISTE_LIEU liste7Creer(void)
{
    LISTE_LIEU L;
   L = (LISTE_LIEU) malloc(sizeof(LSTLIEU));
   if(!L) {
		printf("\nProbleme de memoire") ;
		exit(0) ;
	}
  L->lg = 0;
   return(L);
}

void liste7Detruire(LISTE_LIEU L)
{
    int i;
   for(i = 1;i <= L->lg; i++)
		{element7Detruire(L->tablieu[i]);}

    free(L);
}

int est7Vide(LISTE_LIEU L)
{
    return (L->lg == 0);
}

int est7Saturee(LISTE_LIEU L)
{
    return (L->lg == LongMax);
}

int liste7Taille(LISTE_LIEU L)
{
return L->lg ;
}
ELEMENT7 recuperer7(LISTE_LIEU L, int pos)
{
    ELEMENT7 elt= element7Creer();

	if (est7Vide(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else
						element7Affecter(&elt,L->tablieu[pos]);
			}
	return(elt);
}

int inserer7(LISTE_LIEU L, ELEMENT7 e ,int pos)
{
     int i;
   int succee=1;

  if (est7Saturee(L)){
		printf ("\nListe saturee",130);
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{

						for(i = L->lg; i>= pos; i--)
								element7Affecter(&L->tablieu[i+1], L->tablieu[i]);
						element7Affecter(&L->tablieu[pos], e);
						(L->lg)++;
					 	}
			}
	return(succee);
}

int supprimer7(LISTE_LIEU L, int pos)
{
    int i;
	int succee=1;

  if (est7Vide(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						element7Detruire(L->tablieu[pos]);

						for(i=pos;i<=L->lg;i++)
								element7Affecter(&L->tablieu[i], L->tablieu[i+1]);
						(L->lg)--;
					 	}
			}
	return(succee);

}

void liste7Afficher(LISTE_LIEU L)
{
    int i;
    if (L->lg ==0){printf("aucune");}
  else { for(i = 1;i <= L->lg; i++)
   {
        printf("LIEU  %d :\n",i);
		element7Afficher(recuperer7(L,i));
		printf("\n");
   }}
}

LISTE_LIEU liste7Copier(LISTE_LIEU L)
{
    LISTE_LIEU LR = liste7Creer();

int i;
ELEMENT7 elt;

   for(i = 1;i <= L->lg; i++) {

	    elt=element7Creer();
		element7Copier(&elt, recuperer7(L,i));

		inserer7(LR,elt, i);
	}
 return LR;
}

int  liste7Comparer(LISTE_LIEU L1, LISTE_LIEU L2)
{
    int test= 1;
int i=1;

if (liste7Taille(L1) != liste7Taille(L2)) {test= 0;}

while ((i<=liste7Taille(L1)) && (test)) {
	   if (element7Comparer(recuperer7(L1,i),recuperer7(L2,i))==0)
		test=0;
	i++;
}

return test;
}

