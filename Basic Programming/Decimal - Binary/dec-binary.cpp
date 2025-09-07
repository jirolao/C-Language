#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimalToBinary(int num) {
	
    char *value = (char *)malloc(9 * sizeof(char));
    int temp, counter = 7;
    
    while (counter >= 0) {
        if (num % 2 == 0) {
            *(value + counter) = '0';
        } else {
            *(value + counter) = '1';
        }
        temp = num / 2;
        num = temp;
        counter--;
    }
    *(value + 8) = '\0';

    return value;
}

int main() {
    int num;
    char *binary;

    printf("Enter Time (integer): ");
    scanf("%d", &num);

    binary = decimalToBinary(num);

    printf("Binary representation: %s\n", binary);

    free(binary);

    return 0;
}

