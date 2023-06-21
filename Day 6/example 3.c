#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* inputString, struct Student* students, int size) {
    char* token;
    int count = 0;

    token = strtok(inputString, " ");
    while (token != NULL) {
        switch (count % 3) {
            case 0:
                students[count / 3].rollno = atoi(token);
                break;
            case 1:
                strcpy(students[count / 3].name, token);
                break;
            case 2:
                students[count / 3].marks = atof(token);
                break;
        }
        token = strtok(NULL, " ");
        count++;
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
    char inputString[100];
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Allocate memory for the array of structures
    students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Read the input string
    printf("Enter the student details as a string: ");
    scanf(" %[^\n]s", inputString);

    // Parse the string and initialize the array of structures
    parseString(inputString, students, size);

    // Display the student details
    displayStudents(students, size);

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
