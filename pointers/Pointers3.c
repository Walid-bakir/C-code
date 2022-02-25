#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// call by refrence

void increment(int *a){
   // we cant use a , because when we modify a, we only modify a copy
   // we need to increment the value stored at adress &a
  *a=*a+1;
}

int main()
{
  int a = 10;
  increment(&a);
  printf("%d\n", a);
  return 0;
}
