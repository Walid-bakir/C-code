#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Pointers and arrays

int main(void)
{
  int A[5];
  int i;
  for (i = 0; i < 5; i++){
    A[i] = i;
  }
  // an array takes a place in the memory in a way that its element
 // have consecutive addresses in the memory, so when we do:
 int *p = &A[0];
 printf("%d\n", *(p + 1)); // we will get the value in the
                          //next address wich is here A[1] = 1
// we can print the address of an element in the array at index i by:
printf("the address of A[3] is %p\n", &A[3]);
// Or
printf("the address of A[3] is %p\n", (A + 3));
// Same with value
printf("the value of A[3] is %d\n", A[3]);
// Or
printf("the value of A[3] is %d\n", *(A + 3));
/*
the address of A[3] is 0x7fffa902a1cc
the address of A[3] is 0x7fffa902a1cc
the value of A[3] is 3
the value of A[3] is 3
*/
printf("%p and %d\n", &A, *A); // 0x7ffe49ba1220 and 0, the first element in A

}
