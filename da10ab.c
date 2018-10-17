#include<stdio.h>

int main(){
	int cifre[100] = {0};
	int n, b, segnalino=0;

	scanf("%d %d", &n, &b);
	printf("\n");
	while(n!=0){
		cifre[segnalino]=n%b;
		n=n/b;
		if(n!=0)
			segnalino++;
	}

	if(segnalino<=100){
		for(int i=segnalino; i>=0; i--)
			printf("%d ", cifre[i]);
		printf("\n");
	}
	else{
		printf("Numero troppo grande\n");
	}

	return 0;
}