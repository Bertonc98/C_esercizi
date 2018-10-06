#include<stdio.h>

int main(){
int m, h;
scanf("%d:%d", &h, &m);

if(h>=0 && h<=23 && m>=0 && m<=59){
	if(m==0 && h==0)
		printf("12:00AM\n");
	else if(h<12 && (h!=0 && m!=0)){
		printf("%d:%dAM\n", h, m);	
	}
	else{
		printf("%d:%dPM\n", h%13, m);	
	}
}
else
	printf("Non valido\n");

return 0;
}
