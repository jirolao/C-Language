#include <stdio.h>
#include <string.h>

void getWords(char sentences[], char words[][20]){
	char *token = strtok(sentences, " ");
	
	int i = 0;
	while( token != NULL){
		strcpy(words[i++], token);
		token = strtok(NULL, " ");
	}
}

int common(){
	
	
}

int main(){
	char sentences[3][20], words[3][20][20];
	
	int i;
	for(i = 0;i < 3; i++){
		printf("Enter: ");
		scanf(" %99[^\n]", sentences[i]);
		getWords(sentences[i], words[i]);
	}
}
