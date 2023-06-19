#include <stdio.h>
#include <string.h>

void rotateString(char* str, int positions) {
    int length = strlen(str);

    // Ensure positive number of positions within the length of the string
    positions = positions % length;

    // Rotate the string by moving characters
    for (int i = 0; i < positions; i++) {
        char temp = str[0];

        // Shift each character one position to the left
        for (int j = 0; j < length - 1; j++) {
            str[j] = str[j + 1];
        }

        // Place the first character at the end
        str[length - 1] = temp;
    }
}

int main() {
    char str[100];
    int positions;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    printf("Original string: %s\n", str);

    rotateString(str, positions);

    printf("Rotated string: %s\n", str);

    return 0;
}
