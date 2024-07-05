#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define LEN 13

// Given an array of integers, find the one that appears an odd number of times.
// There will always be only one integer that appears an odd number of times.

// Examples
// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).


int find_odd (size_t length, const int array[length])
{
  int xor = 0;

  for (size_t i = 0; i < length; i++)
    xor ^= array[i];

  return xor;
}



int main(void)
{
    int array[LEN] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    printf("%d\n", find_odd(LEN, array));
    return 0;
}