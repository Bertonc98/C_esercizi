#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct element {  // definizione di un elemento della lista
  char ch;
  struct element *next;    // prossimo elemento
};

typedef struct queue {
  struct element *head;
  struct element *tail;
  int count;
} *Queue;


Queue init();
void enqueue(char ch, Queue q);
char dequeue(Queue q); // assume che la coda non sia vuota

// inserite qui la funzione extract e eventuali altre funzioni aggiuntive
void extract(Queue q);


int main(int argc, char **argv){
  Queue q=init(), v=init(), c=init(), s=init();
  char scelta=*(argv[1]), buffer;
  int counter=0;

  // lettura delle lettere e inserimento nella coda q
  while((buffer=getchar())!='\n'){
    enqueue(buffer, q);
  }  
  

  // estrazione dalla coda e distribuzione delle lettere nelle code v,c,s
  for(; q->count>0;){
    buffer=dequeue(q);
    if(buffer=='a' || buffer=='e' || buffer=='i' || buffer=='o' || buffer=='u' ||
       buffer=='A' || buffer=='E' || buffer=='I' || buffer=='O' || buffer=='U'){
      enqueue(buffer, v);
    }
    else if(buffer=='j' || buffer=='k' || buffer=='w' || buffer=='x' || buffer=='y' ||
            buffer=='J' || buffer=='K' || buffer=='W' || buffer=='X' || buffer=='Y'){
      enqueue(buffer, s);
    }
    else
      enqueue(buffer, c);
    counter++;
  }
  

  // stampa della coda opportuna
  switch( scelta ) {
    case 'V': extract(v);
      break;
    case 'C': extract(c);
      break;
    case 'S': extract(s);
  }
  printf("\n");


  return 0;
}

void extract(Queue q){
  for(; q->count>0; ){
    printf("%c", dequeue(q));
  }
}



Queue init(){
  Queue q = malloc(sizeof(struct queue));
  q->head = NULL;
  q->count = 0;
  return q;
}

void enqueue(char ch, Queue q){
  struct element *new = malloc(sizeof(struct element));
  new->ch = ch;
  new->next = NULL;
  if (q->head == NULL)
    q->head = new; // la coda era vuota
  else {
    q->tail->next = new; // attacco in coda
  }
  q->tail = new;
  q->count++;
}

// assumo che la coda non sia vuota
char dequeue(Queue q){
  char ch;
  struct element *testa = q->head;
  ch = testa->ch;
  q->head = q->head->next;
  free(testa);
  q->count--;
  return ch;
}
