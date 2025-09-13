#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

enum State {
    EMPTY_QUEUE,
    FULL_QUEUE,
    NORMAL
};

void initQueue(Queue *q);
enum State enqueue(Queue *q, int item);
enum State dequeue(Queue *q);
int front(Queue q);
int isEmpty(Queue q);
int isFull(Queue q);
void visualize(Queue q);
void display(Queue q);
void removeItem(Queue *q, int item);
Queue removeEven(Queue *q);
int doubleTheValue(Queue *q, int value);

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
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

enum State enqueue(Queue *q, int item) {
    if ((q->rear + 1) % MAX == q->front) {
        return FULL_QUEUE;
    }
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->elems[q->rear] = item;
    return NORMAL;
}

enum State dequeue(Queue *q) {
    if (isEmpty(*q)) {
        return EMPTY_QUEUE;
    }
    q->elems[q->front] = EMPTY;
    q->front = (q->front + 1) % MAX;
    if (q->front == (q->rear + 1) % MAX) {
        q->front = EMPTY;
        q->rear = EMPTY;
    }
    return NORMAL;
}

int front(Queue q) {
    if (!isEmpty(q)) {
        return q.elems[q.front];
    }
    return EMPTY;
}

int isEmpty(Queue q) {
    return (q.rear == EMPTY) && (q.front == EMPTY);
}

int isFull(Queue q) {
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
    printf("{");
    int i;
    for (i = 0; i < MAX; i++) {
        if (q.elems[i] != EMPTY) {
            printf("%d ", q.elems[i]);
        } else {
            printf("");
        }
    }
    printf("}\n\n");
}

void removeItem(Queue *q, int item) {
    int trav = q->front;
    int count = 0;
    while (count < MAX) {
        if (q->elems[trav] == item) {
        	int i;
            for (i = trav; i != q->rear; i = (i + 1) % MAX) {
                q->elems[i] = q->elems[(i + 1) % MAX];
            }
            q->elems[q->rear] = EMPTY;
            q->rear = (q->rear - 1 + MAX) % MAX;
            return;
        }
        trav = (trav + 1) % MAX;
        count++;
    }
}

Queue removeEven(Queue *q) {
    Queue newQueue;
    initQueue(&newQueue);
    if (isEmpty(*q)) {
        printf("QUEUE EMPTY\n");
        return newQueue;
    }
    int i = q->front;
    while (i != q->rear) {
        if (q->elems[i] % 2 == 0) {
            enqueue(&newQueue, q->elems[i]);
            removeItem(q, q->elems[i]);
        } else {
            i = (i + 1) % MAX;
        }
    }
    if (q->elems[i] % 2 == 0) {
        enqueue(&newQueue, q->elems[i]);
        removeItem(q, q->elems[i]);
    }
    return newQueue;
}

int doubleTheValue(Queue *q, int value) {
    int changedCount = 0;
    int size = (q->rear - q->front + MAX + 1) % MAX;
	int i;
	
    for (i = 0; i < size; i++) {
        int currentIndex = (q->front + i) % MAX;
        if (q->elems[currentIndex] % value == 0) {
            q->elems[currentIndex] *= 2;
            changedCount++;
        }
    }
    return changedCount;
}

