#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
	int stack[MAX];
	int top;
}Stack;

typedef struct{
	int queue[MAX];
	int front, rear;
}Queue;

// STACK //

void initStack(Stack *stack);
void push(int data, Stack *stack);
void pop(Stack *stack);
bool isfull(Stack stack);
bool isempty(Stack stack);
void printStack(Stack stack);
void top(Stack stack);

// QUEUE //

void initQueue(Queue *q);
void enqueue(int data, Queue *q);
void dequeue(Queue *q);
bool isfullQ(Queue stack);
bool isemptyQ(Queue stack);	
void printQueue(Queue q);

int main(){
	Stack stack;
	initStack(&stack);
	push(4, &stack);
	push(7, &stack);
	push(9, &stack);
	push(8, &stack);
	pop(&stack);
	push(1, &stack);
	push(3, &stack);
	pop(&stack);
	pop(&stack);
	top(stack);
	printStack(stack);

	Queue q;
	initQueue(&q);
	enqueue(1, &q);
	enqueue(2, &q);
	enqueue(3, &q);
	enqueue(4, &q);
	enqueue(5, &q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printf("\n\n");
	printQueue(q);
	
}

// STACK //

void initStack(Stack *stack){
	int i;
	for(i = 0;i < MAX;i++){
		stack->stack[i] = -1;
	}
	stack->top = 0;
}

void push(int data, Stack *stack){
	if(!isfull(*stack)){
		stack->stack[stack->top] = data;
		stack->top++;
	}
}

void pop(Stack *stack){
	if(!isempty(*stack)){
		stack->top--;
	}
}

void top(Stack stack){
	printf("Top: %d\n", stack.stack[stack.top]);
}


bool isfull(Stack stack){
	return (stack.top == MAX - 1) ? 1: 0;
}

bool isempty(Stack stack){
	return (stack.top == -1) ? 1 : 0;
}


void printStack(Stack stack){
	int i;
	for(i = 0;i < stack.top+1;i++){
		printf("%d ", stack.stack[i]);
	}
}

// QUEUE //

void initQueue(Queue *q){
	int i;
	q->front = -1;
	q->rear = -1;
	for(i = 0;i < MAX;i++){
		q->queue[i] = -1;
	}
}

void enqueue(int data, Queue *q){
 	if(!isfullQ(*q)){
		if(isemptyQ(*q)){
	 		q->front = 0;	
		}
		q->rear = (q->rear + 1) % MAX;
		q->queue[q->rear] = data;
 	}
}

void dequeue(Queue *q){
	if(!isemptyQ(*q)){
		q->queue[q->front] = -1;
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}else{
			q->front = (q->front + 1) % MAX;
		}
	}
}

bool isemptyQ(Queue q){
 return (q.rear == -1 && q.front == -1) ? 1 : 0;
}

bool isfullQ(Queue q){
	return ((q.rear + 1) % MAX == q.front) ? 1 : 0;
}

void printQueue(Queue q){
	int i, j;
	if(!isemptyQ(q)){
		for(i = q.front, j = q.rear;i <= j && q.queue[i] != -1;i++){
			printf("%d ", q.queue[i]);
		}
	}
}


