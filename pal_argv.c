#include<stdio.h>
#include<string.h>

int palindromo(char *frase, char *end);

int main(int argc, char const *argv[]){
	char *parola=argv[1],*end=argv[1]+strlen(argv[1]);
	for(int k=1; k<argc; k++){
		parola=argv[k];
		end=argv[k]+strlen(argv[k]);
	if(palindromo(parola, end)){
		printf("Non palindroma\n");
	}
	else
		printf("Palindroma\n");

	}
	return 0;
}

int palindromo(char *frase, char *end){
	
	for(int i=0; i<strlen(frase)/2; i++){
		
		if(tolower(*(frase+i))!=tolower(*(end-i-1))){
			return 1;
		}
	}
	return 0;
	
}

