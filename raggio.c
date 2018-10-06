#include<stdio.h>
#include<math.h>

int main(){
float r, area;
printf("Inserire il raggio ");
scanf(" %f", &r);

area=pow(r,2.0)*M_PI;

printf("%f", area);
return 0;
}
