#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//Initialise un ensemble de sommets
int init_ens_de_sommets(ens_de_sommets *e,int n){
  int som,ret=0;
  e->n=n;
  e->som=(int *)malloc(sizeof(int *));
  for(int i=0;i<e->n;i++){
    printf("Sommet : ");
    if(scanf("%d",&som) ==1)
      e->som[i]=som;
    else{
      fprintf(stderr,"Erreur : Le nombre entré n'est pas valide!\n");
      ret=1;
      i=e->n;
    }
  }
  return ret;
}

//Initialise un ensemble de sommets avec un tableau de bool
void init_ens_de_sommets_bool(ens_de_sommets *e,int n){    //avec n = G.n
  char conf;
  e->n=n;
  e->som=(int *)malloc(sizeof(int *));
  for(int i=0;i<e->n;i++){
    printf("Sommet %d (y/n) : ",i);
    conf=getchar();
    getchar();
    if(conf=='y')  
    	e->som[i]=1;
    else
	e->som[i]=0;
  }
}

//Vérifie si l'ensemble de sommets contient le sommet x
int contains(ens_de_sommets e,int x){
	int i;
	for(i=0;i<e.n && e.som[i]!=x;i++);
	if(i==e.n)
		return 0;
	return 1;
}
