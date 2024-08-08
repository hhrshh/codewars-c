#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Write a method (or function, depending on the language) that converts a string to camelCase,
// that is, all words must have their first letter capitalized and spaces must be removed.

// Examples (input --> output):
// "hello case" --> "HelloCase"
// "camel case word" --> "CamelCaseWord"

char *camel_case(const char *s)
{
    char *p = NULL;
    p = (char*)malloc(sizeof(char) * strlen(s) + 1);

    int i = 0, j = 0, flag = 0;
    p[j++] = s[i] & 223; //Upper register
    while(s[++i])
        if(isalpha(s[i]))
        {
            if(flag)
            {
                p[j++] = s[i] ^ 32;
                flag = 0;
            }
            else
                p[j++] = s[i];
        }
        else
            flag = 1;
    return p;
}



int main(void)
{
    char* s = "The sunset sets at twelve**o!clock!!"; 
    printf("%s\n", camel_case(s));
    return 0;
}