#include <stdio.h>

#define MAX 20
typedef struct {
	char Fname[16];
	char Lname[24];
	char Mi;
	int link;
}Name;
typedef struct {
	Name nametype[MAX];
	int Avail;
}Vheap;

typedef int Clist;

void initList(Clist *l) {
	*l = -1;
}

void initHeap(Vheap* V) {
	int x;
	int m = MAX-1;
	for(x = 0; x < m; x++) {
		V->nametype[x].link = x+1;
	}
	V->nametype[m].link = -1;
	V->Avail = 0;
}

void printHeap(Vheap L, Clist n) {
	int x;
	for(x = n; x != -1; x = L.nametype[x].link) {
		printf("%c", L.nametype[x].Mi);
	}
}
int allocSpace(Vheap* VH) {
	int curIndx = VH->Avail;
	if(curIndx != -1) {
		VH->Avail = VH->nametype[curIndx].link;
	}
	return curIndx;
}

void insertFirst(Vheap *a, char let, Clist* L) {
	Clist temp = allocSpace(a);
	if(temp != -1) {
		a->nametype[temp].Mi = let;
		a->nametype[temp].link = *L;
		*L = temp;
	}
}

void deallocSpace(Vheap* V, Clist* L) {
	if(*L !=-1) { //check if Clist is available
		V->nametype[*L].link = V->Avail; //.link will get the value of the first available index to use or do
		V->Avail = *L; //Avail will then get the value of *L
	}
}
int main() {
	Vheap A;
	Clist num;
	initList(&num);
	initHeap(&A);
	insertFirst(&A,'3', &num);
	insertFirst(&A,'<', &num);
	insertFirst(&A,'n', &num); //2 since its insert first and this is first declared, it will be index 0
	insertFirst(&A,'o', &num); //1 this will now be index 0 as it pushes 'c' at the left side
	insertFirst(&A,'o', &num); //0 this will now be index 0 as it then push 's' at the left side
	insertFirst(&A,'s', &num);
	insertFirst(&A,' ', &num);
	insertFirst(&A,'l', &num);
	insertFirst(&A,'l', &num);
	insertFirst(&A,'e', &num);
	insertFirst(&A,'w', &num);
	insertFirst(&A,' ', &num);
	insertFirst(&A,'t', &num);
	insertFirst(&A,'e', &num);
	insertFirst(&A,'g', &num);
	printHeap(A, num);
	return 0;
}
