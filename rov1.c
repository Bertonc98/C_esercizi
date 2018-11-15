#include<stdio.h>
#include<stdlib.h>



int main(){
	int x, *p, size=2, index=0, *temp;
	p=malloc(size*sizeof(int));
	do{
		scanf(" %d",&x);
		*(p+index)=x;
		if(x!=0){
		index++;
			if(index>=size){
				size=size*2;
				temp=p;
				//printf("size=%d\n",size);
				p=malloc(size*sizeof(int));
				if(p==NULL)
					exit(0);
				for(int i=0; i<size;i++){
					if(i<index)
					*(p+i)=*(temp+i);
					else
					*(p+i)=0;	
				}
			free(temp);
			}
		}

	}while(x!=0);

	for(int i=index-1; i>=0; i--)
		printf("%d ",*(p+i));
	printf("\n");
	free(p);
	return 0;
