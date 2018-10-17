#include<stdio.h>
#include<math.h>

int main(){
	int cifre[100] = {0};
	int b, segnalino=0, sum=0;
	char ch;

	scanf("%d", &b);
	
	while((ch=getchar()) != '.'){
		if(ch != '\n'){
		cifre[segnalino]=(int)ch-'0';
		segnalino++;
		}
	}

	int count=0;

	for(int i=segnalino-1; i>=0; i--){
		sum+=cifre[count]*(int)pow(b,i);
		count++;
	}

	printf("%d\n", sum);

	return 0;
}