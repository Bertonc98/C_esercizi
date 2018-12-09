#include<stdio.h>
#include<stdlib.h>
//IN qursto esercizio lo heap sarà di interi
typedef int *Heap ;

struct pqueue {
	Heap h;
	int size , count ;
};

typedef struct pqueue * Pqueue;

Pqueue pqueue_new ( int n );
void pqueue_destroy ( Pqueue p);
int pqueue_length ( Pqueue p);
void pqueue_insert ( Pqueue p, int n );
int pqueue_extractmin ( Pqueue p);

int father(Heap h, int i);
void swap(Heap h, int i, int j);
void heapify_up(Heap h, int i);

int main(){
	int len, ins;
	scanf(" %d", &len);
	Pqueue prova=pqueue_new(len);

	for(int i=0; i<len; i++){
		scanf(" %d",&ins);
		pqueue_insert(prova, ins);
	}

	for(int i=1; i<prova->count;i++){
		printf("%d ",prova->h[i]);
	}
	printf("\n");
	pqueue_destroy(prova);

	return 0;
}

Pqueue pqueue_new ( int n ){
	Pqueue new=calloc(1,sizeof(struct pqueue));
	int *array=calloc(n+1, sizeof(int));
	array[0]=-1;
	new->h=array;
	new->size=n+1;
	new->count=1;
	return new;
}
void pqueue_destroy ( Pqueue p){
	free(p);
	p=NULL;
}
int pqueue_length ( Pqueue p){
	if(p!=NULL)
		return p->count;
	else
		return 0;
}
void pqueue_insert ( Pqueue p, int n ){
	if(p->count<p->size){
		p->h[p->count]=n;
		heapify_up(p->h, p->count);
		p->count++;
	}
}

void heapify_up(Heap h, int i){
	if(i>1){
		int j=father(h, i);
		if(  h[i] < h[j] ){
			swap( h, i, j );
			heapify_up( h, j );
		}
	}
}
int father(Heap h, int i){
	return i/2;
}
void swap(Heap h, int i, int j){
	int temp;
	temp=h[i];
	h[i]=h[j];
	h[j]=temp;
}