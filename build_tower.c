#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define N 6


// void build_tower(unsigned n, char tower[n][2 * n - 1])
// {
//     for(int j = n - 1, i = 0; i < 2 * n - 1; i += 2, --j)
//     {
//         for(int p = j; p > 0; --p)
//             printf(" ");
//         for(int n = 0; n <= i; n++)
//             printf("*");
//         for(int p = j; p > 0; --p)
//             printf(" ");
//         printf("\n");
//     } 
// }

void tower_show(unsigned n, char tower[n][2 * n - 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("[");
        for (int j = 0; j < 2 * n - 1; j++)
        {
            printf("%c ", tower[i][j]);
        }
        printf("]\n");
    }
    
}

void build_tower(unsigned n, char tower[n][2 * n - 1])
{
    for(int i = 0, t1 = (2 * n - 1) / 2, t2 = t1; i < n; ++i, --t1, t2++)
    {
        for(int j = 0; j < 2 * n - 1; ++j)
        {
            if(j >= t1 && j <= t2 )
                tower[i][j] = '*';
            else
                tower[i][j] = ' ';
        }
    } 
}


int main(void)
{
    char tolower[N][2 * N - 1];
    build_tower(N, tolower);
    tower_show(N, tolower);
    return 0;
}