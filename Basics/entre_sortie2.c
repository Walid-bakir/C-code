#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>  // in-out, fonctions des entrées-sorties

/*
    Retourne l'entier naturel entré au clavier, en effectuant
    une lecture caractère par caractère.
*/
uint32_t get_natural(void)
{
    uint32_t entier = 0;
    char chiffre_lu;

    char lo = getc(stdin);
    while (lo != '\n') {
        chiffre_lu = lo - '0';
        entier = 10 * entier + chiffre_lu;
        lo = getc(stdin);
    }

    return entier;
}


int main(void)
{
    printf("Entrez un entier naturel : ");
    uint32_t entier = get_natural();

    printf("Entrez un entier signe : ");
    /*
        10 caractères ASCII suffisent pour stocker les chiffres
        d'un entier 32 bits. Le 11e caractère permet de stocker
        le caractère de fin de chaine, '\0'.
    */
    char tampon[11];
    fgets(tampon, 11, stdin);
    int32_t signe = atoi(tampon);

    printf("Vous avez saisi %u et %i.\n", entier, signe);

    return EXIT_SUCCESS;
}

/*
Entrez un entier naturel : 123
Entrez un entier signe : -2879
Vous avez saisi 123 et -2879.
*/
/*

    %i : int (entier relatif)
    %u : unsigned (entier naturel)
    %g : float (réel)
    %c : char (caractère)
    %s : une chaîne de caractères

*/


/*
L'utilisation de la fonction fgets offre une solution plus compacte pour lire des
entrées au clavier. fgets(buffer, n, stdin) lit au plus n-1 caractères au clavier
et les stocke dans la chaîne buffer (une chaîne de caractères en C est en fait
un tableau de caractères :
*/
