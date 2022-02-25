/*
Structures de contrôles classiques

Le programme suivant calcule la somme puis le produit des 13 premiers
entiers strictement positifs :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const uint16_t N = 13;
    uint32_t somme = 0, produit = 1;

    /* Somme des entiers appartenant à [1; N] */
    for (uint16_t i = 1; i < N + 1; i++) {
        somme += i;
    }

    uint16_t j = 1;
    /* Produit des entiers appartenant à [1; N] */
    while (j <= N) {
        produit *= j;
        j++;
    }

    /* Qu'on pourrait aussi écrire: */
    produit = 1;
    j = 1;
    do {
        produit = produit * j;
        j++;
    } while (j <= N);

    /* somme % 2 = "reste de la division de somme par 2"
        * (operateur modulo). */
    if (somme % 2 == 0) {
        printf("La somme calculee est paire.\n");
    } else {
        printf("La somme calculee est impaire.\n");
    }

    /* Suite du programme precedent */

/* Pour enchainer des tests */
   printf("La somme calculee vaut: ");
   if (somme == 2 || somme == 4 || somme == 6) {
     printf("2, 4 ou 6\n");
   } else if (somme == 8 || somme == 10) {
     printf("8 ou 10\n");
   } else {
     printf("quelque chose sauf 2, 4, 6, 8 ou 10\n");
   }

/* On peut aussi utiliser un switch ... case */
    switch (somme) {
      case 2:
      case 4:
      case 6:
        printf("2, 4 ou 6\n");
        break;                      // Ne pas oublier!
      case 8:
      case 10:
        printf("8 ou 10\n");
        break;                      // Ne pas oublier!
      default:
        printf("quelque chose sauf 2, 4, 6, 8 ou 10\n");
}




    return EXIT_SUCCESS;
}

/*
|| est l'opérateur OU logique ;
le mot clé elif n'existe pas en C, il faut écrire else if ;
switch permet d'évaluer une variable, et case définit le traitement selon sa valeur ;
attention, ne pas oublier les break! Sinon les instructions suivantes seront exécutées dans tous les cas.
*/
