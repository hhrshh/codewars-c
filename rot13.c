#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet.
// ROT13 is an example of the Caesar cipher.

// Create a function that takes a string and returns the string ciphered with Rot13.
// If there are numbers or special characters included in the string,
// they should be returned as they are. Only letters from the latin/english alphabet should be shifted,
// like in the original Rot13 "implementation".

// In the elevators, the extrovert looks at the OTHER guy's shoes.
// Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

char *rot13(const char *src)
{
    char *buf = NULL;
    buf = (char*)malloc(sizeof(char) * strlen(src) + 1);
    int i = 0;
    for(; src[i]; ++i)
    {
        if(src[i] >= 'A' && src[i] <= 'M' || src[i] >= 'a' && src[i] <= 'm')
            buf[i] = src[i] + 13;
        else if(src[i] >= 'N' && src[i] <= 'Z' || src[i] >= 'n' && src[i] <= 'z')
            buf[i] = src[i] - 13;
        else
            buf[i] = src[i];
    }
    buf[++i] = '\0';
    return buf;
}



int main(void)
{
    char* src = "wab"; 
    printf("%s\n", rot13(src));
    return 0;
}