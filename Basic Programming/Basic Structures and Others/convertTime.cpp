#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int hrs;
	int mins;
	char day[3];
}time;

time* inputTime(){
	time* gets = (time*)malloc(sizeof(time));
	
	printf("Enter Time: ");
	scanf("%d:%d %2s", &gets->hrs, &gets->mins, gets->day);
	
return gets;
}

void convertTime12hr(time* fetch){
	if(fetch.day )
}

int main(){
	time* fetch;
	fetch = inputTime();
	
	printf("%02d:%02d %s", fetch->hrs, fetch->mins, fetch->day);
}
