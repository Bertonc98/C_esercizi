#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){	
	int alfabeto[26]={0};
	char ch;

	while((ch=getchar())!='.'){
		if(isalpha(ch)){
			if(islower(ch)){
				ch=toupper(ch);
			}
		alfabeto[ch-'A']++;
		}
	}

	

	for(int i=0; i<sizeof(alfabeto)/sizeof(int); i++){
		if(alfabeto[i]>0){
			printf("%c:",(char)i+'A');
			for(int k=0; k<alfabeto[i]; k++)
				printf("*");
			printf("\n");
		}

	}
	return 0;
}