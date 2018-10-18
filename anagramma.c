#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){	
	int alfabeto[26]={0};
	char ch;

	printf("Inserire la prima parola: ");
	while((ch=getchar())!='\n'){
		if(isalpha(ch)){
			if(islower(ch)){
				ch=toupper(ch);
			}
		alfabeto[ch-'A']++;
		}
	}


	printf("Inserire la seconda parola: ");
	while((ch=getchar())!='\n'){
		if(isalpha(ch)){
			if(islower(ch)){
				ch=toupper(ch);
			}
		alfabeto[ch-'A']--;
		}
	}
	int i;
	for(i=0; i<sizeof(alfabeto)/sizeof(int); i++){
		if(alfabeto[i]!=0){
			printf("Non sono anagrammi\n");
			break;
		}
	}

	if(i==sizeof(alfabeto)/sizeof(int))
		printf("Sono anagrammi\n");

	return 0;
}