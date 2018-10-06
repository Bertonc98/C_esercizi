#include<stdio.h>
#include<ctype.h>

int main(){
int key;
char c, pulisci_buffer;

scanf(" %d", &key);
pulisci_buffer=getchar();

while( (c=getchar())!='\n'){
	if(islower(c)){
		if((c+key)>'z'){
			printf("%c", 'a'+((c-'a')+key)%26);
		}
		else
			printf("%c", c+key);
		
	}
	else if(isupper(c)){
		if((c+key)>'Z'){
			printf("%c", 'A'+((c-'A')+key)%26);
		}
		else
			printf("%c", c+key);
		
	}
	else
		printf("%c",c);
}

printf("\n");
return 0;
}
