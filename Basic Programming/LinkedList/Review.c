#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}*LIST;

void init(LIST *p);
void insertADD(int data, LIST *p);
void insertSorted(int data, LIST *p);
void bubblesort(LIST *p);
void print(LIST *p);

int main(){
	LIST *p, test1;
	
	init(p);
	init(&test1);
	int i;
	for(i = 5;i > 0;i--){
		insertADD(i, &p);
	}
	
	insertSorted(7, &p);

	print(p);
}

void init(LIST *p){
	p = NULL;
}

void insertADD(int data, LIST *p){
	LIST *trav, temp;
	for(trav = p;*trav != NULL;trav = &(*trav)->link);
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = data;
		temp->link = NULL;
		*trav = temp;
	}
}

void insertSorted(int data, LIST *p){
	LIST *trav, temp;
	for(trav = p;*trav != NULL && data < (*trav)->data;trav = &(*trav)->link){}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = data;
		temp->link = *trav;
		*trav = temp;
	}
}

void print(LIST *p){
	LIST trav;
	for(trav = p;trav != NULL;trav = trav->link){
		printf("%d\n", trav->data);
	}
}
