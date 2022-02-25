#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Pointers are variables that store adresses of other variables
*/
int main()
{
  int a; // a is allocated at an adress in the memory
  int *p; // p is a pointer that can stor an adress of an integer
  p = &a; // p now points to the adress of a
  a = 5;
  char c = 'x';
  char *q = &c;
  uint32_t b = 23;
  uint32_t *r = &b;
  printf("%p\n", r);
  printf("%p\n", r + 1);
  printf("%p\n", q);
  printf("%p\n", q + 1);
  printf("%p\n", p); // this will print the adress of a, %p for pointers
  printf("%p\n", &a); // the same here
  printf("%p\n", p + 1); // = address of a + 4
  printf("%p\n", &p); // this will print the adress in wich p is located.
  printf("%d\n", *p); // this will print the value 5 (derefrencing)
  /*
  0x7ffcb7f2242c
  0x7ffcb7f2242c
  0x7ffcb7f22430
  5
  */
  *p = 8; // p --> address , *p --> value at address
  printf("%d\n", a); // --> 8
  a = a + 7;
  printf("%d", a);
  /*
int is allocated 4 bytes of memory
char is alocated one.
  */

}
