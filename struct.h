typedef int sommet;

//Matrice
typedef struct {
	int n;
	int **a;
}graphe_m;

//Liste d'adjacence
typedef struct chainon{
	sommet st;
	struct chainon *suivant;
}Couple;

typedef Couple *liste;

typedef struct {
	liste *a;
	int n;
}graphe_l;

//typedef liste ens_de_sommets;
typedef struct {
	int n;
	sommet *som;
}	ens_de_sommets;
