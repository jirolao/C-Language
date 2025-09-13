#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct {
    int studID; 
    char studName[20]; //counts the first 3 letters of the name
    bool sex; //true - male false - female
    char program[8];
    int level;
}Student;

typedef struct node {
    Student stud;
    struct node* link;
}NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count; //every time insert a value, add, if remove subtract
}Dictionary;
int getHash(Student s);
void initDictionary(Dictionary* d);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary d);
int main() {
    Dictionary book;
    Student studList[] = {{01100, "Stephen", true, "BSIS", 2},
    {11111, "Vince", true, "BSIT", 3},
    {01110, "Kendo", false, "BSICT", 4},{11110, "Daryll", false, "BSCOOK", 2},
    {01101, "Anthony", false, "BSIT", 3},{10101, "Benedict", true, "BSSING", 2}};
    initDictionary(&book);
    int x;
     for(x = 0; x < sizeof(studList)/sizeof(studList[0]); x++) {
         addStudent(&book, studList[x]);
     }
    visualize(book);
   Student stude = getStudent(book, studList[4]);
   printf("\n\nStudent ID = %d", stude.studID);
    return 0;
}
//counts all the binary ones in studID + the first 3 letters of my studName and count all letters in the program
int getHash(Student s) {
    int count = 0;
    unsigned int mask;
    for(mask = 0; mask != 0; mask >>= 1) {
    count += (s.studID >> mask) & 1;
    } //binary done :-)
    
    int x;
    while(s.studName[x] < 3) {
        count += s.studName[x];
        x++;
    } //hlep me
    for(x = 0; s.program[x] != '\0'; x++){
        count += s.program[x];
    }
    
    return (count % MAX);
} 
void initDictionary(Dictionary* d) {
    int x;
    for(x = 0; x < MAX; x++) {
        d->elems[x] = NULL;
    }
}

bool addStudent(Dictionary *d, Student s) {
	NodePtr* trav = &d->elems[getHash(s)];
	//printf("%d\n\n", getHash(s));
	while (*trav != NULL && (*trav)->stud.studID < s.studID) {
   		trav = &(*trav)->link;
	}
	if (*trav == NULL || (*trav)->stud.studID != s.studID) {
    	NodePtr temp = (NodePtr)malloc(sizeof(NodeType));
    		if (temp != NULL) {
        	temp->stud = s;
        	temp->link = *trav;
        	*trav = temp;
        	d->count++; // Increment count
        //	printf("%d Inserted!!\n\n", temp->stud.studID);
        	return true;
    	} 
	} else {
   	 printf("Get another ID, %d already has an equal here \n", s.studID);
   	 return false;
	}
}
bool removeStudent(Dictionary *d, Student s) {
	NodePtr* trav = &d->elems[getHash(s)], temp;
	while(*trav != NULL && (*trav)->stud.studID != s.studID){
		trav = &(*trav)->link;
	}
	
	if(*trav == NULL) {
		temp = *trav;
		*trav = temp->link;
		return true;
	}else {
		printf("\n\nIt aint here or atm you at last node\n\n");
		return false;
	}
}
Student getStudent(Dictionary d, Student s) {
		NodePtr scan = d.elems[getHash(s)];
		for(;scan != NULL && scan->stud.studID != s.studID; scan = scan->link){}
		return scan->stud; 
}

void visualize(Dictionary d) {
    int x;
    NodePtr temp;
    for(x = 0; x < MAX; x++) {
    	printf("[%d]\t",x);
        for(temp = d.elems[x]; temp != NULL; temp = temp->link) {
            printf("%-10s%-10s", temp->stud.studName, temp->stud.program);
            }
            printf("Empty\n");
    }
}


