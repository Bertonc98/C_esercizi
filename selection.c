#include<stdio.h>

int main(){
	int array[10], min, temp, num=0;

	for(int i=0; i<10; i++){
	scanf(" %d",&array[i]);
	}

	for(int k=0; k<10; k++){
		min=k;
		for(int j=k+1; j<10; j++){
			num++;
			if(array[j]<array[min]){
				min=j;
			}
		}
		temp=array[k];
		array[k]=array[min];
		array[min]=temp;

	}

	for(int i=0; i<10; i++){
	printf(" %d",array[i]);
	}

	printf("\n%d\n", num);
	return 0;
}