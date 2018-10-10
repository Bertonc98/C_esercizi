#include<stdio.h>

int main(){
	int n;
	printf("Inserire la dimensione del quadrato: ");
	scanf(" %d", &n);


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((i+j)%2==0)
				printf(" +");
			else
				printf(" o");
		}
		printf("\n");

	}

	return 0;
}