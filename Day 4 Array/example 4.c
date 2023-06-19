#include <stdio.h>

int main() {
    int array[100];
    int n, i;
    int sumEven = 0, sumOdd = 0, diff;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Calculate the sum of even and odd elements
    for (i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            sumEven += array[i];
        } else {
            sumOdd += array[i];
        }
    }

    // Calculate the difference
    diff = sumEven - sumOdd;

    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Difference between even and odd elements: %d\n", diff);

    return 0;
}
