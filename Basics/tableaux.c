#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

void afficher_tab(uint32_t tab[], uint32_t taille){
  uint32_t i;
  for (i = 0 ; i < taille -1 ; i++){
    printf("%d|", tab[i]);
  }
  printf("%d\n", tab[i]); // here i = taille - 1
  /*
        Nb : ici la variable i existe encore, car elle a été
        déclarée en dehors de la boucle for.
    */
}

int main(void)
{
  uint32_t tab1[] = {1,2,3};
  printf("affichage du tableau 1: \n");
  afficher_tab(tab1, 3);
  uint32_t tab[10];
  for (uint32_t i = 0; i < 10 ; i++){
    tab[i] = i;
  }
  printf("affichage du tableau: \n");
  afficher_tab(tab , 10);
}

/*
affichage du tableau 1:
1|2|3
affichage du tableau:
0|1|2|3|4|5|6|7|8|9

*/
