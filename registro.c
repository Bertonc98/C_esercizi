#include<stdio.h>
#include<stdlib.h>

void *new_book(int n, char **book);
void book_in(int k,char *name, char **book);
char *read_word();

int main(){
	char c, buffer, **book=NULL, *name;
	int n;
	while((c=getchar())!='f'){
		switch(c){
			case 'b':
				scanf(" %d",&n);
				new_book(n,book);
				break;
			case '+':
				scanf(" %d ",&n);
				name=read_word();
				book_in(n, name, book);
				break;
		}
	}
	return 0;
}

void *new_book(int n, char **book){
	free(book);
	book=malloc(n*sizeof(char *));
	if(book==NULL)
		printf("Memoria piena, impossibile creare il registro\n");
	else{
		for(int i=0; i<n; i++)
			*(book+i)=NULL;

		printf("Nuovo registro istanziato\n");
	}
}

void book_in(int k,char *name, char **book){
	
	if(*(book+k)==NULL){
		printf("Inserito\n");
		*(book+k)=name;
	}
	else
		printf("Posizione già prenotata\n");
}

char *read_word(){
	char *p, c, index=0, size=2, *temp;
	p=malloc(size*sizeof(char));
	while((c=getchar())!='\n'){
		if(index==0 && !isalpha(c)){
			p=NULL;
			return p;
		}
		else if(c==' '){
			break;
		}
		else{
		if(index<size)
			*(p+index++)=c;
		else{
			size*=2;
			temp=p;
			p=malloc(size);
			if(p==NULL)
				exit(0);
			else{
				for(int i=0; i<index;i++)
					*(p+i)=*(temp+i);
				free(temp);
			}
			*(p+index++)=c;
		}
	}
	}

	if(index<size-1){
		*(p+index+1)='\0';
	}
	else{
		size*=2;
			temp=p;
			p=malloc(size);
			if(p==NULL)
				exit(0);
			else{
				for(int i=0; i<index;i++)
					*(p+i)=*(temp+i);
				free(temp);
			}
		*(p+index+1)='\0';
	}
	return p;
}