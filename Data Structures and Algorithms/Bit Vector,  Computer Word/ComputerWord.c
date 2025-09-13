#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elem[15];  
    int count;
} SET;


SET unionSET(SET x, SET y);
SET intersectionSET(SET x, SET y);
SET differenceSET(SET x, SET y);
SET insertElement(SET s, int pos);
SET deleteElement(SET s, int pos);
void printSet(SET s);

int main() {
  
    SET a = {.elem = {1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1}, .count = 15};
    SET b = {.elem = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0}, .count = 15};

   
    SET c = unionSET(a, b);
    SET d = intersectionSET(a, b);
    SET e = differenceSET(a, b);

    
    printf("Union: ");
    printSet(c);

    printf("Intersection: ");
    printSet(d);

    printf("Difference: ");
    printSet(e);

  
    SET f = insertElement(a, 2); 
    printf("Delete pos 2: ");
    printSet(f);

    SET g = deleteElement(a, 4);  
    printf("Delete pos 4: ");
    printSet(g);

    return 0;
}


SET unionSET(SET x, SET y) {
    int i;
    SET newSET = {.count = 15};  

    for (i = 0; i < 15; i++) {
        newSET.elem[i] = x.elem[i] | y.elem[i]; 
    }

    return newSET;
}


SET intersectionSET(SET x, SET y) {
    int i;
    SET newSET = {.count = 15};  

    for (i = 0; i < 15; i++) {
        newSET.elem[i] = x.elem[i] & y.elem[i];  
    }

    return newSET;
}


SET differenceSET(SET x, SET y) {
    int i;
    SET newSET = {.count = 15};  

    for (i = 0; i < 15; i++) {
        newSET.elem[i] = x.elem[i] & ~y.elem[i]; 
    }

    return newSET;
}


SET insertElement(SET s, int pos) {
    if (pos >= 0 && pos < 15) {
        s.elem[pos] = 1;  
    }
    return s;
}


SET deleteElement(SET s, int pos) {
    if (pos >= 0 && pos < 15) {
        s.elem[pos] = 0;  
    }
    return s;
}


void printSet(SET s) {
	int i;
    for (i = 0; i < 15; i++) {
        printf("%d ", s.elem[i]);
    }
    printf("\n");
}

