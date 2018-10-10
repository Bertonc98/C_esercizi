#include<stdio.h>

int main()
{
	int n, i=-1;
	float sum=0;

	do{
		scanf("%d", &n);
		sum+=n;
		i++;

	}while(n!=0);

	printf("%.2f",sum/i);
	return 0;
}