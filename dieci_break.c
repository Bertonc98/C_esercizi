#include<stdio.h>

int main(){
int sum=0, x;

for(int i=0; i<10; i++){
	scanf(" %d", &x);
	sum=sum+x;
	if(x==0)
		break;
}

printf("%d\n", sum);
return 0;
}
