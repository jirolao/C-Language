#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node *link;
}*nodePtr, node;

void insertFirst(nodePtr *A, char elem) {
    puts("----------------------------");
    printf("%24s\n","INSERT FIRST");
    printf("[The parameters Address: %p, %p]\n", &A, &elem);
    printf("[The parameters Values: %p, %c]\n", A, elem);
    printf("[The parameters *Values: %p]\n", *A);   //Since the "nodePtr *A" is a Double pointer. This code makes sense
    node *temp = (nodePtr)malloc(sizeof(node));
    /*
        a.) node *temp =   (node*)   malloc(sizeof (node));    
        b.) node *temp =             malloc(sizeof (node));   
        c.) nodePtr temp =           malloc(sizeof (node));
        d.) nodePtr temp = (node*)   malloc(sizeof (node));
        e.) nodePtr temp = (nodePtr) malloc(sizeof (node));

        Description: All of it above are still correct. The only difference is the cast type. It
        is not stricly needed but for sure, adding cast type won't hurt.
    */
    if (temp != NULL) {
        temp->elem = elem;
        temp->link = *A;
        *A = temp;

        printf("&temp: %p\n", &temp);                   //Address of temp
        printf("temp: %p\n", temp);                     // value of temp
        //printf("*temp: %c\n", *temp); // This code won't make sense, Only works if it's a double pointer
        printf("&temp->elem: %p\n", &temp->elem);       //Address of elem
        printf("&temp->link: %p\n", &temp->link);       //Address of link
        printf("temp->elem: %c\n", temp->elem);         //Value of elem
        printf("temp->link: %p\n", temp->link);         //Value of link
    }
}
void insertSorted(nodePtr *A, char elem) {
    puts("----------------------------");
    printf("%20s\n", "INSERTSORTED");
    nodePtr *trav, temp;
    int how_many_times_it_traverses = 1;
    for(trav = A; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->link) {
        printf("[%d] Value of trav: %p\n",how_many_times_it_traverses++, *trav);
        printf("%c < %c\n",(*trav)->elem, elem);
    }
    temp = malloc(sizeof(node));
    if (temp != NULL) {
        printf("*trav before: %p\n", *trav);
        temp->elem = elem;
        temp->link = *trav;
        *trav = temp;
        printf("*trav after: %p\n", *trav);
        printf("value temp->link: %p\n", temp->link);        
    }  
}
void display(nodePtr A) {
    printf("Linked List: ");
    while (A != NULL) {
        printf("%c -> ", A->elem);
        A = A->link;
    }
    printf("NULL\n");
}

int main() {
    nodePtr A = NULL;
    printf("&A: %p\n", &A);
    printf("A: %p\n", A);

    insertFirst(&A, 'I');
    insertFirst(&A, 'E');
    insertFirst(&A, 'B');
    insertSorted(&A, 'G');
    insertSorted(&A, 'A');

    display(A);

}

/*
    The purpose for this program is to visualize where the pointer is pointing, holding and it's address and understanding PN and PPN Fully.

    To understand fully. Visit https://pythontutor.com/visualize.html#mode=edit
    Make sure to set the "C/C++ details: none[default view] to show memory addresses"

    If the program can't run because of "Error! your code/input is 5663 URL-encoded bytes...." remove this comment and other comments when necessary.
    
    Make sure you draw as you do step by step for this program. Include writing the address of it.

    If you have any questions feel free to chat me - Cecil Quibranza

    Note: PN: Pointer to Node
          PPN: Pointer to Pointer Node
*/