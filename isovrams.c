#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>

// An isogram is a word that has no repeating letters,
// consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram.
// Assume the empty string is an isogram. Ignore letter case.

// Example: (Input --> Output)

// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)


bool IsIsogram(const char *string) 
{
	return false;
}



int main(void)
{
    char* isogram = "Dermatoglyphics"; 
    printf("%s\n", IsIsogram(isogram) ? "Yes" : "No");
    return 0;
}