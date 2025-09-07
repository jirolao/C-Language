#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
} node, *nodePtr;

void display(nodePtr A) {
    printf("\n%s %8s %10s %15s %18s %8s %23s %8s %18s\n", "NODE", "||", "CHAR", "||", "ADDRESS NEXT", "||", "NEXT IS POINTING", "||", "ADDRESS NODE");
    for (int count = 0; A != NULL; A = A->next) {
        printf("%02d %10s %7c (%p)%8s %13s (%p) %s %14s (%p) %6s %14p\n", count++, "||", A->data, (void*)&A->data, "||", "pointer", (void*)&A->next, "||", "pointer", (void*)A->next, "||", (void*)A);
    }
}

void insertFirst(nodePtr* A, char C) {
    nodePtr temp = malloc(sizeof(node));
    if (temp != NULL) {
        temp->data = C;
        temp->next = *A;
        *A = temp;
    }
}

void deleteFirst(nodePtr* A) {
    if (*A != NULL) {
        nodePtr temp = *A;
        *A = (*A)->next;
        free(temp);
    }
}

void deleteOccurrence(nodePtr* A) {
    int count = 0;
    nodePtr prev = NULL;
    nodePtr current = *A;

    printf("\nInput how much kinds of characters to delete: ");
    scanf("%d", &count);

    if (count != 0) {
        char select[count];
        printf("Input %d chars to delete: ", count);

        for (int i = 0; i < count; i++)
            scanf(" %c", &select[i]);

        while (current != NULL) {
            int deleteCurrent = 0;

            for (int j = 0; j < count; j++) {
                if (current->data == select[j]) {
                    deleteCurrent = 1;
                    break;
                }
            }

            if (deleteCurrent) {
                if (prev == NULL) {
                    // Delete the first node
                    *A = current->next;
                    free(current);
                    current = *A;
                } else {
                    prev->next = current->next;
                    free(current);
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

void deleteSpecific(nodePtr* A) {
    nodePtr* trav = A;
    if(*A != NULL) {
        for(;trav != NULL && (*trav)->data != 'a' && (*trav)->data != 'c'; *trav = (*trav)->next) { }
    }
}

int main() {
    nodePtr A = NULL;

    insertFirst(&A, 'a');
    insertFirst(&A, 'b');
    insertFirst(&A, 'c');
    insertFirst(&A, 'd');
    insertFirst(&A, 'e');
    insertFirst(&A, 'f');

    printf("Original list:");
    display(A);

    // deleteOccurrence(&A);
    deleteSpecific(&A);

    printf("\nList after deletion:");
    display(A);

    return 0;
}
