#ifndef ELTHOPITAL_H_INCLUDED
#define ELTHOPITAL_H_INCLUDED
#include "LSTPATHOP.h"
#include "LSTDON.h"
#include "LSTPRIM9.h"
#include "LSTPRIM5.h"
#include "LSTPRIM3.h"
typedef struct {
 char adr[100] ;
  char nom [100];
 int id ;
 int code_postal;
 int gouvernorat;
 int nb_lits_ailleurs;
  int nb_lits_rea;
int nb_med_corona;
int nb_paramedicaux ;
int tel;
int fax ;
int urg;
LISTE_PATHOP pat_hop;
LISTE_DON dons ;
  } HOPITAL , *ELEMENT4;




#endif // ELTHOPITAL_H_INCLUDED
