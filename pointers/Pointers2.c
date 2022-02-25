#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
  int a = 1025;
  int *p;
  p = &a;
  printf("size of integer is %lu\n", sizeof(int));
  printf("address = %p, value = %d\n", p, *p);
  printf("address = %p, value = %d\n", p + 1, *(p + 1));
  /*
  size of integer is 4
  adress = 0x7ffe1b729fcc, value = 1025
  */
  char *p0;
  p0 = (char*)p;// typecasting, we cant just do p0 = p, because p points
               //  to an int and p0 points to cha
  printf("size of integer is %lu\n", sizeof(char));
  printf("address = %p, value = %d\n", p0, *p0);
  printf("address = %p, value = %d\n", p0 + 1, *(p0 + 1));
  // a is written 00000000 00000000 00000100 00000001
  /*
  size of integer is 4
  adress = 0x7ffd8ea80434, value = 1025
  adress = 0x7ffd8ea80438, value = -1901591500 //this is garbage because p + 1 is 4 bytes grater than p,
                                              // and there is nothing stored in those bytes
  size of integer is 1
  adress = 0x7ffd8ea80434, value = 1 // 1 = 00000001
  adress = 0x7ffd8ea80435, value = 4 // 4 = 00000100 , it skipped one byte
  */
  void *p1; // generic pointer with no specific type
  p1 = p; // this is allowed, but we cant print the value of *p1, only the adresse
  printf("address = %p" , p1);

  // Pointer to Pointer
  int x = 5;
  int *q = &x;
  int **r = &q; // r points to the pointer q, hence **
  int ***s = &r; // s points to the ponter of a pointer, ergo ***
  printf("%d\n", *q); // = x
  printf("%p\n", *r); // = address de x
  printf("%d\n", *(*r)); // = x


}
