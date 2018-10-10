#include<stdio.h>

int main(){
	int n;
	char c;
	printf("Inserire la dimensione del quadrato: ");
	scanf(" %d", &n);


	for(int i=0; i<n; i++){
		if(i%2==0)
			c='+';
		else
			c='o';
		for(int j=0; j<n; j++)
			printf(" %c", c);
		printf("\n");

	}

	return 0;
}