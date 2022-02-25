#include <stdio.h>
#include <stdlib.h>


// we can define our structure as a type:

typedef struct  {
  // we dont have to name it (car_str is gone)
  char *name;
  int people;
  int speed;
}Car;// the keyword car replaces struct car

void printCar(Car ourCar)
{
  printf("name = %s\npeople = %d\nspeed = %d\n", ourCar.name, ourCar.people, ourCar.speed);
  printf("------------\n");
}

int main(void){
  Car ourCar1 = {"Ferari", 3, 100};
  Car ourCar2 = {"audi", 4, 150};
  printCar(ourCar1);
  printCar(ourCar2);
  return 0;
}
