#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
typedef struct{
	int idNum;
	char name[30];
	int age;
	char address[50];
}Data;
 
int getSize();
Data *getData(int size);
void findData(Data *dat, int size);
int searchAgain();
void thankYou();
 
int main(){
	int again;
	int size = getSize();
	Data *dat = getData(size);
	do{	
		findData(dat, size);
		again = searchAgain();
	}while(again != 0);
	thankYou();
	free(dat);
	return 0;	
}	
 
int getSize(){
	system("cls");
	int size;
	printf("Enter number of employees: ");
	scanf("%d", &size);
	return size;
}
 
Data *getData(int size){
	Data *dat = (Data*)malloc(sizeof(Data)*size);
	for(int i=0; i<size; i++){
		system("cls");
		dat[i].idNum = 1+i;
        printf("Employee #%06d\n\n", dat[i].idNum);
		printf("Enter employee name: ");
		scanf(" %30[^\n]", dat[i].name);
		printf("Enter employee age: ");
		scanf("%d", &dat[i].age);
		printf("Enter employee address: ");
		scanf(" %50[^\n]", dat[i].address);
	}
 
	return dat;
}
 
void findData(Data *dat, int size){
	system("cls");
	int search;
	printf("Input ID number: ");
	scanf("%d", &search);
	for(int i = 0; i<size; i++){
		if(search == dat[i].idNum){
			printf("\nNAME: %s\n", dat[i].name); 
			printf("AGE: %d\n", dat[i].age);
			printf("ADDRESS: %s\n", dat[i].address);
			return;
		}
	}
	printf("\nWRONG OR INVALID ID NUMBER\n");
}
 
int searchAgain(){
	char choice;
	printf("\nWould you like to search again? (y/n): ");
	scanf(" %c", &choice);
	choice = tolower(choice);
	if(choice == 'y')
		return 1;
	else
        system("cls");
		return 0;
}

void thankYou(){
	printf("THANK YOU FOR USING!!!");
}
