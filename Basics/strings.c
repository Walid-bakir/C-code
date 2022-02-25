#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h> /* pour strlen, strncpy, ... */


int main(void)
{
  char chaine[] = "toto";
  char chaine2[5];
  uint32_t taille = strlen(chaine); /* taille vaut */
  /* Affichage d'une chaine caractere par caractere
    * (notez le <= dans la boucle!) */
  for (uint32_t i = 0; i < taille; i++){
    /* %c affiche un caractere, %u son code ASCII */
    printf("%c\n", chaine[i]);
    printf("%u\n", chaine[i]);
    }
  /* Affiche directement la chaine */
  printf("chaine = %s\n" , chaine);

  if (chaine[taille] == '\0'){
    printf("OK!\n");
  }

#ifdef CODEFAUX
    /* Affectation impossible */
    chaine2 = chaine;
#else
    /* Affectation correcte caractère par caractère */
    for (uint32_t i = 0; i <= taille; i++) {
        chaine2[i] = chaine[i];
    }
    printf("%s\n", chaine2);

    /* La même chose via la bibliothèque C */
    strncpy(chaine2, chaine, 5);
    strncpy(chaine2, chaine, 1 + strlen(chaine));
    printf("%s\n", chaine2);
#endif
    return EXIT_SUCCESS;
}
