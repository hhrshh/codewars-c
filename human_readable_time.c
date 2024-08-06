#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

// HH = hours, padded to 2 digits, range: 00 - 99
// MM = minutes, padded to 2 digits, range: 00 - 59
// SS = seconds, padded to 2 digits, range: 00 - 59
// The maximum time never exceeds 359999 (99:59:59)

// You can find some examples in the test fixtures.

char *human_readable_time(unsigned seconds, char *time_string)
{
	time_string = '\0'; // write to time_string
	return time_string; // return it
}

int main(void)
{
    unsigned seconds = 359999;
    char *time_string;

    printf("%s\n", human_readable_time(seconds, time_string));
    return 0;
}