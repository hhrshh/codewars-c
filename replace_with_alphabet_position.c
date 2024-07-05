#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// In this kata you are required to, given a string, replace every letter with its position in the alphabet.
// If anything in the text isn't a letter, ignore it and don't return it.
// "a" = 1, "b" = 2, etc.
// Example
// Input = "The sunset sets at twelve o' clock."
// Output = "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"


// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text)
{
    char *str = NULL;
    int j = 0;
    str = (char*)malloc(sizeof(char) * strlen(text) * 3 + 1);
    str[0] = '\0';
    for(int i = 0; text[i] != 0; ++i)
    {
        if(text[i] >= 65 && text[i] <= 90 || text[i] >= 97 && text[i] <= 122)
            j += snprintf(&str[j], 1000, "%d ", (text[i] | (1 << 5)) - 96);
    }
    str[j - 1] = '\0';
    return str;
}



int main(void)
{
    char* alphabet = "The sunset sets at twelve o' clock."; 
    printf("%s\n", alphabet_position(alphabet));
    return 0;
}