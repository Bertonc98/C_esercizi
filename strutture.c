#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float x, y;
} Punto;

typedef struct{
	Punto p1, p2;
} Rettangolo;

void crea(Rettangolo *r,Punto *pu, Punto *pd ){
	r->p1.x=pu->x;
	r->p1.y=pu->y;
	r->p2.x=pd->x;
	r->p2.y=pd->y;

}

void stampa(Rettangolo *r){
	printf("Vertice 1\nx=%f\ny=%f\n",r->p1.x,r->p1.y);
	printf("Vertice 2\nx=%f\ny=%f\n",r->p2.x,r->p2.y);
}

float area(Rettangolo *r){
	float b, h;
	b=abs(r->p1.x - r->p2.x);
	h=abs(r->p1.y - r->p2.y);

	return b*h;
}

void center(Rettangolo *r, Punto *c){
	float x, y;
	if(r->p1.x > r->p2.x)
		x=((r->p1.x - r->p2.x)/2)+r->p2.x;
	else
		x=((r->p2.x - r->p1.x)/2)+r->p1.x;

	if(r->p1.y > r->p2.y)
		y=((r->p1.y - r->p2.y)/2)+r->p2.y;
	else
		y=((r->p2.y - r->p1.y)/2)+r->p1.y;

	c->x=x;
	c->y=y;
}

void traslazione(Rettangolo *r, float movex, float movey){
	r->p1.x+=movex;
	r->p2.x+=movex;

	r->p1.y+=movey;
	r->p2.y+=movey;
}

int main(){	
	Punto pu, pd, centro;
	Rettangolo r;

	printf("Inserisci le coordiante del primo punto: ");
	scanf("%f %f", &pu.x, &pu.y);

	printf("Inserisci le coordiante del secondo punto: ");
	scanf("%f %f", &pd.x, &pd.y);

	crea(&r,&pu,&pd);

	printf("Area: %0.2f\n", area(&r));
	center(&r, &centro);
	printf("centro: %0.2f %0.2f\n", centro.x, centro.y);

	traslazione(&r, 1.0, 1.0);
	stampa(&r);
	center(&r, &centro);
	printf("centro: %0.2f %0.2f\n", centro.x, centro.y);
	return 0;
}