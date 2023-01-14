#ifndef ELTQUAR_H_INCLUDED
#define ELTQUAR_H_INCLUDED
#include"ELTMALADIE.h"
#include"ELTPRIM1.h"
#include"ELTPERSONNE.h"
#include"ELTPRIM2.h"
#include"LSTPRIM1.h"
#include"LSTPRIM2.h"
typedef struct{int jour; int mois;int annee;}DATE;
typedef struct{ char  nom [20]; char  prenom[20] ;
                int age ; char  adr [100]; int cont_intro ; int etat; int NCIN;
                int sexe; int etat_marital;int num_tel; LISTE_MALADIE L_MAL ; LISTE_PERSONNE L_PER ; int gouvernorat ;
                int code_postal;int provenance; DATE d_debut;DATE d_fin;
                } QUARANTAINE, * ELEMENT6;



#endif // ELTQUAR_H_INCLUDED
