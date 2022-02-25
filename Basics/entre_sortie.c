#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>  // in-out, fonctions des entrées-sorties

void get_natural(void){
  printf("Entrez un entier naturel : ");
  uint32_t entier = 0;
  char chiffre_lu;
  char lo = getc(stdin);
  while (lo != '\n'){
    chiffre_lu = lo - '0';
    entier = entier*10 + chiffre_lu;
    printf("%d\n", entier);
    lo = getc(stdin);
  }
}


int main()
{
  get_natural();
  return EXIT_SUCCESS;
}

/*
Entrez un entier naturel : 123
1
12
123
*/
