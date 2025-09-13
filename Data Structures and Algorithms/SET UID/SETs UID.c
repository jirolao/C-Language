#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------- TYPE DEFINITION -----------
typedef struct node {
    char elem[10];
    struct node *link;
} *SET;

// ----------- FUNCTION PROTOTYPES -----------
void insert(SET *s, const char *value);
void printSet(SET s);
SET UNION(SET A, SET B);
SET INTERSECTION(SET A, SET B);
SET DIFFERENCE(SET A, SET B);

// ----------- MAIN FUNCTION -----------
int main() {
    SET A = NULL, B = NULL;
    
    // Manually insert in reverse sorted order to simulate sorted list
    insert(&A, "mango");
    insert(&A, "kiwi");
    insert(&A, "banana");
    insert(&A, "apple");

    insert(&B, "peach");
    insert(&B, "mango");
    insert(&B, "banana");

    printf("Set A: ");
    printSet(A);
    printf("Set B: ");
    printSet(B);

    SET unionSet = UNION(A, B);
    printf("\nUNION (A ? B): ");
    printSet(unionSet);

    SET intersectionSet = INTERSECTION(A, B);
    printf("INTERSECTION (A n B): ");
    printSet(intersectionSet);

    SET differenceSet = DIFFERENCE(A, B);
    printf("DIFFERENCE (A - B): ");
    printSet(differenceSet);

    return 0;
}

// ----------- FUNCTION DEFINITIONS -----------

void insert(SET *s, const char *value) {
    SET temp = (SET)malloc(sizeof(struct node));
    strcpy(temp->elem, value);
    temp->link = *s;
    *s = temp;
}

void printSet(SET s) {
    while (s != NULL) {
        printf("%s -> ", s->elem);
        s = s->link;
    }
    printf("NULL\n");
}

SET UNION(SET A, SET B) {
    SET C = NULL, temp;
    SET trav1, trav2;

    for (trav1 = A, trav2 = B; trav1 != NULL || trav2 != NULL;) {
        temp = (SET)malloc(sizeof(struct node));

        if (trav1 != NULL && trav2 != NULL) {
            int val = strcmp(trav1->elem, trav2->elem);
            if (val == 0) {
                strcpy(temp->elem, trav1->elem);
                trav1 = trav1->link;
                trav2 = trav2->link;
            } else if (val < 0) {
                strcpy(temp->elem, trav1->elem);
                trav1 = trav1->link;
            } else {
                strcpy(temp->elem, trav2->elem);
                trav2 = trav2->link;
            }
        } else if (trav1 != NULL) {
            strcpy(temp->elem, trav1->elem);
            trav1 = trav1->link;
        } else {
            strcpy(temp->elem, trav2->elem);
            trav2 = trav2->link;
        }

        temp->link = C;
        C = temp;
    }

    return C;
}

SET INTERSECTION(SET A, SET B) {
    SET C = NULL;
    SET trav1, trav2, temp;

    for (trav1 = A, trav2 = B; trav1 != NULL && trav2 != NULL;) {
        int val = strcmp(trav1->elem, trav2->elem);
        if (val == 0) {
            temp = (SET)malloc(sizeof(struct node));
            strcpy(temp->elem, trav1->elem);
            temp->link = C;
            C = temp;
            trav1 = trav1->link;
            trav2 = trav2->link;
        } else if (val < 0) {
            trav1 = trav1->link;
        } else {
            trav2 = trav2->link;
        }
    }

    return C;
}

SET DIFFERENCE(SET A, SET B) {
    SET C = NULL;
    SET trav1, trav2, temp;

    for (trav1 = A, trav2 = B; trav1 != NULL && trav2 != NULL;) {
        int val = strcmp(trav1->elem, trav2->elem);
        if (val == 0) {
            trav1 = trav1->link;
            trav2 = trav2->link;
        } else if (val < 0) {
            temp = (SET)malloc(sizeof(struct node));
            strcpy(temp->elem, trav1->elem);
            temp->link = C;
            C = temp;
            trav1 = trav1->link;
        } else {
            trav2 = trav2->link;
        }
    }

    while (trav1 != NULL) {
        temp = (SET)malloc(sizeof(struct node));
        strcpy(temp->elem, trav1->elem);
        temp->link = C;
        C = temp;
        trav1 = trav1->link;
    }

    return C;
}

