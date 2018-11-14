#include<stdio.h>
#include<string.h>

int smallest_word_index( char *s[], int n );

int main(void){
	char *dict[] = { "ciao", "mondo", "come", "funziona", "bene", "questo", "programma" };
	int lun = 7, pos=0;

	pos = smallest_word_index( dict, lun );

	printf( "La parola minima si trova in posizione %d.\n", pos+1 );
	return 0;
}

int smallest_word_index( char *s[], int n ){
	int j=0;
	for(int i=0; i<n; i++){
		if(strcmp(s[j], s[i])>0)
			j=i;
	}

	return j;
}