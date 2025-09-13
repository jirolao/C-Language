#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node, *AVLtree;

// Function Prototypes
AVLtree createNode(int key);
int height(AVLtree node);
int getBalance(AVLtree node);
AVLtree rightRotate(AVLtree y);
AVLtree leftRotate(AVLtree x);
AVLtree insert(AVLtree node, int key);
AVLtree minValueNode(AVLtree node);
AVLtree deleteNode(AVLtree root, int key);
void handleAVLTreeOperations(AVLtree* root);
void deleteEvenNumbers(AVLtree* root);
void printTreeDetails(AVLtree root);
void inorderTraversal(AVLtree root);

// **Main Function**
int main() {
    AVLtree root = NULL;

    handleAVLTreeOperations(&root);

    return 0;
}

// AVL Tree Functions

// Create a new node
AVLtree createNode(int key) {
    AVLtree node = (AVLtree)malloc(sizeof(Node));
    node->key = key;
    node->height = 1; // New node is initially at height 1
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Get height of a node
int height(AVLtree node) {
    return node ? node->height : 0;
}

// Get balance factor of a node
int getBalance(AVLtree node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Perform a right rotation
AVLtree rightRotate(AVLtree y) {
    AVLtree x = y->left;
    AVLtree T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Perform a left rotation
AVLtree leftRotate(AVLtree x) {
    AVLtree y = x->right;
    AVLtree T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Insert a node
AVLtree insert(AVLtree node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with minimum key value
AVLtree minValueNode(AVLtree node) {
    AVLtree current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
AVLtree deleteNode(AVLtree root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLtree temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            AVLtree temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Perform AVL Tree operations
void handleAVLTreeOperations(AVLtree* root) {
    printf("Inserting integers 1 to 5 into the AVL tree...\n");
    int i;
    for (i = 1; i <= 5; i++) {
        *root = insert(*root, i);
    }

    printf("Initial AVL Tree:\n");
    printTreeDetails(*root);

    printf("\nDeleting even numbers...\n");
    deleteEvenNumbers(root);
}

// Delete all even numbers
void deleteEvenNumbers(AVLtree* root) {
	int i;
    for (i = 2; i <= 5; i += 2) {
        *root = deleteNode(*root, i);
        printf("\nDeleted %d from the AVL tree.\n", i);
        printTreeDetails(*root);
    }
}

// Print tree details
void printTreeDetails(AVLtree root) {
    printf("Height of the AVL tree: %d\n", height(root));
    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");
}

// Perform an inorder traversal
void inorderTraversal(AVLtree root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

