#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Linked lists and data structures

typedef struct S_Racingcars {

  char name[12];
  int speed;
  struct S_Racingcars *next;

} RacingCars;


void PrintList(RacingCars *start){
  RacingCars *currentCar  = start;
  int count = 0;

  while (currentCar != NULL){
    count++;
    printf("Car : %d || name : %s || speed : %d\n",
           count,
           currentCar->name,
           currentCar->speed);
    currentCar = currentCar->next;
  }
  printf("total of cars: %d\n", count);
}

RacingCars *Addcar(RacingCars *previous){
  printf("Enter the name and the speed of the car: ");
  char input[16];
  fgets(input,15,stdin);

  RacingCars *newcar = malloc(sizeof(RacingCars));
  sscanf(input, "%s %d", newcar->name, &newcar->speed);
  printf("Added: name = %s, speed = %d\n\n", newcar->name, newcar->speed);

  newcar->next = NULL;

  if (previous != NULL){
    previous->next = newcar;
  }

  return newcar;
}

void CleanUp(RacingCars *start){
  RacingCars *freeMe = start;
  RacingCars *HoldMe = NULL;

  while (freeMe != NULL){
    HoldMe = freeMe->next;
    printf("Freeing %s \n", freeMe->name);
    free(freeMe);
    freeMe = HoldMe;
  }

}

int main() {

	char command[16];
	char input[16];

	RacingCars *start = NULL;
	RacingCars *newest = NULL;

	while( fgets( input, 15, stdin) ) {

		sscanf(input,"%s",command);

		if ( strncmp(command, "quit", 4) == 0) {
			printf("\n\nBreaking...\n");
			break;
		} else if ( strncmp(command, "print", 5) == 0) {
			PrintList(start);
		} else if ( strncmp(command, "add", 3) == 0) {
			if(start == NULL) {
				start = Addcar(NULL);
				newest = start;
			} else {
				newest = Addcar(newest);
			}
		}
	}

	CleanUp(start);

	return 0;

}
