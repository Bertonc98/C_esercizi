#include<stdio.h>

void scambia(int *p, int *q);

int main(){
	int a, b;

	printf("Inserire i 2 numeri separati da uno spazio: ");
	scanf("%d %d", &a,&b);
	scambia(&a,&b);
	printf("%d %d\n", a,b);
	
	return 0;
}


void scambia(int *p, int *q){
	int c=*p;
	*p=*q;
	*q=c;
}