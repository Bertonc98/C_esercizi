#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



struct element {  // elemento di lista
  char ch;
  int i;
  struct element *next;    // prossimo elemento
};


struct graph {
  int n, m, count;
  struct element **A; // vettore delle liste di adiacenza
};

typedef struct graph *Graph;

Graph newGraph( int n ); /* alloca una struttura grafo con n nodi */
void addEdge( Graph g, char x, char y); /* inserisce l'arco x -> y */
void printGraph( Graph g ); /* stampa su standard output le liste di adiacenza di g */


// funzione read
Graph read(){
	int n;
	char x,y;
	scanf("%d",&n);
	Graph g=newGraph(n);
	while(n>0){
		scanf(" %c%c",&x,&y);
		addEdge(g, x, y );
		n--;
	}

	return g;
}


// funzione followers
void followers(Graph g, char c){

	struct element **al = g -> A;
	struct element *curr;
	printf( "Followers di %c:", c );
		for ( curr = al[c-'A']; curr != NULL; curr = curr -> next ) {
			printf( " %c", curr -> ch );
		}
	printf( "\n" );

}


// funzione max
void max(Graph g){
	struct element **al = g -> A;
	struct element *curr;
	int max=0, count=0;

	for ( int i = 0; i < g->n; i++ ) {
		count=0;
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			count++;
		}
		if(count>max)
			max=count;
	}

	for ( int i = 0; i < g->n; i++ ) {
		count=0;
		
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			count++;
		}
		if(count==max){
			printf( "%c", 'A'+i );
		}
		printf("\n");
	}
}

void parola(Graph g, char c, int *array){
	struct element **al = g -> A;
	struct element *curr;

		for ( curr = al[c-'A']; curr != NULL; curr = curr -> next ) {
			array[curr->i]=1;
			printf("%c", curr->ch);
			if(curr->next!=NULL){
				if(array[curr->next->i]==0)
					parola(g, curr->next->i, array);
			}
		}
	printf( "\n" );

}


int main( int argc, char *argv[]){
  Graph g = read();
  int array[g->n-1];
  for(int k=0; k<g->n;k++)
  	array[k]=0;
  char c;
  scanf( " %c", &c );
  parola(g, c, array);
  //max(g);
  printGraph(g);
  return 0;
}




/* crea una struttura grafo con n nodi */
Graph newGraph( int n ){

	Graph g = malloc(sizeof(struct graph));
	if(!g) {
        	fprintf(stderr,"Errore di Allocazione\n");
	        exit(EXIT_FAILURE);
	}
	g -> n = n;
	g->count=0;
	g -> A = calloc( n, sizeof( struct element* ) ); // vettore delle liste di adiacenza: g -> A [i] e' la lista dell'i-esimo nodo
	return g;
}



// inserimento in liste di adiacenza
struct element *list_insert( struct element *list, char ch , int i) {
	struct element *new = malloc( sizeof( struct element ) );
	new -> ch = ch;
	new -> i=i;
	new -> next = list;
	return new;

}

// inserisce nel grafo l'arco x -> y
void addEdge( Graph g, char x, char y){
  g->A[x-'A'] = list_insert(g->A[x-'A'],y, g->count);
  g->count++;
  g->m++;
}

/* stampa su standard output le liste di adiacenza di g */
void printGraph( Graph g ){
	printf( "\n************** stampo grafo\n" );
	int n = g -> n;
	struct element **al = g -> A;
	struct element *curr;

	printf( "%d nodi\n%d archi\n%d conto\n", n, g -> m, g->count);

	for ( int i = 0; i < n; i++ ) {
		printf( "%c:", 'A'+i );
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
			printf( " %c", curr -> ch );
		}
		printf( "\n" );
	}
	printf( "fine stampa grafo *************************\n\n");

}