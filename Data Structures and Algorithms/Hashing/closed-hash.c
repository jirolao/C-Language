//closed hashing
#include <stdio.h>
#include <stdlib.h>
#define DELETED -1
#define EMPTY 0
#define MAX 10

typedef int Dictionary[MAX];
typedef enum{
	TRUE,FALSE
}boolean;

void initDic(Dictionary);
void Display(Dictionary);
int  hash(int);
void insert(Dictionary,int);
void Delete(Dictionary,int);
boolean isMember(Dictionary, int);

int main(){
	Dictionary sample;
	int ctr, arr[10] = {124,623,734,8434,246,5,3245,724,236,124678};
	initDic(sample);
	Display(sample);
	for(ctr = 0; ctr < 10; ctr++){
		insert(sample,arr[ctr]);
	}
	Display(sample);
	Delete(sample,124);
	Display(sample);
	ctr = 124;
	printf("The value %d is %s the Dictionary",ctr, (isMember(sample,ctr) == FALSE) ? "not in" : "in");
	return 0;
}

void initDic(Dictionary D){
	int ctr;
	for(ctr = 0;ctr < MAX; ctr++){
		D[ctr] = EMPTY;
	}
}

void Display(Dictionary D){
	int ctr;
	for(ctr =0; ctr < MAX; ctr++){
		printf("The value in index %d is: ",ctr);
		if(D[ctr] < 1){
			(D[ctr] == EMPTY) ? printf("EMPTY\n") : printf("DELETED\n");
		}else{
			printf("%d\n",D[ctr]);
		}
	}
	printf("\n");
}

int hash(int x){
	return x % MAX;
}

void insert(Dictionary D, int x){
	int pos,ctr;
	for(pos=hash(x), ctr = 1;ctr < MAX && D[pos] != EMPTY && D[pos] != x; ctr++,pos = (pos + 1) % MAX){}
	if(D[pos] == EMPTY){
		for(ctr = hash(x); ctr != pos && D[ctr] != DELETED; ctr = (ctr + 1) % MAX){}
		D[(ctr == pos) ? pos:ctr] = x;
	}
}

void Delete(Dictionary D, int x){
	int pos, ctr;
	for(pos = hash(x),ctr = 1; ctr < MAX && D[pos] != EMPTY && D[pos] != x;ctr++,pos = (pos + 1) % MAX){}
	D[pos] = (D[pos] != EMPTY && ctr < MAX) ? DELETED:D[pos];
}

boolean isMember(Dictionary D, int x){
	int pos,ctr;
	for(pos = hash(x), ctr = 1; ctr < MAX && D[pos] != EMPTY && D[pos] != x; ctr++, pos = (pos + 1) % MAX){}
	return (D[pos] != EMPTY && ctr < MAX) ? TRUE:FALSE;
}
