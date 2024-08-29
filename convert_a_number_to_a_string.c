#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


//  return a dynamically allocated C-string
//  this output will be freed by the tester

char *number_to_string(int number)
{
    char *str = malloc(sizeof(char) * 11);
    sprintf(str, "%d", number);
    return str;
}

int main(void)
{
    int number = 123456;
    printf("%s\n", number_to_string(number));
}