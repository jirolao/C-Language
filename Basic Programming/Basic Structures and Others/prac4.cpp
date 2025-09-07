#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char names[50];
}test;

void sortNames(test name[3]){
	int i, j;
	test temp;
	for(i=0;i<2;i++){
		for(j=0;j<2-i;j++){
			if(strcmp(name[j].names, name[j+1].names) > 0){						
			temp = name[j];
			name[j] = name[j+1];
			name[j+1] = temp;
			}
		}
	}
}

int main(){
	
	test name[3];
	
	int i;
	for(i=0;i<3;i++){
		scanf(" %99[^\n]", name[i].names);
	}
	
	sortNames(name);
	
	for(i=0;i<3;i++){
		printf("%s", name[i].names);
	}
}
