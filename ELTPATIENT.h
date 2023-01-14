#ifndef ELTPATIENT_H_INCLUDED
#define ELTPATIENT_H_INCLUDED
#include"ELTMALADIE.h"
#include"ELTPRIM1.h"
#include"ELTPERSONNE.h"
#include"ELTPRIM2.h"
#include"LSTPRIM1.h"
#include"LSTPRIM2.h"

typedef struct{ char  nom [20]; char  prenom[20] ;
                int age ; char  adr [100]; int cont_intro ; int etat; int NCIN;
                int sexe; int etat_marital;int num_tel; LISTE_MALADIE L_MAL; LISTE_PERSONNE L_PER ; int gouvernorat ;
                int code_postal;
                } PATIENT, * ELEMENT3;


#endif // ELTPATIENT_H_INCLUDED
