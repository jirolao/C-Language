#include <stdio.h>
#include <stdlib.h>

typedef struct population{
	int country;
	struct population* next;
}population;



int main(){
	
	population coun;
	coun.country = 5;
	coun.next = (population *)malloc(sizeof(population));
	coun.next->country = 10;
	coun.next->next = NULL;
	
	for(population* i = &coun; i != NULL; i = i->next){
		printf("%d\n", i->country);
	}
	
	free(coun.next);
}
