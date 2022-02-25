#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Pointers and strings

void print(char* C){
  // *C because we should work with adresses not copies
  int i = 0;
  while (C[i] != '\0'){
    printf("%c" , C[i]);
    i++;
  }
  printf("\n");
}

void print2(char* C){
  // the same as print
  while (*C != '\0'){
    printf("%c" , *C);
    C++;
  }
  printf("\n");
}

int main(){
  char C[5];
  C[0] = 'J';
  C[1] = 'O';
  C[2] = 'H';
  C[3] = 'N';
  C[4] = '\0';
  printf("C = %s\n", C);
  printf("length of C is %lu\n", strlen(C));
  /*
  C = JOHN
  size of C is 4%
  */

  // Pointers and strings
  char C1[] = "Hello";
  char *C2;
  C2 = C1; // we can do this, C2 points to the first element of c1
  printf("%c\n", *C2); // the output is H
  printf("%c\n", C2[2]); // C2[2] = l
  // C2[i] is *(C2 + i)
  char chaine[] = "Hi, walid";
  print(chaine);
  print2(chaine);
}
