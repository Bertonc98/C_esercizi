#include<stdio.h>

int main(){
	int a[100];
	int i;

	for(i=0; i<100; i++){
		scanf(" %d", &a[i]);

		if(a[i]==0)
			break;
	}

	for(int k=i-1; k>=0; k--){
		printf("%d ", a[k]);
		}

	printf("\n");

	return 0;
}