#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Initialisation d'un graph par listes
void initgraphe_l(graphe_l *G,int n){
	char conf;
	liste p;
	G->n=n;
	G->a=(liste *)malloc(sizeof(liste *)*n);
	for(int i=0;i<G->n;i++){

		G->a[i]=(liste)malloc(sizeof(liste));
		G->a[i]=NULL;
		for(int j=i;j<G->n;j++){
			printf("Arête entre %d et %d?\n",i,j);
			conf=getchar();
			getchar();
			if(conf=='y'){
				p=(liste)malloc(sizeof(liste));
				p->st=j;
				p->suivant=G->a[i];
				G->a[i]=p;
			}
		}
	}
}

//Affiche le nombre de sommets et les arrêtes
void printgraph_l(graphe_l G){
	liste p;
	printf("Il y a %d sommets\n",G.n);
	printf("Arêtes :\n");
	for(int i=0;i<G.n;i++){
		p=G.a[i];
		while(p!=NULL){
			printf("%d %d\n",i,p->st);
			p=p->suivant;
		}
	}
}

//Test d'existence d'une arête pour graphe liste
int arete_l(graphe_l g,sommet x,sommet y){
	liste p;
	p=g.a[x];
	while((p!=NULL) && (p->st!=y))
		p=p->suivant;
	if(p==NULL)
		return 0;
	else
		return 1;
}

//Vérifie si e est un sous-graphe désert de G
int verification_l(graphe_l G,ens_de_sommets e){
	int i,j=0,echap=0;
	for(i=0;i<e.n && !echap;i++)
		for(j=i;j<e.n && !echap;j++)
			if(e.som[j]>=G.n || arete_l(G,e.som[i],e.som[j]))
				echap=1;
	if(i==e.n)
		return 1;
	return 0;
}
