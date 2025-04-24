#include <stdio.h>
#include <stdlib.h>
#define N 8

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("\nQueue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
