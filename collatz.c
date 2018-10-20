#include<stdio.h>

int next_collatz(int a){
	if(a%2==0)
		return a/2;
	else if(a==1)
		return 1;
	else
		return (a*3)+1;
}

int main(){
	int x, count=1;
	scanf("%d", &x);

	while(x!=1){
		x=next_collatz(x);
		printf("%d ", x);
		count++;
	}
	printf("\nLungehzza: %d \n", count);
	return 0;
}