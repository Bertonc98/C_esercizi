#include<stdlib.h>
#include<stdio.h>

struct graph{
	int n,m;
	int **A;	
};

struct coda{
	int v;
	struct coda *next;
};

typedef struct graph *Graph;

Graph graph_new(int n);
void destroy(Graph g);
void graph_edgeinsert(Graph g, int v, int w);
void print_son(Graph g);

int main()
{	
	Graph g=graph_new(5);
	graph_edgeinsert(g,0,1);
	graph_edgeinsert(g,0,2);
	graph_edgeinsert(g,2,3);
	graph_edgeinsert(g,3,4);
	/*for(int i=0; i<g->n; i++){
		for(int j=0; j<g->n; j++)
			printf("%d",g->A[i][j]);
		printf("\n");
	}*/

	print_son(g);
	destroy(g);
	return 0;
}

Graph graph_new(int n){
	Graph g=calloc(1,sizeof(struct graph));
	if(!g)
		exit(0);
	g->A=calloc(n,sizeof(int *));
	if(!g->A)
		exit(0);
	for(int i=0; i<n; i++){
		g->A[i]=calloc(1,sizeof(int));
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			g->A[i][j]=0;
	}
	g->n=n;

	return g;
}

void destroy(Graph g){
	for(int i=0; i<g->n;i++)
		free(g->A[i]);
	free(g);
}

void graph_edgeinsert(Graph g, int v, int w){
	g->A[v][w]=1;
	g->A[w][v]=1;
}

void print_son(Graph g){
	int *aux=calloc(g->n,sizeof(int)),*levels=calloc(g->n,sizeof(int)), *order=calloc(g->n,sizeof(int));
	for(int i=0; i<g->n; i++)
		aux[i]=0;
	aux[0]=1;
	int count=1;
	for(int i=0; i<g->n; i++){
		for(int j=0; j<g->n; j++){
			if(aux[j]!=1 && g->A[i][j]==1){
				order[count]=j;
				levels[j]=i;
				count++;
			}
		}
	}
	for(int i=0; i<g->n; i++)
		printf("%d ",order[i]);
	/*
	for(int i=0; i<g->n; i++){
		for(int j=0; j<levels[i]; j++){
			printf(" ");
		}
		printf("%d\n",order[i]);
	}*/

	free(aux);
	free(levels);
	free(order);
}