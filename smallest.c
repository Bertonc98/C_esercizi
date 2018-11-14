#include<stdio.h>

int *smallest( int a[], int n );

int main(){
	int n=0;
	printf("Lunghezza array: ");
	scanf(" %d", &n);

	int a[n], *min;

	for(int i=0; i<n; i++){
		printf("Inserisci un numero: ");
		scanf(" %d", &a[i]);
	}
	

	min=smallest(a,n);

	printf("Min: %d\n",*min);
	return 0;
}

int *smallest( int a[], int n ){
	int *min=a;
	for(int i=0; i<n; i++){
		if(*min>a[i])
			min=&a[i];
	}
	return min;
}