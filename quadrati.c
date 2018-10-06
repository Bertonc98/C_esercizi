#include<stdio.h>
#include<math.h>
#define n_quadrati 10

int main(){
int count=0, i=0;

while(count<n_quadrati){
	for(int x=0; x<=i/2; x++){
		if(pow(x,2.0)==i){
			printf("%d=%d^2\n", i,x);
			count++;
			break;
		}
	}
i++;
}

return 0;
}

