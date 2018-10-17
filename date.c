#include<stdio.h>
#include<string.h>

typedef struct{
	int giorno;
	int mese;
	int anno;
}Data;

int main(){
	Data lista[100];
	int i,g,m,a;
	for(i=0; i<100; i++){
		scanf(" %d/%d/%d", &g,&m,&a);
		if(g==0 && m==0 && a==0)
			break;
		lista[i].giorno=g;
		lista[i].mese=m;
		lista[i].anno=a;
		
	}
	printf("Inserire la data di controllo: ");
	scanf(" %d/%d/%d", &g,&m,&a);

	for(int k=0; k<i; k++){
		if(lista[k].anno<a || (lista[k].anno==a && lista[k].mese<m) || (lista[k].anno==a && lista[k].mese==m && lista[k].giorno<=g))
			printf("%02d/%02d/%4d \n", lista[k].giorno, lista[k].mese, lista[k].anno);
	}

	return 0;
}