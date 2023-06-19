#include <stdio.h>

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // Leap year
            } else {
                return 0; // Not a leap year
            }
        } else {
            return 1; // Leap year
        }
    } else {
        return 0; // Not a leap year
    }
}

int countDays(int month, int year) {
    int days;

    switch (month) {
        case 1: // January
        case 3: // March
        case 5: // May
        case 7: // July
        case 8: // August
        case 10: // October
        case 12: // December
            days = 31;
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            days = 30;
            break;
        case 2: // February
            if (isLeapYear(year)) {
                days = 29; // Leap year
            } else {
                days = 28; // Not a leap year
            }
            break;
        default:
            days = -1; // Invalid month
            break;
    }

    return days;
}

int main() {
    int month, year;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    int days = countDays(month, year);

    if (days == -1) {
        printf("Invalid month entered.\n");
    } else {
        printf("Number of days: %d\n", days);
    }

    return 0;
}
