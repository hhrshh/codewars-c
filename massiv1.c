#include <stdio.h>
#include <stdlib.h>

int find_outlier(const int values[], size_t count)
{
    int tmp_even = 0, tmp_odd = 0;
    int even = 0, odd = 0;
    for (--count;count >= 0;--count)
    {

        if(values[count] % 2 == 0)
        {
            ++even;
            tmp_even = values[count];
        }
        else
        {
            ++odd;
            tmp_odd = values[count];
        }

        if(even > 0 && odd > 0 && even != odd)
            return even > odd ? tmp_odd : tmp_even;
    }
}

int main(void)
{
    int count = 3;
    int values[3] = {4, 1, 4};
    printf("%d\n", find_outlier(values, count));
    
    return 0;
}