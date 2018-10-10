#include<stdio.h>

int main()
{
	int mese, giorno, limite, bisestile;
	printf("L'anno è bisestile? (1 o 0) \n con altri input verrà valutato come non bisestile: ");
	scanf(" %d", &bisestile);
	if(bisestile!=1 && bisestile!=0)
		bisestile=0;

	printf("Inserisci il mese (1-Gennario...12-Dicembre): ");
	scanf(" %d", &mese);
	if(mese<=12 && mese >=1){

		printf("Inserisci giorno di inizio mese (1-lun...7-Dom): ");
		scanf(" %d", &giorno);
		if(giorno>=1 && giorno <=7){
			printf("L  M  M  G  V  S  D\n");

			if(mese==2){
				if(bisestile==0)
					limite=28;
				else
					limite=29;
			}
			else if(mese==11 || mese==4 || mese==6 || mese== 9)
				limite=30;
			else
				limite=31;

			for(int i=0; i<giorno-1; i++)
				printf("   ");

			for(int i=1; i<=limite; i++){
				if((i+giorno)%7==1)
					printf("%d\n",i);
				else{
					if(i<10)
						printf("%d  ",i);
					else
						printf("%d ",i);
				}
			}
		}
		else
			printf("Formato non valido\n");
	}
	else
		printf("Formato non valido\n");

	printf("\n");
	return 0;
}