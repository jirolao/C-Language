#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[50];
	int age;
	float salary;
	char job[50];
	
	struct cow{
		int ssid;
	}id;
}emp;

emp* getUser(){
	
	int i;
	emp *employee = (emp*)malloc(sizeof(emp) * 2); 
	
	for(i = 0;i < 2;i++){
		printf("Enter Name of Employee %d: ", i + 1);
		scanf(" %99[^\n]", employee[i].name);
		printf("Enter Age: ");
		scanf("%d", &employee[i].age);
		printf("Enter Salary: ");
		scanf("%f", &employee[i].salary);
		printf("Enter Job: ");
		scanf(" %99[^\n]", employee[i].job);
		printf("Give ID (1-10): ");
		scanf("%d", &employee[i].id.ssid);
	}
	return employee;
}

void sortUser(emp* fetch){
	
	int i, j;
    emp temp;

    for (i = 0; i < 2 - 1; i++) {
        for (j = 0; j < 2 - i - 1; j++) {
            if (strcmp(fetch[j].name, fetch[j + 1].name) > 0) {
                temp = fetch[j];
                fetch[j] = fetch[j + 1];
                fetch[j + 1] = temp;
            }
        }
    }
}

void findUser(emp* fetch){
	
	int i;
	int temp;
	
	printf("\nFind user, Enter ID: ");
	scanf("%d", &temp);
	
	for(i=0;i<2;i++){
		if(temp == fetch[i].id.ssid){
		printf("\n");
		printf("%s\n", fetch[i].name);
		printf("%d\n", fetch[i].age);
		printf("%.2lf\n", fetch[i].salary);
		printf("%s\n", fetch[i].job);
		}
	}
}

int main(){
	
	emp* fetch;
	fetch = getUser();
	sortUser(fetch);
	findUser(fetch);
	
	free(fetch);
}
