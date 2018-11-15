#include<stdio.h>
#include<stdlib.h>

int *my_malloc(size_t size, int *p);

int *my_realloc(size_t size, int *p);

int main(){
	int n,m, *p;

	printf("Inserisci la porzione di memoria da allocare: ");
	scanf("%d",&n);

	p=my_malloc(n,p);
	printf("Puntatore malloc:%p\n",p);

	printf("Inserisci la porzione di memoria da riallocare: ");
	scanf("%d",&m);

	p=my_realloc(m,p);
	printf("Puntatore realloc:%p\n",p);

	free(p);
	return 0;
}

int *my_malloc(size_t size, int *p){
	p=malloc(size);

	if(p==NULL){
		printf("Error malloc\n");
		free(p);
		exit(0);
	}
	return p;
}

int *my_realloc(size_t size, int *p){
	p=realloc(p,size);

	if(p==NULL){
		printf("Error realloc\n");
		free(p);
		exit(0);
	}
	return p;
}