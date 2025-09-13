#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct node{
int data;
struct node* next;
}*LL;

typedef struct{
	LL top;
}Stack;

void initStack(Stack *s);
bool isEmptyS(Stack *s);
void push(Stack *s, int data);
void pop(Stack *s);
void peek(Stack *s);
void printStack(Stack *s);

int main(){
	Stack s;
	initStack(&s);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	pop(&s);
	pop(&s);
	peek(&s);
	printStack(&s);
	
return 0;
}

void initStack(Stack *s){
	s->top = NULL;
}

bool isEmptyS(Stack *s){
	return (s->top == NULL) ? 1 : 0;
}

void push(Stack *s, int data){
	LL newNode = malloc(sizeof(struct node));
	if(newNode != NULL){
		newNode->data = data;
		newNode->next = s->top;
		s->top = newNode;
	}
}

void pop(Stack *s){
	if(!isEmptyS(s)){
		LL temp = s->top;
		s->top = s->top->next;
		free(temp);		
	}
}

void peek(Stack *s){
	if(!isEmptyS(s)){
	printf("Top: %d\n", s->top->data);
	}
}

void printStack(Stack *s){
	if(!isEmptyS(s)){
	LL trav = s->top;
	while(trav != NULL){
		printf("%d ", trav->data);
		trav = trav->next;
		}
	}
}




