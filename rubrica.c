#include<stdio.h>
#include<ctype.h>
#define N 100

typedef struct{
	char nome[20];
	char numero[10];
}contatto;

int main(){
	contatto rubrica[N];
	int indice=0;
	char scelta='2';
	do{
		printf("MENU\n");
		printf("Inserire il numero per fare l'azione: \n");
		printf("1.Visualizza la rubrica\n");
		printf("2.Inserisci contatto\n");
		printf("Inserisci '.' per uscire\n\n");

		if(scelta=='1'){
			if(indice==0)
				printf("Rubrica vuota\n");
			else{
				for(int i=0; i<indice; i++){
					printf("Nome: %s Numero: %s \n\n\n", rubrica[i].nome, rubrica[i].numero);
				}
			}
		}
		else if(scelta=='2'){
			printf("Inserire il nome: ");
			scanf("%s", rubrica[indice].nome);
			printf("Inserire il numero: ");
			scanf("%s", rubrica[indice].numero);
			indice++;
			printf("\n\n");
		}
		else if(scelta=='\n')
			indice=indice+0;
		else{
			printf("Comando non riconosciuto\n\n");
		}
	}while( (scelta=getchar())!='.');

	return 0;
}