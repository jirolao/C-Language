#include <stdio.h>

#define MAX 100 // Maximum size of the heap

// Define element type for priority queue elements
typedef struct {
    int priorityNum; // Priority number (key)
    // Add other fields if necessary
} elemType;

// Define the structure for the priority queue (max-heap)
typedef struct {
    elemType list[MAX]; // Array of elements in the heap
    int lastIdx;        // Index of the last element in the heap
} heapPQ;

// Function prototypes
void insert(heapPQ *PQ, elemType elem);
elemType deleteMax(heapPQ *heap);
void heapify(heapPQ *heap, int subRoot);
void heapSort(heapPQ *heap);
int parentIdx(int idx);
int leftChildIdx(int idx);
int rightChildIdx(int idx);

// Helper functions for index calculations
int parentIdx(int idx) {
    return (idx - 1) / 2;
}

int leftChildIdx(int idx) {
    return 2 * idx + 1;
}

int rightChildIdx(int idx) {
    return 2 * idx + 2;
}

// Insert an element into the heap and maintain the heap property
void insert(heapPQ *PQ, elemType elem) {
    if (PQ->lastIdx < MAX - 1) { // Ensure there's space in the heap
        PQ->list[++(PQ->lastIdx)] = elem; // Insert the element at the end
        int idx = PQ->lastIdx;

        // Heapify-up to restore the heap property
        while (idx > 0 && PQ->list[parentIdx(idx)].priorityNum < PQ->list[idx].priorityNum) {
            // Swap parent and child
            elemType temp = PQ->list[idx];
            PQ->list[idx] = PQ->list[parentIdx(idx)];
            PQ->list[parentIdx(idx)] = temp;

            idx = parentIdx(idx); // Move to the parent index
        }
    }
}

// Remove and return the maximum element (root) from the heap
elemType deleteMax(heapPQ *heap) {
    elemType temp = heap->list[0]; // Get the root (max element)
    heap->list[0] = heap->list[(heap->lastIdx)--]; // Replace root with the last element
    if (heap->lastIdx >= 0) {
        heapify(heap, 0); // Heapify down from the root
    }
    return temp;
}

// Restore the heap property for a subtree rooted at subRoot
void heapify(heapPQ *heap, int subRoot) {
    int trav = subRoot, idx;

    while (leftChildIdx(trav) <= heap->lastIdx) { // While there is at least one child
        idx = leftChildIdx(trav);

        // If there is a right child and it's greater than the left child
        if (rightChildIdx(trav) <= heap->lastIdx &&
            heap->list[rightChildIdx(trav)].priorityNum > heap->list[idx].priorityNum) {
            idx = rightChildIdx(trav);
        }

        // Compare parent with the larger child
        if (heap->list[trav].priorityNum < heap->list[idx].priorityNum) {
            // Swap parent with the larger child
            elemType temp = heap->list[trav];
            heap->list[trav] = heap->list[idx];
            heap->list[idx] = temp;

            trav = idx; // Move down to the child
        } else {
            break; // If the parent is larger than both children, stop
        }
    }
}

// Sort the heap using heap sort algorithm
void heapSort(heapPQ *heap) {
    int origLastIdx = heap->lastIdx; // Store the original size of the heap

    while (heap->lastIdx > 0) {
        heap->list[heap->lastIdx] = deleteMax(heap); // Move max to the end
    }

    heap->lastIdx = origLastIdx; // Restore the original size (if needed elsewhere)
}

// Test the implementation
int main() {
    heapPQ heap;
    heap.lastIdx = -1; // Initialize the heap as empty

    // Insert some elements into the heap
    elemType elems[6] = {{10}, {20}, {5}, {30}, {15}, {25}};
    int n = 6;

    for (int i = 0; i < n; i++) {
        insert(&heap, elems[i]);
    }

    printf("Heap before sorting:\n");
    for (int i = 0; i <= heap.lastIdx; i++) {
        printf("%d ", heap.list[i].priorityNum);
    }
    printf("\n");

    // Sort the heap
    heapSort(&heap);

    printf("Heap after sorting:\n");
    for (int i = 0; i <= heap.lastIdx; i++) {
        printf("%d ", heap.list[i].priorityNum);
    }
    printf("\n");

    return 0;
}
