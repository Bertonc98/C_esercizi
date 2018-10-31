#include<stdio.h>

int hanoi(int n, int from, int temp, int to, int x){
	if(n==1){
		return x+1;

	}
	else{
		x=hanoi(n-1, from, to, temp,x);
		
		x=hanoi(n-1, temp, from, to,x);
		x++;
	}
	return x;
	
}

int main(){
	int n;
	printf("Inserire il numero di dischi: ");
	scanf("%d",&n);

	printf("Numero di mosse: %d\n", hanoi(n,0,1,2,0));
	return 0;
}