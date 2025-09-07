#include <stdio.h>
#include <string.h>
#include <string.h>

typedef struct node{
	char data[20];
	struct node *link;
}*LIST;

void init(LIST *L){
	*L = NULL;	
}

void insert(char *name, LIST *L){
	LIST *trav;
	LIST newNode;
	for(trav = L;(*trav) != NULL;trav = &(*trav)->link);
	
	newNode = malloc(sizeof(struct node));
	strcpy(newNode->data, name);
	newNode->link = NULL;
	*trav = newNode;
}

void show(LIST L){
	while(L != NULL){
		printf("\n%s", L->data);
		L = L->link;
	}
}

void edit(LIST *L, char *old, char *new){
	LIST *trav;
	for(trav = L;(*trav) != NULL && strcmp((*trav)->data, old) != 0;trav = &(*trav)->link);
	strcpy((*trav)->data, new);
}

void delete(LIST *L, char *old){
	LIST *trav;
	for(trav = L;(*trav) != NULL && strcmp((*trav)->data, old) != 0;trav = &(*trav)->link);
	*trav = (*trav)->link;
}

int main(){
 
 	LIST *head;
	init(&head);
	
	insert("Rei", &head);
	insert("Rook", &head);
	insert("Jiro", &head);
	insert("Raven", &head);
	show(head);
	
	printf("\n");
	
	edit(&head, "Rei", "Lao");
	edit(&head, "Raven", "Bayon");
	show(head);
	
	printf("\n");
	delete(&head, "Jiro");
	show(head);
	
	free(head);
}

