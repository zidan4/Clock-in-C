#include <stdio.h>
#include <unistd.h> // For sleep function
#include <time.h>   // For time functions

void displayClock(int hour, int minute, int second) {
    printf("\r%02d:%02d:%02d", hour, minute, second);
    fflush(stdout);
}

int main() {
    int hour, minute, second;

    // Initialize the time to 00:00:00
    hour = 0;
    minute = 0;
    second = 0;

    printf("Simple Clock\n");

    while (1) {
        // Display the current time
        displayClock(hour, minute, second);

        // Wait for 1 second
        sleep(1);

        // Increment seconds
        second++;

        // Handle overflow of seconds
        if (second == 60) {
            second = 0;
            minute++;
        }

        // Handle overflow of minutes
        if (minute == 60) {
            minute = 0;
            hour++;
        }

        // Handle overflow of hours
        if (hour == 24) {
            hour = 0;
        }
    }

    return 0;
}

