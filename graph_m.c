#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Vérifie l'existence d'une arête
int arete_m(graphe_m g,sommet x,sommet y){ //Test d'existence d'une arrete pour graphe mat
	return g.a[x][y];
}

//Initialisation d'un graph matriciel
void initgraphe_m(graphe_m *gm, int n){
	char conf;
	gm->n=n;
	gm->a=(int **)malloc(sizeof(int **)*n);
	for(int i=0;i<gm->n;i++)
		gm->a[i]=(int *)malloc(sizeof(int *)*n);
	for(int i=0;i<gm->n;i++){
		for(int j=i;j<gm->n;j++){
			printf("Arrête entre %d et %d?\n",i,j);
			conf=getchar();
			getchar();
			if(conf=='y'){
				gm->a[i][j]=1;
				gm->a[j][i]=1;
			}
			else{
				gm->a[i][j]=0;
				gm->a[j][i]=0;
			}
		}
	}
}

//Affiche le nombre de sommets et existence d'arcs du graph
void printgraph_m(graphe_m g){
	printf("Il y a %d sommets\n",g.n);
	printf("Arêtes :\n");
	for(int i=0;i<g.n;i++)
		for(int j=i;j<g.n;j++)
			printf("%d %d : %d\n",i,j,g.a[i][j]);
}

//Vérifie si e est un sous-graphe désert de G
int verification_m(graphe_m G, ens_de_sommets e){
	int i,j,echap=0;
	for(i=0;i<e.n && !echap;i++)
		for(j=i;j<e.n && !echap;j++)
			if(e.som[j]>=G.n || arete_m(G,e.som[i],e.som[j]))
				echap=1;
	if(!echap)
		return 1;
	return 0;
}

