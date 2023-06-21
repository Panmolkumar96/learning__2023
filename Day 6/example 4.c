#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudentsByMarks(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the positions of students[j] and students[j+1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(struct Student* students, int size) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Allocate memory for the array of structures
    students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Read the student details
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &(students[i].rollno));

        printf("Enter Name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Sort the array of structures by marks in descending order
    sortStudentsByMarks(students, size);

    // Display the sorted student details
    displayStudents(students, size);

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
