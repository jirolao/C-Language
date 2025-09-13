#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;	
}*BSTnode;

void init(BSTnode *root);
BSTnode createNode(int data);
void insert(BSTnode *root, int data);

int main(){
	BSTnode root;
	init(&root);
	
	insert(&root, 15);
	insert(&root, 20);
	insert(&root, 10);
}

void init(BSTnode *root){
	root = NULL;
}

BSTnode createNewNode(int data){
	BSTnode newNode = (BSTnode)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void insert(BSTnode *root, int data){
	if(*root == NULL){
		 *root = createNewNode(data);
		 return;
	}else if(data <= (*root)->data){
		*root->left = insert(*root)
	}
	
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;    
} *BSTnode;

void init(BSTnode *root);
BSTnode createNewNode(int data);
void insert(BSTnode *root, int data);

int main() {
    BSTnode root = NULL;
    init(&root);
    
    insert(&root, 15);
    insert(&root, 20);
    insert(&root, 10);
    
    return 0;
}

void init(BSTnode *root) {
    *root = NULL;
}

BSTnode createNewNode(int data) {
    BSTnode newNode = (BSTnode)malloc(sizeof(struct Node)); // Allocate memory for Node
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

void insert(BSTnode *root, int data) {
    if (*root == NULL) {
        *root = createNewNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
    // If data is already in the tree, do nothing (assuming duplicates are not allowed)
}
/*
