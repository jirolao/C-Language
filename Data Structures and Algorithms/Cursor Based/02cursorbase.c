#include <stdio.h>
#define MAX 5

typedef struct node{
    char elem;
    int link;
}node;

typedef struct VH{
    node Rec[MAX];
    int available;
}VH;
typedef int CList;

void initHeap(VH *T);
void displayHeap(VH T, CList A);
int allocSpace(VH *T, CList *A);
void insertFirst(VH *T, CList *A, char elem);
void removeChar(VH *T, CList *A, char elem);
void deallocSpace(VH *T, int temp);
void deleteFirst(VH *T, CList *A);
void insertLast(VH *T, CList *A, char elem);
void displayList(VH T, CList A);
void mergeList(VH *T, CList *A, CList *B, CList *C);
void insertSorted(VH *T, CList *A, char elem);
int main() {

    VH T;
    CList A = -1;
    CList B = -1;
    CList C = -1;
    printf("\n&T: %p\n", &T);
    printf("&A: %p\n", &A);
    printf("&B: %p\n", &B);
    initHeap(&T);

    insertFirst(&T, &A, 'A');
    insertFirst(&T, &A, 'B');
    insertFirst(&T, &B, 'Z');

    removeChar(&T, &A, 'B');
    insertFirst(&T, &B, 'O');
    insertFirst(&T, &A, 'E');
    insertFirst(&T, &A, 'P');
    deleteFirst(&T, &A);

    deleteFirst(&T, &A);
    deleteFirst(&T, &A);

    insertLast(&T, &A, 'C');
    insertLast(&T, &B, 'E');
    insertLast(&T, &A, 'I');
    displayHeap(T, A);
    
    mergeList(&T, &A, &B, &C);

    displayHeap(T, A);
    printf("[%d] A: ", A);
    displayList(T, A);
    printf("\n[%d] B: ", B);
    displayList(T, B);
    printf("\n[%d] C: ", C);
    displayList(T, C);
    printf("\n\nEND\n");
    return 0;
}

void initHeap(VH *T) {
    int x;
    puts("---------------------------");
    printf("|     &node      &link    |\n");
    for(x = 0; x < MAX; x++) {
        T->Rec[x].elem = ' ';
        T->Rec[x].link = x - 1;
        printf("| [%d] %p | %p |\n", x, &(T->Rec[x]), &(T->Rec[x].link));
    }
    puts("---------------------------");
    T->available = x-1;
}
void displayHeap(VH T, CList A) {;
    printf("+-------+---------+-------+\n");
    printf("| Index | Element |  Link |\n");
    printf("+-------+---------+-------+\n");
    for(int i = 0; i < MAX; i++) {
        printf("| %-5d | %-7c | %-5d |\n", i, T.Rec[i].elem, T.Rec[i].link);
    }
    printf("+-------+---------+-------+\n");
    printf("Available: %d\n", T.available);
}
int allocSpace(VH *T, CList *A) {
    int getSpace = T->available;
    if (getSpace != -1) {
        T->available = T->Rec[getSpace].link;
    }
    return (getSpace != -1)? getSpace : -1;
}
void insertFirst(VH *T, CList *A, char elem) {
    int getSpace = allocSpace(T, A);
    if (getSpace != -1) {
        T->Rec[getSpace].elem = elem;
        T->Rec[getSpace].link = *A;
        *A = getSpace;
    }
}
void removeChar(VH *T, CList *A, char elem) {
    if (*A != -1) {
        int *trav, temp;
        for (trav = A; *trav != -1 && T->Rec[*trav].elem != elem; trav = &T->Rec[*trav].link) { }
        if(*trav != -1) {
            temp = *trav;
            *trav = T->Rec[*trav].link;
            deallocSpace(T, temp);
        }
        // printf("temp: %d\n", temp);
        // printf("trav pointing to: %p\n", trav);
        // printf("trav value: %d\n", *trav);
    }
}
void deallocSpace(VH *T, int temp) {
    T->Rec[temp].link = T->available;
    T->available = temp;
    T->Rec[temp].elem = ' ';
}
void deleteFirst(VH *T, CList *A) {
    if (*A != -1) {
        int temp = *A;
        *A = T->Rec[temp].link;
        deallocSpace(T, temp);
    }
}
void insertLast(VH *T, CList *A, char elem) {
    int getSpace = allocSpace(T, A);
    if (getSpace != -1) {
        int *x;
        for(x = A; T->Rec[*x].link != -1; x = &T->Rec[*x].link) {}
        T->Rec[getSpace].elem = elem;
        T->Rec[getSpace].link = -1;
        T->Rec[*x].link = getSpace;
    }
}
void displayList(VH T, CList A) {
    int x, stopper = 0; // To stop infinite loop incase it fails;
    for(x = A; x != -1 && stopper < MAX; x = T.Rec[x].link, stopper++) {
        printf("%c", T.Rec[x].elem);
        if (T.Rec[x].link != -1) {
            printf(" -> ");
        }
    }
}
void mergeList(VH *T, CList *A, CList *B, CList *C) {
    if (*A != -1 && *B != -1) {
        int *x;
        for(x = A; T->Rec[*x].link != -1; x = &T->Rec[*x].link) { }
        T->Rec[*x].link = *B;
        *C = *A;
        *A = *B = -1;
    }
}
void insertSorted(VH *T, CList *A, char elem) {
    
}






