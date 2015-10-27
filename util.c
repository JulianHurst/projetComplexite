#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

/**
 * Initialise l'ensemble e
 * @param e ensemble de sommets
 * @param n nombre de sommet dans le graphe
 * @author Julian HURST
 * @complexite O(n)
 */
void init_ens_de_sommets_bool(ens_de_sommets *e,int n){
  e->n=n;
  for(int i=0;i<e->n;i++){
      e->som[i]=0;
  }
}

/**
 * Vérifie si l'ensemble de sommets contient le sommet x
 * @param e ensemble de sommets
 * @param x entier
 * @author Julian HURST
 * @complexite O(n)
 */
int contains(ens_de_sommets e,int x){
	int i;
	for(i=0;i<e.n && e.som[i]!=x;i++);
	if(i==e.n)
		return 0;
	return 1;
}

/**
 * Vérifie si l'ensemble de sommets contient le sommet x
 * @param e ensemble de sommets
 * @author Julian HURST
 * @complexite O(n)
 */
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
void copie_ens(ens_de_sommets e_src,ens_de_sommets *e_dest,int n){
	int i;
	e_dest->n=e_src.n;
	for(i=0; i<n; i++) e_dest->som[i] = e_src.som[i];
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

	while(smt != NULL){
		e->som[i] = atoi(smt);
		smt = strtok(NULL,",");
		i = i + 1;
	}
}

/**
 * Calcul le nombre de sommets à 1 d'un ensemble.
 * @param e ensemble de sommets
 * @return Nombre de sommets à 1
 * @author Tristan NARI
 * @complexite O(n)
 */
int count_ens(ens_de_sommets e){
    int i;
    int res =0;
    for(i=0;i<e.n;i++){
        if(e.som[i]==1)
            res++;
    }
    return res;
}
