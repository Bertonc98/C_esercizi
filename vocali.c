#include<stdio.h>
#include<string.h>

char isVocal(char a, char b){
	if(a=='a' || a=='e'|| a=='i'|| a=='o'|| a=='u')
		return b;
	else
		return a;
}

int main(){
	char frase[100]={0}, lettera, ch;
	int i=0;

	printf("Inserire la lettera seguida dallo spazio e la frase: ");
	while((ch=getchar())!='.'){
		if(i==0)
			lettera=ch;
		else if(i>=2)
			frase[i]=ch;
		i++;
	}
	i=i-1;
	for(int j=0; j<i; j++){
		printf("%c", isVocal(frase[j], lettera));
	}
	
	printf("\n");

	return 0;
}