#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Author: Jonaz Juan Sayson (Sky)

typedef struct {
	int data;
	int link;
}NodeType;

typedef struct {
	NodeType arr[MAX];
	int avail;
}Vheap;

typedef int CList;
typedef CList myDict[MAX];
typedef enum {TRUE, FALSE} Boolean;

//init dictionary, and vheap; Vheap memory operations - alloc, dealloc; Open hashing operations

//memory management
void initVheap(Vheap *VH);
int allocSpace(Vheap *VH);
void deallocSpace(Vheap *VH, int elem);

//dictionary functions
void initDict(myDict A);
void insertSorted(myDict A, Vheap *myHeap, int elem);
void deleteElem(myDict A, Vheap *myHeap, int elem);
void display(myDict A, Vheap myHeap);
int hash(int elem);
Boolean isMember(myDict A, Vheap myHeap, int elem);
void displayVHEAP(Vheap VH, CList myList);

int main() 
{
	CList myList = 0;
	myDict A;
	Vheap VH;
	Boolean check;
	
	printf("OPERATIONS PERFORMED:\n");
	initVheap(&VH);
	initDict(A);
	insertSorted(A, &VH, 4);
	insertSorted(A, &VH, 44);
	insertSorted(A, &VH, 4444);
	insertSorted(A, &VH, 522);
	insertSorted(A, &VH, 12);
	deleteElem(A, &VH, 12);
	insertSorted(A, &VH, 12);
	
	//check if isMember is working 
	int checkElem = 69;
	check = isMember(A, VH, checkElem);
	if(check == TRUE) {
		printf(" ELEM %d EXISTS\n\n", checkElem);
	} else {
		printf(" ELEM %d DOESN'T EXIST\n\n", checkElem);
	}
	
	
	printf("Dictionary Display\n");
	display(A, VH);
}
//memory management
void initVheap(Vheap *VH)
{
	int x;
	for(x = 0; x < MAX; x++) {
		VH->arr[x].link = x+1;
	}
	VH->arr[MAX-1].link = -1;
	VH->avail = 0;
}
int allocSpace(Vheap *VH) 
{
	int temp = VH->avail;
	VH->avail = VH->arr[VH->avail].link;
	
	return temp;
}

void deallocSpace(Vheap *VH, int elem)
{
	if(elem < MAX) {
		VH->arr[elem].link = VH->avail;
		VH->avail = elem;
	} else {
		printf(" ELEM is outofbounds \n\n");
	}
} 

void displayVHEAP(Vheap VH, CList List) 
{
	int trav;
	for(trav = List; trav != -1; trav=VH.arr[trav].link){
		printf("[%d] %d \n", trav,VH.arr[trav].link);
	}
}

//dictionary functions
void initDict(myDict A)
{
	int x;
	for(x = 0; x < MAX; x++) {
		A[x] = -1;
	}
}
void insertSorted(myDict A, Vheap *myHeap, int elem) //Not allowed to call other functions except hash
{
	int hashVal = hash(elem), *trav;
	for(trav = &A[hashVal]; (*trav) != -1 && myHeap->arr[*trav].data < elem; trav=&myHeap->arr[*trav].link){}
	if((*trav) == -1 || myHeap->arr[*trav].data != elem) {
		int newNode = allocSpace(myHeap);
		if(newNode != -1) {
			myHeap->arr[newNode].data = elem;
			myHeap->arr[newNode].link = (*trav);
			(*trav) = newNode;
			printf(" INSERTED %d at index [%d]\n", elem, hashVal);
		}
	} else {
		printf(" ELEM %d already exists at index [%d]\n\n", elem, hashVal);
	}
}
void deleteElem(myDict A, Vheap *myHeap, int elem)
{
	int hashVal = hash(elem), *trav, temp;
	for(trav = &A[hashVal]; (*trav) != -1 && myHeap->arr[*trav].data != elem; trav = &myHeap->arr[*trav].link){}
		if((*trav) != -1) {
			temp = (*trav);
			(*trav) = myHeap->arr[*trav].link;
			deallocSpace(myHeap, temp);
			printf(" DELETED %d at index [%d]\n", elem, hashVal);
		}
}
void display(myDict A, Vheap myHeap)
{
	int x, trav;
	for(x = 0; x < MAX; x++) {
		printf("[%d] ", x);
		for(trav = A[x]; trav != -1; trav=myHeap.arr[trav].link) {
			printf("%d ", myHeap.arr[trav].data);
		}
		printf("\n");
	}
}
int hash(int elem)
{
	return elem % MAX;
}

Boolean isMember(myDict A, Vheap myHeap, int elem)
{
	int trav, hashVal = hash(elem);
	for(trav = A[hashVal]; trav != -1 && myHeap.arr[trav].data != elem; trav = myHeap.arr[trav].link){}
	
	return (trav != -1)? TRUE : FALSE;
}










