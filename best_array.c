/*
Raccolta di bestseller

Il New York Times pubblica ogni settimana, fin dal 1942, la lista dei libri più venduti nelle librerie americane, i cosiddetti bestseller. Dovete completare il programma in calce, affinché legga e memorizzi alcuni dettagli relativi ai libri più venduti e sappia compiere alcune ricerche su di essi.

Non importa adesso che cerchiate una soluzione efficiente per la ricerca: questo sarà richiesto nell esercizio successivo! Invece, memorizzate i dettagli relativi ai bestseller tramite un semplice array. Non potete fare assunzioni sul numero di bestseller da memorizzare, quindi il vettore va allocato dinamicamente: cominciate con un numero prefissato di posizioni, e ridimensionate opportunamente quando necessario.

Il programma deve leggere una sequenza di comandi, tra i seguenti:

    + bestseller: legge e memorizza i dettagli relativi a un bestseller;
    ? data: trova il libro che ha raggiunto la vetta della classifica nel giorno data e ne stampa i dati essenziali;
    f : termina il programma.

Nel comando + bestseller, un bestseller è descritto come una stringa formata dalla concatenazione di: titolo, autore, editore, data in cui ha raggiunto la vetta della classifica dei libri più venduti, genere (Fiction oppure Nonfiction). I vari attributi sono separati da un carattere di tabulazione \t. La data è rappresentata nel formato americano mese/giorno/anno.

Per la lettura dei dettagli relativi a un bestseller potete sfruttare la funzione read_tab, che legge da standard input una sequenza di caratteri fino a quando non trova il carattere di tabulazione, memorizza i caratteri letti in una stringa (allocando lo spazio necessario) e ne restituisce l indirizzo.

L output del comando ? data deve essere nel formatodata: titolo - autore.

Se lo ritenete utile, potete scrivere anche funzioni aggiuntive.
Esempio

Eseguendo

./soluzione

avendo nel flusso di ingresso le righe:

+ Bring On the Empty Horses	David Niven	Putnam	11/30/1975	Nonfiction
+ Breaking the Surface	Greg Louganis	Random House	3/19/1995	Nonfiction
? 3/19/1995
f

il programma emette sul flusso di uscita:

3/19/1995: Breaking the Surface - Greg Louganis

Esempio

Eseguendo

./soluzione

avendo nel flusso di ingresso le righe:

+ Breaking the Surface  Greg Louganis   Random House    3/19/1995       Nonfiction
+ Bring On the Empty Horses     David Niven     Putnam  11/30/1975      Nonfiction
+ 1st to Die	James Patterson	Little, Brown	3/25/2001	Fiction
+ 2nd Chance	James Patterson	Little, Brown	3/24/2002	Fiction
+ 3rd Degree	James Patterson	Little, Brown	3/21/2004	Fiction
+ 4th of July	James Patterson	Little, Brown	5/22/2005	Fiction
+ 61 Hours	Lee Child	Delacorte	6/6/2010	Fiction
+ A Breath of Snow and Ashes	Diana Gabaldon	Delacorte	10/16/2005	Fiction
+ A Common Life	Jan Karon	Viking	4/29/2001	Fiction
? 6/6/2010
f

il programma emette sul flusso di uscita:

6/6/2010: 61 Hours - Lee Child

Programma da completare */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FORMATO: title TAB author TAB publisher TAB mm/dd/yyyy TAB Fiction
typedef struct bestseller {
  char *titolo;
  char *autore;
  char *editore;
  int m;
  int d;
  int y;
  char *genere;
} *Bs;

typedef struct bestseller *Bestseller;

Bs read_bs(); // legge una riga con i dati di un bestseller
void print_bs( Bs b); // stampa i dettagli di un bestseller
int compare(int m, int d, int y, int mc, int dc, int yc);//COntrollo se una data è prima o dopo la seconda



int main(){
  char comando = '\0', buffer;
  short int d, m, y;
  int dimensione=10, i=0, trovato=0, ricerca=0;
  Bestseller *lista=calloc(dimensione, sizeof(Bestseller));

  while( (comando = getchar()) != 'f' ) {
    switch( comando ) {
    case '+': // seguito da riga con dettagli su un bestseller
        if(i==dimensione){
          lista=realloc(lista, sizeof(Bestseller)*dimensione*2);
          dimensione=dimensione*2;
        }
        lista[i]=read_bs();
        i++;
      break;

    case '?': // seguito da una data. stampa il libro bestseller in quella data
      scanf(" %hd/%hd/%hd", &m, &d, &y);
      ricerca=0;
      trovato=0;
      printf("Cerco\n");
        while(trovato==0 && ricerca<i){
          if(d==lista[ricerca]->d && m==lista[ricerca]->m && y==lista[ricerca]->y){
            trovato=1;
            print_bs(lista[ricerca]);
          }
          ricerca++;
        }
        buffer=getchar();
      break;

    case '-':
      break;
      }
      
    }

  return 0;
}

//ridà -1 se la prima è minore della seconda
//1 se maggiore
//0 se uguale
int compare(int m, int d, int y, int mc, int dc, int yc){
  if(y>yc)
    return 1;
  else if(y<yc)
    return -1;
  else{
    if(m>mc)
      return 1;
    else if(m<mc)
      return -1;
    else{
      if(d>dc)
        return 1;
      else if(d<dc)
        return -1;
      else
        return 0;
    }
  }
}






// legge da standard input fino a quando non trova un carattere di tabulazione (e ignorando gli spazi iniziali)
char *read_tab() {
  char *p, c;
  int size = 2;
  int n = 0;

  p = malloc( size );
  while ( isspace( c = getchar() ) );


  while ( c != EOF && c!='\n') {

    /* se ho terminato lo spazio, raddoppio l allocazione */
    if ( n >= size ) {
      size *=2;
      //printf( "\nnew size = %d\n", size );
      p = realloc( p, size * sizeof(char) );
    }

    /* memorizzo l n-esimo elemento */
    if ( c == '\t' ) { /* se leggo '\t', memorizzo '\0' e interrompo */
      p[n] = '\0';
      break;
    }

    p[n++] = c;
    c = getchar();
  }

  //printf( "%s\n", p );
  return p;
}

// legge una riga con i dati di un bestseller e la memorizza in una struttura di cui restituisce l'indirizzo
Bs read_bs(){
  Bestseller b = malloc(sizeof(struct bestseller));
  char c;
 
  b->titolo=read_tab();

  b->autore=read_tab();

  b->editore=read_tab();

  scanf(" %d/%d/%d", &b->m, &b->d, &b->y);

  b->genere=read_tab();
 
  return b;
}

// stampa i dettagli di un bestseller
void print_bs( Bs b)
{
  printf("%d/%d/%d: %s - %s\n", b->m, b->m, b->y, b->titolo, b->autore);
}

