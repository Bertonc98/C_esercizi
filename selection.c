#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main(){
	int array[N], min, temp;
	srand(time(NULL));
	for(int i=0; i<N; i++){
		//scanf(" %d",&array[i]);
		array[i]=rand()%100;
	}

	for(int k=0; k<N; k++){
		min=k;
		for(int j=k+1; j<N; j++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		temp=array[k];
		array[k]=array[min];
		array[min]=temp;

	}

	for(int i=0; i<N; i++){
	printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}