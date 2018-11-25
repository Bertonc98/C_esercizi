#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct bit_node {
	int key;
	struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;
Bit_node bit_new(int key);
void bit_preorder(Bit_node b);
void bit_inorder(Bit_node b);
void bit_postorder(Bit_node b);
void bit_printassummary(Bit_node p, int spaces);
Bit_node bit_arr2tree( int a[], int size, int i);

int main(){
	int n;
	printf("Inserire la lunghezza dell'array: ");
	scanf(" %d", &n);
	int a[n];
	srand(time(NULL));
	for(int i=0; i<n; i++){
		a[i]=rand()%50;
		printf("%d ",a[i]);
	}
	printf("\n");
	Bit_node root = bit_arr2tree(a, n, 0);
	bit_printassummary(root, 2);
	return 0;
}

Bit_node bit_new(int key){
	Bit_node temp = malloc(sizeof(struct bit_node));

	if(temp==NULL){
		printf("Memoria esaurita\n");
		exit(0);
	}
	temp->key=key;
	temp->l=NULL;
	temp->r=NULL;
	return temp;
}

void bit_preorder( Bit_node b){
	if(b==NULL){
		printf("nullo\n");
	}
	else if(b->l==NULL && b->r==NULL)
		printf("%d\n", b->key);
	else{
		printf("%d\n", b->key);
		bit_preorder(b->l);
		bit_preorder(b->r);
	}
}

void bit_postorder( Bit_node b){
	if(b==NULL){
		printf("nullo\n");
	}
	else if(b->l==NULL && b->r==NULL)
		printf("%d\n", b->key);
	else{
		bit_preorder(b->l);
		bit_preorder(b->r);
		printf("%d\n", b->key);
	}
}

void bit_inorder( Bit_node b){
	if(b==NULL){
		printf("nullo\n");
	}
	else if(b->l==NULL && b->r==NULL)
		printf("%d\n", b->key);
	else{
		bit_preorder(b->l);
		printf("%d\n", b->key);
		bit_preorder(b->r);
	}
}

void bit_printassummary(Bit_node b, int spaces){
	if(b==NULL){
		printf("*\n");
	}
	else if(b->l==NULL && b->r==NULL){
		printf("*%d\n", b->key);
	}
	else{
		printf("*%d\n", b->key);

		for(int i=0; i<spaces; i++)
			printf(" ");
		bit_printassummary(b->l,spaces+spaces);
		

		for(int i=0; i<spaces; i++)
			printf(" ");
		bit_printassummary(b->r,spaces+spaces);
	}
}

Bit_node bit_arr2tree( int a[], int size, int i){
	if(size==0)
		return NULL;
	Bit_node temp = bit_new(a[i]);
	if(((2*i)+2)<size){
		temp->l=bit_arr2tree(a,size,((2*i)+1));
		temp->r=bit_arr2tree(a,size,((2*i)+2));
	}
	else if(((2*i)+1)<size){
		temp->l=bit_arr2tree(a,size,((2*i)+1));
		temp->r=NULL;
	}
	else{
		temp->l=NULL;
		temp->r=NULL;
	}
	return temp;
}