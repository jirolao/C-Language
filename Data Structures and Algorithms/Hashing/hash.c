#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node {
    int elem;
    struct node *next;
} *SET;

typedef SET Dictionary[MAX];
typedef enum { TRUE, FALSE } Boolean;

void initDictionary(Dictionary x);
void displayDictionary(Dictionary x);
int hash(int num);
void insert(Dictionary x, int num);
Boolean isMember(Dictionary x, int num);
void deleteElement(Dictionary x, int num);

int main() {
    Dictionary A;
    initDictionary(A);
    
    // Inserting elements into dictionary A
    insert(A, 5);
    insert(A, 15);
    insert(A, 25);
    insert(A, 35);
    insert(A, 45);
    
    // Displaying dictionary A after insertion
    printf("Dictionary A after insertion:\n");
    displayDictionary(A);
    
    // Checking if 15 is a member of dictionary A
    if (isMember(A, 15))
        printf("15 is a member of dictionary A.\n");
    else
        printf("15 is not a member of dictionary A.\n");
    
    // Checking if 100 is a member of dictionary A
    if (isMember(A, 100))
        printf("100 is a member of dictionary A.\n");
    else
        printf("100 is not a member of dictionary A.\n");
    
    // Deleting elements from dictionary A
    deleteElement(A, 15); // Element exists
    deleteElement(A, 100); // Element does not exist
    
    // Displaying dictionary A after deletion
    printf("Dictionary A after deletion:\n");
    displayDictionary(A);
    
    return 0;
}

void initDictionary(Dictionary x) {
    int i;
    for (i = 0; i < MAX; i++) {
        x[i] = NULL;
    }
}

void displayDictionary(Dictionary x) {
    int i;
    printf("SET #\tElements\n\n");
    for (i = 0; i < MAX; i++) {
        SET current = x[i];
        printf("%d\t", i);
        if (current == NULL) {
            printf("NULL\n");
        } else {
            while (current != NULL) {
                printf("%d ", current->elem);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int hash(int num) {
    return num % 10;
}

void insert(Dictionary x, int num) {
    int index = hash(num);
    SET temp = malloc(sizeof(struct node));
    temp->elem = num;
    temp->next = x[index];
    x[index] = temp;
}

Boolean isMember(Dictionary x, int num) {
    int index = hash(num);
    SET current = x[index];
    while (current != NULL) {
        if (current->elem == num)
            return TRUE;
        current = current->next;
    }
    return FALSE;
}

void deleteElement(Dictionary x, int num) {
    int index = hash(num);
    SET current = x[index];
    SET previous = NULL;
    while (current != NULL) {
        if (current->elem == num) {
            if (previous == NULL) {
                x[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%d deleted from dictionary.\n", num);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%d not found in dictionary.\n", num);
}







