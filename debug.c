#include<stdio.h>
#include<string.h>


int main(void){
	char *dict[6], buffer[10];
	int lun = 6;

	for(int i=0; i<lun; i++){
		scanf("%s",&buffer);
		strcpy(dict[i], buffer);
	}


	return 0;
}