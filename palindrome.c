#include<stdio.h>
#include<string.h>

int main(){
	char stringa[100];
	int i=0, check=0;

	scanf("%s", stringa);
	int count=strlen(stringa);

	for(i=0; i<strlen(stringa); i++){
		if(stringa[i]!=stringa[count-i-1]){
			printf("Errore\n");
			check=1;
			break;
		}
	}
	

	if(check==0)
		printf("Palindroma\n");

	return 0;
}