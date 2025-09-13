#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Best tip: always assume its going to be found immediately
#define EMPTY 0
#define DELETED -1
#define MAX 20

typedef struct {
    int studID;
    char studName[16];
    char program[8];
    bool sex;
    int level;
}Student;

typedef struct {
    Student *data;
    int count;
    int max;
}Studict;

int getHash(Student c); //add the positions of 1 in the binary placement
void initDict(Studict* s);
void insertStud(Studict* s, Student c);
void deleteStud(Studict* s, Student c);
Student getStudent(Studict s, Student c);
Studict thirdYear(Student stude[], int numstud); // returns third year students
void visualize(Studict s);
void displayID(Studict st);
int main() {
	Studict stud;
	initDict(&stud);
	displayID(stud);
	printf("\n\n");
    Student classs[] = {{11111, "Anthony", "BSIT", true, 3},
	{00011, "Cyrus", "BSIT", true, 3},
	{11011, "Aaron", "BSCS", true, 2},
	{11000, "Shaun",  "BSIS", true, 3}, 
	{10111, "Renee", "BSCS", false, 2}, 
	{10000, "Mark", "BSCS", true, 4},
	{11111, "Xavier", "BSIT", true, 3}};
    int x;
	int count = sizeof(classs)/sizeof(classs[0]);
    for(x = 0; x < count; x++) {
    	insertStud(&stud, classs[x]);
    	visualize(stud);
    	printf("\n\n");
	}
	deleteStud(&stud, classs[4]);
	visualize(stud);
	printf("\n\n");
	Studict third = thirdYear(classs, 7);
	printf("third years\n");
	visualize(third);
	free(stud.data);
	return 0;
}

int getHash(Student s) { //it returns the hash value from the amounts of 1s in the student ID
     unsigned int mask = 0;
    int count = 0;
    for(; mask < 31; mask++) {
        count += (((s.studID >> mask) & 1) == 1) ? mask : 0;
    }
    //printf("%s hashValue = %d\n\n", s.studName, count);
    return (count % MAX) * 0.8;
} 
void initDict(Studict* s) {
	s->data =malloc(sizeof(Student) * MAX);
	int x;
	if(s->data != NULL) {
		s->count = 0;
		s->max = MAX * 0.8;
		printf("Initialized\n");
		for(x = 0; x < MAX; x++) {
			s->data[x].studID = EMPTY;
		}
	}
}
void insertStud(Studict* s, Student c) {
		int hash = getHash(c);
	if(s->count > s->max) {
			printf("It is already full");
		}else { 
			if(s->data[hash].studID == EMPTY) {
				s->data[hash] = c;
			}else {
				while(s->data[hash].studID != EMPTY && hash < s->max) {
					hash = (hash + 1) % s->max;
				}
				s->data[hash] = c;
			}
			s->count++;
	}
}

void deleteStud(Studict* s, Student c) {
		int hash;
	if(s->count > s->max) {
		printf("It is already full");
	}else { 
		if(strcmp(s->data[hash].studName, c.studName) == 0) {
			s->data[hash].studID = DELETED;
		}else {
			for(hash = getHash(c); s->data[hash].studID != EMPTY && strcmp(s->data[hash].studName, c.studName) != 0; hash = (hash + 1) % MAX){}
			s->data[hash].studID = DELETED;
		}
		s->count--;	
	}
}
Student getStudent(Studict s, Student c) {
	int hash = getHash(c);
	for(;s.data[hash].studID != EMPTY && s.data[hash].studID != c.studID; hash = (hash + 1) % s.max) {}
	return s.data[hash];
}
void visualize(Studict s){
	int x;
	for(x = 0; x < s.max; x++) {
		if(s.data[x].studID == EMPTY || s.data[x].studID == DELETED) {
			printf("Empty\n");
		}else {
			printf("[%d] %-5s %-10d%-10d\n", x,s.data[x].studName, s.data[x].studID, getHash(s.data[x]));
		}
	}
}
void displayID(Studict st){
	int x;
	printf("ID lists of Studict\n");
	for(x < 0; x < st.max; x++) {
		printf("IDs are %d\n",st.data[x].studID);
	}
	printf("\n\n\n");
}

Studict thirdYear(Student stude[], int numStud) { // returns third year students
	Studict thirdY;
	initDict(&thirdY);
	int x;
	
	for(x = 0; x < numStud; x++) {
    	if(stude[x].level == 3) {
        	insertStud(&thirdY, stude[x]);
        	printf("\n%s is inserted\n", stude[x].studName);
    	}
	}
	return thirdY;
}
