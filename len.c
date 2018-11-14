#include<stdio.h>
#include<ctype.h>
int lung_stringa( char *s );
int main(){
	char *frase;
	int i=0;
	int x=&frase;

	while((*(frase+i)=getchar())!='\n')
		i++;
	*(frase+i)='\0';
	printf("Lunghezza: %d\n",lung_stringa(frase));
	return 0;
}

int lung_stringa( char *s ){
	int i=0;
	while(*s++!='\0')
		i++;
	return i;
}