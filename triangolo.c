#include<stdio.h>

int main(){
	int n, m, c=0, x=3;
	printf("Inserire la dimensione del quadrato: ");
	scanf(" %d", &n);
	m=n+2;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(j==(m-i-1)){
				printf("*");
			}
			else if((i==(m-x-2)) && j==c ){
				printf("*");
				c++;
				x--;
			}
			else
				printf(".");
		}
		printf("\n");

	}

	return 0;
}