#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define max size for the queue

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *BST;

typedef struct Queue {
    BST* nodes;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

BST createNode(int data);
void insertNode(int data, BST *tree);
int searchNode(int data, BST tree);
void displayInOrder(BST tree);
void enqueue(BST node, Queue *Q);
BST dequeue(Queue *Q);
int isEmpty(Queue *Q);
int isFull(Queue *Q);
void BFS(BST tree, Queue *Q);

int main() {
    BST tree = NULL;  // Initialize the tree to NULL
    Queue Q = {NULL, -1, -1, 0, MAX}; // Initialize queue
    Q.nodes = malloc(MAX * sizeof(BST));  // Allocate memory for queue nodes
    
    insertNode(3, &tree);
    insertNode(2, &tree);
    insertNode(1, &tree);
    insertNode(5, &tree);
    insertNode(6, &tree);
    insertNode(7, &tree);
    insertNode(8, &tree);
    insertNode(9, &tree);


    printf("Nodes in the BST (in-order): ");
    displayInOrder(tree);
    printf("\n");


    printf("Searching for 2: %s\n", searchNode(2, tree) ? "Found" : "Not Found");
    printf("Searching for 4: %s\n", searchNode(4, tree) ? "Found" : "Not Found");

    // Perform BFS traversal
    printf("Breadth-First Traversal (BFS): ");
    BFS(tree, &Q);
    printf("\n");

    free(Q.nodes);  // Free allocated memory for queue
    return 0;
}

BST createNode(int data) {
    BST newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insertNode(int data, BST *tree) {
    if (*tree == NULL) {
        *tree = createNode(data);
    } else if (data < (*tree)->data) {
        insertNode(data, &(*tree)->left);
    } else if (data > (*tree)->data) {
        insertNode(data, &(*tree)->right);
    }
}

int searchNode(int data, BST tree) {
    if (tree == NULL) {
        return 0;  
    }
    if (tree->data == data) {
        return 1;
    } else if (data < tree->data) {
        return searchNode(data, tree->left);
    } else {
        return searchNode(data, tree->right);
    }
}

void displayInOrder(BST tree) {
    if (tree != NULL) {
        displayInOrder(tree->left);   // Visit left subtree
        printf("%d ", tree->data);     // Visit node
        displayInOrder(tree->right);  // Visit right subtree
    }
}

void enqueue(BST node, Queue *Q) {
    if (!isFull(Q)) {
        if (Q->front == -1) {  // Empty queue case
            Q->front = 0;
        }
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->nodes[Q->rear] = node;
        Q->size++;
    }
}

BST dequeue(Queue *Q) {
    BST temp = NULL;
    if (!isEmpty(Q)) {
        temp = Q->nodes[Q->front];
        Q->nodes[Q->front] = NULL;
        if (Q->front == Q->rear) {
            Q->front = -1;
            Q->rear = -1;
        } else {
            Q->front = (Q->front + 1) % Q->capacity;
        }
        Q->size--;
    }
    return temp;
}

int isEmpty(Queue *Q) {
    return Q->size == 0;
}

int isFull(Queue *Q) {
    return Q->size == Q->capacity;
}

void BFS(BST tree, Queue *Q) {
    if (tree == NULL) return;

    enqueue(tree, Q);  // Enqueue the root node
    
    while (!isEmpty(Q)) {
        BST currentNode = dequeue(Q);  // Dequeue node
        
        if (currentNode != NULL) {
            printf("%d ", currentNode->data);  // Visit node
            
            if (currentNode->left != NULL) {
                enqueue(currentNode->left, Q);  // Enqueue left child
            }
            if (currentNode->right != NULL) {
                enqueue(currentNode->right, Q);  // Enqueue right child
            }
        }
    }
}

