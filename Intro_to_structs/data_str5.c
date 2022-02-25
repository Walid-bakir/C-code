#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Linked lists and data structures

typedef struct S_Racingcars {

  char name[8];
  int speed;
  struct S_Racingcars *next;

} RacingCars;


void PrintList(RacingCars *start){
  RacingCars *currentCar  = start;
  int count = 0;

  while (currentCar !=NULL){
    count++;
    printf("Car : %d || name : %s || speed : %d\n",
           count,
           currentCar->name,
           currentCar->speed);
    currentCar = currentCar->next;
  }
  printf("total of cars: %d\n", count);
}

int main()
{
  RacingCars Ferrari = {"Ferrari", 200, NULL};
  RacingCars RedBull = {"RedBull", 200, NULL};
  RacingCars Audi = {"Audi", 200, NULL};
  RacingCars Dacia = {"Dacia", 200, NULL};

  Ferrari.next = &RedBull;
  RedBull.next = &Audi;
  Audi.next = &Dacia;

  PrintList(&Ferrari);
}
