#include <stdio.h>

// Structure for representing a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time startTime, struct Time endTime) {
    struct Time difference;

    // Convert both time periods to seconds
    int startTimeInSeconds = startTime.hours * 3600 + startTime.minutes * 60 + startTime.seconds;
    int endTimeInSeconds = endTime.hours * 3600 + endTime.minutes * 60 + endTime.seconds;

    // Calculate the difference in seconds
    int differenceInSeconds = endTimeInSeconds - startTimeInSeconds;

    // Convert the difference back to hours, minutes, and seconds
    difference.hours = differenceInSeconds / 3600;
    differenceInSeconds %= 3600;
    difference.minutes = differenceInSeconds / 60;
    difference.seconds = differenceInSeconds % 60;

    return difference;
}

int main() {
    struct Time startTime, endTime, difference;

    // Read the start time from the user
    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    // Read the end time from the user
    printf("Enter the end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    // Calculate the difference between the time periods
    difference = calculateTimeDifference(startTime, endTime);

    // Display the difference
    printf("\nDifference between the time periods:\n");
    printf("Hours: %d\n", difference.hours);
    printf("Minutes: %d\n", difference.minutes);
    printf("Seconds: %d\n", difference.seconds);

    return 0;
}
