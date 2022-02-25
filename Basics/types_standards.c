#include <stdint.h>  // entête des entiers de taille explicite
#include <stdbool.h> // entête du type booleen
#include <stdlib.h>

int main(void)
{
    // nombre réels
    float reel_simple_precision = 2.5;
    double reel_double_precision = 10.0e207;

    // caractères et chaines de caractères
    char lettre = 'z';
    char chaine[] = "hello, world!";

    // nombres entiers dont la taille depend de l'architecture
    int entier = -42;
    long gros_entier = 129381239;
    short petit_entier = 300;
    char tout_petit_entier = 2;
    unsigned naturel = 255;

    // nombre entiers standards de taille explicite
    int8_t entier_8bit = -127;
    int32_t entier_32bit = -2147483647;

    // même chose pour les naturels
    uint16_t naturel_16bit = 32767;
    uint64_t naturel_64bit = 9223372036854775807;

    // booléen
    bool b = true;

    return EXIT_SUCCESS;
}

/*
By convention, if main() returns zero or EXIT_SUCCESS (if the values are different)
then the program is deemed to have been terminated successfully. So, to indicate success,
you are allowed to return 0 or EXIT_SUCCESS. If the macro EXIT_SUCCESS expands to
zero then there is no difference between the two options.
*/

/*
Nombres réels

Il existe principalement deux types de nombres réels : float et double,
respectivement codés sur 4 et 8 octets (ceci est normalisé).
Un type long double existe aussi, mais sa taille peut varier selon les architectures.
Utiliser des double permet des calculs plus précis, mais nécessite plus de mémoire
pendant l'exécution. Le choix du type dépend donc des contraintes propres à chaque
programme et à l'environnement dans lequel il est exécuté.
*/

/*

Nombres entiers

Pour les entiers, le type de base est int, pour integer, mais on peut spécifier sa taille
(short, long ou long long) et le fait qu'il soit signé ou non (signed, unsigned}.

La syntaxe C permet plusieurs écritures du même type (int est en fait équivalent à signed int,
unsigned short à unsigned short int), ce qui peut rendre le code verbeux et inhomogène.
Mais le défaut principal des types entiers natifs est que leur taille est liée à
l'architecture d'une machine (32 bits, 64 bits, ...). Par exemple un int peut être
codé sur 4 octets sur une machine et sur 8 octets sur une autre! De ce fait,
la portabilité du code produit n'est pas garantie : un débordement, aussi appelé
dépassement de capacité, peut arriver sur une architecture et pas sur une autre.

Pour les entiers, on préférera toujours utiliser les types normalisés de
taille explicite, décrits plus bas.
*/

/*
Caractères

Le type char est en fait un type entier (le plus petit, en dessous de short int),
qui est aussi utilisé pour représenter des caractères (via en fait leur code ascii).
*/

/*
Types supplémentaires du langage

Des types supplémentaires ont été introduits dans la norme C99, ayant un
comportement garanti identique sur toutes les architectures.
*/

/*
Entiers normalisés, de taille explicite
Les entiers normalisés prennent la forme [u]intXX_t, où u est présent si le type
est non signé (entiers naturels) et XX représente le nombre de bits utilisés
pour stocker l'entier en mémoire :

    int8_t, int16_t, int32_t, int64_t: entier signé codé sur 8, 16, 32, ou 64 bits
    uint8_t, uint16_t, uint32_t, uint64_t: entier non signé de taille 8, 16, 32 ou 64 bits

Ces types sont définis dans le fichier entête stdint.h, qui doit donc être
inclus dans les programmes les utilisant via la ligne : #include <stdint.h> */

/*
Booléens

Un type booléen bool a aussi été introduit, qui peut prendre les valeurs
true ou false. Ajouter #include <stdbool.h> pour l'utiliser.
*/

/*
Transtypage

Le type d'une donnée en C détermine la façon dont sont interprétés les bits qui
composent cette donnée. Il est possible de changer cette interprétation à l'aide
d'une opération de transtypage, ou cast en anglais, qui peut être explicite (
écrite dans votre code) ou implicite (gérée automatiquement par le compilateur).
Transtypage implicite: EX;
*/
int example1(void){
  uint32_t n = 128; // n vaut 128
  float f = n;      // f vaut 128.0
  f = f + 0.3;      // f vaut 128.3
  n = f;            // n vaut 128 : la valeur f est tronquée
  n = n + 0.3;      // n faut toujours 128 (0.3 tronque en 0)
  return EXIT_SUCCESS;
}

/*
Il est important de comprendre que les données en mémoire ne changent pas forcément,
c'est leur interprétation qui peut être différente (comme en archi en somme) :
*/
int example2(void){
  int32_t s = -128;  // en hexadécimal: 0xffffff80

  /*
    La valeur s est transtypée en flottant, puis affectée à f.
    En hexadécimal f vaut aussi 0xffffff80, mais qui est maintenant
    interprété comme -128.0.
 */
  float f = s;

 /*
    u est aussi 0xffffff80, mais en non signé c'est interprété
    comme un entier drôlement grand ! (4294967168)
 */
  uint32_t u = s;

  return EXIT_SUCCESS;
}

/*Il peut aussi y avoir des conversions de type avec des changements de taille :*/
void example3(void){
  // Plus court : on tronque
int16_t s16 = -511;  // En hexadecimal : 0xfe01
int8_t s8 = s16;     // On tronque : il reste 0x01,
                     // c'est-à-dire 1 (le signe a changé !)

// Plus grand : extension de type
uint8_t u8 = s8;     // u vaut 0x01, 1 quoi

uint16_t u16 = u8;   // extension non signée : complétion avec
                     // des 0 à gauche => 0x0001

s16 = s8;            // extension signée : complétion avec le bit
                     // de poids fort. s16 vaut 0x0001, 1

s8 = 0xfd;           // s8 vaut -3 (on peut affecter en
                     // notation hexa, oui oui!)

s16 = s8;            /* s16 vaut 0xfffd, toujours -3. */

}

/*
Transtypage explicite

Il est possible de transtyper explicitement dans le code. La ligne ci-dessous
indique d'interpréter la variable variable comme si elle était de type type :
(type) variable;
*/
void example4(void){
  /*
    En fait cette ligne est équivalente à :

    float f = 10;

    mais on sait au moins que le transtypage est
    voulu puisque que vous le dites explicitement !
    (vous avez conscience de ce que vous faites)
*/
float f = (float) 10;

uint8_t d = 255;
int16_t mystere1 = (int16_t) d;
int16_t mystere2 = (int16_t) (int8_t) d;

/* Si vous avez suivi, mystere1 vaut 255 (0x00ff)
    * et mystere2 -1 (0xffff). */

}

/* UNE ERREUR CLASSIQUE: la division entière*/

void attention(void){
  uint32_t num = 10, div = 4;

/*
    Ici on divise deux variables de type entier,
    le résultat est donc aussi entier : 2
*/
uint32_t quotient = num / div;

// On peut essayer ceci :
/*float ratio = num / div;*/
/*
    Mais ça ne marche pas ! On a transtypé le résultat
    (l'entier 2) en un flottant ; ratio vaut donc 2.0
*/

/*
    Ici il faut transtyper l'un des opérandes en flottant,
    pour forcer une division flottante et non entière.
    ratio_reel vaut bien 2.5.
*/
float ratio_reel = ((float) num) / div;

}
