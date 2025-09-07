#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	
	char names[6][50];
	
}get;

get* getInt(){
	
	int i;
	get* temp;
	temp = (get*)malloc(sizeof(get));
	
	for(i = 0;i < 5;i++){
		printf("Inpute Name %d: ", i + 1);
		scanf(" %99[^\n]", temp->names[i]);
	}
	return temp;
}

void sixthNum(get* rec){
	
	printf("Enter 6th Numer: ");
	scanf(" %99[^\n]", rec->names[5]);
	
}

void display(get* rec){
	
	int i, temp;
	
	for(i = 0;i < 5;i++){
		if(strcmp(rec->names[5], rec->names[i]) == 0){
			printf("%s is found in the array %d\n", rec->names[5], i + 1);
			temp = 0;
		}
	}
	if(temp != 0){
		printf("%s is not found in the array\n");
	}
} 

int main(){
	
	get *rec;
	
	rec = getInt();
	sixthNum(rec);
	display(rec);
	
	free(rec);
	
}
