/*
Full list
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

list* creat_list(int d){
    // creat a list with the single element d.
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list* add_to_front(int d, list *h){
    // add d to the front of the list h.
    list *head = creat_list(d);
    head->next = h;
    return head;
}

list *add_to_end(int d, list *h){
    // add d to the end of the list
    list *head = creat_list(d);
    while(h->next != NULL){
        h = h->next;
    }
    h->next = head;

    return h;
}
void print_list(const list *h, char *title){
    printf("%s\n", title);
    // h is a list, and h->next is also a list
    while(h != NULL){
        printf("%d -> ", h->data);
        h = h->next;
    }
    printf("NULL\n");
}



list* array_to_list(int d[], int size){
    list* head = creat_list(d[0]);
    for (int i = 1; i < size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

void test1(){
    list* my_list = malloc(sizeof(list));
    my_list->data = 4;
    my_list->next = NULL;
    my_list = add_to_end(5,my_list);
    list* newList = add_to_front(3,my_list);

    print_list(my_list, "My List");
    print_list(newList, "New List");

    free(my_list);
    free(newList);
}

void test2(){
    printf("test converting an array to a list\n");
    list* head = NULL;
    int data[6] = {1,2,3,4,5,6};
    head = array_to_list(data,6);
    print_list(head, "Converted list from an array");
}

int main(int argc, char const *argv[]) {
    test1();
    test2();
    return 0;
}
