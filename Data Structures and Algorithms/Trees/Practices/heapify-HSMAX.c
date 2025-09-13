#include <stdio.h>

#define MAX 5
typedef struct {
    int arr[MAX];
    int lastNdx;
}HEAP;

// Function prototypes
void init(HEAP *H);
void insert(HEAP *H, int data);
void heapSort(HEAP *H);
void maxHeapify(HEAP *H, int idx);
void deleteMax(HEAP *H, int idx);
void display(HEAP H);

int main(void) {
    // Initialize the heap
    HEAP POT;
    init(&POT);
    // Insert the data
    insert(&POT, 30);
    insert(&POT, 10);
    insert(&POT, 20);
    insert(&POT, 40);
    insert(&POT, 50);
    // Display the MAX heap
    // Display the sorted heap
    printf("POTs:\n");
    heapSort(&POT);
    display(POT);
    return 0;
}

// Function definitions
void init(HEAP *H) {
    H->lastNdx = -1;
}

void insert(HEAP *H, int data) {
    if(H->lastNdx < MAX - 1) {
        H->lastNdx++;
        H->arr[H->lastNdx] = data;
    }
}

void heapSort(HEAP *H) {
    int len = H->lastNdx, ndx;
    // Build MAX heap
    for(ndx = (H->lastNdx - 1) / 2; ndx >= 0; ndx--) {
        maxHeapify(H, ndx);   
    }
    // Display the MAX heap
    display(*H);
    // Sort the heap
    for(ndx = H->lastNdx; ndx > 0; ndx--) {
        deleteMax(H, ndx);
    }
    H->lastNdx = len;
}

void maxHeapify(HEAP *H, int idx) {
    int largest = idx, left = (2 * idx) + 1, right = (2 * idx) + 2;
    if(left <= H->lastNdx && H->arr[left] > H->arr[largest]) {
        largest = left;
    }
    if(right <= H->lastNdx && H->arr[right] > H->arr[largest]) {
        largest = right;
    }
    if(largest != idx) {
        int temp = H->arr[idx];
        H->arr[idx] = H->arr[largest];
        H->arr[largest] = temp;
        maxHeapify(H, largest);
    }
}

void deleteMax(HEAP *H, int idx) {
    int temp = H->arr[0];
    H->arr[0] = H->arr[idx];
    H->arr[idx] = temp;
    H->lastNdx--;
    maxHeapify(H, 0);
}

void display(HEAP H) {
    int x;
    for(x = 0; x <= H.lastNdx; x++) {
        printf("%d ", H.arr[x]);
    }
    printf("\n");
}