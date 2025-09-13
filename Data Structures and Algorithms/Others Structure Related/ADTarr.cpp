#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int arr[MAX];
	int count;
} *List, node;

typedef enum {
	TRUE, FALSE
} boolean;

// Function declarations
void init(List *);
List insertFirst(List, int);
void insertLast(List, int);
void insertSorted(List, int);
void deleteFirst(List);
void deleteLast(List);
void deletealloccur(List, int);
boolean isMember(List, int);
void Display(List);

int main() {
	List sample = NULL;
	init(&sample);

	int ctr, arr[10] = {123, 534, 423, 23, 6, 23, 5253, 642, 36, 23};

	// Uncomment one of the insertion methods to test:
	// for (ctr = 0; ctr < 10; ctr++) sample = insertFirst(sample, arr[ctr]);
	// for (ctr = 0; ctr < 10; ctr++) insertLast(sample, arr[ctr]);
	for (ctr = 0; ctr < 10; ctr++) insertSorted(sample, arr[ctr]);

	Display(sample);

	deleteFirst(sample);
	Display(sample);

	deleteLast(sample);
	Display(sample);

	deletealloccur(sample, 23);
	Display(sample);

	printf("%s\n", (isMember(sample, 23) == TRUE) ? "TRUE" : "FALSE");

	return 0;
}

void init(List *L) {
	*L = (List)malloc(sizeof(node));
	(*L)->count = 0;
}

List insertFirst(List L, int x) {
	if (L->count < MAX) {
		L->arr[L->count++] = x;
	}
	return L;
}

void insertLast(List L, int x) {
	if (L->count < MAX) {
		for (int ctr = L->count; ctr > 0; ctr--) {
			L->arr[ctr] = L->arr[ctr - 1];
		}
		L->arr[0] = x;
		L->count++;
	}
}

void insertSorted(List L, int x) {
	if (L->count < MAX) {
		int ctr = L->count;
		while (ctr > 0 && L->arr[ctr - 1] > x) {
			L->arr[ctr] = L->arr[ctr - 1];
			ctr--;
		}
		L->arr[ctr] = x;
		L->count++;
	}
}

void deleteFirst(List L) {
	if (L->count > 0) {
		L->count--;
	}
}

void deleteLast(List L) {
	if (L->count > 0) {
		for (int ctr = 0; ctr < L->count - 1; ctr++) {
			L->arr[ctr] = L->arr[ctr + 1];
		}
		L->count--;
	}
}

void deletealloccur(List L, int x) {
	if (L->count > 0) {
		for (int ctr = 0; ctr < L->count;) {
			if (L->arr[ctr] == x) {
				for (int ctr2 = ctr; ctr2 < L->count - 1; ctr2++) {
					L->arr[ctr2] = L->arr[ctr2 + 1];
				}
				L->count--;
			} else {
				ctr++;
			}
		}
	}
}

boolean isMember(List L, int x) {
	for (int ctr = 0; ctr < L->count; ctr++) {
		if (L->arr[ctr] == x) return TRUE;
	}
	return FALSE;
}

void Display(List L) {
	if (L->count > 0) {
		printf("The values of the array are: %d", L->arr[0]);
		for (int ctr = 1; ctr < L->count; ctr++) {
			printf(", %d", L->arr[ctr]);
		}
		printf("\n");
	} else {
		printf("List is empty.\n");
	}
}

