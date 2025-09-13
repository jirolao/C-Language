#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Stack {
    char data[MAX];
    int top;
};

typedef struct Stack *Stack;

void init(Stack *s);
void push(Stack *s, char elem);
void pop(Stack *s);
char top(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void display(Stack *s);

int main() {
    Stack x;
    init(&x);
    push(&x, 'A');
    push(&x, 'B');
    push(&x, 'C');
    display(&x)
 	pop(&x);
 	pop(&x);
    display(&x);

}

void init(Stack *s) {
    *s = malloc(sizeof(struct Stack));
    (*s)->top = -1;
}

void push(Stack *s, char elem){
    if(!isFull(s)){
        (*s)->top++;
        (*s)->data[(*s)->top] = elem;
    }
}

void pop(Stack *s){
    if(!isEmpty(s)){
        char elem = (*s)->data[(*s)->top];
        (*s)->top--;
    }
}

char top(Stack *s) {
    if (!isEmpty(s)) {
        return (*s)->data[(*s)->top];
    }
}

int isEmpty(Stack *s) {
    return (*s)->top == -1;
}

int isFull(Stack *s) {
    return (*s)->top == MAX - 1;
}

void display(Stack *s) {
    int i;
    printf("Stack contents: ");
    for (i = (*s)->top; i >= 0; i--) {
        printf("%c ", (*s)->data[i]);
    }
    printf("\n");
}

