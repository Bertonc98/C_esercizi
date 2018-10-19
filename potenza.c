#include<stdio.h>

int power(int b, int e){
	int sum=1;
	for(int i=0; i<e; i++)
		sum*=b;
	return sum;
}

int main(){
	int b,e;

	scanf("%d %d", &b, &e);

	printf("%d\n", power(b,e));

	return 0;
}