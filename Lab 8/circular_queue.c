#include <stdio.h>
#include <stdlib.h>
#define N 6

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Empty queue\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % N;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
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
