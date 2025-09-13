#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	char elem;
	int link;
}NodeType;

typedef struct{
	NodeType Nodes[MAX];
	int avail;
}VirtualHeap;

typedef int CList;

void init(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void printList(VirtualHeap VH, CList L);
void insertFirst(VirtualHeap *VH, CList *L, char data);
void insertLast(VirtualHeap *VH, CList *L, char data);
void insertPos(VirtualHeap *VH, CList *L, int pos, char data);
void deleteElem(VirtualHeap *VH, CList *L, char data);
void retrieve(VirtualHeap VH, CList L, char data);
void sortBubble(VirtualHeap *VH, CList *L);
void makeNull(VirtualHeap *VH, CList *L);

int main(){
	VirtualHeap VH;
	CList L;
	init(&VH);
	
	insertLast(&VH, &L, 'A');
	insertLast(&VH, &L, 'B');
	insertFirst(&VH, &L, 'F');
	insertLast(&VH, &L, 'C');
	insertPos(&VH, &L, 3, 'D');
	deleteElem(&VH, &L, 'D');
	printList(VH, L);
	retrieve(VH, L, 'F');
}

void init(VirtualHeap *VH){
	int trav;
	for(trav = 0;trav < MAX - 1; trav++){
		VH->Nodes[trav].link = trav + 1;	
	}
	VH->Nodes[trav].link = -1;
	VH->avail = 0;
}

int allocSpace(VirtualHeap *VH){
	int index = VH->avail;
	
	if(index != -1){
		VH->avail = VH->Nodes[index].link;
	}
		return index;
}

void insertLast(VirtualHeap *VH, CList *L, char data){
	CList *trav, temp;
	temp = allocSpace(VH);
	
	if(temp != -1){
	for(trav = L; *trav != -1; trav = &VH->Nodes[*trav].link){}
		VH->Nodes[temp].elem = data;
        VH->Nodes[temp].link = -1;
        *trav = temp;
	}
}

void insertFirst(VirtualHeap *VH, CList *L, char data){
	CList temp = allocSpace(VH);
	if(temp != -1){
		VH->Nodes[temp].elem = data;
		VH->Nodes[temp].link = *L;
		*L = temp;	
	}
}

void insertPos(VirtualHeap *VH, CList *L, int pos, char data) {
    CList *trav, temp, prev;
    temp = allocSpace(VH);
    
    if (temp != -1) {
        if (pos >= 0 && pos < MAX) {
            if (pos == 0) { 
                insertFirst(VH, L, data);
            } else {
                prev = -1; // Initialize prev to -1 before the loop
                for (trav = L; *trav != -1 && pos > 0; prev = *trav, trav = &VH->Nodes[*trav].link, pos--) {}
                if (*trav != -1) { // If the loop stopped before reaching the end of the list
                    VH->Nodes[temp].elem = data;
                    VH->Nodes[temp].link = *trav;
                    if (prev != -1) { // If prev is valid (not -1), update its link
                        VH->Nodes[prev].link = temp;
                    } else { // If prev is -1, update the list pointer
                        *L = temp;
                    }
                } 
            }
        } 
    }
}

void deleteElem(VirtualHeap *VH, CList *L, char data){
	CList *trav, temp;
	if(*L != -1){
		for(trav = L;*trav != -1 && VH->Nodes[*trav].elem != data;trav = &VH->Nodes[*trav].link){}
			temp = *trav;
    		*trav = VH->Nodes[*trav].link;
    		VH->Nodes[temp].link = VH->avail;
    		VH->avail = temp;
	}
}

void retrieve(VirtualHeap VH, CList L, char data){
	CList trav;
	if(L != -1){
		for(trav = L; trav != -1;trav = VH.Nodes[trav].link){
		if(VH.Nodes[trav].elem == data){
			printf("Retrieved Data: %c", data);
			}
		}
	}
}


void makeNull(VirtualHeap *VH, CList *L){
    while (*L != -1) {
        deleteElem(VH, L, 0);
    }
}

void sortBubble(VirtualHeap *VH, CList *L) {
    int swapped;
    CList ptr1, ptr2 = -1;

    if (*L == -1) {
    while (swapped) {
        swapped = 0;
        ptr1 = *L;

        for (; VH->Nodes[ptr1].link != ptr2; ptr1 = VH->Nodes[ptr1].link) {
            CList nextNode = VH->Nodes[ptr1].link;

            if (VH->Nodes[ptr1].elem > VH->Nodes[nextNode].elem) {
                // Swap elements
                char temp = VH->Nodes[ptr1].elem;
                VH->Nodes[ptr1].elem = VH->Nodes[nextNode].elem;
                VH->Nodes[nextNode].elem = temp;
                swapped = 1;
            	}
        	}
        	ptr2 = ptr1;
   		}
	}
}

void printList(VirtualHeap VH, CList L){
	CList trav;
	
	for(trav = L;trav != -1; trav = VH.Nodes[trav].link){
	printf("%c\n", VH.Nodes[trav].elem);
	}
}


