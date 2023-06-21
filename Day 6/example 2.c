#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse a string and initialize an array of structures
void initializeArray(struct Student* students, int size, char* input) {
    char* token;
    char* rest = input;
    int index = 0;

    // Parse the input string and initialize the array of structures
    while ((token = strtok_r(rest, " ", &rest)) != NULL) {
        switch (index % 3) {
            case 0:
                students[index / 3].rollno = atoi(token);
                break;
            case 1:
                strncpy(students[index / 3].name, token, sizeof(students[index / 3].name));
                break;
            case 2:
                students[index / 3].marks = atof(token);
                break;
        }
        index++;
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Clear the input buffer
    while (getchar() != '\n');

    char input[100];

    printf("Enter the student data:\n");

    // Read the input string
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Initialize the array of structures
    initializeArray(students, size, input);

    // Display the initialized array of structures
    printf("\nInitialized Array of Structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
