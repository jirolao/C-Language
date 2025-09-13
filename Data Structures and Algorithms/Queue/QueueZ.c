#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    int data;
} Element;

typedef struct node {
    Element e;
    struct node *next;
} *Nodetype;

typedef struct {
    Nodetype front;
    Nodetype rear;
} Queue;

void init(Queue *Q);
void enqueue(Queue *Q, int data);
void dequeue(Queue *Q);
Element peek(Queue Q);
bool isEmpty(Queue Q);
void displayQueue(Queue Q);

int main() {
    
    Queue qu;
    init(&qu);
    int ele;
    
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &ele);
    
    printf("Enter the elements of the queue: ");
    int i;
    for(i = 0;i < ele;i++){
        int temp;
        scanf("%d", &temp);
        enqueue(&qu, temp);
    }
    
    printf("Queue elements: ");
    displayQueue(qu);
    dequeue(&qu);
     printf("\nQueue after removing first element: ");
    displayQueue(qu);
    
    return 0;
}

void init(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void enqueue(Queue *Q, int data) {
        Nodetype temp = malloc(sizeof(struct node));
        if(temp != NULL){
                temp->e.data = data;
                temp->next = NULL;
            if(Q->front == NULL){
                Q->front = temp;
            }else{
                Q->rear->next = temp;
        }
         Q->rear = temp;
    }
    
}

void dequeue(Queue *Q) {
    if(!isEmpty(*Q)){
        Nodetype temp;
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
}

Element peek(Queue Q) {
    Element temp;
    temp.data = -1;
    if(!isEmpty(Q)){
        temp.data = Q.front->e.data;
    }
    return temp;
}

bool isEmpty(Queue Q) {
    return (Q.front == NULL && Q.rear == NULL) ? true:false;
}

void displayQueue(Queue Q) {
    Queue temp;
    init(&temp);
    
     while(Q.front != NULL){
         printf("%d ", Q.front->e.data);
         enqueue(&temp, Q.front->e.data);
         Q.front = Q.front->next;
     }
}
