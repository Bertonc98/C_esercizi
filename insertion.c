#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main(){
	int array[N], x, j;
	srand(time(NULL));
	for(int i=0; i<N; i++){
		//scanf(" %d",&array[i]);
		array[i]=rand()%100;
	}

	for(int k=1; k<N; k++){
		x=array[k];
		j=k-1;
		while(j>=0 && array[j]>x){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=x;
	}

	for(int i=0; i<N; i++){
	printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}