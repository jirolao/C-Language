#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
}sNode, *Set;
typedef enum {TRUE, FALSE} Boolean;

void init(Set *S);
void insertSorted(Set *S, char x);
Boolean isMember(Set S, char x);
Boolean isEmpty(Set S);
void displaySet(Set S);

Set unionSet(Set A, Set B);
Set interSet(Set A, Set B);
Set diffSet(Set A, Set B); 

int main(){
	
	Set set1, set2;
	init(&set1);
	init(&set2);
	
	printf("Set 1:");
	insertSorted(&set1, 'b');
	insertSorted(&set1, 'd');
	insertSorted(&set1, 'a');
	insertSorted(&set1, 'c');
	displaySet(set1);
	
	printf("\n\nSet 2:");
	insertSorted(&set2, 'f');
	insertSorted(&set2, 'e');
	insertSorted(&set2, 'h');
	insertSorted(&set2, 'g');
	displaySet(set2);
	
	Set set3;
	printf("\n\nSet 3:");
	set3 = unionSet(set1, set2);
	displaySet(set3);
	
	
	return 0;
}

void init(Set *S){
	*S = NULL;
}

Boolean isMember(Set S, char x){
	Set trav;
	for(trav = S; trav != NULL;trav = trav->link){
			return (trav->elem == x ? FALSE : TRUE);
			}
		}

Boolean isEmpty(Set S){
	return S == NULL;
}

void insertSorted(Set *S, char x){
	if(!isMember(*S, x)){
		Set *trav;
		sNode *temp = malloc(sizeof(sNode));
		for(trav = S;*trav != NULL && (*trav)->elem < x;trav = &(*trav)->link){}
		if(temp != NULL){
			temp->elem = x;	
			temp->link = *trav;
			*trav = temp;
		
			}else{printf ("\nElement Exists");
		}
	}
}

void displaySet(Set S){
	Set trav;
	for(trav = S; trav != NULL;trav = trav->link){
		printf("\n%c", trav->elem);
	}
}
Set unionSet(Set A, Set B){
		Set set3 = malloc(sizeof(sNode));
		init(&set3);
		Set travA = A, travB  = B;
		while(travA != NULL || (travB != NULL){
			if(travA != NULL && (travB == NULL || travA->elem < travB->elem)){
			insertSorted(&set3, travA->elem);
			travA = travA->link;
			}else if(travB != NULL && (travA == NULL || travB->elem < travA->elem)){
				insertSorted(&set3, travB->elem);
				travB = travB->link;
			}else{
				insertSorted(&set3, travA->elem);
				travA = travA->link;
				insertSorted(&set3, travB->elem);
				travB = travB->link;
			}
			return set3;
		}
}

Set interSet(Set A, Set B){
	
}

Set diffSet(Set A, Set B){
	
}










