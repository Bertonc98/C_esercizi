#include<stdio.h>

int main(){

int x, count=0;
scanf(" %d", &x);

int i=x/2;
printf("%d, ", x);
while(i>1){
	if(x%i==0){
		printf("%d, ", i);
		count++;
	}
	i--;
}

printf("1\n");

if(count==0)
	printf("Numero primo\n");

printf("Numero di divisori: %d\n", count+2);
return 0;
}
