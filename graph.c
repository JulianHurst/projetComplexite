#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <sys/time.h>

int main(int argc, char *argv[]){
    struct timeval t0,t1;
	struct timezone tz;
	long diff;

	if(argc<=2){
		fprintf(stderr,"Erreur : %s prend un nom de fonction et de fichier de graphe en argument.\n",argv[0]);
		exit(1);
	}

	graphe_l gl;
	char * nfichier = argv[2];
	init_graphe(&gl);
    lecture(nfichier,&gl);
    ens_de_sommets e;
    init_ens_de_sommets_bool2(&e,gl.n);

    gettimeofday(&t0, &tz);
    if(strcmp(argv[1],"verification")==0){
        lecture_ens(&e,argv[3]);
        if(verification_l_bool(gl,e))
            printf("L'ensemble est sous-graphe desert\n");
        else
            printf("L'ensemble n'est pas sous-graphe desert\n");
    }
    else if(strcmp(argv[1],"maximalite")==0){
        lecture_ens(&e,argv[3]);
        if(maximal_bool(gl,e))
            printf("Maximal !\n");
        else
            printf("Pas Maximal !\n");
        printf("\n");
    }
    else if(strcmp(argv[1],"maximal")==0){

    }
    else if(strcmp(argv[1],"maximum_exacte")==0){  
        if(argc==3){
            print_ensemble(maximum_complete(gl));
        }
        else{
            printf("Nombre d'argument incorrect pour la fonction maximum incomplet.\n");
        }
    }
    else if(strcmp(argv[1],"maximum_incomplete")==0){
        if(argc==3){
            print_ensemble(maximimum_incomplete_l(gl));
        }
        else{
            printf("Nombre d'argument incorrect pour la fonction maximum incomplet.\n");
        }
    }
    else{
        printf("Vous vous etes trompe dans le nom de la fonction.\n");
    }
    gettimeofday(&t1, &tz);
    diff=(t1.tv_sec-t0.tv_sec) * 1000000L + (t1.tv_usec-t0.tv_usec);
    printf("Temps effectif : %ld us\n", diff);
}
