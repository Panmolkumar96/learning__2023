#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void transformToUpperCase(FILE *source, FILE *destination) {
    int ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void transformToLowerCase(FILE *source, FILE *destination) {
    int ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void transformToSentenceCase(FILE *source, FILE *destination) {
    int ch;
    int previous = '.';
    int current;

    while ((ch = fgetc(source)) != EOF) {
        current = ch;

        if (previous == '.' || previous == '?' || previous == '!') {
            fputc(toupper(current), destination);
        } else {
            fputc(tolower(current), destination);
        }

        previous = current;
    }
}

void copyFile(FILE *source, FILE *destination) {
    int ch;

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char *option;
    char *sourceFileName;
    char *destinationFileName;

    if (argc < 3) {
        printf("Insufficient arguments!\n");
        printf("Usage: ./cp -u/-l/-s source_file destination_file\n");
        return 1;
    }

    option = argv[1];
    sourceFileName = argv[2];
    destinationFileName = argv[3];

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error creating the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Perform case transformation based on the option
    if (strcmp(option, "-u") == 0) {
        transformToUpperCase(sourceFile, destinationFile);
    } else if (strcmp(option, "-l") == 0) {
        transformToLowerCase(sourceFile, destinationFile);
    } else if (strcmp(option, "-s") == 0) {
        transformToSentenceCase(sourceFile, destinationFile);
    } else {
        copyFile(sourceFile, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
