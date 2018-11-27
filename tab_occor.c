#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define stop "STOP"

struct occorrenza{
	//La struttura occorrenza conterrà come chiave la parola e un campo per il conteggio
	char *word;
	int n;
};
//ho il tipo Occorrenza che è un puntatore ad una struttura occorrenza
typedef struct occorrenza *Occorrenza;

struct bist_node {
	/*La struttura bist_node conterrà un campo all'occorrenza(chiave e numero)
	Inoltre due puntatori ad altri nodi che serviranno a creare l'alber
	il nodo l sarà semrpe minore di occorrenza e r maggiore*/
	Occorrenza occorrenza;
	struct bist_node *l, *r;
};
//nuovo tipo Bist_node puntatore a una struttura nodo
typedef struct bist_node *Bist_node;


char *read_word();
Occorrenza occ_new(char *word);
Bist_node bist_new(Occorrenza occorrenza);
Bist_node bist_insert(Bist_node word, Bist_node root);
void bist_print_alpha(Bist_node p);
void bist_print_inverso(Bist_node p);
Occorrenza ricerca(Bist_node, char *word);

//**--MAIN--**
int main(){
	char *x;
	Bist_node b=NULL, root=NULL;
	Occorrenza o=NULL;
	printf("Inserire le parole per comporre l'albero, eventuale punteggiatura non verrà considerata:\n");
	do{
		x=read_word();
		if(strcmp(x,stop)){
			//istanzio l'occorrenza
			o=occ_new(x);
			//istanzio il nodo con la nuova occorrenza
			b=bist_new(o);
			//lo inserisco nel posto giusto/aumento il conteggio se il valore è già presente
			root=bist_insert(b, root);
		}		
	}while(strcmp(x,stop));

	printf("OCCORRENZE DELLE PAROLE NEL TESTO IN ORDINE ALFABETICO\n");
	printf("******************************************************\n");
	bist_print_alpha(root);
	printf("OCCORRENZE DELLE PAROLE NEL TESTO IN ORDINE INVERSO\n");
	printf("***************************************************\n");
	bist_print_inverso(root);

	Occorrenza found=NULL;
	printf("Inserire le parole da cercare nel testo\n");
	do{
		x=read_word();
		if(strcmp(x,stop)){
			found=ricerca(root, x);	

			if(found!=NULL){
				printf("%s---%d\n",found->word,found->n);
			}
		}		
	}while(strcmp(x,stop));

	return 0;
}

Occorrenza occ_new(char *word){
	Occorrenza temp = malloc(sizeof(Occorrenza));
	if(temp==NULL){
		printf("Memoria esaurita\n");
		exit(0);
	}		
	temp->word=word;
	temp->n=1;
	return temp;
}

Bist_node bist_new(Occorrenza occorrenza){
	Bist_node temp = malloc(sizeof(Bist_node));

	if(temp==NULL){
		printf("Memoria esaurita\n");
		exit(0);
	}
	temp->occorrenza=occorrenza;
	temp->l=NULL;
	temp->r=NULL;
	return temp;
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
		else if(isalpha(c)){
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

Bist_node bist_insert(Bist_node new, Bist_node root){

	if(root==NULL){
		//Se è nulla creo un nodo vuoto e gli assegno occorrenza come valore
		root=bist_new(new->occorrenza);
	}
	else{
		if(strcmp(new->occorrenza->word, root->occorrenza->word)==0){
			printf("aumento\n");
			root->occorrenza->n++;
		}
		else if(strcmp(new->occorrenza->word, root->occorrenza->word)<0){
			if(root->l!=NULL){
				bist_insert(new, root->l);
			}
			else{
				root->l=new;
			}
		}
		else if(strcmp(new->occorrenza->word, root->occorrenza->word)>0){
			if(root->r!=NULL)
				bist_insert(new, root->r);
			else
				root->r=new;
		}
	}

	return root;
}

void bist_print_alpha(Bist_node b){
	if(b==NULL){
		printf("\n");
	}
	else if(b->l==NULL && b->r==NULL){
		printf("%s--%d\n", b->occorrenza->word, b->occorrenza->n);
	}
	else{

		bist_print_alpha(b->l);
		
		printf("%s--%d\n", b->occorrenza->word, b->occorrenza->n);

		bist_print_alpha(b->r);
	}
}

void bist_print_inverso(Bist_node b){
	if(b==NULL){
		printf("\n");
	}
	else if(b->l==NULL && b->r==NULL){
		printf("%s--%d\n", b->occorrenza->word, b->occorrenza->n);
	}
	else{
		
		bist_print_alpha(b->r);
		
		printf("%s--%d\n", b->occorrenza->word, b->occorrenza->n);

		
		bist_print_alpha(b->l);
	}
}

Occorrenza ricerca(Bist_node root, char *word){
	if(root==NULL){
		return NULL;
	}
	else if(root->l==NULL && root->r==NULL){
		return NULL;
	}
	else if(strcmp(root->occorrenza->word,word)==0){
			return root->occorrenza;
	}
	else{
		if(root->r!=NULL)
			return ricerca(root->r, word);
		if(root->l!=NULL)
			return ricerca(root->l, word);

	}
}