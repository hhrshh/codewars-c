#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// Implement a function that receives two IPv4 addresses, and returns the number of addresses between them
// (including the first one, excluding the last one).

// All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.

// Examples
// * With input "10.0.0.0", "10.0.0.50"  => return   50 
// * With input "10.0.0.0", "10.0.1.0"   => return  256 
// * With input "20.0.0.10", "20.0.1.0"  => return  246

uint32_t ips_between(const char *start, const char *end)
{
  return 0;
}


int main(void)
{
    char start[] = "10.0.0.0";
    char end[] = "10.0.0.50";

    
    return 0;
}