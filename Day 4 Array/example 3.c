#include <stdio.h>

int main() {
    int array[100], reversedArray[100];
    int n, i, j;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Reverse the array
    j = 0;
    for (i = n - 1; i >= 0; i--) {
        reversedArray[j] = array[i];
        j++;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nReversed array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", reversedArray[i]);
    }

    return 0;
}
