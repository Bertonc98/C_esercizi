#include<stdio.h>
#include<stdlib.h>

struct element {
	int info; /*valore dell’elemento*/
	struct element *next;/*indirizzo del prossimo elemento*/
};

typedef struct element element;

element *insert(int n, element *h);
void printList(element *h);
int isMember(int n, element *h);
element *delete(int n, element *h);
void destroy(element *h);
void printInv(element *h, int n);

int main(){
	element *head=NULL;
	char c;
	int n, len=0;

	while((c=getchar())!='f'){
		switch(c){
			case '+':
				scanf(" %d", &n);
				if(isMember(n,head)==0){
					head=insert(n, head);
					len++;
				}
				else
					printf("Elemento già presente\n");
				break;
			case'p':
				printList(head);
				break;
			case'?':
				scanf(" %d", &n);
				printf("Result: %d\n",isMember(n, head));
				break;
			case'-':
				scanf(" %d", &n);
				if(n>=len || n<0)
					printf("Posizione non esistente\n");
				else{
					head=delete(n, head);
					len--;
				}
				break;
			case'c':
				printf("#Elementi: %d\n",len);
				break;
			case'd':
				destroy(head);
				len=0;
				head=NULL;
				break;
			case'o':
				if(len>0)
					printInv(head, len);
				else
					printf("Lista vuota");
				break;
		}
	}

	return 0;
}

element *insert(int n, element *h){
	element *new_head=calloc(1,sizeof(element));
	new_head->info=n;
	if(h==NULL){
		new_head->next=NULL;
		new_head->next=h;
		printf("Elemento inserito!\n");
	}
	else{
		new_head->next=h;
		printf("Elemento inserito!\n");
	}

	return new_head;
}

void printList(element *h){
	element *temp=h;
	int i=1;
	if(h==NULL){
		printf("Lista vuota\n");
	}
	else{
		while(temp->next!=NULL){
			printf("%d-->%d\n",i++, temp->info);
			temp=temp->next;
		}
		printf("%d-->%d\n",i++, temp->info);
	}
}

int isMember(int n, element *h){
	element *temp=h;
	if(h==NULL){
		return 0;
	}
	else{
		while(temp->next!=NULL){
			if(temp->info==n)
				return 1;
			temp=temp->next;
		}
		if(temp->info==n)
				return 1;

	}

	return 0;
}

element *delete(int n, element *h){
	element *pos=h, *prec=NULL;
	if(n==0){
		free(h);
		return pos->next;
	}
	else{
		n--;
		prec=pos;
		pos=pos->next;
			while(pos->next!=NULL && n>0){
				prec=pos;
				pos=pos->next;
				n--;
			}
		
		prec->next=pos->next;
	    free(pos);
		return h;
	}
}

void destroy(element *h){
	element *temp_head=h;
	while(temp_head->next!=NULL)
		temp_head=delete(0,temp_head);
}

void printInv(element *h, int n){
	if(n>1){
		printInv(h->next, n-1);
		printf("%d---%d\n",n,h->info);
	}
	else
		printf("%d---%d\n",n,h->info);
}