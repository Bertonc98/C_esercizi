#include<stdio.h>
#include<ctype.h>

char *maiuscolo( char *stringa);

int main(){
	char *frase, *maiuscola;
	int i=0, bo=0;

	while((*(frase+i)=getchar())!='\n')
		i++;
	*(frase+i)='\0';

	maiuscola=maiuscolo(frase);

	while(*(frase+bo)!='\0')
		putchar(*(maiuscola+bo++));
	printf("\n");
	return 0;
}

char *maiuscolo(char *stringa){
	char *inizio=stringa;
	while(*stringa!='\0'){
		if(isalpha(*stringa))
			*stringa=toupper(*stringa);
		stringa++;
	}
	return inizio;
}