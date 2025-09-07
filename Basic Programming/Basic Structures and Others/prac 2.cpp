#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fname[10];
	char mname[2];
	char lname[10];
}userName;

typedef struct{
	int age;
	char gender[2];
	float height;
	float weight;
}userAbout;

typedef struct{
	char job[10];
	float pay;
}userWage;

userName* getUser(){
	int i;
	userName* gets = (userName*)malloc(sizeof(userName) * 3);
	
	for(i=0;i<3;i++){
		printf("Enter Employee (%d) First Name:", i + 1);
		scanf(" %99[^\n]", gets[i].fname);
		printf("Enter Employee (%d) Middle Name:", i + 1);
		scanf(" %1s", gets[i].mname);
		printf("Enter Employee (%d) Last Name:", i + 1);
		scanf(" %99[^\n]", gets[i].lname);
		
	}
	return gets;
}

userAbout* getAbout(){
	int i;	
	userAbout* gets = (userAbout*)malloc(sizeof(userAbout) * 3);
	
	for(i=0;i<3;i++){
		printf("Enter Employee (%d) Age: ", i + 1);
		scanf("%d", &gets[i].age);
		printf("Enter Employee (%d) Gender (M/F): ", i + 1);
		scanf("%1s", &gets[i].gender);
		printf("Enter Employee (%d) Height: ", i + 1);
		scanf("%f", &gets[i].height);
		printf("Enter Employee (%d) Weight: ", i + 1);
		scanf("%f", &gets[i].weight);
	}
	return gets;
}

userWage* getWage(){
	int i;
	userWage* gets = (userWage*)malloc(sizeof(userWage) * 3);
	
	for(i=0;i<3;i++){
		printf("Enter Employee (%d) Job: ", i + 1);
		scanf(" %99[^\n]", gets[i].job);
		printf("Enter Employee (%d) Salary: ", i + 1);
		scanf("%f", &gets[i].pay);
	}
	return gets;
}

void insertUser(userName** fetch, userAbout** fetch2, userWage** fetch3){
	
	*fetch = (userName*)realloc(*fetch, sizeof(userName) * 4);
		printf("Enter 4th User First Name: ");
		scanf(" %99[^\n]", (*fetch)[3].fname);
		printf("Enter Middle Name: ");
		scanf(" %1s", (*fetch)[3].mname);
		printf("Enter Last Name: ");
		scanf(" %99[^\n]", (*fetch)[3].lname);
	
	*fetch2 = (userAbout*)realloc(*fetch2, sizeof(userAbout) * 4);
		printf("Enter Employee Age: ");
		scanf("%d", &(*fetch2)[3].age);
		printf("Enter Employee Gender (M/F): ");
		scanf("%1s", (*fetch2)[3].gender);
		printf("Enter Employee Height: ");
		scanf("%f", &(*fetch2)[3].height);
		printf("Enter Employee Weight: ");
		scanf("%f", &(*fetch2)[3].weight);	
		
	*fetch3 = (userWage*)realloc(*fetch3, sizeof(userWage) * 4);
		printf("Enter Employee Job: ");
		scanf(" %99[^\n]", (*fetch3)[3].job);
		printf("Enter Employee Salary: ");
		scanf("%f", &(*fetch3)[3].pay);	
	
}

void deleteUser(){
	
}

void displayUser(userName* fetch, userAbout* fetch2, userWage* fetch3){
	int i;
	
	for(i=0;i<4;i++){
		printf("\nEmployee %d: \n", i + 1);
		printf("%s\n", fetch[i].fname);
		printf("%1s\n", fetch[i].mname);
		printf("%s\n", fetch[i].lname);
		printf("%d\n", fetch2[i].age);
		printf("%s\n", fetch2[i].gender);
		printf("%.2lf\n", fetch2[i].height);
		printf("%.2lf\n", fetch2[i].weight);
		printf("%s\n", fetch3[i].job);
		printf("%.2lf", fetch3[i].pay);
		}
}

int main(){
	
	userName* fetch;
	fetch = getUser();
	
	userAbout* fetch2;
	fetch2 = getAbout();
	
	userWage* fetch3;
	fetch3 = getWage();
	
	insertUser(&fetch, &fetch2, &fetch3);
	displayUser(fetch, fetch2, fetch3);
	
	free(fetch);
	free(fetch2);
	free(fetch3);
}
