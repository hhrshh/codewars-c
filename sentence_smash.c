#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#define MAX_STRINGS 7

// Sentence Smash
// Write a function that takes an array of words and smashes them together into a sentence and returns the sentence.
// You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word.
// Be careful, there shouldn't be a space at the beginning or the end of the sentence!

// Example
// ['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'


char *smash(const char *const words[/* count */], size_t count)
{
    int num = 0;
    for (size_t i = 0; i < count; ++i)
        num += strlen(words[i]);
    char *resault = NULL;
    resault = calloc(num * sizeof(char) + count + 1, sizeof(char));
    if(resault == NULL)
        printf("Memory allocation error!\n");

    size_t i = 0;
    while (i < count)
    {
        strcat(resault, words[i++]);
        if(i < count)
            strcat(resault, " ");
    }
    strcat(resault, "\0");
    return resault;
}


int main(void)
{   

    const char *strings[] = {"ldm", "ffb", "fyoeea", "o", "xqgj", "e", "sve"};




    printf("%s-\n", smash(strings, MAX_STRINGS));
    return 0;
}