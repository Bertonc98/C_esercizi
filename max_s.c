#include<stdio.h>
#include<ctype.h>

void max_secondmax ( int a[], int n, int *max, int *second);

int main(){
	int n=0;
	printf("Lunghezza array: ");
	scanf(" %d", &n);

	int a[n], max=0, second=0;

	for(int i=0; i<n; i++){
		printf("Inserisci un numero: ");
		scanf(" %d", &a[i]);
	}
	

	max_secondmax(a,n,&max, &second);

	printf("Max: %d\nSecond: %d\n",max,second);
	return 0;
}

void max_secondmax ( int a[], int n, int *max, int *second){
	*max=a[0];
	for(int i=0; i<n; i++){
		printf("done\n");
		if(*max<a[i])
			*max=a[i];
		if(*second<a[i] && a[i]<*max)
			*second=a[i];
	}
}