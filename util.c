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