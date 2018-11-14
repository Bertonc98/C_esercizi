#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[]){
	char *parola;
	for(int i=1; i<argc; i++){
		parola=argv[i];
		int j=0;
		while(*(parola+j)!='\0'){
			if(isalpha(*(parola+j)) && (
				(*(parola+j)=='a' || *(parola+j)=='e' || *(parola+j)=='i'|| *(parola+j)=='o' || *(parola+j)=='u') ||
				(*(parola+j)=='A' || *(parola+j)=='E' || *(parola+j)=='I'|| *(parola+j)=='O' || *(parola+j)=='U')
				)) {
				printf("%cf%c",*(parola+j),*(parola+j));
				j++;
			}
			else
				printf("%c",*(parola+j++));
		}

		printf("\n");
	}
	
	return 0;
		
}