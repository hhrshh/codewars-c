#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>



// Complete the method/function so that it converts dash/underscore delimited words into camel casing.
// The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case).
// The next words should be always capitalized.

// Examples
// "the-stealth-warrior" gets converted to "theStealthWarrior"

// "The_Stealth_Warrior" gets converted to "TheStealthWarrior"

// "The_Stealth-Warrior" gets converted to "TheStealthWarrior"


//  do not allocate memory for the result
//  write to pre-allocated pointer *camel


void to_camel_case(const char *text, char *camel)
{
    int flag = 0;
    int i = 0;
    int j = 0;
    while (text[i])
    {
        if(isalpha(text[i]))
        {
            camel[j++] = text[i];
            if(flag)
            {
                camel[j - 1] = toupper(camel[j - 1]);
                flag = 0;
            }
        }
        else
            flag = 1;
        ++i;
    }
    camel[j] = '\0';
}

int main(void)
{
    char *text = "the-stealth-warrior";
    char camel[255] = "the-stealth-warrior";
    to_camel_case(text, camel);
    printf("%s\n", camel);
    return 0;
}