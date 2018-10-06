#include<stdio.h>
#include<limits.h>

int main(){
int x;
long y;
printf("%d...%d  %ld\n", INT_MIN, INT_MAX, sizeof(x));
printf("%ld...%ld  %ld\n", LONG_MIN, LONG_MAX, sizeof(y));
return 0;
}
