#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *nnode = NULL;
    while (curr != 0)
    {
        nnode = curr->next;
        curr->next = prev;
        curr->prev = nnode;
        prev = curr;
        curr = nnode;
    }
    return prev;
}
node *delete(node *head, int count)
{
    printf("Enter the index you wanna delete:\n");
    int ind;
    scanf("%d", &ind);
    if (ind < 1 || ind > count)
        printf("INVALID INPUT\n");
    else
    {
        node *temp = head;
        if (ind == 1)
        {
            head = head->next;
            head->prev = 0;
            free(temp);
        }
        else if (ind == count)
        {
            while (temp->next != 0)
                temp = temp->next;
            temp->prev->next = 0;
            free(temp);
        }
        else
        {
            int i = 1;
            while (i < ind)
            {
                temp = temp->next;
                i++;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}
node *insert(node *head, int count)
{
    printf("Enter index at which you wanna insert:\n");
    int ind;
    scanf("%d", &ind);
    if (ind < 1 || ind > count + 1)
        printf("INVALID INPUT\n");
    else
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->prev = 0;
        newnode->next = 0;
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        node *temp = head;
        if (ind == 1)
        {
            head = newnode;
            newnode->next = temp;
            temp->prev = newnode;
        }
        else if (ind == count + 1)
        {
            while (temp->next != 0)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
        else
        {
            int i = 1;
            while (i < ind - 1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }
    }
    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice = 1;
    node *head = 0, *temp;
    int count = 0;
    while (choice)
    {
        count++;
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Enter 0 to continue or anyother number to continue:\n");
        scanf("%d", &choice);
    }
    display(head);
    // head = insert(head, count);
    // display(head);
    // head = delete (head, count);
    // display(head);
    head = reverse(head);
    display(head);
}