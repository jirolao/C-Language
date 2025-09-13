#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef struct node {
	int elem;
	struct node* next;
}*SET;

typedef SET Dictionary[MAX];

void initDictionary(Dictionary S);
void initList(SET* L);
int initHash(int num);
void insertFirst(Dictionary Dict, int eLem);
void display(Dictionary Dict);
int main() {
	Dictionary Lib;
	initDictionary(Lib);
	SET List;
	initList(&List);
//	int arr[5] = {40, 22, 91, 63, 23};
//	int x;
//	for(x = 0; x < MAX; x++) {
		insertFirst(Lib, 40);
		insertFirst(Lib, 20);
		insertFirst(Lib, 91);
		insertFirst(Lib, 53);
		insertFirst(Lib, 23);
	display(Lib);
	return 0;
}

void initDictionary(Dictionary S) {
	int x;
	for(x = 0; x < MAX; x++) {
		S[x] = NULL;
	}
}
void initList(SET* L) {
	*L = NULL;
}

void insertFirst(Dictionary Dict, int eLem) {
	int x = initHash(eLem);
	SET trav, temp;
	//for(trav = Dict[x]; trav != NULL;trav = trav->next){}
	  //if(trav == NULL) {
			temp = (SET)malloc(sizeof(struct node));
		if(temp != NULL) {
			temp->elem = eLem;
			temp->next = Dict[x];
			Dict[x] = temp;
		}
}
int initHash(int num) {
	return (num % MAX);
}
void display(Dictionary Dict) {
	int x;
	for(x = 0; x < MAX; x++) {
		printf("index %d: ", x);
	SET place;
	for(place = Dict[x]; place != NULL; place = place->next) {
		printf("%d\t", place->elem);
		}
		printf("\n");
	}
}

