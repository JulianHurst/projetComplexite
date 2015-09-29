#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char *argv[]){
	if(argc>1){
		fprintf(stderr,"Erreur : %s ne prends pas d'arguments\n",argv[0]);
		exit(1);
	}
	graphe_m gm;
	graphe_l gl;
	ens_de_sommets e;
	printf("Initialisation du graphe matriciel :\n");
	initgraphe_m(&gm,4);
	printf("\nInitialisation du graphe par listes:\n");
	initgraphe_l(&gl,5);
	printf("\nInitialisation de l'ensemble de sommets:\n");
	if(init_ens_de_sommets(&e,3))
		return 1;
	printf("\n\n---------Matrice--------------\n\n");
	printgraph_m(gm);
	if(verification_m(gm,e)==1)
		printf("Sous-graphe désert!\n");
	else
		printf("Pas un sous-graphe désert!\n");
	printf("\n\n---------Listes--------------\n\n");
	printgraph_l(gl);
	if(verification_l(gl,e)==1)
		printf("Sous-graphe désert!\n");
	else
		printf("Pas un sous-graphe désert!\n");
	return 0;
}
