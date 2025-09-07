#include <stdio.h>
#include <stdlib.h>

void swapNum(int *num){
    
	int i, k;
	int swap;
	int temp;
	
	for(i = 0;i < 5 - i - 1;i++){
	swap = 0;
	for(k = 0;k < 5 - i - 1;k++){
		temp = 0;
		if(num[k] > num[k+1]){
			swap +=1;
			temp = num[k];
			num[k] = num[k+1];
			num[k+1] = temp;
			}
				if(swap = 0){
			break;
			}
		}
	}
}

int main(){

int num[5];
int i;

for(i = 0;i < 5;i++){
	printf("Num %d:", i+1);
	scanf("%d", &num[i]);
}

	swapNum(num);

	printf("Sorted Numbers\n");
	
	for(i = 0;i < 5;i++){
	printf("%d ", num[i]);
	}
}


	

