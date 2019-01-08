#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef char *String;

typedef struct{
  int size;
  int count;
  String *content;
} *Elenco;


int main( void ) {
  Elenco b = NULL;
  int size = 4, i = 0;
  char *name=NULL;

  b = malloc( sizeof(Elenco) );
  b -> size = 4;
  b -> count = 0;
  b -> content = calloc( size, sizeof(char *) );

  while( name==NULL || (strcmp( name, "FINE" ) != 0) ) {
    name=malloc(sizeof(char)*(N+1));
    scanf( "%s", name );

    if ( b -> count == b -> size ) {
      size*=2;
      b -> size *= 2;
      b-> content = realloc (b-> content, b->size * sizeof(char *));
    }
    b -> content[i] = name;
    i++;
    b->count++;
  }
  printf("%d,%dElenco:\n", b->size, size);
  for ( int k = 0; k < b->count-1; k++ )
      printf( "-%s\n", b -> content[k] );

  return 0;
}