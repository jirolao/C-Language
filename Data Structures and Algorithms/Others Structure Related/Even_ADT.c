#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int *allEven(int*, int);

int main(){
	
	int arr[MAX]={1,2,3,4};
	int *r, i;
	
	
	r = allEven(arr, MAX);
	
	printf("%d even numbers\n", r[0]);
	
	printf("Evens:");
	for(i = 1; i<=r[0]; i++){
		printf("%d,", r[i]);
	}
	
}

int *allEven(int *a, int size){
	
	int evenArr[size], *evens, i, even=0;
	
	for(i=0;i<size;i++){
		if(a[i]%2==0){
			evenArr[even++]=a[i];
		}
	}
	
	evens = (int*)malloc(sizeof(int)*(even+1));
	
	evens[0] = even;
	
	memcpy(&evens[1],evenArr, even*sizeof(int));
	
	return evens;
	
}
