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

    // Optional: Test the search function
    printf("Searching for 2: %s\n", searchNode(2, tree) ? "Found" : "Not Found");
    printf("Searching for 4: %s\n", searchNode(4, tree) ? "Found" : "Not Found");

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
        printf("%d ", tree->data);     // Visit node
        displayInOrder(tree->right);  // Visit right subtree
    }
}

