#include <stdio.h>
#include <stdlib.h>

int stringToInteger(char* str) {
    int result = 0;
    int i = 0;

    // Check for negative sign
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    // Convert each digit to integer and update the result
    while (str[i] != '\0') {
        int digit = str[i] - '0';
        result = result * 10 + digit;
        i++;
    }

    // Apply the sign
    result = result * sign;

    return result;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the input
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int number = stringToInteger(str);

    printf("Converted integer: %d\n", number);

    return 0;
}
