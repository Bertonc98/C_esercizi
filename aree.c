#include<stdio.h>
#include<math.h>

typedef struct{
	float x, y;
} Punto;

typedef struct{
	Punto p1, p2;
} Rettangolo;

typedef struct{
	Punto center;
	float r;
} Cerchio;

int main(){
	char c=getchar();

	if(c=='c'){
		Cerchio c;
		float in;

		printf("Inserire la lunghezza del raggio: ");
		scanf(" %f", &in);
		printf("%f", in*3,14*3,14);

	}
	else if(c=='r'){
		Rettangolo r;
		float in, b, h;

		printf("Inserire le coordinate del primo punto: ");
		scanf(" %f", &in);
		r.p1.x=in;
		scanf(" %f", &in);
		r.p1.y=in;
		printf("Inserire le coordinate del secondo punto: ");
		scanf(" %f", &in);
		r.p2.x=in;
		scanf(" %f", &in);
		r.p2.y=in;

		b=fabs(r.p1.x-r.p2.x);
		h=fabs(r.p1.y-r.p2.y);

		printf("Area=: %f", b*h);

	}
	else
		printf("Ancora non esiste\n");
	

	return 0;
}