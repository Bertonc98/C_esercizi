#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct occorrenza{
	char*word;
	int n;	
};

typedef struct occorrenza *Oc;

struct node{
	Oc oc;
	struct node *l, *r;
};

typedef struct node *Node;

Node new(char *word);
Node search(Node r, char *word);
Node search_p(Node r, char *word);
void insert(Node r, char *word, Node *ro);
void alfa(Node r);
void reverse_alfa(Node r);
void *read_text(Node *root, int mode);
char *r_w();

int main()
{
	Node root=NULL;
	char *w="ciao";
	read_text(&root, 0);
	printf("************************\n");
	alfa(root);
	printf("************************\n");
	reverse_alfa(root);
	printf("************************\n");
	read_text(&root, 1);

	return 0;
}

char *r_w(){
	int size=2, count=0;
	char *w=malloc(sizeof(char)*size), buffer;
	

	while((buffer=getchar())!=' ' && buffer!='\n'){
		if(count==size){
			size*=2;
			w=realloc(w, size);
			w[count++]=buffer;
		}
		else
			w[count++]=buffer;
	}

	w=realloc(w, count+1);
	w[count+1]='\0';

	return w;
}

void *read_text(Node *root, int mode){
	char *word, *stop="STOP";
	Node find=NULL;
	while(1){
		word=r_w();
		if(strcmp(stop, word)==0)
			break;
		if(mode==0)
			insert(*root, word, root);
		else{
			find=search(*root, word);
			if(find)
				printf("%s %d\n", find->oc->word, find->oc->n);
			else
				printf("Non esiste\n");
		}

	}

}

void alfa(Node r){
	if(r){
		alfa(r->l);
		printf("%s, %d\n", r->oc->word, r->oc->n);
		alfa(r->r);
	}
}

void reverse_alfa(Node r){
	if(r){
		alfa(r->r);
		printf("%s, %d\n", r->oc->word, r->oc->n);
		alfa(r->l);
	}
}

void insert(Node r, char *word, Node *ro){
	if(r==NULL){
		*ro=new(word);
	}
	else{
		Node father=search_p(r, word);

		if(strcmp(father->oc->word, word)==0)
			father->oc->n++;
		else if(strcmp(father->oc->word, word)<0)
			father->r=new(word);
		else
			father->l=new(word);
	}
}

Node search_p(Node r, char *word){
	Node temp =r, f=NULL;
	while(temp!=NULL && strcmp(temp->oc->word, word)!=0){
		if(strcmp(temp->oc->word, word)<0){
			f=temp;
			temp=temp->r;
		}
		else{
			f=temp;
			temp=temp->l;
		}
	}
	if(!f)
		return temp;

	return f;
		
}

Node search(Node r, char *word){
	while(r && strcmp(r->oc->word, word)!=0){
		if(strcmp(r->oc->word, word)<0)
			r=r->r;
		else
			r=r->l;
	}

	return r;
}

Node new(char *word){
	Node n=malloc(sizeof(struct node));
	n->oc=malloc(sizeof(struct occorrenza));
	n->l=NULL;
	n->r=NULL;
	n->oc->word=word;
	n->oc->n=1;
	return n;
}


