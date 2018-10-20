#include<stdio.h>
int checkx(int n, int x){
	if((x+1)>=n)
		return 0;
	return x+1;
}

int checky(int n, int y){
	if((y-1)<0)
		return n-1;
	return y-1;
}


void quad(int n){
	int campo[n][n], x=n/2, y=0, count=1;
	int sumd=0, sumid=0, r=0, c=0;

	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++)
			campo[i][k]=0;
	}

	

	for(int i=0; i<n*n; i++){
			campo[y][x]=count;

			if(x+1>=n)
				x=0;
			else
				x=x+1;

			if(y-1<0)
				y=n-1;
			else
				y=y-1;

			if(campo[y][x]!=0){
				if(x-1<0)
					x=n-1;
				else
					x=x-1;

				if(y+2>=n)
					y=0;
				else
					y=y+2;
			}

			if(campo[y][x]!=0)
				y=y+1;
			count++;
	
	}
	

	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++)
			printf("%02d ", campo[i][k]);
		printf("\n");
	}
	printf("\n");

	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
			if(i==k)
				sumd=sumd+campo[i][k];
		}
	}

	for(int i=0; i<n; i++){
		for(int k=n-1; k>=0; k--){
			r+=campo[i][k];
			if(i==n-k-1){
				sumid=sumid+campo[i][k];
			}
		}
		printf("Riga %d: %d\n", i, r);
		r=0;
	}
	printf("\n");

	for(int i=0; i<n; i++){
		for(int k=n-1; k>=0; k--){
			c+=campo[k][i];
		}
		printf("Colonna %d: %d\n", i, c);
		c=0;
	}
	printf("\n");

	printf("Diagonale: %d\n", sumd);
	printf("Diagonale inversa: %d\n", sumid);

}




int main(){
	int n;

	do{
		printf("Inserire un numero dispari: ");
		scanf(" %d",&n);
	}while(n%2==0);
	printf("\n");
	quad(n);
	printf("\n");

	return 0;
}
