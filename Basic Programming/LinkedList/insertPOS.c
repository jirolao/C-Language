#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int elem;
	struct node *link;
}*LIST;

void insert(LIST *L, int val){
	LIST newNode = malloc(sizeof(struct node));
	if(L != NULL){
		newNode->elem = val;
		newNode->link = *L;
		*L = newNode;
	}
}

void insertAtPOS(LIST *L, int pos, int val){
	int count;
	LIST *trav;
	LIST newNode;
	
	if(pos == 0){
		newNode = malloc(sizeof(struct node));
		newNode->elem = val;
		newNode->link = *L;
		*L = newNode;
	}
	
	for(trav = L, count = 0; *trav != NULL && count < pos - 1; trav = &(*trav)->link, count++){}

	if(count == pos - 1){
	newNode = malloc(sizeof(struct node));
	newNode->elem = val;
	newNode->link = (*trav)->link;
	(*trav)->link = newNode;
	}
}

void print(LIST L){
	while(L != NULL){
		printf("%d\n", L->elem);
		L = L->link;
	}
}

int main(){
	LIST head = NULL;
	
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insertAtPOS(&head, 0, 4);
	insertAtPOS(&head, 1, 5);
	insertAtPOS(&head, 3, 6);
	print(head);
}
