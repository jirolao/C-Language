#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int num;
	struct Node *left;
	struct Node *right;
}*BSTnode;

BSTnode* newNode(int data);
BSTnode* insert(BSTnode *root, int data);
BSTnode* del(BSTnode *root, int data);

int main(){
	BSTnode *root = NULL;
	int val[] = {3, 4, 6, 9, 11, 2, 8};
	int x;
	for(x = 0; x < sizeof(val)/sizeof(val[0]); x++){
		insert(&root, val[x]);
	}
	
}

BSTnode* newNode(int data){
	BSTnode temp;
	temp = malloc(sizeof(BSTnode));
	temp->num = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

BSTnode* insert(BSTnode *root, int data){
	
	
}

/* 
 ( TOO LONG INSERT )

BSTnode* insert(BSTnode *root, int data){
	BSTnode temp = newNode(data);
	
		if(root == NULL)
		root = temp;
		
	BSTnode current = root;                                                                                                                                                            
	BSTnode parent = NULL;

	while(current != NULL){
		parent = current;
		if(current->num < data){
			current = current->right;
		}else if(current->num > data){
			current = current->left;
		}else{
			free(temp);
			return root;
		}
	}
	
	if(parent->num < data)
		parent->right = temp;
		
	else
		parent->left = temp;
		
		return root;
	}
	
	*/

// SPACE ----------------------------------------------------------------

/*
  ( RECURSIVE CODE FOR INSERT )
 
BSTnode* insert(BSTnode *root, int data){
	if(root == NULL){
		return newNode(data);
	}else if(root->num > data){
		root->left = insert(root->left, data);
	}else if(root->num < data){
		root->right = insert(root->right, data);
	}
	return root;
}

*/

BSTnode* del(BSTnode *root, int data){
	
}

