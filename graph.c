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
	initgraphe_l(&gl,3);	
	printf("\nInitialisation de l'ensemble de sommets:\n");
	//if(init_ens_de_sommets(&e,1))
	//	return 1
	init_ens_de_sommets_bool(&e,gl.n);
	printgraph_l(gl);
  	printf("\n\n----------Vérification----------\n");
	if(verification_l_bool(gl,e)==1)
		printf("Sous-graphe désert!\n");
	else
		printf("Pas un sous-graphe désert!\n");
  	printf("\n----------Maximalité----------\n");
	if(maximal(gl,e))
		printf("Maximal !\n");
	else
		printf("Pas Maximal !\n");
	printf("\n");
	return 0;
}
