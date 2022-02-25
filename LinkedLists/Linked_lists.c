#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Linked lists

/*
A linked list is a set of dynamically allocated nodes, arranged in such a way
that each node contains one value and one pointer. The pointer always points
to the next member of the list. If the pointer is NULL, then it is the
last node in the list.
*/

struct Student{
  int age;
};

struct Student *getNewStudent(int age){
  struct Student *NewStudent = NULL;
  NewStudent = (struct Student*)malloc(sizeof(struct Student));// we can do just malloc(sizeof(struct Student));
  NewStudent->age = age;
  printf("New Student is created at %p", NewStudent);
  return NewStudent;
}

void printStudent(struct Student *student, char *rank){
  if (student == NULL){
    printf("%s is NULL\n", rank);
  }else{
    printf("%s of age %d, created at address %p\n", rank, student -> age, student);
  }
}

int main()
{
  struct Student *first = NULL;
  struct Student *second = NULL;

  printStudent(first, "first");
  printStudent(second, "second");

  first = getNewStudent(20);
  second = getNewStudent(21);
  struct Student *third = getNewStudent(22);
  printStudent(first,"first");
  printStudent(second, "second");
  printStudent(third, "third");

  free(first);
  free(second);
  free(third);

  first = NULL;
  second = NULL;
  third = NULL;

  return 0;
}
