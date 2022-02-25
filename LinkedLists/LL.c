#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

/* Structure de données décrivant un élément d'une liste. */

struct cellule{
  uint32_t val;
  struct cellule *suiv;
};

/*
    Affiche sur la sortie standard les valeurs des cellules de la liste
    pointée par l.
*/
static void afficher(struct cellule *l){
  while (l != NULL){
    printf("%d-> ", l->val);
    l = l->suiv;
  }
  printf("FIN\n");
}

/*
    Crée une nouvelle cellule contenant la valeur v et l'insère en tête
    de la liste pointée par pl.
*/

static void inserer_tete(struct cellule **pl, uint32_t v){
  struct cellule *liste = malloc(sizeof(struct cellule));
  assert( liste != NULL);
  liste->val = v;
  liste->suiv = *pl;
  *pl = liste;
}

/*
    Crée une nouvelle cellule contenant la valeur v et l'insère en queue
    de la liste pointée par pl.
*/

static void inserer_queue(struct cellule **pl, uint32_t v){
  struct cellule sent = {-1, *pl};
  struct cellule *queue = &sent;
  while (queue->suiv != NULL){
    queue = queue->suiv;
  }
  queue->suiv = malloc(sizeof(struct cellule));
  assert(queue->suiv != NULL);
  queue->suiv->val = v;
  queue->suiv->suiv = NULL;
  *pl = sent.suiv;
}

/*
    Supprime de la liste pointée par pl la première occurrence de cellule
    contenant la valeur v.
*/

static void supprimer_premiere_occurrence(struct cellule **pl, uint32_t v){
  struct cellule sent = { -1, *pl };
  struct cellule *p = &sent;
  while (p->suiv != NULL && p->suiv->val != v){
    p = p->suiv;
  }
  /* Cas occurence trouvée */
  if (p->suiv != NULL){
    /*
        On rechaine les 2 cellules de la liste entourant l'occurrence et on
        libère la cellule trouvée.
    */
    struct cellule *style = p->suiv;
    p->suiv = style->suiv;
    free(style);
  }
  *pl = sent.suiv;
}




int main(void)
{
    struct cellule *liste = NULL;
    for (uint32_t i = 6; i < 10; i++) {
        inserer_queue(&liste, i);
        afficher(liste);
    }
    for (uint32_t i = 5; i > 0; i--) {
        inserer_tete(&liste, i);
        afficher(liste);
    }

    /*
        Initialisation du générateur de nombres aléatoires
        (nécessaire pour que rand() retourne des valeurs différentes à chaque
        exécution du programme).
    */
    srand(time(NULL));

    while (liste != NULL) {
        supprimer_premiere_occurrence(&liste, rand() % 10);
        afficher(liste);
    }
    return EXIT_SUCCESS;
}
