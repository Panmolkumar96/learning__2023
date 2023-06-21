#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the input string and initialize the array of structures
void parseString(const char* inputString, struct Student* students, int numStudents) {
    char* token;

    // Parse the input string and initialize the array of structures
    token = strtok((char*)inputString, " ");
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = atoi(token);
        
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name));
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        
        token = strtok(NULL, " ");
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Consume the newline character

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Read the input string from the user
    char inputString[100];
    printf("Enter the input string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0'; // Remove the newline character from the input string

    // Parse the input string and initialize the array of structures
    parseString(inputString, students, numStudents);

    // Display the initialized array of structures
    printf("\nStudent Data:\n");
    for (int i = 0; i < numStudents; i++) {
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
