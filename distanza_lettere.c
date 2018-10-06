#include<stdio.h>

int main(){
char a, b, pulisci_buffer;

a=getchar();
pulisci_buffer=getchar();
b=getchar();
if((a>='A' && a<='Z')&&(b>='A' && b<='Z')){
	char max= a>=b? a:b;
	char min= a>=b? b:a;
	printf("Distanza= %d \n", (max-min)); 
	}
else
	printf("nop\n");
return 0;
}
