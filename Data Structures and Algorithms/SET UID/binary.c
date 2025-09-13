//Computer word count how many 1s
#include <stdio.h>
#include <stdlib.h>
typedef char SET;
#define SIZE 0XA
typedef short BitVector[SIZE];
int countBit(char let);
void insertBit(char* let, int pos);
void displayBit(char let);
SET findUnion(SET A, SET B);
SET findSet(SET A, SET B);
BitVector* findDifference(BitVector A, BitVector B);
void display(BitVector bitt);
int main() {
	char var = 'C';
	int bits = countBit(var); 
	printf("Amount of 1s in %c is %d",var, bits);
	displayBit(var);
	insertBit(&var, 4);
	int bit2 = countBit(var);
	printf("\nAmount of 1s in %c is %d",var, bit2);
	displayBit(var);
	printf("\n\nSize of unsigned short %d", sizeof(unsigned short));
	SET A = 59;
	displayBit(A);
	SET B = 70;
	displayBit(B);
	SET C = findSet(A,B);
	printf("\nvalue of both A & B %d", C);
	displayBit(C);
	SET D = findUnion(A,B);
	printf("\nvalue of both A | B %d", D);
	displayBit(D);
	printf("\nfinding difference between A and B\n\n");
	BitVector AA = {0,2,3,1,4,5};
	BitVector BB = {7,1,3,6,4,5};
	BitVector* CD = findDifference(AA,BB);
	display(*CD);
	return 0;
}
int countBit(char let) {
	int bits = 0;
	int mask;
	unsigned char P = sizeof(unsigned char) * 7;
	for(mask = 0; mask < P; mask++) {
		bits += ((let << mask) & 1); 
	}
	return bits;
}

void displayBit(char let) {
	int mask; unsigned char bit = sizeof(unsigned char) * 7;
	printf("\nThe bit value of %c is \n", let);
	for(mask = bit; mask >= 0; mask--) {
		printf("%d", (let >> mask) & 1);
	}
}
void insertBit(char* let, int pos) {
	unsigned char mask = 1;
	int bit = mask << pos; 
		//	bitVal << posiion(trav)
		if((*let & bit) == 0 ){
		*let |= bit;	   
		}else {
			printf("\nThis is already occupied\n");
		}
}
SET findUnion(SET A, SET B) {
	return A|B;
}
SET findSet(SET A, SET B) {
	return A&B;
}

BitVector* findDifference(BitVector A, BitVector B) {
	int x;
	BitVector* C = (BitVector*)calloc(10,sizeof(unsigned short));
	if(*C != NULL)  {
	for(x = 0; x < SIZE; x++) {
		(*C)[x] = ((A[x] == 0 || B[x] == 0)) ? 1 : 0;
		}
	}
	
	return C;
}
void display(BitVector bitt) {
	int x;
	int size = sizeof(bitt)/sizeof(sizeof(bitt[0]));
	printf("\nSIZE %d\n", size);
	for(x = 0; x <= size; x++) {
		printf("[%d]%d\n",x,bitt[x]);
	} 
}
