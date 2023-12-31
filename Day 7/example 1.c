#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

    printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    printf("Enter the name of the destination file: ");
    scanf("%s", destinationFileName);

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error creating the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
