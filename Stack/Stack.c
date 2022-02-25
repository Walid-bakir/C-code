/*
developp a stack

*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack{
    char s[MAX_LEN];
    int top;
}stack;


void reset(stack *stk){
    stk->top = EMPTY;
}

void push(char c, stack *stk){
    // add the char s to the top of the stack
    stk->top++; // increment the top
    stk->s[stk->top] = c; // place c in the new top
}

char pop(stack *stk){
    // remove the top and return it.
    return stk->s[stk->top--];
}

char top(const stack *stk){
    // take a peek of the top
    // The stack is unchanged, hence the use of const
    return stk->s[stk->top];
}

int is_empty(const stack *stk){
    return (stk->top == EMPTY);
}

int is_full(const stack *stk){
    return (stk->top == FULL);
}


int main(){
    stack stack_of_char;
    char *str = "i am otto i am";
    char str_back[20];
    int i = 0;
    reset(&stack_of_char);
    printf("Original is : %s\n", str);

    while (str[i] != '\0') {
        printf("%c\n", str[i]);
        push(str[i++], &stack_of_char);
    }

    i = 0;
    while(!is_empty(&stack_of_char)){
        str_back[i++] = pop(&stack_of_char);
    }
    printf("Reverse is : %s\n", str_back);
    printf("\n");

    struct point{
    double x;
    double y;
} p1 = {4, p1.x};
    struct point* ptr = &p1;
    printf("%f\n", ptr->y);
}
