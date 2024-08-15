#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

//Lyrics...
//Pyramids are amazing! Both in architectural and mathematical sense. If you have a computer,
//you can mess with pyramids even if you are not in Egypt at the time.
// For example, let's consider the following problem. Imagine that you have a pyramid built of numbers, like this one here:

//  			                [75],
//                           [95, 64],
//                         [17, 47, 82],
//                       [18, 35, 87, 10],
//                     [20,  4, 82, 47, 65],
//                   [19,  1, 23, 75,  3, 34],
//                 [88,  2, 77, 73,  7, 63, 67],
//               [99, 65,  4, 28,  6, 16, 70, 92],
//             [41, 41, 26, 56, 83, 40, 80, 70, 33],
//           [41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
//         [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
//       [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
//     [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
//   [63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
//  [4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23]

// 75+64+82+87+82+75+73+28+83+32+91+78+58+73+93 = 1074

// Let's say that the 'slide down' is the maximum sum of consecutive numbers from the top to the bottom of the pyramid.
// As you can see, the longest 'slide down' is 3 + 7 + 4 + 9 = 23
// Your task is to write a function that takes a pyramid representation as an argument and returns its largest 'slide down'. For example:
// *With the input `[[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]`
// *Your function should return `23`.
// By the way...
// My tests include some extraordinarily high pyramids so as you can guess,
// brute-force method is a bad idea unless you have a few centuries to waste. You must come up with something more clever than that.
// Memory model of `pyramid`:
// `pyramid` is a one-dimensional array containing the elements of a pyramid with `rows` levels,
// in direct succession from left to right, top to bottom


void pyramid_show(int num_elements, const int pyramid[num_elements], int rows)
{

    for(int s = rows, i = 0, j = 0; i < rows; j += i++ + 1, s = rows - i)
    {
    while(s--)
    {
        printf(" ");
    }
    printf("[ ");    
        for (int n = 0; n <= i; n++)
            printf("%02d ", pyramid[j + n]);
    printf("]\n");
    } 
}

int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows)
{
    // Create massive for the sums and offset for levels
    int res_buf[num_elements];
    int offset = num_elements - rows;

    // Beginning from last row, copy all values
    for (int i = 0; i < rows; ++i)    
        res_buf[offset + i] = pyramid[offset + i];

    for (int i = rows - 2; i >= 0; --i)
    {
        offset -= i + 1;

        for (int j = 0; j <= i; ++j)
        {
            int left = res_buf[offset + j + i + 1];
            int right = res_buf[offset + j + i + 2];
            res_buf[offset + j] = pyramid[offset + j] + (left > right ? left : right);
        }
        
    }
    return res_buf[0];
}


int main(void)
{
   int input[] = { 3, 
                   7, 4,
                   2, 4, 6,
                   8, 5, 9, 3};

    pyramid_show(sizeof(input) / sizeof(input[0]), input, 4);
    printf("\n max slide down sum = %d\n", pyramid_slide_down(sizeof(input)/sizeof(input[0]), input, 4));
    return 0;
}