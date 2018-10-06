#include<stdio.h>
typedef int Bool;
#define vero 1
#define falso 0

int main(){
int x, min=0, max=1000;
Bool trovato=vero;
char in;
while(trovato){
if(min!=max-1){
	printf("Il numero è: %d?", (min+max)/2);
	scanf(" %c", &in);
	
	if(in=='=')
		break;
	else if(in=='<')
		max=(min+max)/2;
	else if(in=='>')
		min=(min+max)/2;
	else
		printf("Carattere non valido\n");
}
else{
	printf("Non mentire\n");
	break;
}
}

return 0;
}
