#include<stdio.h>
#define N 20

void reverse(char *stringa, char *ritorno, int l);

int main(){
	char frase[N], rovesciata[N];
	int i=0;

	while((frase[i]=getchar())!='\n')
		i++;
	

	reverse(frase,rovesciata, i);

	for(int j=0; j<i; j++)
		putchar(rovesciata[j]);
	printf("\n");
	return 0;
}

void reverse(char *stringa, char *ritorno, int l){
	for(int i=0; i<l; i++){
		*(ritorno+i)=*(stringa+(l-1-i));
		}	
	}

