#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct node{
  char data[MAX];
  struct node *link;
}*LIST;


void init(LIST *L);
void insert(LIST *L, char *str);
void show(LIST L);
void del(LIST *L, char *str);
void edit(LIST *L, char *oldstr, char *newstr);


void init(LIST *L){
  *L = NULL;
}


void insert(LIST *L, char *str){
	LIST *trav;
	LIST newNode;
	for(trav = L;(*trav) != NULL;trav = &(*trav)->link);
	
	newNode = malloc(sizeof(struct node));
	strcpy(newNode->data, str);
	newNode->link = NULL;
	*trav = newNode;
}


void insertSorted(LIST *L, char *str){
	LIST *trav;
	LIST newNode;
	for(trav = L;(*trav) != NULL && strcmp((*trav)->data, str) < 0;trav = &(*trav)->link);
	
	newNode = malloc(sizeof(struct node));
	strcpy(newNode->data, str);
	newNode->link = (*trav);
	*trav = newNode;
}


void show(LIST L){
	
	while(L != NULL){
		printf("%s\n", L->data);
		L = L->link;
	}
}


void del(LIST *L, char *str){
	LIST *trav;
	
	for(trav = L;(*trav) != NULL && strcmp((*trav)->data, str) != 0; trav = &(*trav)->link);

		*trav = (*trav)->link;
		 
}


void edit(LIST *L, char *oldstr, char *newstr){
	LIST *trav;
	for(trav = L;(*trav) != NULL && strcmp((*trav)->data, oldstr) != 0; trav = &(*trav)->link);
	strcpy((*trav)->data, newstr);
	
}


int main(){
  LIST *head;	//creates root for a linked list
  init(&head);	//gives the root value of NULL

  insert(&head, "Rei");
  insert(&head, "Seth");
  insert(&head, "Zeus");
  show(head);
  
  printf("\n");
  
  insertSorted(&head, "Farah");
  insertSorted(&head, "Sakura");
  show(head);
  
  printf("\n");
  
  del(&head, "Seth");
  show(head);
  
  printf("\n");
  
  edit(&head, "Sakura", "Seth");
  show(head);
  
  

}
