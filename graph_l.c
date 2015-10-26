#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

//Initialisation d'un graph par listes
/*void initgraphe_l(graphe_l *G,int n){
	char conf;
	liste p,pr;
	G->n=n;
	G->a=(liste *)malloc(sizeof(liste *)*n);
	for(int i=0;i<G->n;i++){
		G->a[i]=(liste)malloc(sizeof(liste));
		G->a[i]=NULL;
	}
	for(int i=0;i<G->n;i++){
		for(int j=i;j<G->n;j++){
			printf("Arête entre %d et %d?\n",i,j);
			conf=getchar();
			getchar();
			if(conf=='y'){
				p=(liste)malloc(sizeof(liste));
				pr=(liste)malloc(sizeof(liste));
				p->st=j;
				p->suivant=G->a[i];
				G->a[i]=p;
				pr->st=i;
				pr->suivant=G->a[j];
				G->a[j]=pr;
			}
		}
	}
}*/

void init_graphe(graphe_l *g)
{
	sommet i;
	g->n = 0;
	//g->m = 0;
	for(i=0; i<n_max; i++)
	{
		g->a[i] = NULL;
	}
}

/* Lexture de fichier de graphe */
int lecture(char * f,graphe_l * g)
{
    FILE* fichier = NULL;
    init_graphe(g);
    int n, m, i;
    int a, b;
    char chemin[100];
    strcpy(chemin,"Benchs/");
    strcat(chemin,f);
    fichier = fopen(chemin, "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d", &n, &m);
		g->n = n;
		//g->m = m;
		for(i=0; i<m; i++)
		{
			fscanf(fichier, "%d %d", &a, &b);
			ajouter_arc(a, b, g);
		}
		fclose(fichier);
        return 1;
    }
    else return 0;
}

void ajouter_arc(sommet x,sommet y,graphe_l *g)
{
	liste p = (liste)malloc(sizeof(Couple));
	liste q = (liste)malloc(sizeof(Couple));
	if(x >= g->n) ajouter_sommet(g);
	if(y >= g->n) ajouter_sommet(g);
	p->st = y;
	q->st = x;
	p->suivant = g->a[x];
	q->suivant = g->a[y];
	g->a[x] = p;
	g->a[y] = q;
}

void ajouter_sommet(graphe_l * g)
{
	g->n = g->n + 1;
}

//Affiche le nombre de sommets et les arrêtes
void printgraph_l(graphe_l G){
	liste p;
	printf("Il y a %d sommets\n",G.n);
	printf("Aretes :\n");
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
	return !echap;
}

//Vérifie si e est un sous-graphe désert de G version bool
int verification_l_bool(graphe_l G,ens_de_sommets e){
	int i,j=0,echap=0;
	for(i=0;i<e.n && !echap;i++)
		for(j=i;j<e.n && !echap;j++)
			if((e.som[i] && e.som[j]) && arete_l(G,i,j))
				echap=1;
	return !echap;
}

/* Maximalité vérifie si un ensemble est maximal*/
int maximal(graphe_l g,ens_de_sommets e)
{
    int x=0;
    int ok=1;
    int i=e.n;
    if(verification_l(g,e))
    {
        do
        {
            if(!contains(e,x))
            {
                e.som[i]=x;
                e.n++;
                ok=!verification_l(g,e);
                e.som[i]=-1;
                e.n--;
            }
            x=x+1;
        }while((x<g.n) && ok);
    }
    else
        ok=0;
    return ok;
}

/* Maximalité vérifie si un ensemble est maximal*/
int maximal_bool(graphe_l g,ens_de_sommets e)
{
    int x=0;
    int ok=1;
    if(verification_l_bool(g,e))
    {
        do
        {
            if(!e.som[x])
            {
                e.som[x]=1;
                ok=!verification_l_bool(g,e);
                e.som[x]=0;
            }
            x=x+1;
        }while((x<g.n) && ok);
    }
    else
        ok=0;
    return ok;
}

/**
* Calcul de manière complète du sous graphe desert maximum
* @param G graphe non-orienté
* @return l'ensemble des sommets validé
* @author Kevin Garabedian
**/
ens_de_sommets maximum_complete(graphe_l G){
    int x = 0;
    int cpt = 0;
    int max = 0;
    int offset = 0;         //Décallage de sommet.
    int i;

    ens_de_sommets e;       //Enssemble de sommet à conserver
    ens_de_sommets tmp;     //Ensemble de sommet temporaire pour chaque itérations
    init_ens_de_sommets_un_bool2(&e,G.n);

    //Boucle pour départ à chaque sommet
    while(offset < G.n){
        init_ens_de_sommets_un_bool2(&tmp,G.n);
        cpt = 0;
        x = offset;
        //Première boucle passage des sommets de 1 à 1 vers le suivant
        do{
            tmp.som[x] = 0;
            x++;
        }while(verification_l_bool(G, tmp));
        //Deuxième boucle passage des sommets de 1 à 1 vers le précédent
        do{
            tmp.som[x] = 1;
            if(!verification_l_bool(G, tmp)){
                tmp.som[x] = 0;
            }
            x--;
        }while(x > 0);
        if(cpt > max){
            for(int i = 0; i<G.n; i++){
                e.som[x] = tmp.som[x];
            }
            max = cpt;
        }
        offset++;
    }
    return e;
}

/**
 * Calcul de manière incomplète un sous graphe desert maximum.
 * @param G Graphe non-orienté
 * @return L'ensemble maximum calculé
 * @author Tristan NARI
 * @complexite O(n^2)
 */
ens_de_sommets maximimum_incomplete_l(graphe_l G){
    int Kmax=0;
    int Ktmp=0;
    ens_de_sommets e;
    init_ens_de_sommets_bool2(&e,G.n);
    ens_de_sommets emax;
    init_ens_de_sommets_bool2(&emax,G.n);
    int i,j;
    //parcours du nombre de nombre
    for(i=0;i<G.n;i++){
        creation_maximum(G,&e,i);
        //calcul du nombre de sommets
        for(j=0;j<G.n;j++){
            if(e.som[j]==1)
                Ktmp++;
        }
        //enregistre le meilleur ensemble
        if(Ktmp>Kmax){
            Kmax = Ktmp;
            copie_ens(&e,&emax,G.n);
        }
        //met à 0 pour le prochain passage dans la boucle
        init_ens_de_sommets_bool2(&e,G.n);
        Ktmp=0;
    }
    //printf("%K maximal trouve : d\n",Kmax);
    return emax;
}

/**
 * Calcul d'un sommet maximal à partir du sommet i.
 * @param G Graphe non-orienté
 * @param e ensemble de sommets
 * @param i entier correspondant au sommet sélectionné
 * @author Tristan NARI
 * @complexite O(n)
 */
void creation_maximum(graphe_l G,ens_de_sommets *e, int i){
    int j;
    e->som[i]=1;
    for(j = 0;j<G.n;j++){
        if(j!=i){
            e->som[j]=1;
            if(!verification_l_bool(G,*e))
                e->som[j]=0;
        }
    }
}

