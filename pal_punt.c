#include<stdio.h>
#define N 30

int palindromo(char *frase, int l);

int main(){
	char frase[N];
	int i=0, bo;

	while((frase[i]=getchar())!='\n')
		i++;

	bo=palindromo(frase,i);

	if(bo==0)
		printf("Palindromo\n");
	else
		printf("Non palindromo\n");

	return 0;
}

int palindromo(char *frase, int l){
	int i=l/2;
	for(int j=0; j<=i; j++){
		if(*(frase+j)!=*(frase+l-j-1))
			return 1;
	}
	return 0;
}