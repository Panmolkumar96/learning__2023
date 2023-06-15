#include <stdio.h>

typedef struct {
    int rollNo;
    char name[50];
    int physicsMarks;
    int mathMarks;
    int chemistryMarks;
} Student;

void printSummary(Student student) {
    int totalMarks = student.physicsMarks + student.mathMarks + student.chemistryMarks;
    float percentage = (float)totalMarks / 3;

    printf("Roll No: %d\n", student.rollNo);
    printf("Name: %s\n", student.name);
    printf("Physics Marks: %d\n", student.physicsMarks);
    printf("Math Marks: %d\n", student.mathMarks);
    printf("Chemistry Marks: %d\n", student.chemistryMarks);
    printf("Total Marks: %d\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);
}

int main() {
    Student student;

    printf("Enter Roll No: ");
    scanf("%d", &student.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", student.name);

    printf("Enter Physics Marks: ");
    scanf("%d", &student.physicsMarks);

    printf("Enter Math Marks: ");
    scanf("%d", &student.mathMarks);

    printf("Enter Chemistry Marks: ");
    scanf("%d", &student.chemistryMarks);

    printf("\n");
    printf("Summary:\n");
    printSummary(student);

    return 0;
}
