#include <stdio.h>

int main(){
float farenotte;

printf("Inserire il valore in farenotte: ");
scanf(" %f", &farenotte);

float celsius=(farenotte-32)/1.8;

printf("Celsius: %f \n", celsius);

return 0;
}
