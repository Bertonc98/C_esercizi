#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 100
 
char cifra( char c, int k );
 
int main( int argc, char *argv[] ) {
 
  int k, i = 0;
  char op = *(argv[1]);
  char testo[N];
  
 
 
  while ( ( testo[i] = getchar() ) != '\n' ) {
    i++;
  }
  char *modificato=malloc((i+1)*sizeof(char));
 
  scanf( "%d", &k );
  if ( op == 'D' )
    k = k * -1;
 
 
  i = 0;
  while ( testo[i]  != '\0' ) {
    modificato[i] = cifra( testo[i], k );
    i++;
  }
 
 
  printf ( "Testo inserito: %s\n", testo );
  if ( op == 'C')
    printf ( "Testo cifrato:" );
  else
    printf ( "Testo decifrato:");
  printf ( " %s\n", modificato );
 
  return 0;
 
}
 
 
char cifra( char c, int k) {
  int a,z;
  if(islower(c)){
    a='a';
    z='z';
  }
  else{
    a='A';
    z='Z';
  }

 
  if ( isalpha( c ) ) {
   
    c=((c+k)-a)%26;
   
    if(c<0)
      c=(z-a+1)+c;
    return c+a; 
  }
 
  else return c;
}