#include <stdio.h>

// Define the structure for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of the box
double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

// Function to calculate the total surface area of the box
double calculateSurfaceArea(struct Box* boxPtr) {
    double length = boxPtr->length;
    double width = boxPtr->width;
    double height = boxPtr->height;

    return 2 * (length * width + width * height + height * length);
}

int main() {
    struct Box myBox = { 3.0, 4.0, 5.0 };
    struct Box* boxPtr = &myBox;

    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
