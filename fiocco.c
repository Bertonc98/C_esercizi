#include<stdio.h>
#include "libpsgraph.h"

void line(double l, int x){
	if(x==0)
		draw(l);
	else{
		line(l/3, x-1);
		turn(-60);
		line(l/3, x-1);
		turn(120);
		line(l/3, x-1);
		turn(-60);
		line(l/3, x-1);
	}


}

int main(){
	int x;
	double l;
	printf("Inserire i livelli del segmento e la lunghezza: ");
	scanf("%d %lf", &x, &l);
	start("graph.ps");
	line(l,x);

	turn(120);
	line(l,x);

	turn(120);
	line(l,x);

	end();

	return 0;

}