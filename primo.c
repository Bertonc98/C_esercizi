#include<stdio.h>

enum boolean{VERO, FALSO};

int primo(int b){
	if(b%2==0)
		return FALSO;
	else{
		for(int i=3; i<b/2; i++)
			if(b%i==0)
				return FALSO;
	}

	return VERO;
}

int main(){
	int b;

	scanf("%d", &b);

	if(primo(b)==VERO)
		printf("PRIMO\n");
	else
		printf("NON PRIMO\n");

	return 0;
}