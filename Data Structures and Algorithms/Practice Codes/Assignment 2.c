#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int num;
    struct node *link;
}*LL;

void insert(LL *s, int data);
void init(LL *s);
LL popFactors(LL *s, int Seth);

int main(){
	LL s;
	init(&s);
	
	insert(&s, 1);
	insert(&s, 2);
	insert(&s, 3);
	insert(&s, 4);
	insert(&s, 5);
	insert(&s, 6);
	insert(&s, 7);
	insert(&s, 8);
	insert(&s, 9);
	insert(&s, 10);
	LL newS = popFactors(&s, 8);
	
	LL trav;
	for(trav = s;trav != NULL; trav = trav->link){
		printf("%d\n", trav->num);
	}
	printf("\n");
	for(trav = newS;trav != NULL; trav = trav->link){
		printf("%d\n", trav->num);
	}

}

void init(LL *s){
	*s = NULL;
}

void insert(LL *s, int data){
	LL temp = malloc(sizeof(struct node));
	if(temp != NULL){
	temp->num = data;
	temp->link = *s;
	*s = temp;	
	}
}

LL popFactors(LL *s, int Seth){
	LL newStack = NULL, tempStack = NULL, tempNode;
	
	while(*s != NULL){
	if((Seth % (*s)->num) != 0){
		tempNode = malloc(sizeof(struct node));
		if(tempNode != NULL){
			tempNode->num = (*s)->num;
			tempNode->link = tempStack;
			tempStack = tempNode;
			}		
		}else{
			tempNode = malloc(sizeof(struct node));
			if(tempNode != NULL){
			tempNode->num = (*s)->num;
			tempNode->link = newStack;
			newStack = tempNode;
			}
		}
		*s = (*s)->link;
	}
	return newStack;
}
