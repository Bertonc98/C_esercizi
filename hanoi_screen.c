#include<stdio.h>

void hanoi(int n, int from, int temp, int to){
	if(n==1){
		from--;
		to++;
		for(int i=0; i<from; i++)
			printf("%c", i+'A');
		printf(",");
		for(int i=0; i<temp; i++)
			printf("%c", i+'A');
		printf(",");
		for(int i=0; i<to; i++)
			printf("%c", i+'A'+from);
		printf("\n");

	}
	else{
		hanoi(n-1, from, to, temp);

		from--;
		temp++;
		for(int i=0; i<from; i++)
			printf("%c", i+'A');
		printf(",");
		for(int i=0; i<temp; i++)
			printf("%c", i+'A');
		printf(",");
		for(int i=0; i<to; i++)
			printf("%c", i+'A'+from);
		printf("\n");
		
		hanoi(n-1, temp, from, to);
	}
	
}

int main(){
	int n;
	printf("Inserire il numero di dischi: ");
	scanf("%d",&n);
	hanoi(n,n,0,0);
	return 0;
}