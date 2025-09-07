#include <stdio.h>
#include <string.h>

void extractWords(char sentence[], char words[][10]) {
    char *token = strtok(sentence, " ");
    int i = 0;

    while (token != NULL) {
        strcpy(words[i++], token);
        token = strtok(NULL, " ");
    }
}

int isWordPresent(char word[], char words[][10]) {
    for (int i = 0; words[i][0] != '\0'; ++i) {
        if (strcmp(word, words[i]) == 0) {
            return 1; // Word is present
        }
    }
    return 0; // Word is not present
}

int main() {
    char sentences[3][10];
    char words[3][10][10];

    // Input three sentences
    for (int i = 0; i < 3; ++i) {
        printf("Enter sentence %d: ", i + 1);
        scanf(" %99[^\n]", sentences[i]);
        extractWords(sentences[i], words[i]);
    }

    // Find and print common words
    printf("\nCommon words: ");
    for (int i = 0; words[0][i][0] != '\0'; ++i) {
        if (isWordPresent(words[0][i], words[1]) && isWordPresent(words[0][i], words[2])) {
            printf("%s ", words[0][i]);
        }	
    }

    return 0;
}



