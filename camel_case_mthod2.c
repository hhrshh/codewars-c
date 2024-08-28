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
    int num = strlen(s);
    char *p = NULL;
    p = (char*)malloc(sizeof(char) * num + 1);
    if(p == NULL)
       printf("Memory allocated error");
    int j = 0, flag = 1;
    for(int i = 0; i < num; ++i)
    {
        if(isalpha(s[i]))
        {
            p[j++] = s[i];
            if(flag)
            {
                p[j - 1] = toupper(p[j - 1]);
                flag = 0;
            }
        }
        else
            flag = 1;
    }
    p[j] = '\0';
    return p;
}



int main(void)
{
    char* s = "hello case"; 
    printf("%s\n", camel_case(s));
    return 0;
}