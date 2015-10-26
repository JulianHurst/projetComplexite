#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

//Initialise un ensemble de sommets
/*int init_ens_de_sommets(ens_de_sommets *e,int n){
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
}*/

//Initialise un ensemble de sommets avec un tableau de bool
/*void init_ens_de_sommets_bool(ens_de_sommets *e,int n){    //avec n = G.n
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
}*/

void init_ens_de_sommets_bool2(ens_de_sommets *e,int n){
  e->n=n;
  //e->som=(int *)malloc(sizeof(int *));
  for(int i=0;i<e->n;i++){
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

void print_ensemble(ens_de_sommets e){
    int i;
    for(i=0;i<e.n;i++){
        printf("Sommet %d = %d\n",i,e.som[i]);
    }
}

/**
 * Copie l'ensemble e_src dans l'ensemble e_dest
 * @param e_src ensemble de sommets source
 * @param e_dest ensemble de sommets de destination
 * @param n entier correspondant à la taille des ensembles de sommet.
 * @author Tristan NARI
 */
void copie_ens(ens_de_sommets *e_src,ens_de_sommets *e_dest,int n){
	int i;
	e_dest->n=e_src->n;
	for(i=0; i<n; i++) e_dest->som[i] = e_src->som[i];
}

/**
 * Remplie le tableau d'ensemble en fonction d'une chaine de texte de nombre 0 et 1 séparé par des virgules
 * @param e ensemble de sommets
 * @param liste_e chaine de caractère
 * @author Tristan NARI
 */
void lecture_ens(ens_de_sommets *e,char liste_e[]){
    int i = 0;
    char* smt=NULL;
    smt = strtok(liste_e,",");
    printf("smt : %d\n",atoi(smt));
	while(smt != NULL){
		e->som[i] = atoi(smt);
		smt = strtok(NULL,",");
		i = i + 1;
	}
}
