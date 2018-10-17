#include<stdio.h>
#include<math.h>

int main(){
	int esami[5][5], medie[5]={0};

	for(int i=0; i<5; i++){
		printf("Inserire i voti dello studente %d: ", i+1);
		for(int j=0; j<5; j++){
			scanf(" %d", &esami[i][j]);
		}
	}

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			medie[i]+=esami[i][j];
		}
		medie[i]/=5;
	}

	for(int i=0; i<5; i++){
			printf("%d ", medie[i]);
	}

	return 0;
}