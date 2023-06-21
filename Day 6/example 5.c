#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student* students, int size, const char* name) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with name '%s' not found.\n", name);
    }
}

int main() {
    int size;
    struct Student* students;
    char searchName[20];

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

    // Read the name to search
    printf("\nEnter the name to search: ");
    scanf(" %[^\n]s", searchName);

    // Perform search operation on the array of structures
    searchStudentByName(students, size, searchName);

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
