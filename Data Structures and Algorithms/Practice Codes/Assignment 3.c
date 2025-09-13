#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char FName[24], LName[16], MI;
}nametype;

typedef struct{
	unsigned int ID;
	nametype SName;
	char course[8];
	int yr;
}studRec;

typedef struct node{
	studRec stud;
	struct node *link;
}*qptr;

typedef struct{
	qptr front;
	qptr rear;
	int count;
}studQueue;

typedef enum {TRUE, FALSE} Boolean;


int main(){
		
}


Boolean iAscendingID(studQueue q){
	Boolean status = TRUE;
	
	unsigned int prev;
	
	if(Q.front != NULL){
		prev = Q.front->stud.ID;
		
		while(Q.front != NULL){
			if(prev > Q.front->stud.ID){
				status = FALSE;
			}
			
			prev = Q.front->stud.ID;
			Q.front = Q.front->link;
		}
		
		return status;
	}
}
