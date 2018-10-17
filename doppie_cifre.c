#include<stdio.h>

int main(){
	int n;
	int count=0;
	scanf(" %d", &n);
	int copia=n;
	int cifre[10]={0};

	while(copia>0){
			copia=copia/10;
			count++;
		}

	int array[count+1];

	for(int i=0; i<count; i++){
		array[i]=n%10;
		n=n/10;
	}
	

	for(int i=0; i<count; i++){
		for(int k=0; k<count; k++){
			if(i!=k && array[i]==array[k])
				cifre[array[i]]=1;
		}
	}


	for(int k=0; k<10; k++){
		if(cifre[k]==1)
			printf("%d ", k);
			
		}

	printf("\n");


	printf("\n");
	return 0;
	
}