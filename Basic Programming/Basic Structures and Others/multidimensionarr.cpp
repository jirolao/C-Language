#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getInt(){
	
	int i;
	char *temp;
	temp = (char*)malloc(sizeof(char) * 5 * 20);
	
	for(i = 0;i < 5; i++){
		printf("Enter %dst Name: ", i + 1);
		scanf(" %99[^\n]", temp + i * 50);
		printf("\n");
	}
	return temp;
}

int main(){
	
	int i;
	char names[6][50];
	char *get;
	
	get = getInt();
	
	printf("Enter 6th Name: ");
	scanf(" %99[^\n]", names[5]);
	
	for(i = 0;i < 5;i++){
		if(strcmp(names[5], get + i * 50) == 0){
			printf("\n%s is in array %d", names[5], i);
		}
	}
	
	free(get);
}
