#include <stdio.h>
int push(int top, int n, int stack[])
{
    if (top == n - 1)
    {
        printf("Overflow\n");
        return top;
    }
    else
    {
        int data;
        printf("Enter data to be entered:\n");
        scanf("%d", &data);
        stack[++top] = data;
        return top;
    }
}
int pop(int top, int n, int stack[])
{
    if (top == -1)
    {
        printf("Underflow\n");
        return top;
    }
    else
        return top - 1;
}
void peek(int top, int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty:\n");
    }
    else
    {
        printf("%d", stack[top]);
    }
}
void isEmpty(int top)
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}
void isFull(int top, int n)
{
    if (top == n - 1)
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}
void display(int top, int n, int stack[])
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter size of the stack: ");
    scanf("%d", &n);
    int stack[n];
    int top = -1;
    int choice;
    do
    {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Check if stack is full\n");
        printf("6. Display stack\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            top = push(top, n, stack);
            break;
        case 2:
            top = pop(top, n, stack);
            break;
        case 3:
            peek(top, stack);
            break;
        case 4:
            isEmpty(top);
            break;
        case 5:
            isFull(top, n);
            break;
        case 6:
            display(top, n, stack);
            break;
        case 7:
            choice = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);
}
