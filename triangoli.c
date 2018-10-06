#include <stdio.h>

int main(){
int a,b,c;

printf("Inserire i 3 lati \n");
scanf(" %d %d %d", &a, &b, &c);

if(a>b+c || b>a+c || c>a+b){
	printf("Non è un triangolo\n");
}
else{
	if(a==b && b==c)
		printf("Equilatero\n");
	else if(a==b || a==c || b==c)
		printf("Isoscele\n");
	else
		printf("Scaleno\n");
}


return 0;
}
