#include "struct.h"

//Fonctions pour le graphe par listes d'adjacence
int arete_l(graphe_l g,sommet x,sommet y);
int verification_l(graphe_l G, ens_de_sommets e);
int verification_l_bool(graphe_l G, ens_de_sommets e);
void initgraphe_l(graphe_l *G,int n);
void printgraph_l(graphe_l G);
int maximal_bool(graphe_l g,ens_de_sommets e);

//Fonctions utiles
int init_ens_de_sommets(ens_de_sommets *e,int n);
void init_ens_de_sommets_bool(ens_de_sommets *e,int n);
