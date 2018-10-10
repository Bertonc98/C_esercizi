#include<stdio.h>
#include<ctype.h>

int main(){
	char c;
	int count=0;

	while((c=getchar())!='\n'){

		if(c=='(')
			count++;
		else if(c==')')
			count--;

		if(count<0){
			printf("Sbagliato-\n");
			break;
		}
	}

	if(count>0)
		printf("Sbagliato+\n");
	else if(count==0)
		printf("Bravo\n");

	return 0;
}