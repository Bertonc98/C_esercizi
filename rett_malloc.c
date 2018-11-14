#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float x, y;
} punto;

typedef struct{
	punto *p1, *p2;
} rett;




int main(){	
	punto *p1,*p2;
	p1=calloc(2, sizeof(float));
	p1->x=1.0;
	p1->y=1.0;

	p2=calloc(2, sizeof(float));
	p2->x=2.0;
	p2->y=2.0;

	rett *r=calloc(1, sizeof(rett));
	r->p1=p1;
	r->p2=p2;
	printf("%f\n",r->p2->x);
	return 0;
}