#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *BST;

BST createNode(int data);
void insertNode(int data, BST *tree);
int searchNode(int data, BST tree);
void displayInOrder(BST tree);
void deleteNode(int data, BST *tree);
void bstToMinHeap(BST tree);
void bstToMaxHeap(BST tree);

// Helper functions
void inOrderToArray(BST tree, int* arr, int* index);
void arrayToMinHeap(BST* tree, int* arr, int* index, int n);
void arrayToMaxHeap(BST* tree, int* arr, int* index, int n);

int main() {
    BST tree = NULL;  // Initialize the tree to NULL
    insertNode(3, &tree);
    insertNode(2, &tree);
    insertNode(1, &tree);
    insertNode(5, &tree);

    // Display the nodes in ascending order
    printf("Nodes in the BST (in-order): ");
    displayInOrder(tree);
    printf("\n");

    // Test the delete function
    deleteNode(2, &tree);
    printf("After deleting 2 (in-order): ");
    displayInOrder(tree);
    printf("\n");

    // Transform to Min-Heap
    bstToMinHeap(tree);
    printf("After transforming to Min-Heap (in-order): ");
    displayInOrder(tree);
    printf("\n");

    // Transform to Max-Heap
    bstToMaxHeap(tree);
    printf("After transforming to Max-Heap (in-order): ");
    displayInOrder(tree);
    printf("\n");

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
        return 0;  // Not found
    }
    if (tree->data == data) {
        return 1;  // Found
    } else if (data < tree->data) {
        return searchNode(data, tree->left);
    } else {
        return searchNode(data, tree->right);
    }
}

void displayInOrder(BST tree) {
    if (tree != NULL) {
        displayInOrder(tree->left);   // Visit left subtree
        printf("%d ", tree->data);   // Visit node
        displayInOrder(tree->right); // Visit right subtree
    }
}

void deleteNode(int data, BST *tree) {
    if (*tree == NULL) {
        return; // Node not found
    }

    if (data < (*tree)->data) {
        deleteNode(data, &(*tree)->left);
    } else if (data > (*tree)->data) {
        deleteNode(data, &(*tree)->right);
    } else {
        // Node to be deleted found
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            // Case 1: No children (leaf node)
            free(*tree);
            *tree = NULL;
        } else if ((*tree)->left == NULL) {
            // Case 2: Only right child
            BST temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        } else if ((*tree)->right == NULL) {
            // Case 3: Only left child
            BST temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        } else {
            // Case 4: Two children
            BST* successor = &(*tree)->right;
            while ((*successor)->left != NULL) {
                successor = &(*successor)->left;
            }
            (*tree)->data = (*successor)->data;
            deleteNode((*successor)->data, successor);
        }
    }
}


void bstToMinHeap(BST tree) {
    int arr[100], index = 0;
    inOrderToArray(tree, arr, &index);
    index = 0;
    arrayToMinHeap(&tree, arr, &index, index);
}

void bstToMaxHeap(BST tree) {
    int arr[100], index = 0;
    inOrderToArray(tree, arr, &index);
    index--;
    arrayToMaxHeap(&tree, arr, &index, index + 1);
}

void inOrderToArray(BST tree, int* arr, int* index) {
    if (tree == NULL) return;
    inOrderToArray(tree->left, arr, index);
    arr[(*index)++] = tree->data;
    inOrderToArray(tree->right, arr, index);
    
}

void arrayToMinHeap(BST* tree, int* arr, int* index, int n) {
    if (*tree == NULL || *index >= n) return;
    (*tree)->data = arr[(*index)++];
    arrayToMinHeap(&(*tree)->left, arr, index, n);
    arrayToMinHeap(&(*tree)->right, arr, index, n);
}

void arrayToMaxHeap(BST* tree, int* arr, int* index, int n) {
    if (*tree == NULL || *index < 0) return;
    (*tree)->data = arr[(*index)--];
    arrayToMaxHeap(&(*tree)->right, arr, index, n);
    arrayToMaxHeap(&(*tree)->left, arr, index, n);
}

