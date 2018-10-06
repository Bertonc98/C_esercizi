//vocale consonante o altro
#include <stdio.h>
#include<ctype.h>

int main(){
char c;

scanf(" %c", &c);

if(isupper(c))
	c=tolower(c);

if(c=='a' || c=='u' ||c=='e' ||c=='i' ||c=='o')
	printf("Una vocale \n");
else if(c<='z' && c>='a')
	printf("Consonante \n");
else
	printf("Not a letter\n");
return 0;
}
