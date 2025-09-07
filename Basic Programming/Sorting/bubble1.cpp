#include <stdio.h>
#include <stdlib.h>

int main(){

int num[5];
int i, j;
int swap;

for(i = 0;i < 5;i++){
	printf("Num %d:", i+1);
	scanf("%d", &num[i]);
}

for(i = 0;i < 5;i++){
	for(j = 0; j < 4; j++){
		if(num[j] > num[j+1]){
			int temp = num[j];
			num[j] = num[j+1];
			num[j+1] = temp;
		}
	}
}
	printf("Sorted Numbers\n");
for(i = 0;i < 5;i++){
	printf("%d ", num[i]);
	} 
}




	

