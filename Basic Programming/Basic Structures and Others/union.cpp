#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int select;
    union {
        char name[20];
        int age;
        char job[20];
    } det;
} sel;

sel* getInfo(int length) {
    int i;
    sel *arr = (sel*)malloc(sizeof(sel) * length);

    for (i = 0; i < length; i++) {
        printf("Enter [1]Name | [2]Age | [3]Job\n");
        scanf("%d", &arr[i].select);

        if (arr[i].select == 1) {
            printf("Enter Name: ");
            scanf(" %99[^\n]", arr[i].det.name);
        } else if (arr[i].select == 2) {
            printf("Enter Age: ");
            scanf("%d", &arr[i].det.age);
        } else if (arr[i].select == 3) {
            printf("Enter Job: ");
            scanf(" %99[^\n]", arr[i].det.job);

        }
    }
    return arr;
}
/*
void display(sel *show, int length){
	
	int i;
	
	do{
		printf("Search[Name]: ");
		scanf(" %99[^\n]", pers);
	}while(strcmp(pers, show[i].det.name) == 0);
		printf("%s\n", pers);
		printf("%d", show[i].det.age);
		printf("%s", show[i].det.job);

	for(i = 0;i < length;i++){
		printf("Search[Name]: ");
		scanf(" %99[^\n]", pers);
		if(strcmp(pers, show[i].det.name) == 0){
			printf("")
		}
	}
}
*/
int main() {
    int i, length = 3;
    sel *show;

    show = getInfo(length);
    
    //display(show, length);

    free(show);

    return 0;
}

