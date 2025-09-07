#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user{
	char name[50];
	struct user *link;
}*node;

void init(node *root){
	*root = NULL;
}

void addUser(node *root, char *str){
	node *trav, create;
	for(trav = root;(*trav) != NULL; trav = &(*trav)->link);
	create = malloc(sizeof(struct user));
	strcpy(create->name, str);
	create->link = NULL;
	*trav = create;

}

void addUserSort(node *root, char *str){
	node *trav, create;
	for(trav = root;(*trav) != NULL && strcmp((*trav)->name,str) < 0; trav = &(*trav)->link);
	create = malloc(sizeof(struct user));
	strcpy(create->name, str);
	create->link = (*trav);
	*trav = create;
}

void deleteUser(node *root, char *str){
	node *trav, temp;
	for(trav = root; (*trav) != NULL && strcmp((*trav)->name, str) != 0;trav = &(*trav)->link);
	if(*trav != NULL){
	temp = *trav;
	*trav = (*trav)->link;
	free(temp);
	}
}

void updateUser(node *root, char *oldStr, char *newStr){
	node *trav;
	for(trav = root; (*trav) != NULL && strcmp((*trav)->name, oldStr) != 0;trav = &(*trav)->link);
	strcpy((*trav)->name, newStr);
}

void showUsers(node root){
		while(root != NULL){
			printf("%s\n", root->name);
			root = root->link;
		}
}

void sortUser(node *root){

    }

void insertFILE(node *root){
	FILE* fptr;
	fptr = fopen("data.txt", "w");
	node *trav;
	
	for(trav = root; (*trav) != NULL; trav = &(*trav)->link){
		fprintf(fptr, "%s\n", (*trav)->name);
	}
	fclose(fptr);
}

void displayDATA(node *root){
	FILE* fptr;
	fptr = fopen("data.txt", "r");
	char data[1000];
		
	while(fgets(data, 1000, fptr)){
		printf("%s", data);
	}
}

void findDATA(node *root, char *str){
	FILE* fptr;
	fptr = fopen("data.txt", "r");
	
	node *trav;
	char temp[150];
	for(trav = root;(*trav) != NULL && strcmp((*trav), str) != 0; trav = &(*trav)->link);
	while(fgets(temp, sizeof(temp), fptr)){
		if(strcmp((*trav)->name, fptr) == 0){
			printf("%s", temp);
			}
		}
		fclose(fptr);	
	}

int main(){
	node *root;
	init(&root); 
	
	addUser(&root, "Rei");
	addUser(&root, "Zeus");
	addUser(&root, "Seth");
	addUser(&root, "Akeesha");
	addUser(&root, "Rookie");
	addUser(&root, "Venz");
	addUserSort(&root, "Honey");
	addUserSort(&root, "Freya");
	addUserSort(&root, "Robert");	
	deleteUser(&root, "Zeus");
	deleteUser(&root, "Rookie");
	updateUser(&root, "Venz", "Zeus");
	updateUser(&root, "Honey", "Rookie");
	updateUser(&root, "Freya", "Thea");
	sortUser(&root);
	insertFILE(&root);
	displayDATA(&root);
	free(root);
}
