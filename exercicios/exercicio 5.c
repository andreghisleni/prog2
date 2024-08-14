/**
  
*/

#include <stdio.h>
#include <stdlib.h>

main(){

  char c[81], c2[81];

  scanf("%80[^\n]", c);

  fflush(stdin);

  scanf("%80[^\n]", c2);

  printf("%s\n", c);
  
}