#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>

// Per Wikipedia, a prime number ( or a prime ) is a natural number greater than 1
// that has no positive divisors other than 1 and itself.

// Requirements
// You can assume you will be given an integer input.
// You can not assume that the integer will be only positive. You may be given negative numbers as well ( or 0 ).
// NOTE on performance: There are no fancy optimizations required,
// but still the most trivial solutions might time out. Numbers go up to 2^31
// ( or similar, depending on language ). Looping all the way up to n, or n/2, will be too slow.
// Example
// is_prime(1)  /* false */
// is_prime(2)  /* true  */
// is_prime(-1) /* false */

bool is_prime(int num)
{
    if(num < 2)
        return false;
    for (size_t i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
        return false;
    }
    return true;
}

int main(void)
{
    int num = 247464361;
    printf("%s\n", is_prime(num) ? "Yes" : "No");
    return 0;
}