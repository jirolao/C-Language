#include <stdio.h>
#define MAX 10

typedef char Type;
typedef int Position;
typedef int List;

typedef struct{
    Type elem;
    Position next;
}NodeType;

typedef struct{
    NodeType data[MAX];
    Position avail;
}VSpace;

void initializeSpace(VSpace *vs);
void visualSpace(VSpace vs, List list);
void displayList(VSpace vs, List list);
void insertFront(VSpace *vs, List *list, Type item);
int allocateSpace(VSpace *vs);
int deallocateSpace(VSpace *vs, List list);
void deleteFront(VSpace *vs, List *list);
void reverseList(VSpace *vs, List *list);
void insertRear(VSpace *vs, List list, Type item);
int main() {
    List A = -1;
    VSpace vs;
    initializeSpace(&vs);
    // visualSpace(vs, A);
    // displayList(vs, A);

    insertFront(&vs, &A, 'A');
    insertFront(&vs, &A, 'B');
    // insertFront(&vs, &A, 'C');
    // insertFront(&vs, &A, 'D');
    // insertFront(&vs, &A, 'E');

    deleteFront(&vs, &A);
    deleteFront(&vs, &A);
    deleteFront(&vs, &A);
    
    insertFront(&vs, &A, 'C');
    insertFront(&vs, &A, 'D');
    insertFront(&vs, &A, 'E');
    insertFront(&vs, &A, 'C');
    insertFront(&vs, &A, 'D');
    insertFront(&vs, &A, 'E');
    

    // reverseList(&vs, &A);
    // insertRear(&vs, A, 'F');
    visualSpace(vs, A);
    displayList(vs, A);
}
void initializeSpace(VSpace *vs){
    int x;
    for(x = MAX-1 ; x >= 0; --x) {
        vs->data[x].next = x - 1;
        vs->data[x].elem = ' ';
    }
    vs->avail = MAX-1;
}
void visualSpace(VSpace vs, List list){
    int x;
    printf("\n%18s", "Virtual Space");
    printf("\n________________________\n");
    printf("|%5s | %5s | %5s |\n", "INDX", "ELEM", "NEXT");
    for(x=0; x<MAX; x++)
        if(list == x) 
            printf("|%5d | %5c | %5d |  <---- List Starts Here (%d)\n", x, vs.data[x].elem, vs.data[x].next, x);
        else
            printf("|%5d | %5c | %5d |\n", x, vs.data[x].elem, vs.data[x].next);

    printf("|______|_______|_______|\n");
    switch (vs.avail) {
    case 3:
        printf("Available: %drd index\n", vs.avail);
        break;
    case 2:
        printf("Available: %dnd index\n", vs.avail);
        break;
    case 1:
        printf("Available: %dst index\n", vs.avail);
        break;
    case -1:
        printf("Available: %dst index [Not available]\n", vs.avail);
        break;
    default:
        printf("Available: %dth index\n", vs.avail);
        break;
    }
}
void displayList(VSpace vs, List list){
    int x;
    printf("List: %d    [", list);
    for(x = list; x > 0; x = vs.data[x].next){
        printf("%c", vs.data[x].elem);
        if(vs.data[x].next != -1){
            printf(", ");
        }
    }
    printf("] [(in-order)]\n");
}
void insertFront(VSpace *vs, List *list, Type item) {
    int getSpace = allocateSpace(vs);
    if (getSpace != -1) {
        vs->data[getSpace].elem = item;
        vs->data[getSpace].next = *list;
        *list = getSpace;
    }
}
int allocateSpace(VSpace *vs) {
    Position availSpace = vs->avail;
    if (availSpace != -1) {
        vs->avail = vs->data[availSpace].next;
    }
    return availSpace;
}
int deallocateSpace(VSpace *vs, List list) {
    Position removeSpace = list;
    if (removeSpace != -1) {
        vs->avail = removeSpace;
    }
    return (removeSpace != -1)? vs->data[removeSpace].next: -1;
}

void deleteFront(VSpace *vs, List *list) {
    *list = deallocateSpace(vs, *list);
    vs->data[vs->avail].elem = ' ';
    
}
void reverseList(VSpace *vs, List *list) {
    int totalInTheList = MAX - (*list);
    int y = MAX - 1;
    int z = MAX;
    for(int x = totalInTheList; x > 0; x--) {
        if (x == 1) {
            vs->data[y].next = -1;
        }
        vs->data[z].next = y--;
        z--;
    }
    *list = MAX - 1;
}
void insertRear(VSpace *vs, List list, Type item) {
    int getSpace = allocateSpace(vs);
    if (getSpace != -1) {
        int totalInTheList = MAX - list;
        
    }
}










