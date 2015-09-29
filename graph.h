#include "struct.h"

//Fonctions pour le graphe matriciel
int arete_m(graphe_m g,sommet x,sommet y);
void initgraphe_m(graphe_m *gm, int n);
void printgraph_m(graphe_m g);
int verification_m(graphe_m G, ens_de_sommets e);

//Fonctions pour le graphe par listes d'adjacence
int arete_l(graphe_l g,sommet x,sommet y);
int verification_l(graphe_l G, ens_de_sommets e);
void initgraphe_l(graphe_l *G,int n);
void printgraph_l(graphe_l G);

//Fonctions utiles
int init_ens_de_sommets(ens_de_sommets *e,int n);
