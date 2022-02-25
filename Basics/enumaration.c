#include <stdio.h>
#include <stdlib.h>


enum color{
  Red,
  Blue,
  Green,
  NB_color
};

enum shows{
  THE_OFFICE =  10,
  FRIENDS,

};

void create(enum color couleur){
    switch(couleur){
        case Red:
            printf("I love red\n");
            break;
        case Green:
            printf("I love green\n");
            break;
        case Blue:
            printf("I dont really love blue\n");
            break;
        default:
            printf("I dont know this color\n");

    }
}

int main(void)
{
  enum color color_1 = Red;
  enum color color_2 = Green;
  printf("%d\n" , color_1);
  printf("%d\n" , color_2);
  enum shows show_1 = THE_OFFICE;
  enum shows show_2 = FRIENDS;
  printf("%d\n" , show_1);
  printf("%d\n" , show_2);
  create(color_1);
  create(color_2);
  return 0;
  /*
   0
   2
   10
   11
   I love red
   I love green
  */
}
