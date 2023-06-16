#include <stdio.h>

int findLargestAfterDeletion(int num) {
    int largest = 0;
    int temp, rem, mult;
    
    // Iterate through each digit
    for (int i = 0; i < 4; i++) {
        temp = num;
        rem = 1;
        mult = 1;

        // Exclude the current digit
        for (int j = 0; j < i; j++) {
            rem *= 10;
            mult *= 10;
        }
        temp = (temp / (mult * 10)) * mult + (temp % rem);

        // Check if the resulting number is larger than the current largest
        if (temp > largest)
            largest = temp;
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largest = findLargestAfterDeletion(num);
    printf("Largest number after deleting a single digit: %d\n", largest);

    return 0;
}
