#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char elem;
	int link;
}Node;

typedef struct {
	Node *nodes;
	int avail;
}VHeap;

typedef struct {
	VHeap *VH;
	CList front;
	CList rear;
}Queue;

typedef int CList;

typedef enum { TRUE, FALSE }Bool;


void initVHeap(VHeap **VH);
void initList(CList **L);
void initQueue(Queue **Q);
Bool isFull(Queue Q);
Bool isEmpty(Queue Q);
void enqueue(Queue **Q);
void dequeue(Queue **Q);
char front(Queue Q);

int main(){
	VHeap VH;
	CList List;
	
	initVHeap(&VH);
	initList(&List);
	
	
}

void initVHeap(VHeap **VH){
	*VH = malloc(sizeof(VHeap));

}

void initList(CList *L){

}

void initQueue(Queue *Q) {
	
}
