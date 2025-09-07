#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int num;
}memory;

typedef struct{
	int num2;
}memory2;
	
memory* getElements(){
	memory* create;
	create = (memory*)malloc(sizeof(memory) * 5);
	
	int i;
	for(i=0;i<5;i++){
		create[i].num = i + 1;
	}
	
	return create;
}

void insertEnd(memory* fetch){
	printf("\nInsert Number at the End: ");
	scanf("%d", &fetch[4].num);
}

void insertStart(memory* fetch){
	printf("\nInsert Number at the End: ");
	scanf("%d", &fetch[0].num);
}

void deleteNum(memory* fetch){
	int i, j, number;
	printf("\nEnter a number in the array you want to delete: ");
	scanf("%d", &number);
	
	for(i=0;i<5;i++){
		if(number == fetch[i].num){
			for(j=i	;j<4;j++){
				fetch[j].num = fetch[j+1].num;
			}
		}
	}
}

memory2* copyArr(memory* fetch){
	memory2* fetch2;
	fetch2 = (memory2*)malloc(sizeof(memory2) * 4);
	
	int i;
	for(i=0;i<4;i++){
		fetch2[i].num2 = fetch[i].num;
	}
	return fetch2; 
}

void sortSecond(memory2* fetch2){
	int i, j;
	memory2 swap;
	
	for(i=0;i<4;i++){
		for(j=0;j<3-i;j++){
			if(fetch2[j].num2 > fetch2[j+1].num2){
				swap = fetch2[j];
				fetch2[j] = fetch2[j+1];
				fetch2[j+1] = swap;
			}
			}
		}
	}

int main(){
	int i;
	
	memory* fetch;
	fetch = getElements();
	
	for(i=0;i<5;i++){
		printf("%d ", fetch[i].num);
	}
	
	insertEnd(fetch);
	insertStart(fetch);
	
	for(i=0;i<5;i++){
		printf("%d ", fetch[i].num);
	}
	
	deleteNum(fetch);
	memory* new_fetch = (memory*)realloc(fetch, sizeof(memory) * 4);
    fetch = new_fetch;
    
	for(i=0;i<4;i++){
		printf("%d ", new_fetch[i].num);
	}
	
	memory2* fetch2;
	fetch2 = copyArr(fetch);
	sortSecond(fetch2);
	
	printf("\n");
	printf("Sorted: ");
	for(i=0;i<4;i++){
		printf("%d ", fetch2[i].num2);
	}
	
	free(fetch);
	free(fetch2);
	
return 0;
}
