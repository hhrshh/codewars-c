#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>

// A pangram is a sentence that contains every single letter of the alphabet at least once.
// For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram,
// because it uses the letters A-Z at least once (case is irrelevant).
// Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.

// "The quick, brown fox jumps over the lazy dog!",  true
// "The quick, brown fox jumped over the lazy dog!", false

bool is_pangram(const char *str_in)
{
    uint32_t mask = 0;
    for (int i = 0; str_in[i] != 0; ++i)
        if(str_in[i] >= 65 && str_in[i] <= 90 || str_in[i] >= 97 && str_in[i] <= 122)
            mask = (1 << (((str_in[i] | (1 << 5)) - (1 << 5)) - (1 << 6))) | mask;
    return mask == 134217726;
}

int main(void)
{
    char* pangram = "The quick, brown fox jumped over the lazy dog!"; 
    printf("%s\n", is_pangram(pangram) ? "Yes" : "No");
    return 0;
}