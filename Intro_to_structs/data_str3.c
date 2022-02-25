#include <stdio.h>
#include <stdlib.h>


// using pointers in data structures

typedef struct  {
  char *name;
  int people;
  int speed;
}Car;

void printCar(const Car *ourCar)
{
  printf("name = %s\npeople = %d\nspeed = %d\n", ourCar->name, ourCar->people, ourCar->speed);
  printf("------------\n");
}

// ourCar->name is the same as (*ourCar).name
// it is a good practice to use the keyword const if you are not going to change the structure

int main(void){
  Car ourCar1 = {"Ferari", 3, 100};
  Car ourCar2 = {"audi", 4, 150};
  printCar(&ourCar1);
  printCar(&ourCar2);
  return 0;
}
