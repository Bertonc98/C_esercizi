#include <stdio.h>
#include <math.h>

//Calcolare le equazioni complesse dell'equzione ax^2+bx+c
int main(){
double a, b, c;
double delta;
printf("Inserire 3 numeri: \n");
scanf(" %lf", &a);
scanf(" %lf", &b);
scanf(" %lf", &c);

delta=pow(b,2.0)-4*(a*c);

if(a!=0){
	if(delta>0){
		double x1,x2;
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);

		printf("Le soluzioni sono: %lf, %lf \n", x1, x2);
	}
	if(delta==0){
		double x = -b/(2*a);
		if(x==-0.0)
			x*=-1;
		printf("Soluzione: %lf \n", x);
	}
	if(delta<0){
		delta=-delta;
		b=-b;
		a=2*a;
		delta=sqrt(delta);
		double xr=b/a;	
		double xi=delta/a;

		printf("Soluzione1: \n %lf, +i(%lf) \n", xr, xi);
		printf("Soluzione2: \n %lf, -i(%lf) \n", xr, xi);
	}
}
else
	printf("Non è di secondo grado \n");
return(0);
}
