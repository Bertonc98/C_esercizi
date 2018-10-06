#include<stdio.h>

int main(){
int sum=0, x, count=-1;
while(x!=0){
	scanf(" %d", &x);
	sum=sum+x;
	count++;
}
printf("%d\n", sum/count);
return 0;
}
