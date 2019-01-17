#include <stdio.h>
#include <stdlib.h>


struct node {
  struct node *next;
  int v;
};


struct graph {
  int n, m;
  struct node **A;
  int soglia;
  int *toxicity;
};


typedef struct graph *G;



/* creazione della struttura dati */
G dataStructure_new( int n );


void dataStructure_insert( G s, int v, int w );

/* lettura da standard input */
G dataStructure_read( void );

/* stampa su standard output */
void dataStructure_print( G s );







// FUNZIONI AUSILIARIE
//***************************************

/* DOCUMENTATE QUI cosa fa la funzione add
... */
struct node *add( struct node *l, int v ) {

	struct node *new = malloc( sizeof( struct node ) );
	new -> v = v;
	new -> next = l;
	return new;

}

void toxic(G s);
void unlinked(G s, int nodo);
void visit(G s, int nodo, int *visited);
int partition(G s);


// MAIN
// ***********

int main(){
	G s = NULL;
	int nodo;
	s = dataStructure_read();

	dataStructure_print(s);
	//toxic(s);
	printf("Partizioni: %d\n", partition(s));

	printf("Di quale nodo vuoi esplorare il settore? ");
	scanf(" %d", &nodo);
	unlinked(s, nodo);
	printf("\n");
	return 0;
}


// IMPLEMENTAZIONE DELLE FUNZIONI DELL'INTERFACCIA 
// **************************************************************
int partition(G s){
	int *visited=calloc(s->n, sizeof(int));
	int completed=1;
	int count=0;
	int nodo=0;
	for(int i=0; i<s->n; i++)
		visited[i]=0;

	for(int i=0; i<s->n; i++)
			if(s->toxicity[i]>=s->soglia)
				visited[i]=1;

	for(int i=0; i<s->n; i++)
		completed*=visited[i];

	for(int i=0; i<s->n; i++)
		if(visited[i]==0)
			nodo=i;

	while(completed==0){
		
		if(s->toxicity[nodo]<=s->soglia)
			visit(s, nodo, visited);
		count++;
		completed=1;
		for(int i=0; i<s->n; i++)
			completed*=visited[i];
		for(int i=0; i<s->n; i++)
			if(visited[i]==0)
				nodo=i;
	}

	return count;
}

void unlinked(G s, int nodo){
	int *visited=calloc(s->n, sizeof(int));
	for(int i=0; i<s->n; i++)
		visited[i]=0;

	for(int i=0; i<s->n; i++)
		if(s->toxicity[i]>=s->soglia)
			visited[i]=1;
	if(s->toxicity[nodo]>s->soglia)
		printf("Nodo isolato perchè tossico\n");
	else
		visit(s, nodo, visited);

}

void visit(G s, int nodo, int *visited){
	struct node * curr=s->A[nodo];
	printf("%d ", nodo);
	visited[nodo]=1;
	while(curr!=NULL){
		if(visited[curr->v]==0)
			visit(s,curr->v, visited);
		curr=curr->next;
	}
}

void toxic(G s){
	printf("Nodi tossici\n");
	for(int i=0; i<s->n; i++)
		if(s->toxicity[i]>=s->soglia)
			printf("%d", i);
	printf("\n");
}

G dataStructure_new( int n ){

	G s = malloc(sizeof(struct graph));
	if(!s) {
        	fprintf(stderr,"Errore di Allocazione\n");
	        exit(EXIT_FAILURE);
	}
	s-> n = n;
	s -> A = calloc( n, sizeof( struct node* ) ); // 
	return s; 
}



void dataStructure_insert( G s, int v, int w ){
        s->A[v] = add(s->A[v],w); // 
        if ( v != w )
		s->A[w] = add(s->A[w],v);
}

G dataStructure_read( void ){
	int n, m, i, v, w;
	G s;
	printf("Inserire il numero di nodi ");
	scanf( " %d", &n );
	s = dataStructure_new( n );
	printf("Inserire il numero di archi ");
	scanf( "%d", &m );
	s -> m = m;
	printf("Inserire le coppie di nodi che formano %d archi:\n", s->m);
	for (i = 0; i < m; i++) {
		scanf( " %d %d", &v, &w );
		dataStructure_insert( s, v, w);
	}

	printf("Inserire la soglia di tossicità:");
	scanf(" %d", &s->soglia);
	s->toxicity=calloc(s->n, sizeof(int));
	printf("Inserire le tossicità dei vari nodi in ordine (0-n):\n");
	for(int i=0; i<s->n; i++)
		scanf(" %d", &s->toxicity[i]);

	return s;
}

void dataStructure_print( G s ){
	int n = s -> n;
	struct node **al = s -> A;
	struct node *curr; 	
	
	printf( "nodi = %d\narchi = %d\n", n, s -> m );

	for ( int i = 0; i < n; i++ ) {
		printf( "%d:", i );
		for ( curr = al[i]; curr != NULL; curr = curr -> next ) {
				printf( " %d", curr -> v );
		}
		printf( "\n" );
	}

	printf("Soglia tossicità: %d, valore nei nodi: ",s->soglia);
	for(int i=0; i<s->n; i++)
		printf("%d ", s->toxicity[i]);
	printf("\n");

}


