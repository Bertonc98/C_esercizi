#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
 
#define HASHSIZE 10
 
// PRODOTTI
typedef struct prodotto {
  char *key;
  char *descrizione;
  int prezzo;
} *Item;
 
 
Item newItem( char *key, char *descr, int pr) {
  Item p=malloc(sizeof(struct prodotto));
  p->key=key;
  p->descrizione=descr;
  p->prezzo=pr;
  return p;
}
 
void printItem( Item p ){
 printf("%s %s %d€",p->key, p->descrizione, p->prezzo);
}
 
 
 
// ELEMENTO DI LISTA
struct element {  // definizione di un elemento della lista
  Item item;
  struct element *next;    // prossimo elemento
};
 
// LISTA DI COLLISIONE
typedef struct element *List;
Item list_find( List c, char *w );
List list_insert( List c, Item p ); // crea nuovo elemento, lo inserisce in testa alla catena e restituisce l'indirizzo della nuova testa
void list_print( List h );
 
// DIZIONARIO IMPLEMENTATO CON HASHTABLE
typedef struct ht {
  List array[HASHSIZE];
  int count; // parole inserite
} *Dict;
 
Dict dict_init ();
void dict_print( Dict h );
Item dict_lookup ( Dict t, char *key ); // Restituisce l'Item con chiave key, oppure NULL se key non è nel dizionario
void dict_add( Dict t, Item p ); // aggiunge l'item p nel dizionario
unsigned long hash ( char *s ); // funzione di hash
 
 
/* MAIN
**************/
 
int main(){
  char comando[3] = "";
  char *key=malloc(sizeof(char)*10), *descrizione=malloc(sizeof(char)*10);
  int prezzo;
  Dict t=dict_init();
  Item p;
 
 
  while( 1 ) {
    scanf( " %s", comando );
    //printf( "LETTO COMANDO <%s>\n", comando );
    if ( comando[0] == 'f' ) // uscita
      break;
 
 
    if ( isdigit( comando[0] ) ) { // calcola somma dei prezzi dei prodotti che seguono
      
      printf( "Il totale è ... per ... prodotti\n");
    }
 
    else
      switch( comando[0] ) {
 
      case '+': // aggiungo prodotto
        scanf( "%s %s %d", key, descrizione, &prezzo);
        p=newItem(key, descrizione, prezzo);
        dict_add(t, p);
        break;
 
 
      case '!': // cerca il prezzo di un prodotto
        scanf( " %s", key);
        p=dict_lookup(t, key);
        if(p)
          printf("Prezzo di %s: %d€",p->key, p->prezzo);
        else
          printf("Non esiste");
        break;
 
      case 'p':
        dict_print(t);
        break;
      }
  }
 
  return 0;
}
 
 
 
 
 
 
 
/* FUNZIONI DI GESTIONE DELLA CHAIN (lista)
*******************************************/
 
 
// Inserisce in testa e restituisce la nuova testa.
List list_insert( List h, Item p ){
  struct element *new = malloc( sizeof( struct element ) );
  new -> item = p;
  new -> next = h;
  return new;
}
 
 
/* Cerca un item con chiave key nella list c. Se lo trova ne restituisce l'indirizzo, altrimenti restituisce NULL. */
Item list_find( List c, char *key ){
  struct element *p;
  for( p = c  ; p!= NULL; p = p->next ) {
    if( strcmp( p -> item -> key, key ) == 0 ) {
      return p -> item;
    }
  }
  return NULL;
}
 
 
/* Stampa gli elementi della Lista di trabocco */
void list_print( List h ) {
  /* h e' usato  per attraversare la  lista */
  for( ; h!= NULL; h=h->next)
    printItem( h -> item );
  putchar('\n');
}
 
 
 
 
/* FUNZIONI DI GESTIONE DELLA HASHTABLE
*******************************************/
 
 
// Crea una hastable di con HASHSIZE buckets
Dict dict_init () {
    Dict t = malloc ( sizeof ( struct ht ) );
    t -> count = 0;
 
    for ( int i = 0; i < HASHSIZE; i++ )
        t -> array[i] = NULL;
    return t;
}
 
// funzione di hash
unsigned long hash( char *str )
{
    unsigned long hash = 5381;
    int c;
 
    while ( (c = *str++) )
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
 
    return hash % HASHSIZE;
}
 
// cerca l'item con chiave key
Item dict_lookup ( Dict t, char *key ) {
    return list_find( t -> array[hash(key)], key );
}
 
 
// inserisce l'item nel dizionario
 void dict_add( Dict t, Item p ){
    int i = hash( p -> key);
    t -> array[i] = list_insert ( t -> array[i], p );
    t -> count++;
//    printArray( t -> array[i] -> ln_arr, t -> array[i] -> count );
}
 
 
 
// inserisce l'item nel dizionario
 void dict_print( Dict t ){
  for ( int i =0; i < HASHSIZE; i++ ) {
    printf( "[%d]:\t", i );
    list_print( t -> array[i]) ;
  }
}