#include <header.h>
#include <stdio.h>
#include <stdlib.h>

void init(Set *S){
    (*S) = NULL;
}

Set unionSetV1(Set A, Set B){
    Set uSet = (Set)malloc(sizeof(struct node));
    init(&uSet);
    Set travA = A, travB = B;
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
    return uSet;
}

void insertSorted(char el, Set *S){
    if(!isMember(el, *S)){
        Set *trav;
        for(trav = S; (*trav) != NULL && el < (*trav)->elem; trav = &(*trav)->link){}
        sNode *temp = (sNode *)malloc(sizeof(sNode));
        if(temp != NULL){
            temp->elem = el;
            // Check if the Set is initially empty
            if(isEmpty(S)){
                temp->link = (*S);
                (*S) = temp;
            }else{
                temp->link = (*trav);
                (*trav) = temp;
            }
        }
    }else{
        printf("Element to be inserted is already a member of the set!\n");
    }
}

Boolean isMember(char el, Set S){
    if(!isEmpty(S)){
        Set trav;
        for(trav = S; trav != NULL && trav->elem != el; trav = trav->link){}
        return trav != NULL;
    }
}

Boolean isEmpty(Set S){
    return S == NULL;
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

Set interSet(Set A, Set B){
    Set intSet = (Set)malloc(sizeof(struct node)), trav;
    init(&intSet);
    for(trav = A; trav != NULL; trav = trav->link){
        if(isMember(trav->elem, B)){
            insertSorted(trav->elem, &intSet);
        }
    }
    return intSet;
}

Set diffSet(Set A, Set B){
    Set diSet = (Set)malloc(sizeof(struct node)), travA, travB;
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
