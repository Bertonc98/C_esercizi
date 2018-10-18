#include<stdio.h>
#include<ctype.h>

int main(){
	int x,y, contapos=0;

	printf("Inserire il numero di righe: ");
	scanf("%d", &x);
	printf("Inserire il numero di colonne: ");
	scanf(" %d", &y);

	char campo[x][y];


	printf("Inserire i valori per riga: \n");

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			scanf(" %c", &campo[i][j]);
		}
	}
	printf("\n");
	for(int i=0; i<x; i++){
		for(int j=y-1; j>=0; j--){
			if(isalpha(campo[j][i]) && campo[y-contapos-1][i]=='*'){
				campo[y-contapos-1][i]=campo[j][i];
				campo[j][i]='*';
				contapos++;
			}
		}
		contapos=0;
	}


	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			printf("%c ", campo[i][j]);
		}
		printf("\n");
	}


	return 0;
}