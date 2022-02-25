/*
Single element list
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


typedef struct list{
    int data;
    struct list *next;
}list;

int is_empty(const list *l){
    return (l == NULL);
}
void print_list(const list *h, char *title){
    printf("%s\n", title);
    // h is a list, and h->next is also a list
    while(h != NULL){
        printf("%d -> ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    // print a single element list.
    list* head = malloc(sizeof(list));
    printf("sizeof(list) = %lu\n", sizeof(list)); // unsigned long
    head->data = 5;
    head->next = NULL;
    print_list(head, "Single elemet list");
    return 0;
}
