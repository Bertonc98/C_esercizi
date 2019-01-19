#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *A, int *X, int i, int f);
void merge(int *A, int *X, int i, int m, int f);
int partiziona(int *A, int i, int f);
void quicksort(int *A, int i, int f);

int main(){
	int scelta;
	printf("Seleziona l'algoritmo da utilizzare: ");
	scanf(" %d",&scelta);

	if(scelta==0){//selection sort
				int array[10]={2,12,25,89,58,20,60,29,31,4};
				int max, i, j, temp;
				printf("Selection sort \n");
				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");
				for(i=0; i<9; i++){
					max=i;
					for(j=i+1; j<10; j++){
						if(array[j]<array[max]){
							max=j;
							}
						}
				temp=array[i];
				array[i]=array[max];
				array[max]=temp;
				}

				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");
	}
	else if(scelta==1){//insertion sort
		/*Prendo un elemento, e sposto in avanti tutti quelli prima di lui finche non trovo uno di lui minore
		Dando per scontato che la parte prima sia ordinata*/
		printf("Insertion sort \n");
				int array[10]={2,12,25,89,58,20,60,29,31,4};
				int i, j, x;
				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");

				for(i=1; i<10; i++){
					x=array[i];
					j=i-1;
					while(j>=0 && x<array[j]){
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=x;
				}

				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");
	}
	else if(scelta==2){//Bubble sort
		printf("Bubble sort \n");
				int array[10]={2,12,25,89,58,20,60,29,31,4};
				int i, j, temp, scambiato;

				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");

				/*for(i=0; i<10; i++){
					for(j=i; j<10-i; j++){
						if(array[i]>array[i+1]){
							temp=array[i];
							array[i]=array[i+1];
							array[i+1]=temp;
						}
					}
				}*/
				
				i=0;
				do{
					scambiato=0;
					for(j=0; j<10-i; j++){
						if(array[j]>array[j+1]){
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
							scambiato=1;
						}
					}
				i++;
				}while(scambiato==1 && i<10);
				
				for(i=0; i<10; i++)
					printf("%d ",array[i]);
				printf("\n");
	}
	else if(scelta==3){//mergesort
		printf("Mergesort \n");
		int array[10]={2,12,25,89,58,20,60,29,31,4}, X[10], i;
		for(i=0; i<10; i++)
			printf("%d ",array[i]);
		printf("\n");

		mergeSort(array,X,0,10);

		for(i=0; i<10; i++)
			printf("%d ",array[i]);
		printf("\n");

	}
	else if(scelta==4){
		printf("Quicksort \n");
		int array[10]={2,12,25,89,58,20,60,29,31,4}, i;
		for(i=0; i<10; i++)
			printf("%d ",array[i]);
		printf("\n");

		quicksort(array,0,10);

		for(i=0; i<10; i++)
			printf("%d ",array[i]);
		printf("\n");

	}
}

void mergeSort(int *A, int *X, int i, int f){
	int m;
	if(f-i>1){
		m=(f+i)/2;
		mergeSort(A,X,i,m);
		mergeSort(A,X,m,f);
		merge(A,X,i,m,f);
	}
}

void merge(int *A, int *X, int i, int m, int f){
	int i1=i, i2=m, k=0;

	while(i1<m && i2<f){
		if(A[i1]<A[i2]){
			X[k]=A[i1];
			i1++;
		}
		else{
			X[k]=A[i2];
			i2++;
		}
		k++;
	}
	if(i1<m){
		for(int j=i1; j<m; j++){
			X[k]=A[j];
			k++;
		}
	}
	else{
		for(int j=i2; j<f; j++){
			X[k]=A[j];
			k++;
		}
	}

	for(int j=i; j<f; j++)
		A[j]=X[j-i];
}

int partiziona(int *A, int i, int f){
	int perno=A[i], sx=i, dx=f, temp;

	while(sx<dx){
		do{
			dx--;
		}while(A[dx]>perno);
		do{
			sx++;
		}while(A[sx]<perno);

		if(sx<dx){
			temp=A[sx];
			A[sx]=A[dx];
			A[dx]=temp;
		}
	}

	temp=A[i];
	A[i]=A[dx];
	A[dx]=temp;

	return dx;
}

void quicksort(int *A, int i, int f){
	int perno;
	if(f-i>1){
		perno=partiziona(A,i,f);
		quicksort(A,i,perno);
		quicksort(A,perno+1, f);
	}
}