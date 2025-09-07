#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *link;
}*LINK;

LINK populate(LINK A1);
LINK getEven(LINK A1);
void display(LINK A1);
void deleteFront(LINK *A1);

int main() {

    LINK A = NULL;
    puts("-----------------------");
    printf("| A Address: %p |\n", &A);
    puts("-----------------------");
    A = populate(A);
    system("Pause");

    // LINK B = getEven(A);
    // system("Pause");
    printf("Displaying A...\n");
    display(A);

    // system("Pause");
    // printf("Displaying B...\n");
    // display(B);

    deleteFront(&A);


    return 0;
}
LINK populate(LINK A1) {
    printf("\nPopulating...\n");
    LINK T = NULL;
    printf("| Address of T: %p %20c\n", &T, '|');
    printf("|-------------------------------------------|\n");
    for(int x=0; x<5; x++) {
        T = (LINK)malloc(sizeof(struct node));
        printf("| [%.01d] %s %34c\n", x, "NODE", '|');
        printf("| Address of new node created: %12p %c\n", T, '|');
        printf("| Address of T->elem: %21p %c\n", &(T->elem), '|');
        printf("| Address of T->link: %21p %c\n", &(T->link), '|');
        if (T != NULL) {
            T->elem = x + 1;
            T->link = A1;
            A1 = T;
            printf("| T->link is pointing: %20p %c\n\n",(T->link), '|');
        }
        printf("|-------------------------------------------|\n");
    }
    printf("| DESCRIPTION: %30c\n",'|');
    printf("| T->LINK POINTING IS POINTING ABOVE EACH   |\n");
    printf("| OTHER AND IF THERE IS NO NODE ABOVE, THEN |\n");
    printf("| IT IS NULL. [ Illustration purpose only]  |\n");
    printf("\nPopulating Complete\n");
    return A1;
}
LINK getEven(LINK A1) {
    printf("Get even numbers...\n");
    LINK Trav, Temp, Even = NULL;
    if(A1 != NULL) {
        for(Trav = A1; Trav != NULL; Trav = Trav->link) {
            if(Trav->elem % 2 == 0) {
                Temp = (LINK) malloc (sizeof(struct node));
                Temp->elem = Trav->elem;
                Temp->link = Even;
                Even = Temp;
            }
        }
    }
    printf("Get even numbers complete\n");
    return Even;
}
void display(LINK A1) {
    printf("\nDisplaying...\n");
    LINK Trav = A1;

    if (Trav == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    while (Trav != NULL) {
        printf("Node Address: %p <-----|\n", Trav);
        printf("Element: %d\n", Trav->elem);
        printf("Link Address: %p ------|\n", Trav->link);
        printf("----------------------       |\n");
        Trav = Trav->link;
    }

    printf("Display Complete\n");
}
void deleteFront(LINK *A1) {
    LINK *DEL = A1;
    printf("Deleting Front of the linked list...\n");
    puts("--------------------------------------------------");
    printf("| &DEL Address: %p | &A1 Address: %p |\n", &DEL, &A1);
    printf("| *DEL Address: %p | *A1 Address: %p |\n", *DEL, *A1);
    printf("| DEL Address: %p  | A1 Address: %p  |\n", DEL, A1);
    puts("--------------------------------------------------");
    if (*DEL != NULL) {
        
    }
}


