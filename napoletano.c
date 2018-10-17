#include<stdio.h>
#include<string.h>

int main(){
	char frase[100];
	char buffer;
	printf("Inserire la frase: \n");
	int i=0;
	while((buffer=getchar())!='\n'){
		frase[i]=buffer;
		i++;
	}

	for(int k=0; k<i; k++){
		if(frase[k+1]!=' ' && k!=i-1)
			printf("%c", frase[k]);
	}
	
	printf("\n");
	return 0;
}