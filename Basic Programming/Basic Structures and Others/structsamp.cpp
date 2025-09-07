#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
	
	char fname[MAX];
	char lname[MAX];
	char gen;
	int age;
	
} User;

void getUser(User *person, int size){
	
	int i;
	
	for(i = 0; i < size; i++){
	printf("Enter First Name: ");
	scanf(" %s", &person[i].fname);
	
	printf("Enter Last Name: ");
	scanf(" %s", &person[i].lname);
	
	printf("Enter Gender (M/F): ");
	scanf(" %c", &person[i].gen);
	
	printf("Enter Age: ");
	scanf("%d", &person[i].age);
	
	}
	
}

void printUsers(User *person, int size){
	
	int i;
	
	for(i = 0; i < size; i++){
		printf("\n%s", person[i].fname);
		printf("\n%s", person[i].lname);
		printf("\n%c", person[i].gen);
		printf("\n%d", person[i].age);
		printf("\n");
	}
}

int main(){	

	int size = 2;
	User *person = malloc(size * sizeof(User));
	
	getUser(person, size);
	printUsers(person, size);
	
	free(person);
	
}
