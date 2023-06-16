#include <stdio.h>
#include <limits.h>

void findSmallestAndLargestDigits(int n) {
    int i, num;
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int currentDigit;

    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        // Find the smallest and largest digit in the current number
        while (num != 0) {
            currentDigit = num % 10;

            if (currentDigit < smallest)
                smallest = currentDigit;

            if (currentDigit > largest)
                largest = currentDigit;

            num /= 10;
        }
    }

    if (smallest == INT_MAX || largest == INT_MIN)
        printf("Not Valid\n");
    else
        printf("Smallest digit: %d\nLargest digit: %d\n", smallest, largest);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    findSmallestAndLargestDigits(n);

    return 0;
}
