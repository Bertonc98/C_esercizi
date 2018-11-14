#include<stdio.h>
#include<stdlib.h>

char *read_line();

char *read_word();

int main(){
	char *phrase, index=0;

	phrase=read_word();

	while(*(phrase+index)!='\0'){
		putchar(*(phrase+index));
		index++;
	}
	printf("\n");
	return 0;
}

char *read_line(){
	char *p, c, index=0, size=2, *temp;
	p=malloc(size*sizeof(char));
	while((c=getchar())!='\n'){
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

