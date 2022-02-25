/*
Implement a struct representing binary trees.
Date  : 23/03/2022
Author : Walid Bakir
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


typedef char DATA;
typedef struct node{
    DATA d;
    struct node *left;
    struct node *right;
}NODE;

typedef NODE *BTREE; // We look into the node using its root

void inorder(BTREE root ){
    // This equivalent to : NODE* root
    if (root != NULL){
        inorder(root->left);
        printf("%c", root->d);
        inorder(root->right);
    }

}

void preorder(BTREE root ){
    // This equivalent to : NODE* root
    if (root != NULL){
        printf("%c", root->d);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BTREE root ){
    // This equivalent to : NODE* root
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->d);
    }
}



BTREE new_node(){
    // malloc returns a pointer,
    // The difference in malloc and calloc is that malloc does not set the
    // memory to zero where as calloc sets allocated memory to zero.
    return (malloc(sizeof(NODE)));
}

BTREE init_node(DATA c, BTREE b1, BTREE b2){
    // initialize a node with the given arguments.
    BTREE node = new_node();
    node->d = c;
    node->left = b1;
    node->right = b2;
    return node;
}

BTREE create_tree(DATA a[], int i, int size){
    if (i >= size){
        return NULL;
    }
    return (init_node(a[i], create_tree(a, 2*i + 1, size), create_tree(a, 2*i + 2, size)));
}

int main(int argc, char const *argv[]) {
    char d[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    BTREE tree = create_tree(d, 0, 7);
    printf("inorder : \n");
    inorder(tree);
    printf("\n");
    printf("preorder : \n");
    preorder(tree);
    printf("\n");
    printf("postorder : \n");
    postorder(tree);
    printf("\n");
    return 0;
}
