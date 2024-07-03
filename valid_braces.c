#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

// This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

// All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

// What is considered Valid?
// A string of braces is considered valid if all braces are matched with the correct brace.

// Examples
// "(){}[]"   =>  True
// "([{}])"   =>  True
// "(}"       =>  False
// "[(])"     =>  False
// "[({})](]" =>  False

bool valid_braces(const char *braces)
{
    char stack[strlen(braces)]; // стек для хранения последней открывающейся скобки
    int top = -1; // указыает на положение стека
    for (int i = 0; braces[i] != '\0'; ++i)
    {

        if(braces[i] == '(' || braces[i] == '[' || braces[i] == '{')
            stack[++top] = braces[i];
        else
        {
            if(top < 0)
                return false;
            if(!(stack[top] == '(' && braces[i] == ')' || stack[top] == '[' && braces[i] == ']' || stack[top] == '{' && braces[i] == '}'))
                return false;
            --top;
        }
    }
	return top == -1;
}


int main(void)
{
    char* braces = "[(])"; 
    printf("%s\n", valid_braces(braces) ? "True" : "False");
    return 0;
}
