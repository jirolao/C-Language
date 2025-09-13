#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data;
    int priority;
} QueueElement;

typedef struct {
    QueueElement *arr;
    int size;
    int capacity;
} PriorityQueue;

void initQueue(PriorityQueue *q);
int isFull(PriorityQueue *q);
int isEmpty(PriorityQueue *q);
void enqueueUnordered(PriorityQueue *q, QueueElement element);
void enqueueOrdered(PriorityQueue *q, QueueElement element);
QueueElement* findElement(PriorityQueue *q, char data);
void display(PriorityQueue *q);
void deleteUnordered(PriorityQueue *q);
void deleteOrdered(PriorityQueue *q);

int main() {
    PriorityQueue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    enqueueUnordered(&q1, (QueueElement){'A', 3});
    enqueueUnordered(&q1, (QueueElement){'B', 1});
    enqueueUnordered(&q1, (QueueElement){'C', 2});

    printf("Unordered Queue:\n");
    display(&q1);

    enqueueOrdered(&q2, (QueueElement){'A', 3});
    enqueueOrdered(&q2, (QueueElement){'B', 1});
    enqueueOrdered(&q2, (QueueElement){'C', 2});

    printf("\nOrdered Queue:\n");
    display(&q2);

    deleteUnordered(&q1);
    display(&q1);
    deleteOrdered(&q2);
    display(&q2);

    return 0;
}

void initQueue(PriorityQueue *q) {
    q->capacity = 5;
    q->size = 0;
    q->arr = malloc(q->capacity * sizeof(QueueElement));
}

int isFull(PriorityQueue *q) {
    return q->size == q->capacity;
}

int isEmpty(PriorityQueue *q) {
    return q->size == 0;
}

void enqueueUnordered(PriorityQueue *q, QueueElement element) {
    if (!isFull(q)) {
        q->arr[q->size] = element;
        q->size++;
    }
}

void enqueueOrdered(PriorityQueue *q, QueueElement element) {
    if (!isFull(q)) {
        int i = q->size - 1;
        while (i >= 0 && q->arr[i].priority > element.priority) {
            q->arr[i + 1] = q->arr[i];
            i--;
        }
        q->arr[i + 1] = element;
        q->size++;
    }
}

QueueElement* findElement(PriorityQueue *q, char data) {
	int i;
    for (i = 0; i < q->size; i++) {
        if (q->arr[i].data == data) {
            return &q->arr[i];
        }
    }
    return NULL;
}

void display(PriorityQueue *q) {
    if (!isEmpty(q)) {
    	int i;
        for (i = 0; i < q->size; i++) {
            printf("Data: %c, Priority: %d\n", q->arr[i].data, q->arr[i].priority);
        }
    } else {
        printf("Queue is empty.\n");
    }
}

void deleteUnordered(PriorityQueue *q) {
    if (!isEmpty(q)) {
        int minIndex = 0;
        int i;
        for (i = 1; i < q->size; i++) {
            if (q->arr[i].priority < q->arr[minIndex].priority) {
                minIndex = i;
            }
        }
        for (i = minIndex; i < q->size - 1; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->size--;
    }
}

void deleteOrdered(PriorityQueue *q) {
    if (!isEmpty(q)) {
    	int i;
        for (i = 0; i < q->size - 1; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->size--;
    }
}

