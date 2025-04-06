#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int isValidChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int getPrio(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isRightAssoc(char op)
{
    return op == '^';
}

void toPostfix(char input[], char output[])
{
    int outInd = 0;
    for (int i = 0; input[i]; i++)
    {
        char c = input[i];
        if (isValidChar(c))
        {
            output[outInd++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                output[outInd++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && peek() != '(' && (getPrio(peek()) > getPrio(c) || (getPrio(peek()) == getPrio(c) && !isRightAssoc(c))))
                output[outInd++] = pop();
            push(c);
        }
    }
    while (top != -1)
        output[outInd++] = pop();
    output[outInd] = '\0';
}

int main()
{
    char expr[MAX], postfix[MAX];
    printf("Enter expression:\n");
    scanf("%s", expr);
    toPostfix(expr, postfix);
    printf("Postfix: %s\n", postfix);
}
