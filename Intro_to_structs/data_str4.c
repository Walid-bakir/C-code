#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Linked lists and data structures

typedef struct {

  char name[8];
  int speed;

} RacingCars;

void PrintList(RacingCars CarArray[], int num){

  printf("the Car list:\n");
  int index = 0;
  for (index = 0; index < num;index++){
    printf("Car %d || name:%s || speed:%d\n",
           index+1,
           CarArray[index].name,
           CarArray[index].speed);
  }
  printf("total of cars: %d\n", num);
}


void PrintList2(RacingCars CarArray[], int num){
  // same as PrintList, with pointers
  printf("the Car list:\n");
  RacingCars *cars;
  int index = 0;
  for (index = 0; index < num;index++){
    cars = &CarArray[index];
    printf("Car %d || name:%s || speed:%d\n",
           index+1,
           cars->name,
           cars->speed);
  }
  printf("total of cars: %d\n", num);
}


int AddCar(RacingCars *car){
  printf("Enter the name and the speed of the car: ");
  char input[16];
  fgets(input,15,stdin);

  int ok = 0;

  int res = sscanf(input, "%s %d", car->name, &car->speed);

  if (res == 2){
    ok = 1;
    printf("Adding the car...\n");
    printf("Added: name = %s, speed = %d\n\n", car->name, car->speed);
  }else {
    printf("sorry, error in the input!\n");
  }
  return ok;
}


const int MaxCars = 4;

int main()
{
  RacingCars allcars[MaxCars];
  int numCars = 0;

  char command[16];
  char input[16];

  while (fgets(command, 15,stdin)){
    sscanf(input,"%s", command);
    if (strncmp(command, "quit",4) == 0){
      printf("Breaking...\n");
      break;
    }else if (strncmp(command,"print",5) == 0){
      PrintList(allcars,numCars);
    }else if (strncmp(command, "add", 3) == 0){
      if (numCars < 4){
        AddCar(&allcars[numCars]);
        numCars += 1;
      }else{
        printf("Sorry, the list is full\n");
      }

    }
  }
  return 0;
}
