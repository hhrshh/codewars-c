#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

// The arguments are passed as strings.
// The numbers may be way very large
// Answer should be returned as a string
// The returned "number" should not start with zeros e.g. 0123 is invalid
// Note: 100 randomly generated tests!



char *multiply (const char *a, const char *b)
{
// return a heap-allocated string
  return calloc(1, 1);
}

int main(void)
{

    char a[] = '98765';
    char b[] = '56894';
    char *actual = multiply(a, b);
    
    return 0;
}