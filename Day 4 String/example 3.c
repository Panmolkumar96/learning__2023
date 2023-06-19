#include <stdio.h>

int computeTotalSeconds(int hours, int minutes, int seconds) {
    return (hours * 3600) + (minutes * 60) + seconds;
}

int main() {
    int hours, minutes, seconds;

    printf("Enter the time in hours, minutes, and seconds:\n");
    printf("Hours: ");
    scanf("%d", &hours);
    printf("Minutes: ");
    scanf("%d", &minutes);
    printf("Seconds: ");
    scanf("%d", &seconds);

    int totalSeconds = computeTotalSeconds(hours, minutes, seconds);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
