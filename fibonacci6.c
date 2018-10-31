#include<stdio.h>

void potenza(long a[][2]){
	long x=a[0][0],b=a[0][1],c=a[1][0],d=a[1][1];
	a[0][0]=x+b;
	a[0][1]=x;
	a[1][0]=c+d;
	a[1][1]=c;
}

int main(){
	long matrice[2][2]={{1,1},{1,0}};
	long n=0;

	scanf(" %ld",&n);

	for(int i=0; i<n-1;i++){
	
		potenza(matrice);

	}

	for(int k=0; k<2; k++){
		for(int j=0; j<2; j++)
			printf("%03ld ", matrice[k][j]);
		printf("\n");
	}

	printf("\n");
	printf("Numero di fibonacci %ld = %ld\n", n, matrice[0][0]);
	


}