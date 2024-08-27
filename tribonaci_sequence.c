#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>



// Well met with Fibonacci bigger brother, AKA Tribonacci.

// As the name may already reveal, it works basically like a Fibonacci, but summing the last 3 (instead of 2) numbers of the sequence to generate the next. And,
// worse part of it, regrettably I won't get to hear non-native Italian speakers trying to pronounce it :(

// So, if we are to start our Tribonacci sequence with [1, 1, 1] as a starting input (AKA signature), we have this sequence:

// [1, 1 ,1, 3, 5, 9, 17, 31, ...]
// But what if we started with [0, 0, 1] as a signature? As starting with [0, 1] instead of [1, 1] basically shifts the common Fibonacci sequence by once place,
// you may be tempted to think that we would get the same sequence shifted by 2 places, but that is not the case and we would get:

// [0, 0, 1, 1, 2, 4, 7, 13, 24, ...]
// Well, you may have guessed it by now, but to be clear: you need to create a fibonacci function that given a signature array/list,
// returns the first n elements - signature included of the so seeded sequence.

// Signature will always contain 3 numbers; n will always be a non-negative number;
// if n == 0, then return an empty array (except in C return NULL) and be ready for anything else which is not clearly specified ;)

// If you enjoyed this kata more advanced and generalized version of it can be found in the Xbonacci kata

// [Personal thanks to Professor Jim Fowler on Coursera for his awesome classes that I really recommend to any math enthusiast
// and for showing me this mathematical curiosity too with his usual contagious passion :)]


long long *tribonacci(const long long signature[3], size_t n)
{   
    if(!n)
        return NULL;
    long long *trib = NULL;
    trib = malloc(n * sizeof(long long));
    if(trib == NULL)
        printf("Memory allocated error!");

    for (int i = 0; i < n; ++i)
        trib[i] = signature[i];
    if(n > 3)
        for (int i = 3; i < n; ++i)
            trib[i] =  trib[i - 3] + trib[i - 2] + trib[i - 1];
    return trib;
}

void trib_show(const long long* signature, size_t n)
{
    if(!n)
        printf("NULL\n");
    else
    {
        printf("{");
        for(int i = 0; i < n; ++i)
        {
            printf("%lld", signature[i]);
            if(i < n-1)
                printf(", ");
        }
        printf("}\n");
    }
}



int main(void)
{
    size_t n = 10;
    unsigned long long signature[3] = {1, 1, 1};
    int res;
    trib_show(tribonacci(signature, n), n);
    return 0;
}