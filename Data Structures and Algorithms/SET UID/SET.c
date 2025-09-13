#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int elem[15];
    int count;
}SET;

int isEmpty(SET x);
SET unionSET(SET x, SET y);
SET differenceSET(SET x, SET y);
void displaySET(SET x);

int main(){
	
     SET a = {.elem = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1}, .count = 15};
     SET b = {.elem = {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0}, .count = 15};
    
    SET c = unionSET(a, b);
    SET d = differenceSET(a, b);
    
    displaySET(c);
    printf("\n");
    displaySET(d);
    
    return 0;
}

int isEmpty(SET x){
    return (x.count == 0);
}

SET unionSET(SET x, SET y){
	int i;
	SET newSET;
	
	if(!isEmpty(x) || !isEmpty(y)){
		for(i = 0;i < x.count;i++){	
		if(x.elem[i] == 1 || y.elem[i] == 1){
			newSET.elem[i] = x.elem[i];
			}else{
				newSET.elem[i] = 0;
			}
		}
	}
	return newSET;
}

SET differenceSET(SET x, SET y) {
    int i;
    SET newSET = {.count = 15};  

    if (!isEmpty(x) && !isEmpty(y)) {  
        for (i = 0; i < 15; i++) {
            
            if (x.elem[i] == 1 && y.elem[i] == 0) {
                newSET.elem[i] = 1; 
            }else if(x.elem[i] == 0 && y.elem[i] == 1){
            	newSET.elem[i] = 1;
			}else {
                newSET.elem[i] = 0; 
            }
        }
    }

    return newSET;
}

void displaySET(SET x){
	int i;
	for(i = 0;i < 15;i++){
		printf("%d", x.elem[i]);
	}
}



