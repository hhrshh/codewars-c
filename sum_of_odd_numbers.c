#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>

// Given the triangle of consecutive odd numbers:

//                1
//             3     5
//          7     9    11
//      13    15    17    19
//   21    23    25    27    29
//31    33    35    37    39    41 
// ...
// Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.: (Input --> Output)

// 1 -->  1
// 2 --> 3 + 5 = 8
// 2 * (n - 1)


uint64_t rowSumOddNumbers(uint64_t n)
{   
    return (n * n * n);
}


int main(void)
{
    printf("%ld\n", rowSumOddNumbers(5));
    return 0;
}