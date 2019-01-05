#include<stdio.h>
#define N 100

void stampa(int a[], int lung);

void scambia(int a[], int i, int j);

void selectionsort(int a[], int n);

void mergesort(int a[], int sx, int dx);

int main(){
	int a[N]={0};
	int l;
	printf("Inserisci la lunghezza: ");
	scanf("%d",&l);
	printf("Inserisci la sequenza di %d numeri: ", l);

	for(int i=0; i<l; i++)
		scanf("%d",&a[i]);

	mergesort(a, 0, l);

	stampa(a,l);

	return 0;
}

void stampa(int a[], int lung){
	for(int i=0; i<lung; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void scambia(int a[], int i, int j){
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

void selectionsort(int a[], int n){
	if(n>1){
		int max=0;
		for(int i=0; i<n; i++){
			if(a[i]>a[max])
				max=i;
		}
		scambia(a, max, n-1);

		selectionsort(a, n-1);
	}

}


void mergesort(int a[], int sx, int dx){
	if(dx-sx>1){
		mergesort(a, sx, (sx+dx)/2);
		mergesort(a, ((sx+dx)/2), dx);

		int i1=sx, i2=(sx+dx)/2, counter=0, sup[dx];
		
		while(i1<(sx+dx)/2 && i2<dx){
			if(a[i1]>a[i2]){
				sup[counter]=a[i2];
				i2++;
			}
			else{
				sup[counter]=a[i1];
				i1++;
			}
			counter++;
		}

		if(i2==dx){
			for(int k=i1; k<(sx+dx)/2; k++){
				sup[counter]=a[k];
				counter++;
			}
		}
		else{
			for(int k=i2; k<dx; k++){
				sup[counter]=a[k];
				counter++;
			}
		}
		for(int k=sx; k<dx; k++)
			a[k]=sup[k-sx];

	}
}