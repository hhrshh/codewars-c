#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))


// Given the string representations of two integers, return the string representation of the sum of those integers.

// For example:

// strsum("1", "2")    /* => 3 */
// A string representation of an integer will contain no characters besides the ten numerals "0" to "9".

// I have removed the use of BigInteger and BigDecimal in java

// Python: your solution need to work with huge numbers (about a milion digits), converting to int will not work.

// StringsBig IntegersAlgorithms
// Suggest kata description edits



char *strsum(const char *a, const char *b)
{
    int an = strlen(a);
    int bn = strlen(b);
    int dif;
    int max = MAX(an, bn);

    char *sum = NULL;
    sum = (char*)calloc(sizeof(char) * max + 2, sizeof(char));
    if(sum == NULL)
        fprintf(stderr, "Allocated memory error!\n");
    
    char *min = NULL;
    min = (char*)calloc(sizeof(char) * max + 2, sizeof(char));
    if(min == NULL)
        fprintf(stderr, "Allocated memory error!\n");
        
    if(an > bn)
    {
        dif = an - bn + 1;
        for(int i = 0; i < dif; ++i)
            sum[i] = '0';
        strcat(sum, b);
        min[0] = '0';
        strcat(min, a);
    }

    else
    {
        dif = bn - an + 1;
        for(int i = 0; i < dif; ++i)
            sum[i] = '0';
        strcat(sum, a);
        min[0] = '0';
        strcat(min, b);
    }

    for (int i = max; i >= 0; --i)
    {
        sum[i] += min[i] - 48;
        if(sum[i] > 57)
        {
            sum[i - 1] += 1;
            sum[i] = sum[i] - 10;
        }
    }

    // int -> char
    for (int i = 0; i != 0; ++i)
        sum[i] += 48;
    
    // removing 0, 000132 => 123
    for(int i = 0, j = 0; i <= max; ++i)
    {
        if(sum[i] == 0 && i == max)
            max = 0;
        if(sum[i] == '0')
            continue;
    else if(i > 0)
        for(max = max - i; j <= max; ++j, ++i)
            sum[j] = sum[i];
        break;
    }
      sum[max + 1] = '\0';
        
    free(min);
    return sum;
}

int main(void)
{

  char a[] = "00000";
  char b[] = "0";
  printf("%s\n", strsum(a, b));
    
  return 0;
}