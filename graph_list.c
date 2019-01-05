#include<stdlib.h>
#include<stdio.h>

struct listnode{
	struct listnode *next;
	int v;	
};

struct graph{
	int n,m;
	struct listnode **A;	
};


typedef struct graph *Graph;

Graph graph_new(int n);
void destroy(Graph g);
void graph_edgeinsert(Graph g, int v, int w);
void dsf(Graph g);
void dsf1(Graph g, int i, int *aux);

int main()
{	
	Graph g=graph_new(5);
	graph_edgeinsert(g,0,1);
	graph_edgeinsert(g,0,2);
	graph_edgeinsert(g,3,4);
	
	struct listnode *t;
	for(int k=0; k<5;k++){
		t=g->A[k];
		printf("Nodo %d: ",k);
		while(t!=NULL){
			printf("-->%d",t->v);
			t=t->next;
		}
		printf("\n");
	}
	dsf(g);

	destroy(g);
	return 0;
}

Graph graph_new(int n){
	Graph g=calloc(1,sizeof(struct graph));
	if(!g)
		exit(0);
	g->A=calloc(n,sizeof(struct listnode*));
	if(!g->A)
		exit(0);
	for(int i=0; i<n; i++)
		g->A[i]=NULL;
	g->n=n;
	return g;
}

void destroy(Graph g){
	struct listnode* temp, *aux;
	for(int i=0; i<g->n; i++){
		temp=g->A[i];
		while(temp!=NULL){
			aux=temp->next;
			free(temp);
			temp=aux;
		}
	}
	free(g);
	printf("Liberato\n");
}

void graph_edgeinsert(Graph g, int v, int w){
	struct listnode *temp=malloc(sizeof(struct listnode));
	temp=g->A[v];//temp contiene la testa della lista di collegamenti di v
	g->A[v]=malloc(sizeof(struct listnode));
	g->A[v]->v=w;//v ora punta al nuovo nodo
	g->A[v]->next=temp;//Il nuovo nodo punterà alla vecchia testa

	temp=g->A[w];
	g->A[w]=malloc(sizeof(struct listnode));
	g->A[w]->v=v;
	g->A[w]->next=temp;
}

void dsf(Graph g){

	int *aux=calloc(g->n,sizeof(int));

	for(int i=0; i<g->n; i++)
		aux[i]=0;

	for(int i=0; i<g->n; i++){
		if(aux[i]==0){
			printf("%d\n", i);
			dsf1(g,i,aux);
		}
	}
}

void dsf1(Graph g,int i, int *aux){
	struct listnode *t=malloc(sizeof(struct listnode));
	aux[i]=1;
	t=g->A[i];
	while(t!=NULL){
		if(aux[t->v]==0){	//Significa che v non è stato visitato
			printf("%d\n", t->v);
			dsf1(g,t->v,aux);
		}
		t=t->next;
	}
	free(t);
}