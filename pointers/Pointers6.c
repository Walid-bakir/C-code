#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Dynamique memory


/*
malloc takes one argument ( size ), and initialize the allocated memory with
garbage. calloc takes two (number of elements and size), it initialize
everything with 0
*/

void test(){
  int n;
  printf("size of the array n = ");
  scanf("%d", &n);
  int *A = (int*)malloc(n*sizeof(int));
  for (int i = 0 ;i < n; i++){
    A[i] = i;
  }
  for (int i = 0 ;i < n; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}
int main()
{
  int a; // local variable, it goes on stack
  // if we want to store an integer on the heap, we should do:
  int *p;
  p = (int*)malloc(sizeof(int)); // malloc asks for how much zise you need reserved in the heap
                                 // here, we want 4 bytes, hence sizeof(int)
  printf("%p\n",p); // 0x56436d7de2a0
  *p = 4;
  printf("%d\n", *p); // 4
  free(p); // free the space allocated for p on the heap
  p = (int*)malloc(20*sizeof(int)); // to store an array of integers
  printf("[ ");
  int i;
  for ( i = 0; i < 19; i++){
    p[i] = i + 2;
    printf("%d, ", p[i]);
  }
  p[i] = i + 2;
  printf("%d", p[i]);
  printf("]\n");
  // [ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]
  test();
   // size of the array n = 10
  //  0 1 2 3 4 5 6 7 8 9

}
