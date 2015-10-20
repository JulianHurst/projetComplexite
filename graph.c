#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char *argv[]){
	if(argc>1){
		fprintf(stderr,"Erreur : %s ne prends pas d'arguments\n",argv[0]);
		exit(1);
	}
	graphe_l gl;
	ens_de_sommets e;
	printf("\nInitialisation du graphe par listes:\n");
	initgraphe_l(&gl,2);	
	printf("\nInitialisation de l'ensemble de sommets:\n");
	if(init_ens_de_sommets(&e,1))
		return 1;
	printf("\n\n---------Listes--------------\n\n");
	printgraph_l(gl);
	if(verification_l(gl,e)==1)
		printf("Sous-graphe désert!\n");
	else
		printf("Pas un sous-graphe désert!\n");
	if(maximal(gl,e))
		printf("Maximal !\n");
	else
		printf("Pas Maximal !\n");
	return 0;
}
