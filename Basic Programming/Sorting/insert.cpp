#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertSort(int *num){
	int i, k, temp;
	for(i = 1;i < 5;i++){
		temp = num[i];
		k = i - 1;
		while(num[k] > temp){
			num[k+1] = num[k];
			k = k - 1;
		}
		num[k+1] = temp;
	}
}

int main(){
	int num[5];
	int i;
	
	for(i = 0;i < 5;i++){
		printf("Num%d: ", i+1);
		scanf("%d", &num[i]);
	}
	
	insertSort(num);
	
	printf("Sorted Numers\n");
	
	for(i = 0;i < 5;i++){
		printf("%d ", num[i]);
	}
		
}
