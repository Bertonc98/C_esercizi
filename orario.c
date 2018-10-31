#include<stdio.h>

void split_time(long sec, int *h, int *m, int *s);

int main(){
	int h=0, m=0, s=0;
	long sec;

	printf("Inserire il numero di secondi da convertire: ");
	scanf(" %ld",&sec);

	split_time(sec, &h,&m,&s);

	printf("Ore: %d\nMinuti: %d\nSecondi: %d\n",h,m,s);

	return 0;
}

void split_time(long sec, int *h, int *m, int *s){

	*h=sec/3600;
	sec%=3600;

	*m=sec/60;
	sec%=60;

	*s=sec;
}
