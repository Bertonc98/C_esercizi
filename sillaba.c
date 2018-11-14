#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[]){
	char *parola;
	for(int i=1; i<argc; i++){
		parola=argv[i];
		int j=0, isup=0, upn=0;
		while(*(parola+j)!='\0'){
			if(isupper(*(parola+j))){
				*(parola+j)=tolower(*(parola+j));
				isup=1;
			}
			if(isupper(*(parola+j+1))){
				*(parola+j+1)=tolower(*(parola+j+1));
				upn=1;
			}

			if(*(parola+j)<*(parola+j+1) || *(parola+j+1)=='\0'){
				if(isup==1)
					printf("%c",toupper(*(parola+j)));
				else
					printf("%c",*(parola+j));
				if(upn==1)
					*(parola+j+1)=toupper(*(parola+j+1));
				isup=0;
				upn=0;
				j++;
			}
			else if(*(parola+j)!='\0'){
				if(isup==1)
					printf("%c-",toupper(*(parola+j)));
				else
					printf("%c-",*(parola+j));
				if(upn==1)
					*(parola+j+1)=toupper(*(parola+j+1));
				isup=0;
				upn=0;
				j++;
			}

		}

		printf("\n");
	}
	
	return 0;
		
}