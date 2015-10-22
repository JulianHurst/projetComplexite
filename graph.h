#include "struct.h"

//Fonctions pour le graphe par listes d'adjacence
int arete_l(graphe_l g,sommet x,sommet y);
int verification_l(graphe_l G, ens_de_sommets e);
int verification_l_bool(graphe_l G,ens_de_sommets e);
int maximal(graphe_l g,ens_de_sommets e);
int maximal_bool(graphe_l g, ens_de_sommets e);
ens_de_sommets maximimum_incomplete_l(graphe_l G);
void creation_maximum(graphe_l G, ens_de_sommets * e, int i);
void printgraph_l(graphe_l G);
int lecture(char * f, graphe_l * g);
void init_graphe(graphe_l *g);
void ajouter_arc(sommet x, sommet y, graphe_l *g);
void ajouter_sommet(graphe_l * g);
//void initgraphe_l(graphe_l *G,int n);

//Fonctions utiles
//int init_ens_de_sommets(ens_de_sommets *e,int n);
//void init_ens_de_sommets_bool(ens_de_sommets *e,int n);
void init_ens_de_sommets_bool2(ens_de_sommets *e,int n);
int contains(ens_de_sommets e,int x);
void print_ensemble(ens_de_sommets e);
void copie_ens(ens_de_sommets *e_src, ens_de_sommets *e_dest, int n);
void lecture_ens(ens_de_sommets *e, char liste_e[]);
