#include <stdio.h>
#include <stdlib.h>

struct s_car {
  char *name;
  int people;
  int speed;
};

void printCar(struct s_car ourCar)
{
  printf("name = %s\npeople = %d\nspeed = %d\n", ourCar.name, ourCar.people, ourCar.speed);
  printf("------------\n");
}

int main(void){
  struct s_car ourCar1 = {"Ferari", 3, 100};
  struct s_car ourCar2 = {"audi", 4, 150};
  printCar(ourCar1);
  printCar(ourCar2);
  return 0;
}
