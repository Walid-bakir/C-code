/*
create from input at the terminal the first ten elements in the periodic table
as a linked list with this struct as data. Then print out this information to
the screen in a nicely readable form.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct atom{
    char *name;
    char *symbol;
    double weight;
    struct atom *next;
}atom;

void print_atoms(atom *atom_set, char *title){
    // print the elements stored in the linked list atom_set with basic information
    printf("%s\n", title);
    while(atom_set != NULL){
        printf("Name = %s | Symbol = %s | Weight = %lf\n", atom_set->name, atom_set->symbol, atom_set->weight);
        atom_set = atom_set->next;
    }
}

atom *create_atom( char *n,  char *s, double w){
    // create an atom using its info.
    atom *a = malloc(sizeof(atom));
    a->name = n;
    a->symbol = s;
    a->weight = w;
    a->next = NULL;
    return a;
}


atom *add_to_front( char *n,  char *s, double w, atom *a){
    // add the new atom info to the end of the atom list.
    atom *new_atom = create_atom(n, s, w);
    new_atom->next = a;
    return new_atom;
}

atom *array_to_atom( char *n[],  char *s[], double w[], int size){
    // take three arrays storing atom information and convert them into a linkedList of atoms
    atom* a = create_atom(n[size - 1], s[size - 1], w[size - 1]);
    for (int i = size - 2; i >= 0; i--){
        a = add_to_front(n[i],s[i],w[i], a);
    }
    return a;

}

int main(int argc, char  *argv[]) {
    // initialize the atom arrays
    char *atom_names[10] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
    char *atom_symbols[10] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
    double atom_weights[10] = {1.008, 4.003, 6.941, 9.012, 10.811, 12.011,14.007, 15.99, 18.998,20.180};
    atom *my_atom = malloc(sizeof(atom));
    my_atom = array_to_atom(atom_names, atom_symbols, atom_weights, 10);
    print_atoms(my_atom, "Atoms list");
    return 0;
}
