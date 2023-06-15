#include <stdio.h>

// Function to find the biggest of two numbers using if-else
int findBiggestIfElse(int num1, int num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}

// Function to find the biggest of two numbers using the ternary operator
int findBiggestTernary(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int biggestIfElse = findBiggestIfElse(num1, num2);
    int biggestTernary = findBiggestTernary(num1, num2);

    printf("Using if-else: %d is the biggest.\n", biggestIfElse);
    printf("Using ternary operator: %d is the biggest.\n", biggestTernary);

    return 0;
}
