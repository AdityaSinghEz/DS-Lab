
#include <stdio.h>
#include <stdlib.h>

struct queue_node
{
    int data;
    struct queue_node *next;
} *front = NULL, *rear = NULL;

void enqueue()
{
    struct queue_node *newnode;
    newnode = (struct queue_node *)(malloc(sizeof(struct queue_node)));
    printf("Enter the value to be inserted\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct queue_node *temp = front;
    printf("\n\nDequeued node =\n Value = %d\n\n", front->data);
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
        front = front->next;
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct queue_node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
