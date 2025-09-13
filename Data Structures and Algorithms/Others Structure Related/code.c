#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Header.h"
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool addProductBaseOnExpiry(Inventory *i, Product p) {
	NodePtr box;
	box = malloc(sizeof(NodeType));
	bool value;
	if(box == NULL && i->currQty + p.prodQty < 100) {
		value = false; 
	}
	//use loop if there is a passed container(arr|LL) in order to check every value in that placement 
	Inventory contain;
	initInventory(&contain);
	while(i->top != NULL && dateDiffrence(i->top->prod.expiry, p.expiry) >= 0) {
		NodePtr holdPtr = i->top;
		i->top = holdPtr->link;
		holdPtr->link = contain.top;
		contain.top = holdPtr;
	}
	box->link = i->top;
	i->top = box;
	i->currQty += p.prodQty;
	
	while(contain.top != NULL) {
		NodePtr newP = contain.top;
		contain.top = newP->link;
		newP->link = i->top;
		i->top = newP;
		value = true; 
	}
	
	return value;
}
int main(int argc, char *argv[]) {
	 ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    int i;
    for(i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }

    for(i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}


