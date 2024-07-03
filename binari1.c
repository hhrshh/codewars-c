#include <stdio.h>
#include <stdlib.h>



size_t countBits(unsigned value)
{
    size_t count = 0;
    for(;value; value >>= 1)
    if(value & 1)
        ++count;
	return count;
}

int main(void)
{
    unsigned int a = 1234;
    printf("%ld\n", countBits(a));
    
    return 0;
}