#include <stdio.h>
#include <stdlib.h>

// Structure for representing student data
struct Student {
    int rollNumber;
    char name[50];
    int age;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' student structures
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &(students[i].rollNumber));

        printf("Enter Name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter Age: ");
        scanf("%d", &(students[i].age));
    }

    // Display the stored data for each student
    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
