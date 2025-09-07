#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*LIST;

void initialize(LIST *head);
void addNode(LIST **head, int num);
void insertFront(LIST **head, int num);
void printNode(LIST *head);

int main() {
    LIST *head;
    initialize(head);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);
    insertFront(&head, 9);
    insertFront(&head, 10);
    printNode(head);
    return 0;
}

void initialize(LIST *head){
    *head = NULL;
}

void addNode(LIST **head, int num){
    LIST *current = *head, temp;
    for(current; (*current) != NULL; current = &(*current)->next);
    temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = num;
        temp->next = NULL;
        (*current) = temp;
    }
    else{
        printf("ERROR IN ADDNODE");
    }
}

void printNode(LIST *head){
    LIST *current = head;
    for(current; (*current) != NULL; current = &(*current)->next){
        printf("%d\n", (*current)->data);
    }
}

void insertFront(LIST **head, int num){
    LIST *current = *head;
    LIST temp = malloc(sizeof(struct node));
    temp->next = (*current);
    temp->data = num;
    **head = temp;
}
