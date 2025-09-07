#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addData(){
	FILE* fptr;
	fptr = fopen("data.txt", "a");
	
	char fname[50], lname[50];
	int age;
	
	printf("Enter First Name: ");
	scanf(" %99[^\n]", fname);
	printf("Enter Last Name: ");
	scanf(" %99[^\n]", lname);
	printf("Enter Age: ");
	scanf("%d", &age);
	
	fprintf(fptr, "%s, %s, %d\n", fname, lname, age);
	
	fwrite(&age, sizeof(int), 1, fptr);
	fclose(fptr);
	
	return;
}

void showData(){
	
	FILE* fptr;
	fptr = fopen("data.txt", "r+");
		
		char content[1000];
		
		printf("\nData in Text File: \n");
		
		while(fgets(content, sizeof(content), fptr) != NULL){
			printf("%s", content);
		}
		
		printf("\n");
	
	fclose(fptr);
	return;
}

void findData(){
	
	FILE* fptr;
	fptr = fopen("data.txt", "r");
	
	char test[1000];
	char name[20];
	
	printf("\nEnter First Name: ");
	scanf(" %99[^\n]", name);
	
	while(fgets(test, sizeof(test), fptr)){
		
		
		if(strcmp(name, test) == 0){
			test[strcspn(test, "\0")] = ',';
			printf("User/s Found: %s", test);
			break;
		}
	}
	fclose(fptr);
	return;
}

void deleteData(){
	FILE *fptr, *fptr2;
	fptr = fopen("data.txt", "r");
	fptr2 = fopen("temp.txt", "w" );
	
	char temp[1000];
	char user[20];
	int found = 0;
	
	printf("Enter First Name: ");
	scanf(" %99[^\n]", user);
	
	while(fgets(temp, 1000, fptr)){
		
		temp[strcspn(temp, ",")] = '\0';
			
		if(strcmp(user, temp) != 0){
			temp[strcspn(temp, "\0")] = ',';
			fputs(temp, fptr2);
			}else{found++;}
		}
		
		fclose(fptr);
		fclose(fptr2);
		
		if(found){
			remove("data.txt");
			rename("temp.txt", "data.txt");
		}else if(!found){
			remove("temp.txt");
		}
		return;	
}

void updateData(){
	FILE *fptr, *fptr2;
	fptr = fopen("data.txt", "r");
	fptr2 = fopen("temp.txt", "w");
	
	char temp[1000];
	char user[20];
	int found = 0;
	
	printf("Find User (Fname): ");
	scanf(" %99[^\n]", user);
	
	while(fgets(temp, 1000, fptr)){
		temp[strcspn(temp, ",")] = '\0';
		if(strcmp(temp, user) != 0){
			temp[strcspn(temp, "\0")] = ',';
			fputs(temp, fptr2);
			temp[strcspn(temp, ",")] = '\0';
			}else if(strcmp(temp, user) == 0){
				char fname[50], lname[50];
				int age;
				printf("Edit User: \n");
				printf("Enter First Name: ");
				scanf(" %99[^\n]", fname);
				printf("Enter Last Name: ");
				scanf(" %99[^\n]", lname);
				printf("Enter Age: ");
				scanf("%d", &age);
				fprintf(fptr2, "%s, %s, %d\n", fname, lname, age);
				found++;
			}
		}
		
		fclose(fptr);
		fclose(fptr2);
		
		if(found){
			remove("data.txt");
			rename("temp.txt", "data.txt");
		}else if(!found){
			remove("temp.txt");
		}
		
}

int main(){
	
	
	int opt;
	
	while(1){
		puts("Select Option: \n");
		puts(" 1. Add Data\t");
		puts(" 2. Show All Data");
		puts(" 3. Find Data");
		puts(" 4. Delete Data");
		puts(" 5. Update Data");
		puts(" 6. Exit\n");
		printf("Enter Number: ");
		scanf("%d", &opt);
			if(opt == 1){
				addData();
			}else if(opt == 2){
				showData();
			}else if(opt == 3){
				findData();
			}else if(opt == 4){
				deleteData();
			}else if(opt == 5){
				updateData();
			}else if(opt == 6){
			break;
		}
	}
	
return 0;
}
