#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAtStart(struct node *head)
{
    struct node *inode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of node inserted:\n");
    scanf("%d", &inode->data);
    inode->next = head;
    return inode;
}

void insertAtLast(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    struct node *inode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of node inserted:\n");
    scanf("%d", &inode->data);
    inode->next = NULL;
    temp->next = inode;
}

void insertAtIndex(struct node *head, int index)
{
    int i = 0;
    struct node *inode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of node inserted:\n");
    scanf("%d", &inode->data);
    struct node *temp = head;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }

    inode->next = temp->next;
    temp->next = inode;
}

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 4;
    head->next = NULL;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->data = 2;
    second->next = NULL;
    head->next = second;

    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->data = 0;
    third->next = NULL;
    second->next = third;

    head = insertAtStart(head);
    insertAtLast(head);
    insertAtIndex(head, 2);
    traverse(head);
}
