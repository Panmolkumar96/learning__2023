#include <stdio.h>

// Structure for representing a point
struct Point {
    int x;
    int y;
};

// Function to swap the fields of two structures using pointers
void swapStructures(struct Point* ptr1, struct Point* ptr2) {
    int tempX = ptr1->x;
    int tempY = ptr1->y;

    ptr1->x = ptr2->x;
    ptr1->y = ptr2->y;

    ptr2->x = tempX;
    ptr2->y = tempY;
}

int main() {
    struct Point point1, point2;

    // Read the coordinates for point 1
    printf("Enter the coordinates for point 1:\n");
    printf("x: ");
    scanf("%d", &(point1.x));
    printf("y: ");
    scanf("%d", &(point1.y));

    // Read the coordinates for point 2
    printf("Enter the coordinates for point 2:\n");
    printf("x: ");
    scanf("%d", &(point2.x));
    printf("y: ");
    scanf("%d", &(point2.y));

    // Display the original coordinates
    printf("\nOriginal Coordinates:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    // Swap the fields of the structures using pointers
    swapStructures(&point1, &point2);

    // Display the swapped coordinates
    printf("\nSwapped Coordinates:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    return 0;
}
