#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = 0;

void createStack(int n)
{
    if (n == 0)
        return;
    node *temp;
    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = top;
        top = temp;
    }
}

void displayStack()
{
    if (top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    node *temp = top;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push()
{
    int data;
    printf("Enter data to be pushed: ");
    scanf("%d", &data);
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = top;
    top = new;
}

void pop()
{
    if (top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    node *temp = top;
    top = top->next;
    free(temp);
}

void peek()
{
    if (top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", top->data);
}

void isEmpty()
{
    if (top == 0)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

int main()
{
    int n;
    printf("Enter size of stack: ");
    scanf("%d", &n);
    createStack(n);
    int choice = 1;
    while (choice)
    {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            displayStack();
            break;
        case 6:
            choice = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
