#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Create a function which answers the question "Are you playing banjo?".
// If your name starts with the letter "R" or lower case "r", you are playing banjo!

// The function takes a name as its only argument, and returns one of the following strings:

// name + " plays banjo" 
// name + " does not play banjo"
// Names given are always valid strings.


char *strdup(const char* str)
{
  if (str == NULL)
    return NULL;

    char* duplicate = (char*)malloc(strlen(str) + 1);
    if (duplicate == NULL)
      return NULL;

    strcpy(duplicate, str);

    return duplicate;
}

char *are_you_playing_banjo(const char *name)
{
    char *s = strdup(name);
    if(name[0] == 'R' || name[0] == 'r')
        return strcat(s, " plays banjo");
    return strcat(s, " does not play banjo");
}



int main(void)
{
    
    char *s1 = "Martin";
    char *s2 = "Ravo";
    printf("%s\n", are_you_playing_banjo(s1));
    printf("%s\n", are_you_playing_banjo(s2));
    return 0;
}