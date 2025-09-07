#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char names[50];
}people;

people* getName(){
	int i;
	people* ppl;
	ppl = (people*)malloc(sizeof(people)*3);
	for(i = 0;i < 3;i++){
		printf("Enter Name %d: ", i+1);
		scanf(" %99[^\n]", ppl[i].names);
	}
	return ppl;
}

void insertEnd(people* fetch){
	printf("Insert name at end: ");
	scanf(" %99[^\n]", fetch[2].names);
}

void insertStart(people* fetch){
	printf("Insert name at start: ");
	scanf(" %99[^\n]", fetch[0].names);
}

void deleteName(people* fetch){
	int i, j, temp;
	char rem[50];
	printf("Enter name you want to delete: ");
	scanf(" &99[^\n]", rem);
	
	for(i=0;i<3;i++){
		if(strcmp(rem, fetch[i].names) == 0){
			for(j=i;j<2;j++){
				strcpy(fetch[j].names, fetch[j + 1].names);
			}
			strcpy(fetch[2].names, "");
		}
	}
}

void sortNames(people* fetch){
	int i, j, test;
	people swap;
	for(i=0;i<2;i++){
		test = 0;
		for(j=0;j<1-i;j++){
			if(strcmp(fetch[j].names, fetch[j+1].names) != 0){
				swap = fetch[j];
				fetch[j] = fetch[j+1];
				fetch[j+1] = swap;
				test += 1;
			}
			if(test == 0){
				break;
			}
		}
	}
}

int main(){
	
	int i;
	people* fetch = getName();
	
	for(i=0;i<3;i++){
		printf("Name %d: %s\n", i+1, fetch[i].names);
	}
	
	insertEnd(fetch);
	for(i=0;i<3;i++){
		printf("Name %d: %s\n", i+1, fetch[i].names);
	}
	
	insertStart(fetch);
	for(i=0;i<3;i++){
		printf("Name %d: %s\n", i+1, fetch[i].names);
	}
	
	sortNames(fetch);
	for(i=0;i<3;i++){
		printf("Name %d: %s\n", i+1, fetch[i].names);
	}
	
	deleteName(fetch);
	people* new_fetch = (people*)realloc(fetch, sizeof(people)* 2);
	fetch = new_fetch;
	for(i=0;i<2;i++){
	printf("Name %d: %s\n", i+1, fetch[i].names);
	}
	
	free(fetch);
return 0;
}
