#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

// The arguments are passed as strings.
// The numbers may be way very large
// Answer should be returned as a string
// The returned "number" should not start with zeros e.g. 0123 is invalid
// Note: 100 randomly generated tests!



char *multiply (const char *a, const char *b)
{
  int ia = strlen(a);
  int ib = strlen(b);
  int num = ia + ib;
  char *str = NULL;
  int flag = 0;

  str = (char*)calloc(sizeof(char) * num + 1, sizeof(char));
  --ia;
  --ib;
  num = num - 1;
  
  // multiplay
  for (int i = ia, ik = 0, j = ib, ij = 0 ;i >= 0; --i, ++ik)
  {
    for (j = ib, ij = 0; j >= 0; --j, ++ij)
    {
      str[num - ik - ij] += (a[i]-48) * (b[j]-48) + flag;
      flag = 0;
      if(str[num - ik - ij] > 9)
      {
        flag = str[num - ik - ij] / 10;
        str[num - ik - ij] = str[num - ik - ij] % 10;
      }
    }
    str[num - ik - ij] = flag;
    flag = 0;
  }

  
  // removing 0, 000132 => 123
  for(int i = 0, j = 0; i <= num; ++i)
  {
    if(str[i] == 0 && i == num)
      num = 0;
    if(str[i] == 0)
      continue;
    else if(i > 0)
      for(num = num - i; j <= num; ++j, ++i)
        str[j] = str[i];
    break;
  }

  str[num + 1] = '\0';

  // int => char
  for(int i = 0; i <= num; ++i)
    str[i] += 48;


  return str;
}

int main(void)
{

  char a[] = "09";
  char b[] = "0000009";
  printf("%s\n", multiply(a, b));
    
  return 0;
}