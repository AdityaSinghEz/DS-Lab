#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int topIndex = -1;

void push(char c)
{
    stack[++topIndex] = c;
}

char pop()
{
    if (topIndex == -1)
        return '\0';
    return stack[topIndex--];
}

int check(char input[])
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        push(input[i]);
    }
    for (int i = 0; i < length; i++)
    {
        if (input[i] != pop())
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    if (check(input))
        printf("It's a Palindrome\n");
    else
        printf("Not a Palindrome\n");
}
