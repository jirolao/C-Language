#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 0xF


typedef char Switch[4]; // either ON or OFF

typedef Switch Set[SIZE];

void init(Set S);
void insert(Set S, int elem);
void delete(Set S, int elem);
Set *Union(Set A, Set B);
Set *Intersection(Set A, Set B);
Set *Difference(Set A, Set B);

void displayVector(Set S);
void display(Set S);

int main() {
    printf("\033[H\033[J");

    Set A;
    Set B;

    init(A);
    init(B);

    insert(A, 1);
    insert(A, 2);
    insert(A, 3);

    insert(B, 2);
    insert(B, 3);
    insert(B, 4);

    printf("Set A: ");
    display(A);
    displayVector(A);

    printf("Set B: ");
    display(B);
    displayVector(B);

    Set *U = Union(A, B);
    printf("\nUnion: ");
    display(*U);

    Set *I = Intersection(A, B);
    printf("Intersection: ");
    display(*I);

    Set *D = Difference(A, B);
    printf("(A - B): ");
    display(*D);

    D = Difference(B, A);
    printf("(B - A): ");
    display(*D);

    return 0;
}

void init(Set S) {
    int i;
    for(i = 0;i < SIZE;i++){
    	strcpy(S[i], "OFF");
	}
}

void insert(Set S, int elem) {
    strcpy(S[elem], "ON");
}

void delete(Set S, int elem) {
    
}

Set *Union(Set A, Set B) {
	
}

Set *Intersection(Set A, Set B) {
    
}

Set *Difference(Set A, Set B) {
    
}

void displayVector(Set S) {
	int i;
    for ( i = 0; i < SIZE; i++) {
        printf("%d: %s\n", i, S[i]);
    }

    printf("\n");
}

void display(Set S) {
	int i;
    for (i = 0; i < SIZE; i++) {
        if(strcmp(S[i], "ON") == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}
