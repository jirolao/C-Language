#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
	int elem[MAX];
	int count;
}LIST;

LIST allEvens(int*, int);


int main(){
	
	LIST given, receiver;
	int i;
	
	for(i=0;i<MAX;i++){
		scanf("%d", &given.elem[i]);
	}
	given.count = sizeof(given.elem)/sizeof(int);
	
	receiver = allEvens(given.elem, given.count);
	
	printf("Even numbers:");
	for(i=0;i<receiver.count;i++){
		printf("%d,", receiver.elem[i]);
	}
	
}


LIST allEvens(int *arr, int size){
	
	int a;
	LIST ret;
	ret.count=0;
	
	for(a=0;a<size;a++){
		if(arr[a]%2==0){
			ret.elem[ret.count++]=arr[a];
		}
	}
	
	return ret;
		
}
