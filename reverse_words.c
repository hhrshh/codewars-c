#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

// Examples
// "This is an example!" ==> "sihT si na !elpmaxe"
// "double  spaces"      ==> "elbuod  secaps"


char* reverseWords(const char* text)
{   
    int num = strlen(text);
    char *resault = malloc(num * sizeof(char) + 1);
    int i = 0;
    for (int word = 0; i <= num; ++i)
    {
        if(word > 0 && (text[i] == ' ' || text[i] == '\0'))
        {
            for (int j = i - word, w = i; word >= 0; --word)
                resault[j++] = text[--w];
            word = 0;
            resault[i] = ' ';
        }
        else if(text[i] != ' ')
            ++word;
        else
            resault[i] = ' ';
    }
    resault[--i] = '\0';
    return resault;
}

int main(void)
{
    char text[] = "double  spaced  words";
    printf("%s\n", reverseWords(text));
    return 0;
}