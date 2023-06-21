#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
};

void extractLogData(const char* filename, struct LogEntry logEntries[], int* numEntries) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[100];
    *numEntries = 0;

    // Read and parse each line in the file
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';  // Remove the newline character
        }

        // Tokenize the line using comma as the delimiter
        char* token;
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        // Extract the values and store them in the array of structures
        logEntries[*numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[*numEntries].sensorNo, token, sizeof(logEntries[*numEntries].sensorNo));

        token = strtok(NULL, ",");
        logEntries[*numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[*numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[*numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[*numEntries].timestamp, token, sizeof(logEntries[*numEntries].timestamp));

        (*numEntries)++;

        if (*numEntries >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

void displayLogData(const struct LogEntry logEntries[], int numEntries) {
    printf("Log Data:\n");
    printf("-----------------------------------------------------------------\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }

    printf("-----------------------------------------------------------------\n");
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogData("data.csv", logEntries, &numEntries);
    displayLogData(logEntries, numEntries);

    return 0;
}
