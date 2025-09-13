#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1

typedef enum {
    false,
    true
} check;

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
check isEmpty(Queue q);
check isFull(Queue q);
void visualize(Queue q);
void display(Queue q);

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue after enqueue operations:\n");
    display(q);
    
	printf("Queue after denqueue operations:\n");
	dequeue(&q);
	display(q);
	
    printf("Queue visualization:\n");
    visualize(q);

    return 0;
}

void initQueue(Queue *q) {
    q->front = EMPTY;
    q->rear = EMPTY;
    int x;
    for (x = 0; x < MAX; x++) {
        q->elems[x] = EMPTY;
    }
}

void enqueue(Queue *q, int item) {
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->elems[q->rear] = item;
}

void dequeue(Queue *q) {
    q->elems[q->front] = EMPTY;
    q->front = (q->front + 1) % MAX;
}

int front(Queue q) {
    if (!isEmpty(q)) {
        return q.elems[q.front];
    }
    return EMPTY;
}

check isEmpty(Queue q) {
    return (q.rear == EMPTY) && (q.front == EMPTY);
}

check isFull(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}

void visualize(Queue q) {
    printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
    printf("------------------------\n");
    int i;
    for (i = 0; i < MAX; i++) {
        printf("%5d | ", i);
        if (q.elems[i] != EMPTY) {
            printf("%5d | ", q.elems[i]);
        } else {
            printf("%5s | ", " ");
        }
        if (i == q.front) {
            printf("Front");
        }
        if (i == q.rear) {
            printf("Rear");
        }
        printf("\n");
    }
    printf("------------------------\n");
}

void display(Queue q) {
    int i;
    printf("{");
    for (i = 0; i < MAX; i++) {
        if (q.elems[i] != EMPTY) {
            printf("%d ", q.elems[i]);
        }
    }
    printf("}\n\n");
}






