#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// An isogram is a word that has no repeating letters,
// consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram.
// Assume the empty string is an isogram. Ignore letter case.

// Example: (Input --> Output)

// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)


bool IsIsogram(const char *string) 
{
    uint32_t mask = 0, pre_mask = 0;
    for(int i = 0; string[i] != 0; ++i, pre_mask = mask)
    {
        mask = 1 << ((string[i] | (1 << 5)) - 97) | mask;
        if(mask == pre_mask)
           return false;
    }
    return true;
}



int main(void)
{
    char* isogram = "moOse"; 
    printf("%s\n", IsIsogram(isogram) ? "Yes" : "No");
    return 0;
}