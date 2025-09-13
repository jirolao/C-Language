#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} sNode, *Set;

typedef enum {TRUE, FALSE} Boolean;

void init(Set *S);
Set unionSetV1(Set A, Set B);
void insertSorted(char el, Set *S);
Boolean isMember(char el, Set S);
Boolean isEmpty(Set S);
void display(Set S);
Set interSet(Set A, Set B);
Set diffSet(Set A, Set B);

int main() {
    Set set1, set2;
    init(&set1);
    init(&set2);
    
    insertSorted('a', &set1);
    insertSorted('b', &set1);
    insertSorted('c', &set1);
    
    insertSorted('b', &set2);
    insertSorted('c', &set2);
    insertSorted('d', &set2);
    
    printf("Set 1: ");
    display(set1);
    printf("\n");
    
    printf("Set 2: ");
    display(set2);
    printf("\n");
    
    Set unionSet = unionSetV1(set1, set2);
    printf("Union of Set 1 and Set 2: ");
    display(unionSet);
    printf("\n");
    
    Set intersectionSet = interSet(set1, set2);
    printf("Intersection of Set 1 and Set 2: ");
    display(intersectionSet);
    printf("\n");
    
    Set differenceSet = diffSet(set1, set2);
    printf("Difference of Set 1 and Set 2: ");
    display(differenceSet);
    printf("\n");
    
    return 0;
}

void init(Set *S){
    (*S) = NULL;
}

void insertSorted(char letter, Set *S){
    if(!isMember(letter, *S)){
        Set *trav;
        for(trav = S; (*trav) != NULL && letter < (*trav)->elem; trav = &(*trav)->link){}
        Set temp;
		temp =(sNode *)malloc(sizeof(sNode));
        if(temp != NULL){
            temp->elem = letter;

            if(isEmpty(*S)){
                temp->link = (*S);
                (*S) = temp;
            }else{
                temp->link = (*trav);
                (*trav) = temp;
            }
        }
    }
}

Boolean isMember(char letter, Set S){
    if(!isEmpty(S)){
        Set trav;
        for(trav = S; trav != NULL && trav->elem != letter; trav = trav->link){}
        return trav != NULL;
    }
}

Boolean isEmpty(Set S){
    return S == NULL;
}

Set unionSetV1(Set A, Set B){
    Set uSet;
    init(&uSet);
    
    Set travA = A, travB = B;
    
    for(; travA != NULL || travB != NULL;travA = travA->link, travB = travB->link){
    	insertSorted(travA->elem, &uSet) || insertSorted(travB->elem, &uSet);
	}
	return uSet;
}
    
    
    
    
 /*   
    while(travA != NULL || travB != NULL){
        if(travA == NULL && travB != NULL){
            travA = travB;
        }else{
            travB = travA;
        }
        if((travA != travB) && travA->elem < travB->elem){
            insertSorted(travA->elem, &uSet);
            travA = travA->link;
        }else if((travB != travA) && travB->elem < travA->elem){
            insertSorted(travB->elem, &uSet);
            travB = travB->link;
        }else{
            insertSorted(travA->elem, &uSet);
        }
    }
    return uSet; */
}

Set interSet(Set A, Set B){
    Set intSet = (Set)malloc(sizeof(sNode)), trav;
    init(&intSet);
    for(trav = A; trav != NULL; trav = trav->link){
        if(isMember(trav->elem, B)){
            insertSorted(trav->elem, &intSet);
        }
    }
    return intSet;
}

Set diffSet(Set A, Set B){
    Set diSet = (Set)malloc(sizeof(sNode)), travA, travB;
    init(&diSet);
    for(travA = A, travB = B; travA != NULL || travB != NULL; travA = travA->link, travB = travB->link){
        if((travA != NULL) && !isMember(travA->elem, B)){
            insertSorted(travA->elem, &diSet);
        }
        if((travB != NULL) && !isMember(travB->elem, A)){
            insertSorted(travB->elem, &diSet);
        }
    }
    return diSet;
}

void display(Set S){
    if(!isEmpty(S)){
        Set trav;
        for(trav = S; trav != NULL; trav = trav->link){
            printf("%c ", trav->elem);
        }
    }else{
        printf("Set is empty.\n");
    }
}







