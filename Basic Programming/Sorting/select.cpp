#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectSort(int *num){
	int i, k, temp, min;

	for(i = 0;i < 5 - 1;i++){
		min = i;
		for(k = i + 1;k < 5;k++){
			if(num[k] < num[min]){
				min = k;
			}
		}
		if(min != i){
				temp = num[i];
				num[i] = num[min];
				num[min] = temp;
		}
	}
}

int main(){
	int num[5];
	int i;
	
	for(i = 0;i < 5;i++){
		printf("Num%d: ", i+1);
		scanf("%d", &num[i]);
	}
	
	selectSort(num);
	
	printf("Sorted Numners\n");
	
	for(i = 0;i < 5;i++){
		printf("%d ", num[i]);
	}
}
